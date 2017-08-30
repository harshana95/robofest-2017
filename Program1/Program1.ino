#include <Arduino.h>
#include <EEPROM.h>
#include <SoftwareSerial.h>
#include "define.h"
#include "StepperDriver.h"

SoftwareSerial mySerial(3, 2); // RX, TX
volatile int mode = BEGIN ;

#define MOTOR_STEPS 200
#define MICROSTEPS 16

StepperDriver stepper(MOTOR_STEPS);    //(MOTOR_STEPS, DIR, STEP, ENBL);

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);

  //motorsBegin();
  stepperMotorBegin();
  //sonarBegin();
  //irSensorsBegin();
  //lineFollowBegin();
  eepromBegin();

  pinMode(BUTTON_1, INPUT_PULLUP);
  //pinMode(BUTTON_2, INPUT_PULLUP);
  pinMode(13, OUTPUT);

}

void test() {


}


