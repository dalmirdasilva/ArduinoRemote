/**
 * Arduino - Remote Car Control
 * 
 * RemoteCarControl.h
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_LIBRARY_REMOTE_CAR_CONTROL_H__
#define __ARDUINO_LIBRARY_REMOTE_CAR_CONTROL_H__ 1

class RemoteCarControl {

protected:

  char isForward;
  int throttle;
  int leftWheel;
  int rightWheel;

public:
  
  virtual void apply() = 0;
  
  void setThrottle(int throttle);
  
  void stop();
  
  void forward();
  
  void backward();
  
  void turnLeft();
  
  void turnRight();
};

#endif /* __ARDUINO_LIBRARY_REMOTE_CAR_CONTROL_H__ */
