/*
 * Gamepad.hpp
 *
 *  Created on: Oct 20, 2015
 *      Author: fero
 */


#ifndef GAMEPAD_HPP_
#define GAMEPAD_HPP_

#include "mainjoystick.h"
#include <boost/signal.hpp>
class Gamepad{

public:
	boost::signal<bool(int nr,void* wsk)> SigW;
	Gamepad();
	static void *runner(void*param){
		Gamepad *G =(Gamepad*)(param);
		cout<<"\nGamepad thread running\n";
		MainJoystick Joy(0,"dupa");
		Joy.getCommands(G);
		pthread_exit(0);
	}
	bool work(void* wsk);

};


#endif /* GAMEPAD_HPP_ */
