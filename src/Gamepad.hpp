/*
 * Gamepad.hpp
 *
 *  Created on: Oct 20, 2015
 *      Author: fero
 */
#include "main.hpp"
#include "mainjoystick.h"
#ifndef GAMEPAD_HPP_
#define GAMEPAD_HPP_
static int a;

class Gamepad: Module{

public:

	Gamepad();
	static void *runner(void*param){
		cout<<"\nGamepad thread running\n";
		MainJoystick Joy(0,"dupa");
		Joy.getCommands();
		pthread_exit(0);
	}

	bool work(void* wsk);

};


#endif /* GAMEPAD_HPP_ */
