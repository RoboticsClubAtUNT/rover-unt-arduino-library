/*
  Test.h - Test library for Wiring - implementation
  Copyright (c) 2006 John Doe.  All right reserved.
*/

// include core Wiring API
#include "Arduino.h"

// include this library's description file
#include "RoverUNT.h"

// include description files for other libraries used (if any)
#include "HardwareSerial.h"

Motor::Motor(int speedPin, int forwardPin, int backwardPin) {
  _speedPin = speedPin;
  _forwardPin = forwardPin;
  _backwardPin = backwardPin;
  _speedCalibration = 0;
  pinMode(_speedPin, OUTPUT);
  pinMode(_forwardPin, OUTPUT);
  pinMode(_backwardPin, OUTPUT);
}

void Motor::forward(int speed) {
  digitalWrite(_backwardPin, LOW);
  digitalWrite(_forwardPin, HIGH);

  if (speed < 0) {
    analogWrite(_speedPin, 0);
  } else if (speed > 255) {
    analogWrite(_speedPin, 255);
  } else {
    analogWrite(_speedPin, speed);
  }
}

void Motor::backward(int speed) {
  digitalWrite(_forwardPin, LOW);
  digitalWrite(_backwardPin, HIGH);
  if (speed < 0) {
    analogWrite(_speedPin, 0);
  } else if (speed > 255) {
    analogWrite(_speedPin, 255);
  } else {
    analogWrite(_speedPin, speed);
  }
}

void Motor::stop() {
  digitalWrite(_forwardPin, LOW);
  digitalWrite(_backwardPin, LOW);
  analogWrite(_speedPin, 0);
}

Rover::Rover(
  int leftSpeedPin,
  int leftForwardPin,
  int leftBackwardPin,
  int rightSpeedPin,
  int rightForwardPin,
  int rightBackwardPin
) {
  _Left = new Motor(leftSpeedPin, leftForwardPin, leftBackwardPin);
  _Right = new Motor(rightSpeedPin, rightForwardPin, rightBackwardPin);
}

void Rover::forward(int speed) {
  _Left->forward(speed);
  _Right->forward(speed);
}

void Rover::backward(int speed) {
  _Left->backward(speed);
  _Right->backward(speed);
}

void Rover::stop() {
  _Left->stop();
  _Right->stop();
}

void Rover::rotateLeft(int speed) {
  _Left->forward(speed);
  _Right->backward(speed);
}

void Rover::rotateRight(int speed) {
  _Left->backward(speed);
  _Right->forward(speed);
}

void Rover::leftMotorForward(int speed) {
  _Left->forward(speed);
}

void Rover::leftMotorBackward(int speed) {
  _Left->backward(speed);
}

void Rover::leftMotorStop() {
  _Left->stop();
}

void Rover::rightMotorForward(int speed) {
  _Right->forward(speed);
}

void Rover::rightMotorBackward(int speed) {
  _Right->backward(speed);
}

void Rover::rightMotorStop() {
  _Right->stop();
}
