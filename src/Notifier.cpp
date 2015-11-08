/*
 * Notifier.cpp
 * Definicje funkcji modułu roboczego
 *  Created on: Jun 3, 2015
 *      Author: Tomek Ferens
 */
#include "main.hpp"


//Sets apropriate output LEDs on Robot's control panel
bool Notifier::work(void* wsk){

	dbg_msg("Running");
	LEDS= *(static_cast<char*>(wsk));

	if(LEDS & 0x01){
#ifdef BRD_BUILD

#endif
	}
	else
	{
#ifdef BRD_BUILD
		digitalWrite(0,HIGH);
#endif
	}
	 if (LEDS & NET_LED){//Network communication LED status
#ifdef BRD_BUILD
		 for(int i=0; i<4; i++){
		digitalWrite(1,HIGH);
		usleep(1000);
		digitalWrite(1,LOW);
		 }
#endif

	}
	else
	{}

	return false;
}
//Initialization of IO ports
Notifier::Notifier(){

	name="Notifier";
#ifdef BRD_BUILD
	wiringPiSetup();
	pinMode (ON_LED,OUTPUT);	//GPIO_0 (BCM_GPIO 17) (PHYS. HEADER -> 11)
	pinMode (BAT_LED,OUTPUT);	//GPIO_2 (BCM_GPIO 27) (PHYS. HEADER -> 13)
	pinMode (NET_LED,OUTPUT);	//GPIO_1 (BCM_GPIO 18) (PHYS. HEADER -> 12)
	//Let's inform world that RPI2 is alive ('ON' LED)
	digitalWrite(ON_LED,HIGH);
#endif

}


