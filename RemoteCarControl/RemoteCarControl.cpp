/**
 * Arduino - Remote Car Control
 * 
 * RemoteCarControl.cpp
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_LIBRARY_REMOTE_CAR_CONTROL_CPP__
#define __ARDUINO_LIBRARY_REMOTE_CAR_CONTROL_CPP__ 1

#include "RemoteCarControl.h"
  
void RemoteCarControl::setThrottle(int throttle) {
    this->throttle = throttle;
    this->apply();
}
  
void RemoteCarControl::turnLeft() {
    if (this->isForward) {
        this->leftWheel = throttle;
        this->rightWheel = 0;
    } else {
        this->leftWheel = 0;
        this->rightWheel = -(throttle);
    }
    this->apply();
}
  
void RemoteCarControl::turnRight() {
    if (this->isForward) {
        this->leftWheel = 0;
        this->rightWheel = throttle;
    } else {
        this->leftWheel = -(throttle);
        this->rightWheel = 0;
    }
    this->apply();
}
  
void RemoteCarControl::stop() {
    this->leftWheel = 0;
    this->rightWheel = 0;
    this->apply();
}

void RemoteCarControl::forward() {
    this->leftWheel = throttle;
    this->rightWheel = throttle;
    this->isForward = 1;
    this->apply();
}
  
void RemoteCarControl::backward() {
    this->leftWheel = -(throttle);
    this->rightWheel = -(throttle);
    this->isForward = 0;
    this->apply();
}
  
#endif /* __ARDUINO_LIBRARY_REMOTE_CAR_CONTROL_CPP__ */
