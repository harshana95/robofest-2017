

#include <Arduino.h>
#include <EEPROM.h>
#include <SoftwareSerial.h>

#include "define.h"
#include "StepperDriver.h"

SoftwareSerial mySerial(3, 2); // RX, TX
volatile int mode = BEGIN ;

#if defined(STEPPER_MOTORS)
StepperDriver stepper(MOTOR_STEPS);    //(MOTOR_STEPS, DIR, STEP, ENBL);
#endif

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);


  irSensorsBegin();
  eepromBegin();

  //lineFollowBegin();
  //sonarBegin();

#if defined(GEARED_MOTORS)
  motorsBegin();
#elif defined(STEPPER_MOTORS)
  stepperMotorBegin();
#endif


  pinMode(BUTTON_1, INPUT_PULLUP);
  //pinMode(BUTTON_2, INPUT_PULLUP);
  pinMode(13, OUTPUT);

}

void test() {


}


