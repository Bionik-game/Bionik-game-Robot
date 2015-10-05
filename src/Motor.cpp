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

	int state = *(static_cast<int*>(wsk));
if(state<0){
	//TODO : wysłać po I2C komunikat LEWO/TYŁ/OBRÓTL
}
else{
	//TODO : wysłać po I2C komunikat PRAWO/TYŁ/OBRÓTP
}
	return false;
}

Motor::Motor(int nr){
std::stringstream ss;
ss<<nr;
	name="MOTOR"+std::string(ss.str());
	//TODO: Inicjalizacja I2C
}
