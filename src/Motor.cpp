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

#define STRING_SIZE 8
using namespace std;
bool Motor::work(void* wsk){

	std::cout<<name<<" RUNNING"<<std::endl;

	int state = *(static_cast<int*>(wsk));
	if(state<0){
		//TODO : wysłać po I2C komunikat LEWO/TYŁ/OBRÓTL
	}
	else{
		//TODO : wysłać po I2C komunikat PRAWO/TYŁ/OBRÓTP
	}
	return false;
}

Motor::Motor(int nr){
	std::stringstream ss;
	ss<<nr;
	name="MOTOR"+std::string(ss.str());
	//TODO: Inicjalizacja I2C
}

void send_string( char* message ){
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
