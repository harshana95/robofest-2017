#include <Servo.h>
#include <Wire.h>

#include <Adafruit_Sensor.h>
//#include <Adafruit_HMC5883_U.h>
#include "Adafruit_TCS34725.h"
#include "define.h"

Adafruit_TCS34725 color0 = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);  // Integration, Grain [1,4]
//Adafruit_HMC5883_Unified compass = Adafruit_HMC5883_Unified(12345);

void setup() {

  Serial.begin(9600);
  Serial.println(">> Begin : Prog2");


  //compassBegin();
  sharpIRBegin();
  //sonarBegin();
  colorBegin();
  indicatorBegin();

}

void loop() {

  colorUpdate();
  readWalls(wall);
  //readCompass();
  //Serial.println(colorR0);

  delay(100);

}
void colorUpdate() {
  readColor();
  //Serial.println(colorR0);

  if (1) {
    Serial.print(blue0);
    Serial.print(" ");
    Serial.print(red0);
    Serial.print(" ");
    Serial.print(green0);
    Serial.print(" ");
    Serial.print(clr0);
    Serial.print(" ");
    Serial.print(color0.calculateColorTemperature(red0, green0, blue0) );
    Serial.print(" ");

    Serial.print(colorR0);
    Serial.println(" ");
  }
}
