#include <Arduino.h>
#include <Servo.h>

Servo servo1; 
Servo servo2;

int xPin = A0;   // Joystick X-axis
int yPin = A1;   // Joystick Y-axis

int currentPos1 = 90;  // start centered
int currentPos2 = 90;

void setup() {
  servo1.attach(9);
  servo2.attach(10);
}

void loop() {
  int xVal = analogRead(xPin);   // 0–1023
  int yVal = analogRead(yPin);

  // Convert joystick values to servo angles (0–180)
  int targetPos1 = map(xVal, 0, 1023, 0, 180);
  int targetPos2 = map(yVal, 0, 1023, 0, 180);

  // Smooth slow movement for servo 1
  if (currentPos1 < targetPos1) currentPos1++;
  if (currentPos1 > targetPos1) currentPos1--;
  servo1.write(currentPos1);

  // Smooth slow movement for servo 2
  if (currentPos2 < targetPos2) currentPos2++;
  if (currentPos2 > targetPos2) currentPos2--;
  servo2.write(currentPos2);

  delay(10);  // speed of movement (higher = slower)
}
