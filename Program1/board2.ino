

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
    Serial.println(mySerial.read()- '0');
  }

  if (color >= 0 && color <= 3) {
    //correct
    Serial.println(color);
  } else {
    color = -1;
    Serial.println(color);
    Serial.println("Error: Color reading");
  }
  return 1;
}

int readWalls(int *wall) {

  while (mySerial.available())mySerial.read();
  mySerial.println('a');
  mySerial.flush();
  delay(100);
  byte val = mySerial.read() - '0';
  //Serial.println(val);
  while (mySerial.available())mySerial.read();
  if (val >= 0 && val <= 7) {
    wall[0] = val % 2;
    wall[1] = (val / 2) % 2;
    wall[2] = val / 4;
    //mySerial.print(wall[0] + 2 * wall[1] + 4 * wall[2]);
    //Serial.print('*'); Serial.println(wall[0] + 2 * wall[1] + 4 * wall[2]);
    
    return 1;
  } else {
    return 0;
  }

}


