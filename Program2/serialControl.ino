//String inputString = "";        // a string to hold incoming data
//String cmd2 = "";
//boolean stringComplete = false;  // whether the string is complete


void serialEvent() {

  while (Serial.available()) {
    //digitalWrite(13, HIGH);

    int r = Serial.read();
    char inChar = (char)r;

    if (inChar == 'a') {
      //while (!readWalls(wall)) {
      int x = wall[0] + 2 * wall[1] + 4 * wall[2];
      Serial.print(x);

      indicatorChange(COLOR_BLUE, x % 2);
      indicatorChange(COLOR_GREEN, (x / 2) % 2);
      indicatorChange(COLOR_RED, (x / 4));

    }
    else if (inChar == 'g') {
      pickBox();
    }
    else if (inChar == 'h') {
      dropBox();
    }

    else if (inChar == 'j') {
      char val = '0' + colorR0;
      Serial.print(val);
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




