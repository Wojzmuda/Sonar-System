#pragma once
#include <Arduino.h>
#include "ServoHandler.h"
#include "SonarHandler.h"

struct ScannerData{
    int angle;
    long distance;
};

class ScannerHandler{
    private:
        ServoHandler& _servo;
        SonarHandler& _sonar;
        int _delayTime;
    public:
        ScannerHandler(ServoHandler& servo, SonarHandler& sonar, int delayTime = 50);
        float scanAtAngle(int angle);
        void init();
        ScannerData getSingleMeasurment(int angle);
        int getDelayTime();
        void setDelayTime(int time);
        void runFullScan(int stepangle = 1);

};

