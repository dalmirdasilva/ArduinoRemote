/**
 * Arduino - Remote Car Radio Control
 * 
 * RemoteCarRadioControl.h
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_LIBRARY_REMOTE_CAR_RADIO_CONTROL_H__
#define __ARDUINO_LIBRARY_REMOTE_CAR_RADIO_CONTROL_H__ 1

#include "SerialRadioFrequency.h"
#include "RemoteCarControl.h"

class RemoteCarRadioControl : public RemoteCarControl {
  
    SerialRadioFrequency* serialRadioFrequency;
    int leftForwardPin;
    int leftBackwardPin;
    int rightForwardPin;
    int rightBackwardPin;

public:

    RemoteCarRadioControl(SerialRadioFrequency* serialRadioFrequency,
        int leftForwardPin, 
        int leftBackwardPin, 
        int rightForwardPin, 
        int rightBackwardPin);
    
    virtual void apply();
    
    void parseCommand(char* cmdBuf, char cmdBufPointer);
    
    void loop();
};

#endif /* __ARDUINO_LIBRARY_REMOTE_CAR_RADIO_CONTROL_H__ */
