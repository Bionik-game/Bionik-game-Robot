/*
 * Gamepad.cpp
 *
 *  Created on: Oct 20, 2015
 *      Author: fero
 */
#include "main.hpp"

#include <sys/ioctl.h>
#include <sys/time.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include <linux/joystick.h>

#define NAME_LENGTH 128
extern bool gpd_enabled;
Gamepad::Gamepad(){

	name="Gamepad";
	axis =(int*) calloc(axes, sizeof(int));
	button = (int*)calloc(buttons, sizeof(char));
	checkRequest();
}
bool Gamepad::work(void *wsk){
	dbg_msg("Running");
	SigW(GPD,wsk);
	return 0;
}

void Gamepad::getCommands()
{

	axes = 2;
	buttons = 2;
	version = 0x000800;
	char namee[128] = "Unknown";


	ioctl(fd, JSIOCGVERSION, &version);
	ioctl(fd, JSIOCGAXES, &axes);
	ioctl(fd, JSIOCGBUTTONS, &buttons);
	ioctl(fd, JSIOCGNAME(NAME_LENGTH), namee);





	//joy.getdata();

	if (read(fd, &js, sizeof(struct js_event)) != sizeof(struct js_event)) {
		perror("\njstest: error reading");
		exit (1);
	}

	switch(js.type & ~JS_EVENT_INIT) {
	case JS_EVENT_BUTTON:
		button[js.number] = js.value;
		break;
	case JS_EVENT_AXIS:
		axis[js.number] = js.value;
		break;
	}



	if (axes) {/*
			printf("Axes: ");
			for (i = 0; ( i==0||i==3 || i==4); i++)
				printf("%2d:%6d ", i, axis[i]);
	 */
		//	printf(" X = %d\n Y = %d\n Z = %d\n",axis[4],axis[3],axis[0]);
		//	fflush(stdout);
	}

	if (buttons) {
		if(button[7]){
			invert(gpd_enabled);
			dbg_msg("Gamepad: "+ itos((int)(gpd_enabled)));
			//printf("\ngamepad %s",gpd_enabled ? "on": "false");
		}
	}




	//W TYM MIEJSCU POWINNA BYC ZASTOSOWANA JAKAS FORMA PRZEKAZANIA INFORMACJI Z JOYSTICKA
	Comm robotCommands;
	robotCommands.xCent=axis[4]*0.03051851;
	robotCommands.yCent=axis[3] *0.03051851;;
	robotCommands.zRad=axis[0] *0.03051851;;
	/*dbg_msg("zRad = "+itos(robotCommands.zRad));
	dbg_msg("xCent = "+itos(robotCommands.xCent));
	dbg_msg("yCent = "+itos(robotCommands.yCent));
	 */
	if(gpd_enabled)
	work(&robotCommands);
}

void Gamepad::checkRequest()
{
	if ((fd = open("/dev/input/js1", O_RDONLY)) < 0) {
		perror("jstest");
		exit(1);
	}
	/*
}
	joy.getdata();
	//     Jako guzika przejscia uzylem przycisku "RB"
	if(joy.axis.size()!=6)
		dbg_msg("Detected number of axis differs from 6! Change mode to 'X' !",ERR);
	// joy.buttons[5] == 1 - to jest warunkiem przejecia sterowania przez joystick
	if(joy.buttons[5]== 1){
		gpd_enabled=true;
		dbg_msg("Joystick control enabled!",INF);
	}
	 */
}
void Gamepad::invert(bool &b){
	bool a=b;
	a=!a;
	b=a;

}
