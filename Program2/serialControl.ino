//String inputString = "";        // a string to hold incoming data
//String cmd2 = "";
//boolean stringComplete = false;  // whether the string is complete


void serialEvent() {

  while (Serial.available()) {
    //digitalWrite(13, HIGH);

    int r = Serial.read();
    char inChar = (char)r;

    if (inChar == 'a') {
      int x = wall[RIGHT_SENSOR] + 2 * wall[FRONT_SENSOR] + 4 * wall[LEFT_SENSOR];
      Serial.print(x);

      indicatorChange(COLOR_BLUE, x % 2);
      indicatorChange(COLOR_GREEN, (x / 2) % 2);
      indicatorChange(COLOR_RED, (x / 4));

      // Encode details as binary >> {2}{1}{0}

    }
    else if ((inChar - '0') >= 0 && (inChar - '0') <= 7) {
      byte in = inChar - '0';
    }
    else if (inChar == 'g') {
      pickBox();
    }
    else if (inChar == 'h') {
      dropBox();
    }

    else if (inChar == 'j') {
      Serial.println((char)('0' + colorR0));
    }
    else if (inChar == 'k') {
      buzzer(1);
    }
    else if (inChar == '\n') {} // Nothing to do
    else if (inChar == '\r') {} // Nothing to do
    else {
      //This is to to say there is something wrong

      //Serial.write((int)inChar);
      //Serial.println();
      indicatorBlink(PIN_BLUE, 3);

    }

    //Serial.println(inChar);
    //digitalWrite(13, LOW);
  }

}




