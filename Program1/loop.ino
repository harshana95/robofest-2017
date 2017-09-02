
void loop() {

  switch (mode) {
    case TEST:

      buttonStatus = digitalRead(BUTTON_1);
      //Serial.println(buttonStatus);

      if (buttonStatus == 0 ) {
        mode = BEGIN;
        beep();
        delay(1000);
        Serial.println(">> Mode : Begin");

      } else {
        test();
      }

      break;

    case BEGIN:
      buttonStatus = digitalRead(BUTTON_1);

      if (buttonStatus == 0 ) {
        beep();
        //readWalls(wall);
        //readColor();
        mode = MAZE_RUN;//FIND_ARROW;
        Serial.println(">> Mode : FIND");
        delay(500);
      } else {
        readWalls(wall);
        delay(1000);
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
        // TODO: solveMaze
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
