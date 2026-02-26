#include "JoystickHandler.h"

JoystickHandler::JoystickHandler(byte pinX, byte pinY, byte pinSW):
_pinX(pinX),
_pinY(pinY),
_pinSW(pinSW)
{};

void JoystickHandler::init(){
    pinMode(_pinSW, INPUT_PULLUP);
}

bool JoystickHandler::isPressed(){
    return digitalRead(_pinSW)==LOW;
}

int JoystickHandler::getDirectionFromX(){
    int val = analogRead(_pinX);
    int center = 512;
    int deadzone = 150;
    if(val > (center+deadzone)){
        return 1;
    }else if (val < (center - deadzone)){
        return -1;
    }
    return 0;
}

