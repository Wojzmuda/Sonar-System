#include "ServoHandler.h"
#include <Arduino.h>

ServoHandler::ServoHandler(byte servoPin):_servoPin(servoPin), _currentAngle(90){}

void ServoHandler::init(){
    attach();
}
void ServoHandler::attach(){
    if(!_servo.attached()){
        _servo.attach(_servoPin);
    }
}
void ServoHandler::detach(){
    if(_servo.attached()){
        _servo.detach();
    }
}


int ServoHandler::getAngle() const{
    return _currentAngle;
}

void ServoHandler::setAngle(int angle){
    if (angle < 0) angle = 0;
    if (angle > 180) angle = 180;
    _currentAngle = angle;
    _servo.write(_currentAngle);
}

void ServoHandler::moveSmoothly(int angle, int delayTime){

    while (_currentAngle != angle) {
        if (_currentAngle < angle) {
            _currentAngle++; 
        } else {
            _currentAngle--; 
        }
        
        setAngle(_currentAngle);
        delay(delayTime); 
    }
}