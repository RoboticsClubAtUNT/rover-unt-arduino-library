/*
  Test.h - Test library for Wiring - description
  Copyright (c) 2006 John Doe.  All right reserved.
*/

// ensure this library description is only included once
#ifndef RoverUNT_h
#define RoverUNT_h

// include types & constants of Wiring core API
#include "Arduino.h"

// library interface description
class Motor {
  private:
    int _speedPin;
    int _forwardPin;
    int _backwardPin;
    int _speedCalibration;
  public:
    Motor(int, int, int);
    void forward(int);
    void backward(int);
    void stop();
};
class Rover {
  private:
    Motor* _Left;
    Motor* _Right;
  public:
    Rover(int, int, int, int, int, int);
    void forward(int);
    void backward(int);
    void stop();
    void rotateLeft(int);
    void rotateRight(int);
    void leftMotorForward(int);
    void leftMotorBackward(int);
    void leftMotorStop();
    void rightMotorForward(int);
    void rightMotorBackward(int);
    void rightMotorStop();
};

#endif
