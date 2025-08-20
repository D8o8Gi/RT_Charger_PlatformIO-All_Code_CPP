#include <Arduino.h>
#include "Variables.h"
// --- Motor Pins ---
/* --- Urd RT_Motor Piston udirdah REV Control --- */
void setup_FrontMot() {
  pinMode(MotFrontA, OUTPUT);
  pinMode(MotFrontB, OUTPUT);
  ledcSetup(MotFrontPWM, 2000, 8); // 2000 Hz frequency, 8-bit resolution
  ledcAttachPin(MotFrontPWM, 1); // Attach the PWM pin to the channel
  // ledcAttachChannel(MotFrontPWM, 2000, 8, 1);
}
void loop_MotFront() {
  if (L2 > 10) {
    digitalWrite(MotFrontA, HIGH);
    digitalWrite(MotFrontB, LOW);
    ledcWrite(MotFrontPWM, L2);
  } else {
    digitalWrite(MotFrontA, LOW);
    digitalWrite(MotFrontB, LOW);
    ledcWrite(MotFrontPWM, 0);  // Хэрвээ R2 бага байвал map ашиглаж boost хийж болно
  }
  Serial.print("L2_Val: ");
  Serial.println(L2);
}
/* --- Ard Differential motor Direct_Throtle --- */

void setup_RearMot() {
  pinMode(MotRearA, OUTPUT);
  pinMode(MotRearB, OUTPUT);
  ledcSetup(MotRearPWM, 2000, 8); // 2000 Hz frequency, 8-bit resolution
  ledcAttachPin(MotRearPWM, 4); // Attach the PWM pin to the channel
}

void loop_MotRear() {
  if (R2 > 10) {
    digitalWrite(MotRearA, HIGH);
    digitalWrite(MotRearB, LOW);
    ledcWrite(MotRearPWM, R2);
  } else {
    digitalWrite(MotRearA, LOW);
    digitalWrite(MotRearB, LOW);
    ledcWrite(MotRearPWM, 0);  // Хэрвээ R2 бага байвал map ашиглаж boost хийж болно
  }
  Serial.print("R2_Val: ");
  Serial.println(R2);
}
