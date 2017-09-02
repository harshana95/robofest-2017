

void pick() {
  mySerial.print("g");
}

void drop() {
  mySerial.print("h");
}

void beep() {
  mySerial.print("k");

}
boolean readColor() {

  while (mySerial.available())mySerial.read();
  mySerial.println("j");
  mySerial.flush();
  delay(100);
  color = mySerial.read() - '0';     // 0-No 1-Red 2-Green 3-Blue
  
  while (mySerial.available()) {
    mySerial.read();
    //Serial.println(mySerial.read() - '0');
  }

  if (color >= 0 && color <= 3) {
    //correct
    Serial.println(color);
  } else {
    color = -1;
    //Serial.println(color);
    //Serial.println("Error: Color reading");
  }
  return 1;
}
void readWalls(int *wall) {
  wall[RIGHT_SENSOR] = 0;
  wall[FRONT_SENSOR] = 0;
  wall[LEFT_SENSOR] = 0;

  //for (int i = 0; i < 5; i++) {
  wall[RIGHT_SENSOR] += digitalRead(12);
  wall[FRONT_SENSOR] += digitalRead(11);
  wall[LEFT_SENSOR] += digitalRead(10);
}
/*
int readWalls(int *wall) {
  //Serial.println("Reading what's in the mySerial to clear");
  while (mySerial.available())mySerial.read();

  //Serial.println("Sending signal 'a' to mySerial");
  mySerial.println('a');
  mySerial.flush();
  //Serial.println("Signal sent");
  
  delay(100);
  //Serial.println("Reading from mySerial");
  byte val = mySerial.read() - '0';
  Serial.print("Value read = ");
  Serial.println(val);
  
  while (mySerial.available())mySerial.read();
  if (val >= 0 && val <= 7) {
    wall[RIGHT_SENSOR] = val % 2;
    wall[FRONT_SENSOR] = (val / 2) % 2;
    wall[LEFT_SENSOR] = val / 4;
    //mySerial.print(wall[RIGHT_SENSOR] + 2 * wall[FRONT_SENSOR] + 4 * wall[LEFT_SENSOR]);
    //Serial.print('*'); Serial.println(wall[0] + 2 * wall[1] + 4 * wall[2]);

    return 1;
  } else {
    return 0;
  }

}*/


