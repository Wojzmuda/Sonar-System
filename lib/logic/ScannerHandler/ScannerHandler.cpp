
#include "ScannerHandler.h"

ScannerHandler::ScannerHandler(ServoHandler& servo, SonarHandler& sonar, int delayTime ):
 _sonar(sonar),
 _servo(servo){
    _delayTime = delayTime;
 };

float ScannerHandler::scanAtAngle(int angle){
    _servo.setAngle(angle);
    delay(20);
    return _sonar.getDistance();
}

ScannerData ScannerHandler::getSingleMeasurment(int angle){
    _servo.setAngle(angle);
    delay(_delayTime);
    ScannerData data;
    data.angle = angle;
    data.distance = _sonar.getDistance();
    return data;
}

int ScannerHandler::getDelayTime(){
    return _delayTime;
}

void ScannerHandler::setDelayTime(int time){
    _delayTime=time;
}

void ScannerHandler::runFullScan(int stepangle){
    for(int i = 0; i<=180; i+=stepangle){
        ScannerData data = getSingleMeasurment(i);
        Serial.print("Scanning...:");
        Serial.print("At ");
        Serial.print(data.angle);
        Serial.print(" degrees -> ");
        Serial.print(data.distance);
        Serial.println("cm");
    }
        for(int i = 180; i>=0; i-=stepangle){
        ScannerData data = getSingleMeasurment(i);
        Serial.print("Scanning...:");
        Serial.print("At ");
        Serial.print(data.angle);
        Serial.print(" degrees -> ");
        Serial.print(data.distance);
        Serial.println("cm");
    }
    delay(100);
}

void ScannerHandler::init(){
    _servo.init();
    _sonar.init();
}