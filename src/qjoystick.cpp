#include "qjoystick.h"

#include <vector>
#include <assert.h>

#define POLL_INTERVAL 40
using namespace std;
QJoystick::QJoystick()
    : m_joystick(nullptr)
{
    // Sure, we're only using the Joystick, but SDL doesn't work if video isn't initialised
    sdl::SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK);
}

int QJoystick::currentJoystick()
{
    return sdl::SDL_JoystickIndex(m_joystick);
}

string QJoystick::joystickName(int js)
{
    assert(js < availableJoysticks());
    assert(js >= 0);
    return string(sdl::SDL_JoystickName(js));
}

int QJoystick::joystickNumAxes(int js)
{
    assert(js < availableJoysticks());
    assert(js >= 0);
    return (sdl::SDL_JoystickNumAxes(m_joystick));
}

int QJoystick::joystickNumButtons(int js)

{
    assert(js < availableJoysticks());
    assert(js >= 0);
    return (sdl::SDL_JoystickNumButtons(m_joystick));
}

void QJoystick::setJoystick(int js)
{
    assert(js < availableJoysticks());
    assert(js >= 0);

    if (m_joystick != nullptr)
        sdl::SDL_JoystickClose(m_joystick);
    m_joystick = sdl::SDL_JoystickOpen(js);
}

QJoystick::~QJoystick()
{
    axis.clear();
    buttons.clear();
    sdl::SDL_JoystickClose(m_joystick);
    sdl::SDL_QuitSubSystem(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK);
}


int QJoystick::availableJoysticks()
{
     return sdl::SDL_NumJoysticks();
}

void QJoystick::getdata()
{
    axis.clear();
    buttons.clear();


        sdl::SDL_Event event;

     sdl::SDL_PollEvent(&event);

    for(int i=0;i<sdl::SDL_JoystickNumAxes(m_joystick);i++)
    {
        axis.push_back(sdl::SDL_JoystickGetAxis(m_joystick,i));
    }

    for(int i=0;i<sdl::SDL_JoystickNumButtons(m_joystick);i++)
    {
        buttons.push_back(sdl::SDL_JoystickGetButton(m_joystick,i));
    }

}
