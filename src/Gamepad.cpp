/*
 * Gamepad.cpp
 *
 *  Created on: Oct 20, 2015
 *      Author: fero
 */
#include "main.hpp"

Gamepad::Gamepad(){
	//name="Gamepad";
}
bool Gamepad::work(void *wsk){
	SigW(0,wsk);
}
