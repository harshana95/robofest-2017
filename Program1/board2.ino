


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


