#ifndef VARIABLES_H
#define VARIABLES_H

// === Motor Pins ===
#define MotFrontPWM 19
#define MotFrontA   18
#define MotFrontB   5

#define MotRearPWM 32
#define MotRearA   33
#define MotRearB   25

// === Controller Variables ===
extern int LS_X, LS_Y, RS_X, RS_Y;
extern int DPad_Up, DPad_Down, DPad_Left, DPad_Right;
extern int Square, Cross, Circle, Triangle;
extern int L1, R1, L2, R2;
extern int L3, R3, Share, Options, Touchpad;

// === Servo Control ===
extern float Kp, Ki, Kd;
extern float prevError, integral;
extern int targetAngle, currentAngle;

// Servo_sg90.cpp functions
void ServoSetup();
void servo_loop();

// Mot_Control.cpp functions
void setup_FrontMot();
void loop_MotFront();
void setup_RearMot();
void loop_MotRear();

// Print data function
void Print_Controller_data(); 

#endif
