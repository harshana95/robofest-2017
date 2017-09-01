
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

      /*readWalls(wall);

        Serial.print(wall[2]);
        Serial.print(" ");
        Serial.print(wall[1]);
        Serial.print(" ");
        Serial.print(wall[0]);
        Serial.println();*/

      if (buttonStatus == 0 ) {
        beep();
        readWalls(wall);
        mode = MAZE_RUN;
        Serial.println(">> Mode : MAZE_RUN");
        delay(500);
      } else {
        readWalls(wall);
      }

      break;


    case MAZE_RUN:
      //readColor();
      buttonStatus = digitalRead(BUTTON_1);

      if (buttonStatus == 0 ) {
        mode = BEGIN;
      } else {
        mazeRunAdvanced();//mazeRunAdvanced(); //mazeRun();
      }

      break;

    case MAZE_RUN_ADVANCED:

      //readWalls(wall);
      //readColor();

      if (color != COLOR_OPEN) {
        if (isMazeSolved == 0 ) {

          // solve the maze using matrix
          isMazeSolved = 1;
        }
        mode = PICKING_BOX;
        break;
      }
      //mazeRunAdvanced();
      break;

    case MAZE_PATH:
      buttonStatus = digitalRead(BUTTON_1);

      if (buttonStatus == 0 ) {
        mode = BEGIN;
      } else {
        mazePath(); //mazeRun();
      }

      break;
  }

}
