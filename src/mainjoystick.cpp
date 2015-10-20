#include "mainjoystick.h"
#include <iostream>
#include <string>
using namespace std;
MainJoystick::MainJoystick(unsigned robotId, string device)
    : tempVal(0.0), robotId(robotId), device(device), tempCounter(0), padRequest(false)
{
   // QObject::connect(&requestChecker, &QTimer::timeout, this, &MainJoystick::checkRequest);
   // requestChecker.start(200);
    joy.setJoystick(0);
}

void MainJoystick::getCommands()
{

    joy.getdata();
    if(joy.axis.size()!=6)
        cout<<"UWAGA, WYKRYTO LICZBE OSI INNA NIZ 6! ZMNIEN TRYB PADA NA 'X'! "<<endl;

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

    //RobotCommands robotCommands = {robotId, joy.axis[4]*0.03051851 , joy.axis[3] *0.03051851 , joy.axis[0]*0.03051851 };
     //  stala 0.03051851 powoduje ze MAX wartosc w strukturze jest nie wieksza niz 1000
    //emit robotCommandUpdate(robotCommands);

}

void MainJoystick::checkRequest()
{
    joy.getdata();
//     Jako guzika przejscia uzylem przycisku "RB"
    if(joy.axis.size()!=6)
        cout<<"UWAGA, WYKRYTO LICZBE OSI INNA NIZ 6! ZMNIEN TRYB PADA NA 'X'! "<<endl;
     // joy.buttons[5] == 1 - to jest warunkiem przejecia sterowania przez joystick
}
