#include "Variables.h"

// === Controller Variables ===
int LS_X = 128, LS_Y = 128, RS_X = 128, RS_Y = 128;
int DPad_Up = 0, DPad_Down = 0, DPad_Left = 0, DPad_Right = 0;
int Square = 0, Cross = 0, Circle = 0, Triangle = 0;
int L1 = 0, R1 = 0, L2 = 0, R2 = 0;
int L3 = 0, R3 = 0, Share = 0, Options = 0, Touchpad = 0;

// === Servo Control ===
float Kp = 1.3;
float Ki = 0.005;
float Kd = 0.0;

float prevError = 0;
float integral = 0;

int targetAngle = 90;
int currentAngle = 90;
