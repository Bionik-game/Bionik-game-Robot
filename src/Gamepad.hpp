/*
 * Gamepad.hpp
 *
 *  Created on: Oct 20, 2015
 *      Author: fero
 */


#ifndef GAMEPAD_HPP_
#define GAMEPAD_HPP_

#include "main.hpp"

using namespace std;
static bool gpd_enabled=true;
class Gamepad: public Module{
	int fd;
	int *axis;
	int *button;
	int i;
	struct js_event js;
	unsigned char axes;
	unsigned char buttons;
	int version;
	char namee[128];
public:
	/**
	 * Metoda odczytuje aktualne wartosci z joysticka i przesyła je dalej.
	 */
	void getCommands();
	static void invert(bool &b);
	/**
	 *  ta metoda odcztyje akualne wartosci z joysticka i przy nacisnieciu 'RB' sterowanie przejmuje tylko joystick
	 */
	bool checkRequest();
	Gamepad();

	static void *runner(void*param){
		Gamepad *G =(Gamepad*)(param);
		cout<<"\nGamepad thread running\n";
		while(gpd_enabled)
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
