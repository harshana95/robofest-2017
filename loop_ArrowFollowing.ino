static int reading[6];




void trailAndErrorArrowFollow_Loop() {
  while(true){
    trailAndErrorArrowFollow_LoopOneArrow();
  }
}

void trailAndErrorArrowFollow_LoopOneArrow() {
  Serial.begin(9600);
  Serial.println("Starting");
  /*
    31/08/2017
    We have to test this function by keeping the robot POINTED AT AN ARROW
    You should not keep the robot on an arrow
  */
  //BLOCK 1 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  readSensorLine(reading);
  while (sumOfArray(reading, 6) == 0) {
    motorWrite(200, 200);
    delay(100);
    motorWrite(0, 0);
    delay(100);
    readSensorLine(reading);
  }



  readSensorLine(reading);
  while (sumOfArray(reading, 6) != 0) {
    trailAndErrorArrowFollow_Forward();
    readSensorLine(reading);
  }

  //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

  //BLOCK 2>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  motorWrite(-200, -200);
  delay(100);
  motorWrite(0, 0);
  delay(100);
  readSensorLine(reading);
  while (sumOfArray(reading, 6) != 0) {
    
    motorWrite(-200, -200);
    delay(100);
    motorWrite(0, 0);
    delay(100);
    readSensorLine(reading);
  }


  //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>.

  //BLOCK 1 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  readSensorLine(reading);
  while (sumOfArray(reading, 6) == 0) {
    motorWrite(200, 200);
    delay(100);
    motorWrite(0, 0);
    delay(100);
    readSensorLine(reading);
  }



  readSensorLine(reading);
  while (sumOfArray(reading, 6) != 0) {
    trailAndErrorArrowFollow_Forward();
    readSensorLine(reading);
  }

  //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
}

int sumOfArray(int ar[], int n) {
  int sum = 0;
  for (int i = 0; i < n; i++)sum += ar[i];
  return sum;
}


void trailAndErrorArrowFollow_Forward() {
  /*
    (LEFT) R[0] R[1] R[2] R[3] R[4] R[5]  (Right)
    Weights:  3   2   1   -1   -2    -3
              R[7]
              R[8]
  */

  Serial.print("Forward loop| weight= ");
  int weight[6] = { -3, -2, -1, 1, 2, 3};

  readSensorLine(reading);
  int weightedSum = 0;
  for (int j = 0; j < 6; j++) {
    weightedSum += reading[j] * weight[j];
  }

  Serial.println(weightedSum);

  //LOGIC -- 1 -- Basic
  if (weightedSum != 0) {
    if (weightedSum < 0) {
      Serial.println("Forward loop- Turn right");
      motorWrite(100, -100);
      delay(50);
      motorWrite(0, 0);
      delay(100);
    }
    else {
      Serial.println("Forward loop- Turn left");
      motorWrite(-100, 100);
      delay(100);
      motorWrite(0, 0);
      delay(100);
    }
  }


  motorWrite(100, 100);
  delay(100);
  motorWrite(0, 0);
  delay(100);
}


void trailAndErrorArrowFollow_Backward() {
  /*
    (LEFT) R[0] R[1] R[2] R[3] R[4] R[5]  (Right)
    Weights:  3   2   1   -1   -2    -3
              R[7]
              R[8]
  */

  Serial.print("Backward loop| weight= ");
  int weight[6] = { -3, -2, -1, 1, 2, 3};

  readSensorLine(reading);
  int weightedSum = 0;
  for (int j = 0; j < 6; j++) {
    weightedSum += reading[j] * weight[j];
  }

  Serial.println(weightedSum);

  //LOGIC -- 1 -- Basic
  if (weightedSum != 0) {
    if (weightedSum > 0) {
      Serial.println("Backward loop- Turn right");
      motorWrite(100, -100);
      delay(50);
      motorWrite(0, 0);
      delay(100);
    }
    else {
      Serial.println("Backward loop- Turn left");
      motorWrite(-100, 100);
      delay(100);
      motorWrite(0, 0);
      delay(100);
    }
  }


  motorWrite(-100, -100);
  delay(100);
  motorWrite(0, 0);
  delay(100);
}




void loop() {

  switch (mode) {
    case TEST:

      buttonStatus = digitalRead(BUTTON_1);
      //Serial.println(buttonStatus);

      if (buttonStatus == 0 ) {
        mode = BEGIN;
        delay(500);
        Serial.println(">> Mode : MazeRun");
        //mode = MAZE_RUN; //MAZE_RUN_ADVANCED;
      } else {
        trailAndErrorArrowFollow_Loop();
      }

      break;

    case BEGIN:
      buttonStatus = digitalRead(BUTTON_2);

      if (buttonStatus == 0 ) {

        /*pos = CENTER_EDGE_READING;
          error = 0;
          lastError = 0;*/

        mode = TEST;
        Serial.println(">> Mode : BLUETOOTH");
        delay(500);
        //mode = MAZE_RUN; //MAZE_RUN_ADVANCED;
      }

      break;


    case MAZE_RUN:
      readWalls();
      readColor();

      if (color != COLOR_OPEN) {
        mode = PICKING_BOX;
      } else {
        mazeRun();
      }

      break;


    case MAZE_RUN_ADVANCED:
      readWalls();
      readColor();

      if (color != COLOR_OPEN) {
        if (isMazeSolved == 0 ) {

          // solve the maze using matrix



          isMazeSolved = 1;
        }
        mode = PICKING_BOX;
        break;
      }
      mazeRunAdvanced();
      break;
  }

}
