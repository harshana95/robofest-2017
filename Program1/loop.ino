<<<<<<< HEAD

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
<<<<<<< HEAD
        //readWalls(wall);
        //readColor();

        if (isMazeSolved) {
          loadEEPROM();
          
          solveMaze();
        }

        mode = MAZE_RUN;//FIND_ARROW;
        Serial.println(">> Mode : RUN");
        //delay(500);
=======

        loadEEPROM();
        if (isMazeSolved) {
          solveMaze();
        }


        mode = MAZE_RUN;
        Serial.println(">> Mode : FIND");
        delay(500);
>>>>>>> 28fafaf4425a61a7e09b8bd497ffe9504ff51ad0
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

=======

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
<<<<<<< HEAD
        //readWalls(wall);
        //readColor();

        if (isMazeSolved) {
          loadEEPROM();
          
          solveMaze();
        }

        mode = MAZE_RUN;//FIND_ARROW;
        Serial.println(">> Mode : RUN");
        //delay(500);
=======

        loadEEPROM();
        if (isMazeSolved) {
          solveMaze();
        }


        mode = MAZE_RUN;
        Serial.println(">> Mode : FIND");
        delay(500);
>>>>>>> 28fafaf4425a61a7e09b8bd497ffe9504ff51ad0
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

>>>>>>> 48663b89ce8a194943336feee277eba6b07dc008
}
