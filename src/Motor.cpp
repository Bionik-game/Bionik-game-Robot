/*
 * Motor.cpp
 *
 *  Created on: Aug 3, 2015
 *      Author: Tomek Ferens (fero)
 *
 */
#include "main.hpp"
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>

#define ADDRESS 0x04

// The I2C bus: This is for V2 pi's. For V1 Model B you need i2c-0
static const char *devName = "/dev/i2c-1";
void send_string(const char*);
#define STRING_SIZE 8
using namespace std;

bool Motor::work(void* wsk){

	dbg_msg("Running");
	/*Zdekodowanie komendy na wartości x,y,obrot*/
	Command* comm;
	comm=(Command*)(wsk);
	string move = "+"+itos(comm->xCent)+","+itos(comm->yCent)+","+itos(comm->zRad);
	dbg_msg(move);
	const char* cstr = move.c_str();
	dbg_msg("zRad = "+itos(comm->zRad));
	dbg_msg("xCent = "+itos(comm->xCent));
	dbg_msg("yCent = "+itos(comm->yCent));
	send_string(cstr);
	return false;
}

Motor::Motor(int nr){

	name="MOTOR";
	//TODO: Inicjalizacja I2C
}

void send_string(const  char* message ){
	int file;

	if ((file = open(devName, O_RDWR)) < 0) {
		fprintf(stderr, "I2C: Failed to access %d\n", devName);
		exit(1);
	}

	printf("I2C: acquiring buss to 0x%x\n", ADDRESS);

	if (ioctl(file, I2C_SLAVE, ADDRESS) < 0) {
		fprintf(stderr, "I2C: Failed to acquire bus access/talk to slave 0x%x\n", ADDRESS);
		exit(1);
	}


	for(int i=0; i < STRING_SIZE; i++){
		//cmd[0] = message[i];
		if (write(file, &message[i], 1) == 1) {

			// As we are not talking to direct hardware but a microcontroller we
			// need to wait a short while so that it can respond.
			//
			// 1ms seems to be enough but it depends on what workload it has

		}

		// Now wait else you could crash the Arduino by sending requests too fast
		usleep(10000);
	}

	close(file);

}
