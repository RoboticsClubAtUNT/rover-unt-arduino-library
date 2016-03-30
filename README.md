# RoverUNT Arduino Library

An original Arduino library to interface w/ the Robotics Club @ UNT's own [RoverBot](http://www.untrobotics.com/guides/56f5bab36d290903004cc37d).

## How to install the Library

1. Download the RoverUNT Arduino Library [here](https://drive.google.com/file/d/0B9_eUsc7ZlewQkNiUThsN0hCLU0/view).
2. Follow [these instructions](https://www.arduino.cc/en/Guide/Libraries#toc4) to import the library into the Arduino IDE.

## Basic Usage

### Initialization

After installing the [RoverUNT Library](https://drive.google.com/file/d/0B9_eUsc7ZlewQkNiUThsN0hCLU0/view), include the library in the top of your Arduino Sketch.

```
#include <RoverUNT.h>
```

After it's imported, create an instance of the Rover class.

```
Rover* Bot

const int MAX = 255; // max speed

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
```

### Moving Forward

A good way to test if your sketch is setup correctly with your hardware is to make the Rover move forward. This will confirm if both wheels rotate in the same direction - otherwise, modify your pin assignments in your code.

```
// ...

void loop() {
  Bot->forward(MAX); // MAX == 255
}

// ...
```


## API Reference

### `Rover::Rover(int,int,int,int,int,int)`

### `Rover::forward(int speed)`

- Move the Rover forward at a defined `speed`.

- `speed` is a PWM value between 0 and 255.

- Usage

  ```
  Bot->forward(255);
  ```

### `Rover::backward(int speed)`

- Move the Rover backward at a defined `speed`.

- `speed` is a PWM value between 0 and 255.

- Usage

  ```
  Bot->backward(255);
  ```


### `Rover::stop()`

- Stop the Rover from moving.
- Usage

  ```
  Bot->stop();
  ```

### `Rover::rotateLeft(int speed)`

- Rotate the Rover counter-clockwise at a defined speed
- `speed` is a PWM value between 0 and 255.

- Usage

  ```
  Bot->rotateLeft(255);
  ```


### `Rover::rotateRight(int speed)`

- Rotate the Rover clockwise at a defined speed

- `speed` is a PWM value between 0 and 255.

- Usage

  ```
  Bot->rotateRight(255);
  ```


### `Rover::leftMotorForward(int speed)`

- Move the Rover's left motor forward at a defined `speed`.

- `speed` is a PWM value between 0 and 255.

- Usage

  ```
  Bot->leftMotorForward(255);
  ```


### `Rover::leftMotorBackward(int speed)`

- Move the Rover's left motor backward at a defined `speed`.

- `speed` is a PWM value between 0 and 255.

- Usage

  ```
  Bot->leftMotorBackward(255);
  ```

### `Rover::leftMotorStop()`

- Stop the Rover's left motor from moving.
- Usage

  ```
  Bot->leftMotorStop();
  ```


### `Rover::rightMotorForward(int speed)`

- Move the Rover's right motor forward at a defined `speed`.

- `speed` is a PWM value between 0 and 255.

- Usage

  ```
  Bot->rightMotorForward(255);
  ```


### `Rover::rightMotorBackward(int speed)`

- Move the Rover's right motor backward at a defined `speed`.

- `speed` is a PWM value between 0 and 255.

- Usage

  ```
  Bot->rightMotorBackward(255);
  ```

### `Rover::rightMotorStop()`

- Stop the Rover's right motor from moving.
- Usage

  ```
  Bot->rightMotorStop();
  ```

## Notes and Tips
1. Add a short delay with a stop to prevent the motors from sparking on sudden spin changes:

  ```
  void loop() {

      Bot->rotateLeft();
      delay(1000); // rotate left for one second

      Bot->stop(); // stop
      delay(200) // and short delay to prevent sparking

      Bot->rotateRight();
      delay(1000); // rotate right for one second

      Bot->stop(); // stop
      delay(200) // and short delay to prevent sparking

  }
  ```
