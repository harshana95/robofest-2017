
//TODO: Need well defined communication protocol

void serialEvent() {

  while (Serial.available()) {

    digitalWrite(13, HIGH);

    int r = Serial.read();
    char inChar = (char)r;

    if (inChar == 'b') {
      byte val = 0;
      debug = ! debug;
      EEPROM.update(debug, debug);
      Serial.print("Print\t:"); Serial.println(debug);
    }

    else if (inChar == 'p') {
      loadEEPROM();
      printCurrentMaze();

    }
    else if (inChar == 'c') {
      cleanEEPROM();
      Serial.println(">> Maze cleared");
    }
    else if (inChar == 's') {
      Serial.print("Kp\t:"); Serial.println(kP * 10);
      Serial.print("Ki\t:"); Serial.println(kI * 10);
      Serial.print("Kd\t:"); Serial.println(kD * 10);
      Serial.print("Base\t:" ); Serial.println(baseSpeed);
      Serial.print("Max\t:"); Serial.println(maxSpeed);
      Serial.print("Debug\t:"); Serial.println(debug);
    }

    else if (inChar == 't') {
      readWalls(wall);

      Serial.print(wall[2]);
      Serial.print(wall[1]);
      Serial.print(wall[0]);
      Serial.println();
    }

    else if (mode == BLUETOOTH) {
#if defined(STEPPER_MOTORS)
      if  (inChar == '8')motorWrite(100, 1, 1);
      else if (inChar == '2')motorWrite(100, -1, -1);
      else if (inChar == '4')motorWrite(100, 1, -1);
      else if (inChar == '6')motorWrite(100, -1, 1);

#elif defined(GEARED_MOTORS)
      if  (inChar == '8')motorWrite(baseSpeed, baseSpeed);
      else if (inChar == '2')motorWrite(-1 * baseSpeed, -1 * baseSpeed);
      else if (inChar == '4')motorWrite(baseSpeed, -1 * baseSpeed);
      else if (inChar == '6')motorWrite(-1 * baseSpeed, baseSpeed);
#endif
    }
    digitalWrite(13, LOW);
  }
}


