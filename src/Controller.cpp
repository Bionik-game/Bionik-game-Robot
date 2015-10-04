/*
 * Controller.cpp
 *
 *  Created on: Aug 3, 2015
 *      Author: Tomek Ferens (fero)
 */
#include "main.hpp"


bool Controller::lunit(int nr,void* wsk){
	int state= -1;

	std::cout<<"CONTROLLER "<<"RECEIVED SIGNAL : " << nr<<std::endl;
	switch (nr){
	Command* comm;
	comm=(Command*)(wsk);


	case NET:					//signal from Network module
		switch(comm->type){
		case STRAIGHT:
			cout<<"straight";
			//TODO: zaimplementować wywołania(lub jedno wywołanie) dla modułów silników

			break;
		case BACK:
			cout<<"back";
			break;
		case LEFT:
			cout<<"left";
			break;
		case RIGHT:
			cout<<"right";
			break;
		default :
			std::cout<<"ERROR IN NETWORK COMMAND"<<std::endl;
		}

		break;
		default :
			;

	}

	return false;
}

Controller::Controller(){
	//creation of Modules
	modules[NET]=new Network(NET_PORT,this);
	modules[MOT0]=new Motor(MOT0);
	modules[MOT1]=new Motor(MOT1);

	c_net=(*(this->modules[NET])).SigW.connect(bind(&Controller::lunit,this,_1, _2));
	c_mot_0=(*(this->modules[MOT0])).SigW.connect(bind(&Controller::lunit,this,_1 , _2));
	c_mot_1=(*(this->modules[MOT1])).SigW.connect(bind(&Controller::lunit,this,_1 , _2));
}
Controller::~Controller(){
	delete  [] modules;
}
