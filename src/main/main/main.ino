#include <Servo.h>

Servo servoYaw;
Servo servoPitch;

int delayTime = 500;
int distThresh = 550;

int servoYawPin = 9;
int servoPitchPin = 10;
int leftIrPin = A0;
int rightIrPin = A1;
int upIrPin = A4;
int downIrPin = A3;

int clockwise = 90;
int anticlockwise = 92;
int stopSpin = 91;
int leftDist = 0;
int rightDist = 0;
int upDist = 0;
int downDist = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  servoYaw.attach(servoYawPin);
  servoYaw.write(stopSpin);
  servoPitch.attach(servoPitchPin);
  servoPitch.write(stopSpin);
}

void loop()
{
  readLeft();
  readRight();
  readUp();
  readDown();
  if (leftDist > distThresh) {
    servoYaw.write(anticlockwise); // rotate left
  } else if (rightDist > distThresh) {
    servoYaw.write(clockwise); // rotate right
  } else if (upDist > distThresh) {
    servoPitch.write(clockwise); // rotate up
  } else if (rightDist > distThresh) {
    servoPitch.write(anticlockwise); // rotate down
  } else {
    servoYaw.write(stopSpin);
    servoPitch.write(stopSpin);
  }
  delay(delayTime);
}

void readLeft() {
  leftDist = analogRead(leftIrPin);
  Serial.print("Left: ");
  Serial.print(leftDist);
}

void readRight() {
  rightDist = analogRead(rightIrPin);
  Serial.print(" Right: ");
  Serial.print(rightDist);
}

void readUp() {
  upDist = analogRead(upIrPin);
  Serial.print(" Up: ");
  Serial.print(upDist);
}

void readDown() {
  downDist = analogRead(downIrPin);
  Serial.print(" Down: ");
  Serial.println(downDist);
}
