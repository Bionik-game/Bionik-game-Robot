/*
 * Controller.cpp
 *
 *  Created on: Aug 3, 2015
 *      Author: Tomek Ferens (fero)
 */
#include "main.hpp"
#include <stdio.h>
using namespace std;

bool Controller::lunit(int nr,void* wsk){
	int state= -1;

	dbg_msg("Received SIGNAL : "+itos(nr),INF);
	switch (nr){
	case NET:					//signal from Network module
		Command* comm;
		comm=static_cast<Command*>(wsk);
		dbg_msg("Controller - NET");
		break;
	case GPD:				//signal from Gamepad module
		dbg_msg("Controller - GPD");
		modules[MOT]->work(wsk);
		break;
	default :
		;

	}

	return false;
}

Controller::Controller(void* m){
	//creation of Modules
	modules[NET]=new Network(NET_PORT,this);
	modules[MOT]=new Motor(MOT);
	name="Controller";

	c_net=(*(this->modules[NET])).SigW.connect(bind(&Controller::lunit,this,_1, _2));
	c_mot_0=(*(this->modules[MOT])).SigW.connect(bind(&Controller::lunit,this,_1 , _2));
	Gamepad *g=(Gamepad*)(m);
	c_gpd=(*(g)).SigW.connect(bind(&Controller::lunit,this,_1 , _2));
}
Controller::~Controller(){
	delete  [] modules;
}
