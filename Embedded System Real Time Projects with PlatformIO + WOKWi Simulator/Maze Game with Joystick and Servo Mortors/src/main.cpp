#include <Arduino.h>
#include <Servo.h>

Servo servoX;
Servo servoY;

int joyX = A0;  // Joystick X-axis
int joyY = A1;  // Joystick Y-axis

int xVal, yVal;
int servoXPos, servoYPos;

void setup() {
  servoX.attach(9);
  servoY.attach(10);
  
  // Center both servos
  servoX.write(90);
  servoY.write(90);
  
  Serial.begin(9600);
}

void loop() {
  // Read joystick values
  xVal = analogRead(joyX);
  yVal = analogRead(joyY);

  // Map joystick (0–1023) to servo angles (0–180)
  servoXPos = map(xVal, 0, 1023, 0, 180);
  servoYPos = map(yVal, 0, 1023, 0, 180);

  // Write mapped values to servos
  servoX.write(servoXPos);
  servoY.write(servoYPos);

  // Optional: print for debugging
  Serial.print("X: "); Serial.print(servoXPos);
  Serial.print(" | Y: "); Serial.println(servoYPos);

  delay(20); // Smooth movement
}
