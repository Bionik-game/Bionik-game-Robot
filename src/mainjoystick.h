#ifndef MAINJOYSTICK_H
#define MAINJOYSTICK_H


#include "qjoystick.h"
using namespace std;
class MainJoystick 
{
private:
    double tempVal;
    unsigned tempCounter;
    unsigned robotId;
    string device;

    bool padRequest;

    QJoystick joy;

public:
    explicit MainJoystick(unsigned robotId, string device);

	/**
	 * Metoda odczytuje aktualne wartosci z joysticka i przesyła je dalej.
	 */
    void getCommands();
    
    /**
     *  ta metoda odcztyje akualne wartosci z joysticka i przy nacisnieciu 'RB' sterowanie przejmuje tylko joystick
     */
    void checkRequest();
};

#endif // MAINJOYSTICK_H
