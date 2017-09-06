
/*

  a -> Read walls

  q -> Ready to pick
  w -> stand
  e -> pickBox
  r -> dropBox
  j -> readColor
  k -> beep
  d -> Change indicator (boolean 000 - 111 )
*/



void serialEvent() {

  while (Serial.available()) {
    //digitalWrite(13, HIGH);

    int r = Serial.read();
    char inChar = (char)r;

    // --------------------------------------------------------------------------------------- Read Walls - Not required now
    if (inChar == 'a') {
      //while (!readWalls(wall)) {
      int x = wall[0] + 2 * wall[1] + 4 * wall[2];
      Serial.print(x);

      indicatorChange(COLOR_BLUE, x % 2);
      indicatorChange(COLOR_GREEN, (x / 2) % 2);
      indicatorChange(COLOR_RED, (x / 4));

    }

    // --------------------------------------------------------------------------------------- Servo Commands
    else if (inChar == 'q' ) {
      readyToPick();
    }
    else if (inChar == 'w') {
      stand();
    }
    else if (inChar == 'e') {
      pickBox();
    }
    else if (inChar == 'r') {
      dropBox();
    }

    // --------------------------------------------------------------------------------------- LED indicators   [ ] |

    else if (inChar == '[') {
      digitalWrite(PIN_RED, HIGH);
      digitalWrite(PIN_GREEN, LOW);
      digitalWrite(PIN_BLUE, LOW);

    }
    else if (inChar == '|') {
      digitalWrite(PIN_RED, LOW);
      digitalWrite(PIN_GREEN, HIGH);
      digitalWrite(PIN_BLUE, LOW);

    }
    else if (inChar == ']') {
      digitalWrite(PIN_RED, LOW);
      digitalWrite(PIN_GREEN, LOW);
      digitalWrite(PIN_BLUE, HIGH);
    }
    
    // --------------------------------------------------------------------------------------- Read box color
    else if (inChar == 'j') {
      char val = '0' + colorR0;
      Serial.print(val);
    }

    // --------------------------------------------------------------------------------------- Buzzer
    else if (inChar == 'k') {
      buzzer(1);
    }

    // --------------------------------------------------------------------------------------- Indicator change

    else if (inChar == 'd') {
      if (Serial.available() == 1) {
        // instruction bit
        int x = (Serial.read() - '0');
        Serial.print(">> LED Update : ");
        Serial.println(x, BIN);
        indicatorChange(COLOR_BLUE, x % 2);
        indicatorChange(COLOR_GREEN, (x / 2) % 2);
        indicatorChange(COLOR_RED, (x / 4));
      }
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




