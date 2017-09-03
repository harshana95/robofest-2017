
void loop() {

  switch (mode) {
    case TEST:

      buttonStatus = digitalRead(BUTTON_1);
      Serial.println("Test");

      motorWrite(100, 1, 1);
      delay(1000);

      if (buttonStatus == 0 ) {
        mode = BEGIN;
        beep();
        //delay(1000);
        Serial.println(">> Mode : Begin");

      } else {
        /*motorWrite(100, 1, 1);
          delay(1000);
          test();*/
      }

      break;

    case BEGIN:
      buttonStatus = digitalRead(BUTTON_1);
      //readSensorLine(reading);
      colorUpdate();
      delay(500);

      if (buttonStatus == 0 ) {
        beep();

        /*loadEEPROM();
          if (isMazeSolved) {
          solveMaze();
          }*/

        mode = FIND_ARROW;  //MAZE_RUN;//
        Serial.println(">> Mode : FIND");
        delay(500);

      } else {
        readWalls(wall);
        //delay(1000);
      }

      break;

    case FIND_ARROW:
      start(COLOR_GREEN);

      break;
    case MAZE_RUN:
      //readColor();
      buttonStatus = digitalRead(BUTTON_1);

      if (buttonStatus == 0 ) {   // TODO: is  color dected ?
        mode = BEGIN;
      } else {
        mazeRunAdvanced();//mazeRunAdvanced(); //mazeRun();
      }

      break;

    case MAZE_OPTION:
      buttonStatus = digitalRead(BUTTON_1);

      if (buttonStatus == 0 ) {
        mode = BEGIN;
      } else {
        mazeOption1(); //mazeRun();
      }

      break;
  }

}
