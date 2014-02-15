/**
 * Arduino - Remote Car Radio Control
 * 
 * RemoteCarRadioControl.cpp
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_LIBRARY_REMOTE_CAR_RADIO_CONTROL_CPP__
#define __ARDUINO_LIBRARY_REMOTE_CAR_RADIO_CONTROL_CPP__ 1

#include "RemoteCarRadioControl.h"

RemoteCarRadioControl::RemoteCarRadioControl(SerialRadioFrequency* serialRadioFrequency,
      int leftForwardPin, 
      int leftBackwardPin, 
      int rightForwardPin, 
      int rightBackwardPin) :
    RemoteCarControl(),
    serialRadioFrequency(serialRadioFrequency) {
      this->leftForwardPin = leftForwardPin;
      this->leftBackwardPin = leftBackwardPin;
      this->rightForwardPin = rightForwardPin;
      this->rightBackwardPin = rightBackwardPin;
      this->throttle = 200;
      
}

void RemoteCarRadioControl::loop() {
    char cmdBuf[8];
    unsigned char cmdBufPointer = 0;
    char endCommandMark = ';';
    while(true) {
        if (this->serialRadioFrequency->available()) {
            char c = this->serialRadioFrequency->read();
            serialRadioFrequency->write(c);
            if (c == endCommandMark || cmdBufPointer >= 8) {
                if (cmdBufPointer > 1) {
                  parseCommand(cmdBuf, cmdBufPointer);
                }
                cmdBufPointer = 0;
            } else {
                cmdBuf[cmdBufPointer++] = c;
            }
        }
    }
}

void RemoteCarRadioControl::parseCommand(char* cmdBuf, char cmdBufPointer) {
    char action = cmdBuf[cmdBufPointer - 1];
    Serial.println(action);
    switch(action) {
        case 'B':
            serialRadioFrequency->println("backward");
            this->backward();
        break;
        case 'F':
            serialRadioFrequency->println("forward");
            this->forward();
        break;
        case 'S':
            serialRadioFrequency->println("stop");
            this->stop();
        break;
        case 'L':
            serialRadioFrequency->println("turnLeft");
            this->turnLeft();
        break;
        case 'R':
            serialRadioFrequency->println("turnRight");
            this->turnRight();
        break;
        /*
        case 'T':
            serialRadioFrequency->println("setThrottle");
            char throttle = cmdBuf[1];
            this->setThrottle(((int) throttle) | 0xff);
        break;
        */
        default:
            serialRadioFrequency->println("not recognized");
    }
}

void RemoteCarRadioControl::apply() {
    if (this->leftWheel >= 0) {
        analogWrite(this->leftForwardPin, this->leftWheel);
        analogWrite(this->leftBackwardPin, 0);
    } else {
        analogWrite(this->leftForwardPin, 0);
        analogWrite(this->leftBackwardPin, abs(this->leftWheel));
    }
    if (this->rightWheel >= 0) {
        analogWrite(this->rightForwardPin, this->rightWheel);
        analogWrite(this->rightBackwardPin, 0);
    } else {
        analogWrite(this->rightForwardPin, 0);
        analogWrite(this->rightBackwardPin, abs(this->rightWheel));
    }
}

#endif /* __ARDUINO_LIBRARY_REMOTE_CAR_RADIO_CONTROL_CPP__ */
