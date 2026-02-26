#include "SonarHandler.h"

SonarHandler::SonarHandler(byte trigPin, byte echoPin): _trigPin(trigPin), _echoPin(echoPin){};

byte SonarHandler::getTrigPin(){return _trigPin;};
byte SonarHandler::getEchoPin(){return _echoPin;};

void SonarHandler::init(){
    pinMode( _echoPin, INPUT);
    pinMode(_trigPin, OUTPUT);
}
long SonarHandler::_measureEchoTime(){
    return pulseIn(_echoPin, HIGH, 25000);
}
void SonarHandler::_sendTriggerPulse(){
    digitalWrite(_trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(_trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(_trigPin, LOW);
}

float SonarHandler::getDistance(){
    _sendTriggerPulse();
    long duration  = _measureEchoTime();
    return _calculateDistance(duration);
}

float SonarHandler::_calculateDistance(long duration){
    if(duration == 0) return -1;
    return (duration * _speed_of_sound) / 2;
}