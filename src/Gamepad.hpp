/*
 * Gamepad.hpp
 *
 *  Created on: Oct 20, 2015
 *      Author: fero
 */


#ifndef GAMEPAD_HPP_
#define GAMEPAD_HPP_

#include "qjoystick.h"
#include "main.hpp"
static bool gpd_enabled=false;
using namespace std;
class Gamepad: public Module{

public:
	QJoystick joy;

	//boost::signal<bool(int nr,void* wsk)> SigW;
	/**
	 * Metoda odczytuje aktualne wartosci z joysticka i przesyła je dalej.
	 */
	void getCommands();

	/**
	 *  ta metoda odcztyje akualne wartosci z joysticka i przy nacisnieciu 'RB' sterowanie przejmuje tylko joystick
	 */
	void checkRequest();
	Gamepad();
	static void *runner(void*param){
		Gamepad *G =(Gamepad*)(param);
		cout<<"\nGamepad thread running\n";
		if(gpd_enabled)
		G->getCommands();
		pthread_exit(0);
	}
	bool work(void* wsk);

};


struct Comm{
	int type;
	int xCent;
	int yCent;
	int zRad;
};

#endif /* GAMEPAD_HPP_ */
