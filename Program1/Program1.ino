

#include <Arduino.h>
#include <EEPROM.h>
#include <SoftwareSerial.h>
#include "define.h"

#include <Adafruit_Sensor.h>
#include "Adafruit_TCS34725.h"

SoftwareSerial mySerial(3, 2); // RX, TX

#if defined(STEPPER_MOTORS)
#include "StepperDriver.h"
StepperDriver stepper(MOTOR_STEPS);    //(MOTOR_STEPS, DIR, STEP, ENBL);
#endif

Adafruit_TCS34725 color0 = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_154MS, TCS34725_GAIN_1X);  // Integration=50, Grain [1,4]

volatile int mode = BEGIN ;

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);


  irSensorsBegin();
  eepromBegin();
  colorBegin();

  //lineFollowBegin();
  //sonarBegin();

#if defined(GEARED_MOTORS)
  motorsBegin();
#elif defined(STEPPER_MOTORS)
  stepperMotorBegin();
#endif

  pinMode(12, INPUT);
  pinMode(11, INPUT);
  pinMode(10, INPUT);

  pinMode(BUTTON_1, INPUT_PULLUP);
  //pinMode(BUTTON_2, INPUT_PULLUP);
  pinMode(13, OUTPUT);

}

void test() {


}


