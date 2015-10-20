#ifndef QJOYSTICK_H
#define QJOYSTICK_H


#include <vector>
#include <string>
namespace sdl {
#include "SDL/SDL.h"
}
using namespace std;

class QJoystick
{
public:
    QJoystick();
    ~QJoystick();
    int availableJoysticks();
    int currentJoystick();
    string joystickName(int id);
    int joystickNumAxes(int id);
    int joystickNumButtons(int id);
    vector<int> axis;
    vector<bool> buttons;
    void getdata();
    void setJoystick(int jsNumber);

private:
    sdl::SDL_Joystick* m_joystick;
};

#endif // QJOYSTICK_H
