/* --- Servo_Control Code Area --- */
#include <ESP32Servo.h>
#include "Variables.h"

Servo FrontServo;
const int servoXPin = 4;

// --- Servo calibration (илүү өргөн pulse range) ---
const int minUs = 500;
const int maxUs = 2400;

void ServoSetup() {
  FrontServo.setPeriodHertz(50);
  FrontServo.attach(servoXPin, minUs, maxUs);
}

void servo_loop() {
  // Joystick-оос targetAngle-г тооцоолно
  int delta = LS_X - 128;
  if (abs(delta) <= 4) {
    targetAngle = 90;
  } else {
    targetAngle = 90 + map(delta, -127, 127, -90, 90);
  }

  // PID тооцоолол
  float error = targetAngle - currentAngle;
  integral += error;
  float derivative = error - prevError;

  float output = Kp * error + Ki * integral + Kd * derivative;

  currentAngle += output;
  currentAngle = constrain(currentAngle, 0, 180);  // servo хязгаар

  FrontServo.write(currentAngle);

  prevError = error;

  Serial.print("Target: ");
  Serial.print(targetAngle);
  Serial.print(" | Current: ");
  Serial.println(currentAngle);

  delay(15);
}
/* --- END_Servo_Control Code Area --- */