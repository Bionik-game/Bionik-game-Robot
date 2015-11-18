/*
 * Gamepad.cpp
 *
 *  Created on: Oct 20, 2015
 *      Author: fero
 */
#include "main.hpp"



#define NAME_LENGTH 128
extern bool gpd_enabled;
Gamepad::Gamepad(){

	axes = 2;
	buttons = 2;
	version = 0x000800;
	name="Gamepad";
	axis =(int*) calloc(axes, sizeof(int));
	button = (int*)calloc(buttons, sizeof(char));
	/*
	 * Retrieve gamepad's info
	 */
	ioctl(fd, JSIOCGVERSION, &version);
	ioctl(fd, JSIOCGAXES, &axes);
	ioctl(fd, JSIOCGBUTTONS, &buttons);
	ioctl(fd, JSIOCGNAME(NAME_LENGTH), namee);

	//checkRequest();
}
/*
 * Sends signal to Controller
 */
bool Gamepad::work(void *wsk){
	dbg_msg("Running");
	SigW(GPD,wsk);
	return 0;
}

void Gamepad::getCommands()
{
	if (read(fd, &js, sizeof(struct js_event)) != sizeof(struct js_event)) {
		dbg_msg("Error reading",ERR);

	}

	switch(js.type & ~JS_EVENT_INIT) {
	case JS_EVENT_BUTTON:
		button[js.number] = js.value;
		break;
	case JS_EVENT_AXIS:
		axis[js.number] = js.value;
		break;
	}

	if (buttons) {
		/* If 'START' button pressed -
		 * enable/disable gamepad
		 */
		if(button[7]){
			invert(gpd_enabled);
			dbg_msg("Gamepad: "+ (((int)(gpd_enabled))== 1 ? string("ENABLED"): string("DISABLED")));
		}
	}
	/*
	 * Scale values to range[-1000;1000]
	 */
	Comm robotCommands;
	robotCommands.xCent=axis[4]*0.03051851;
	robotCommands.yCent=axis[3] *0.03051851;;
	robotCommands.zRad=axis[0] *0.03051851;;
	/*dbg_msg("zRad = "+itos(robotCommands.zRad));
	dbg_msg("xCent = "+itos(robotCommands.xCent));
	dbg_msg("yCent = "+itos(robotCommands.yCent));
	 */

	/*
	 * Sends signal with values to Controller
	 */
	if(gpd_enabled)
		work(&robotCommands);
}

bool Gamepad::checkRequest()
{
	/*
	 * Acquire acces to gamepad device node
	 */
	if ((fd = open("/dev/input/js2", O_RDONLY)) < 0) {
		dbg_msg("Not detected !",ERR);
		gpd_enabled=false;
		return 1;
	}
	else {
		gpd_enabled=true;
		return 0;
	}

}
void Gamepad::invert(bool &b){
	bool a=b;
	a=!a;
	b=a;
}
