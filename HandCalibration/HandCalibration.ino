#include <Servo.h>
#define pickBox_pick 150
#define pickBox_grab 20

Servo grab;
Servo pick;

int count=0;

void setup() {
  
}

void loop() {
  if(count<10){
    pickBox();
    delay(2000);
    dropBox();
    delay(1000);

    count++;
  }
}


void pickBox() {
  attachServos();
  pick.write(pickBox_pick);
  delay(1000);
  //s = 1;
  grab.write(pickBox_grab);//20
  delay(500);
  detachServos();
  //Serial.println(">> Pick : Complete");
}

void dropBox() {
  attachServos();
  grab.write(120);
  delay(500);
  pick.write(10);
  delay(500);
  detachServos();
}

void stand() {
  attachServos();
  grab.write(30);
  delay(500);
  pick.write(150);
  delay(1000);
  detachServos();
}

void attachServos() {
  pick.attach(8);
  grab.attach(9);
}

void detachServos() {
  pick.detach();
  grab.detach();
}






