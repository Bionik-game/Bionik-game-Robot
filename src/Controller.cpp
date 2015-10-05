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

	case NET:					//signal from Network module
		Command* comm;
		comm=static_cast<Command*>(wsk);
#ifdef DEBUG
	printf("komenda %d \n",comm->type);
#endif
		switch(comm->type){
		case VERTICAL:
			cout<<"Vertical movement\n";
			modules[MOT0]->work((void*)(comm->xCent));
			break;
		case HORIZONTAL:
			cout<<"Horizontal movement\n";
			break;
		case ROTATE:
					cout<<"Rotate movement\n";
					break;
		default :
			std::cerr<<"ERROR IN NETWORK COMMAND"<<std::endl;
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
