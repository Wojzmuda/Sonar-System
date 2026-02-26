#pragma once
#include <Arduino.h>
#include<Servo.h>

class ServoHandler{

    private:
        byte _servoPin;
        Servo _servo;
        int _currentAngle;
    public:
        ServoHandler(byte servoPin);
        void init();
        void setAngle(int angle);
        int getAngle() const;
        void attach();
        void detach();
        void moveSmoothly(int targetAngle, int delayTime);

};