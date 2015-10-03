/*
 * Motor.cpp
 *
 *  Created on: Aug 3, 2015
 *      Author: Tomek Ferens (fero)
 *
 */
#include "main.hpp"

bool Motor::work(void* wsk){

	std::cout<<name<<" RUNNING"<<std::endl;

	int state= *((int*)(wsk));//przerobić na zgodne z standardem C++11
	switch (state){

	case STRAIGHT:
		std::cout<<name<<"IS RUNNING STRAIGHT"<<std::endl;
		//TODO: wystawienie odpowiednich stanów na porty polaryzacji kierunku mostka + PWM
		break;
	case BACK:
		std::cout<<name<<"IS RUNNING BACK"<<std::endl;
			//TODO: wystawienie odpowiednich stanów na porty polaryzacji kierunku mostka + PWM
			break;
	case LEFT:
		std::cout<<name<<"IS RUNNING LEFT"<<std::endl;
			//TODO: wystawienie odpowiednich stanów na porty polaryzacji kierunku mostka + PWM
			break;
	case RIGHT:
		std::cout<<name<<"IS RUNNING RIGHT"<<std::endl;
			//TODO: wystawienie odpowiednich stanów na porty polaryzacji kierunku mostka + PWM
			break;

	default:
		;
	}
	return false;
}

Motor::Motor(int nr){
std::stringstream ss;
ss<<nr;
	name="MOTOR"+std::string(ss.str());
	//TODO: Inicjalizacja portów i PWM'u Rasp'a
}
