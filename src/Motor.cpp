/*
 * Motor.cpp
 *
 *  Created on: Aug 3, 2015
 *      Author: Tomek Ferens (fero)
 *
 */
#include "main.hpp"


//Arduino's Address
#define ADDRESS 0x04

// The I2C bus: This is for V2 pi's. For V1 Model B you need i2c-0
static const char *devName = "/dev/i2c-1";
void send_string(const char*);
#define STRING_SIZE 18
using namespace std;

bool Motor::work(void* wsk){
sync_i2c = 1;
	dbg_msg("Running");
	/*Zdekodowanie komendy na wartości x,y,obrot*/
	Command* comm;
	comm=(Command*)(wsk);

	/*Format komendy do Arduino : +x,y,z*/
	string move = "+"+itos(comm->xCent)+","+itos(comm->yCent)+","+itos(comm->zRad);
	const char* cstr = move.c_str();
#ifndef DEBUG
//dbg_msg(move);


	dbg_msg("zRad = "+itos(comm->zRad));
	dbg_msg("xCent = "+itos(comm->xCent));
	dbg_msg("yCent = "+itos(comm->yCent));
#endif
	send_string(cstr);
	return false;
}

Motor::Motor(int nr){
	name="MOTOR";
}

void send_string(const  char* message ){
	int file;
	if ((file = open(devName, O_RDWR)) < 0) {
//dbg_msg("I2C: FAILED to acces system device",ERR);
//	fprintf(stderr, "I2C: Failed to access %d\n", devName);
		//exit(1);
	}
#ifndef DEBUG
//dbg_msg("I2C: SUCCEDED to acquire bus",INF);
#endif
//	printf("I2C: acquiring buss to 0x%x\n", ADDRESS);

	if (ioctl(file, I2C_SLAVE, ADDRESS) < 0) {
//dbg_msg("I2C : FAILED to talk to slave",ERR);
		//	exit(1);
	}

int i;
	for( i=0; i < STRING_SIZE; i++){
		//cmd[0] = message[i];
		if (write(file, &message[i], 1) == 1) {

			// As we are not talking to direct hardware but a microcontroller we
			// need to wait a short while so that it can respond.
			//
			// 1ms seems to be enough but it depends on what workload it has

		}

		// Now wait else you could crash the Arduino by sending requests too fast
//		usleep(10);
	}

	close(file);
sync_i2c=0;// dodany komentarz Zuza 
}

