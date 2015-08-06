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


case NET:					//signal from Network
	switch(*(int*)(wsk)){	//przerobić na zgodne z std C++11
	case STRAIGHT:
		//TODO: zaimplementować wywołania(lub jedno wywołanie) dla modułów silników
		break;
	case BACK:
		break;
	case LEFT:
		break;
	case RIGHT:
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
	modules[NET]=new Network();
	modules[MOT0]=new Motor(MOT0);
	modules[MOT1]=new Motor(MOT1);

	//TODO: przerobić to na sloty
	//SigC.connect(bind(&Module::work,modules[WR],_1));
	//(*(this->modules[0])).SigW.connect(bind(&Controller::lunit,this,_1, _2));
	(*(this->modules[MOT0])).SigW.connect(bind(&Controller::lunit,this,_1 , _2));
	(*(this->modules[MOT1])).SigW.connect(bind(&Controller::lunit,this,_1 , _2));
}
Controller::~Controller(){
	delete  [] modules;
}
