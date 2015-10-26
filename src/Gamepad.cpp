/*
 * Gamepad.cpp
 *
 *  Created on: Oct 20, 2015
 *      Author: fero
 */
#include "main.hpp"

Gamepad::Gamepad(){
	name="Gamepad";
	gpd_enabled=false;
	joy.setJoystick(0);
	checkRequest();
}
bool Gamepad::work(void *wsk){
	dbg_msg("Running");
	SigW(GPD,wsk);
	return 0;
}

void Gamepad::getCommands()
{


	joy.getdata();
	if(joy.axis.size()!=6)
		dbg_msg("Detected number of axis differs from 6! Change mode to 'X' !",ERR);
	/* Tutaj zawiera sie legenda, ktora komorka axis i buttons odnosi sie do ktorej osi.
	 * Bardzo prosze nie ruszac. To moze byc przydatne przy dalszych zmianach.
        joystick.at(current_joystick)->axis[0]=joy->axis[0];
        joystick.at(current_joystick)->axis[1]=joy->axis[1];
        //joystick.at(current_joystick)->axis[2]=joy->axis[2];//LT
        joystick.at(current_joystick)->axis[3]=joy->axis[3];
        joystick.at(current_joystick)->axis[4]=joy->axis[4];
        //joystick.at(current_joystick)->axis[5]=joy->axis[5];//RT
        joystick.at(current_joystick)->button[0] = joy->buttons[0]; // A
        joystick.at(current_joystick)->button[1] = joy->buttons[1]; // B
        joystick.at(current_joystick)->button[2] = joy->buttons[2]; // X
        joystick.at(current_joystick)->button[3] = joy->buttons[3]; // Y
        joystick.at(current_joystick)->button[4] = joy->buttons[4]; //LB
        joystick.at(current_joystick)->button[5] = joy->buttons[5]; //RB
        joystick.at(current_joystick)->button[6] = joy->buttons[6]; //back
        joystick.at(current_joystick)->button[7] = joy->buttons[7]; //start */


	double predkoscX = joy.axis[4]*0.03051851;
	double predkoscY = joy.axis[3] *0.03051851;
	double obrot = joy.axis[0]*0.03051851;


	//W TYM MIEJSCU POWINNA BYC ZASTOSOWANA JAKAS FORMA PRZEKAZANIA INFORMACJI Z JOYSTICKA
	Comm robotCommands;
	robotCommands.xCent=predkoscX;
	robotCommands.yCent=predkoscY;
	robotCommands.zRad=obrot;
	dbg_msg("zRad = "+itos(robotCommands.zRad));
	dbg_msg("xCent = "+itos(robotCommands.xCent));
	dbg_msg("yCent = "+itos(robotCommands.yCent));
	work(&robotCommands);
	//RobotCommands robotCommands = {robotId, joy.axis[4]*0.03051851 , joy.axis[3] *0.03051851 , joy.axis[0]*0.03051851 };
	//  stala 0.03051851 powoduje ze MAX wartosc w strukturze jest nie wieksza niz 1000
	//emit robotCommandUpdate(robotCommands);

}

void Gamepad::checkRequest()
{
	joy.getdata();
	//     Jako guzika przejscia uzylem przycisku "RB"
	if(joy.axis.size()!=6)
		dbg_msg("Detected number of axis differs from 6! Change mode to 'X' !",ERR);
	// joy.buttons[5] == 1 - to jest warunkiem przejecia sterowania przez joystick
	if(joy.buttons[5]== 1){
		gpd_enabled=true;
		dbg_msg("Joystick control enabled!",INF);
	}
}
