#include <PS4Controller.h>
#include "Variables.h"

int applyDeadzone(int value, int center = 128, int dz = 7) {
  return (abs(value - center) <= dz) ? center : value;
}

void setup() {
  Serial.begin(115200);
  PS4.begin("04:83:08:51:C4:12");
  Serial.println("PS4 controller холбогдож байна...");
/* --- Busad setup end orj irne ---*/
  ServoSetup();
  setup_FrontMot();
  setup_RearMot();
}

void loop() {
  if (PS4.isConnected()) {
    // === Analog sticks with deadzone ===
    LS_X = applyDeadzone(PS4.LStickX() + 128);
    LS_Y = applyDeadzone(PS4.LStickY() + 128);
    RS_X = applyDeadzone(PS4.RStickX() + 128);
    RS_Y = applyDeadzone(PS4.RStickY() + 128);

    // === DPad ===
    DPad_Up = PS4.Up();
    DPad_Down = PS4.Down();
    DPad_Left = PS4.Left();
    DPad_Right = PS4.Right();

    // === Buttons ===
    Square = PS4.Square();
    Cross = PS4.Cross();
    Circle = PS4.Circle();
    Triangle = PS4.Triangle();

    L1 = PS4.L1();
    R1 = PS4.R1();
    L2 = PS4.L2Value();
    R2 = PS4.R2Value();

    L3 = PS4.L3();
    R3 = PS4.R3();
    Share = PS4.Share();
    Options = PS4.Options();
    Touchpad = PS4.Touchpad();
    
/* --- Loop Endees Ehelne --- */
    Print_Controller_data();
    servo_loop();
    loop_MotRear();
    loop_MotFront();
  }

}

void Print_Controller_data(){

    Serial.print(LS_X); Serial.print(" ");
    Serial.print(LS_Y); Serial.print(" ");
    Serial.print(RS_X); Serial.print(" ");
    Serial.print(RS_Y); Serial.print('\t');

    Serial.print(DPad_Up); Serial.print(DPad_Down);
    Serial.print(DPad_Left); Serial.print(DPad_Right); Serial.print('\t');

    Serial.print(Square); Serial.print(Cross);
    Serial.print(Circle); Serial.print(Triangle); Serial.print('\t');

    Serial.print(L1); Serial.print(" ");
    Serial.print(R1); Serial.print(" ");
    Serial.print(L2); Serial.print(" ");
    Serial.print(R2); Serial.print('\t');

    Serial.print(L3); Serial.print(R3);
    Serial.print(Share); Serial.print(Options);
    Serial.print(Touchpad);

    Serial.println();
}
