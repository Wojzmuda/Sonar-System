#pragma once
#include <Arduino.h>


class JoystickHandler{
    private:
        byte _pinX;
        byte _pinY;
        byte _pinSW;

    public:
        JoystickHandler(byte pinX, byte pinY, byte pinSW);
        void init();
        bool isPressed();
        int getDirectionFromX();
};