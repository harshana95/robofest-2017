
#if defined(STEPPER_MOTORS)

void stepperMotorBegin() {

  // Setting pinModes
  pinMode(PIN_EN_LEFT, OUTPUT);
  pinMode(PIN_EN_RIGHT, OUTPUT);

  pinMode(PIN_DIR_LEFT, OUTPUT);
  pinMode(PIN_DIR_RIGHT, OUTPUT);

  pinMode(PIN_STEP, OUTPUT);

  // Initial values
  digitalWrite(PIN_DIR_LEFT, HIGH);
  digitalWrite(PIN_DIR_RIGHT, HIGH);
  digitalWrite(PIN_STEP, LOW);

  stepper.begin(200, MICROSTEPS);

  stepper.setSpeedProfile(LINEAR_SPEED, 500, 2000);    //TODO: LINEAR_SPEED | CONSTANT_SPEED   500,2000

  
  Serial.println(F(">> Steppers : Begin..."));
  stepper.disable();
}

void motorForward(int steps) {
  motorWrite(steps, 1, 1);
}

void motorBackward(int steps) {
  motorWrite(steps, -1, -1);
}

void motorWriteDist(int dist, int left, int right) {
  // Send robot exact distance. 202mm per full rotation
  motorWrite(dist * STEPS_PER_UNIT, left, right);
}


void motorRotate(double angle) {
  angle *= (1.05);
  int steps = STEPS_PER_ROUND * (angle / 360);

  if (steps > 0) {
    motorWrite(steps, 1, -1);   // CW
  } else {
    motorWrite(steps, -1, 1);   // CCW
  }
}

void motorRotatePivot(double angle) {

  int steps = STEPS_PER_ROUND * (angle / 360);

  if (steps > 0) {
    softMotorWrite(steps * 2, 1, 0); // CW
  } else {
    softMotorWrite(steps * 2, 0, 1); // CCW
  }
}

void motorWrite(int steps, int left, int right) {
  //stepper.enable();

  digitalWrite(PIN_EN_LEFT, (left == 0));   // TODO: Uncomment this if using Pivot Motions, not tested yet
  digitalWrite(PIN_EN_RIGHT, (right == 0));

  digitalWrite(PIN_DIR_LEFT, (left == 1));
  digitalWrite(PIN_DIR_RIGHT, (right == 1));

  //Serial.println(steps);

  stepper.move(steps * MICROSTEPS);
  delay(150);                         //Leave some delay until robot stop is's movement
  stepper.disable();

  //stepper.getTimeForMove(steps);

}

void softMotorWrite(int steps, int left, int right) {

  //This mode doesn't disable motor. Make sure to disable after use

  digitalWrite(PIN_EN_LEFT, (left == 0));
  digitalWrite(PIN_EN_RIGHT, (right == 0));

  digitalWrite(PIN_DIR_LEFT, (left == 1));
  digitalWrite(PIN_DIR_RIGHT, (right == 1));

  stepper.move(steps * MICROSTEPS);
  ///delay(150);                        //Leave some delay until robot stop is's movement Nuwan:05/09/2017
  stepper.disable();
  
  //stepper.getTimeForMove(steps);

}


void motorWrite(int left, int right) {

  if (left != 0 & right != 0 ) {
    int leftDir = (left > 0) ? 1 : -1;
    int rightDir = (right > 0) ? 1 : -1;
    //motorWrite(abs(left) / 10, leftDir, rightDir);
    motorWrite(abs(left) / 10, leftDir, rightDir);
  }
}

void polygon(int d, int p) {
  int a = (360 / 4);

  for (int i = 0; i < p; i++) {
    motorForward(d);
    //delay(500);
    motorRotate(a);
    //delay(500);
  }
  delay(3000);

}





/*

  enum Direction {DIR_FORWARD, DIR_REVERSE};
  enum Mode {CONSTANT_SPEED, LINEAR_SPEED};

  BasicStepperDriver(steps,dir_pin,step_pin);

  .begin(rpm,microsteps)

  .setRPM(rpm)
  .setSpeedProfile(mode, accel,decel)

  .getRPM()
  .getCurrentRPM()

  .move(steps)
  .rotate(deg)

  .enable()
  .disable()

  .getTimeForMove(steps)
  .nextAction()

*/

#endif



