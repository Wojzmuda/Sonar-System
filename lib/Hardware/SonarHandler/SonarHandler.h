#pragma once
#include <Arduino.h>

class SonarHandler{
    private:
        byte _trigPin;
        byte _echoPin;
        static constexpr float _speed_of_sound = 0.0343; // cm/us
        void _sendTriggerPulse();
        long _measureEchoTime();
        float _calculateDistance(long duration);
        
    public:
        SonarHandler(byte trigPin, byte echoPin);
        void init();
        float getDistance();
        byte getTrigPin();
        byte getEchoPin();
        
    };