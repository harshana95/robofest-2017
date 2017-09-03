
void loop() {

  switch (mode) {

    //-------------------------------------------------------------------------------------------------------------- Begin
    case BEGIN:
      buttonStatus = digitalRead(BUTTON_1);

      if (buttonStatus == 0 ) {
        beep();
        mode = TEST;//FIND_ARROW;
        Serial.println(F(">> BEGIN -> ###"));
        delay(500);

      } else {
        //readWalls(wall);
        //delay(1000);
        delay(100);
      }

      break;


    //-------------------------------------------------------------------------------------------------------------- Test
    case TEST:
      buttonStatus = digitalRead(BUTTON_1);

      if (buttonStatus == 0 ) {
        mode = BEGIN;
        beep(2);
        Serial.println(F(">> TEST -> BEGIN"));
      } else {
        test();
      }

      break;


    //-------------------------------------------------------------------------------------------------------------- Maze run
    case MAZE_RUN:

      //readColor();
      buttonStatus = digitalRead(BUTTON_1);

      if (buttonStatus == 0 ) {   // TODO: is  color dected ?
        mode = BEGIN;
        Serial.println(F(">> MAZE RUN -> ###"));
      } else {
        mazeRunAdvanced();
      }

      break;


    //-------------------------------------------------------------------------------------------------------------- Pick the box
    case PICKING_BOX:

      pick();
      delay(1000);
      mode = FIND_ARROW;
      Serial.println(F(">> PICKING_BOX -> FIND_ARROW"));
      break;


    //-------------------------------------------------------------------------------------------------------------- Find Arrow
    case FIND_ARROW:
      start(COLOR_BLUE);
      break;


    //-------------------------------------------------------------------------------------------------------------- Maze Option 1 : Run on pre defined maze
    case MAZE_OPTION:
      buttonStatus = digitalRead(BUTTON_1);

      if (buttonStatus == 0 ) {
        mode = BEGIN;
      } else {
        mazeOption1();
      }

      break;
  }

}
