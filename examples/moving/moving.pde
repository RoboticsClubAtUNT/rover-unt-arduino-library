#include <RoverUNT.h>

// Moving Forward
// by Charles Bido <http://www.untrobotics.com>

// Demonstrates how to do move randomly with the RoverUNT library

// Created March 1st, 2016

const int MAX = 255; // max speed;

Rover* Bot;

void setup() {

  int leftSpeedPin = 9;     // enb
  int leftForwardPin = 8;   // in3
  int leftBackwardPin = 7;  // in4
  int rightSpeedPin = 3;    // ena
  int rightForwardPin = 5;  // in2
  int rightBackwardPin = 4; // in1

  Bot = new Rover(
    leftSpeedPin,
    leftForwardPin,
    leftBackwardPin,
    rightSpeedPin,
    rightForwardPin,
    rightBackwardPin
  );

  Serial.begin(9600);
  Serial.println("<Arduino is ready>");
  delay(2000);
}

int dice = 0;

void loop() {

  dice = random(1,7); // roll a random number between 1 and 6

  switch (dice) {

    case 1: // move the rover forwards

      Bot->forward(MAX);
      delay(1000);
      break;

    case 2: // move the rover backwards

      Bot->backward(MAX);
      delay(1000);
      break;

    case 3: // rotate the rover left

      Bot->rotateLeft(MAX);
      delay(1000);
      break;

    case 4: // rotate the rover right

      Bot->rotateRight(MAX);
      delay(1000);
      break;

    case 5: // basic stop

      Bot->stop();
      delay(1000);
      break;

    case 6: // lower-level custom behavior

      Bot->leftMotorForward(MAX);
      Bot->rightMotorForward(200);
      delay(1000);
      Bot->leftMotorStop();
      Bot->rightMotorBackward(MAX);
      delay(1000);
      Bot->leftMotorForward(MAX);
      Bot->rightMotorStop();
      delay(1000);
      Bot->leftMotorBackward(MAX);
      Bot->rightMotorForward(MAX);
      delay(1000);
      break;

    default:

      Bot->stop();
      delay(1000);
      break;

  }
}
