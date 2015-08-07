/**
 * Arduino - Remote Flight Control
 * 
 * RemoteFlightControl.h
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_LIBRARY_REMOTE_FLIGHT_CONTROL_H__
#define __ARDUINO_LIBRARY_REMOTE_FLIGHT_CONTROL_H__ 1

class RemoteFlightControl {
  
  virtual void setThrottle(int throttle) = 0;

  virtual void setPitch(int pitch) = 0;
  
  virtual void setRoll(int roll) = 0;
  
  virtual void setYaw(int yaw) = 0;
};

#endif /* __ARDUINO_LIBRARY_REMOTE_FLIGHT_CONTROL_H__ */
