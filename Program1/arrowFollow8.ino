//*****************************************
//06/09/2017 gihanchanaka@gmail.com
//These global variales are needed ONLY IF we are using the bottom panel as a colour sensor
int floorColorGrid[6];
int calibratedData[6][4];//calibratedData[sensor][color][0=min,1=max]
//*****************************************





void readFloorColorGrid() {
  //06/09/2017 gihanchanaka@gmail.com
  //This function updates the global variable "floorColorGrid"
  //0---No color detected
  //1-- Red
  //2-- Green
  //3-- Blue

  for (int i = 0; i < 6; i++)floorColorGrid[i] = 0;

  //searching for a white floor to make a reference!

  int referenceWhite = 0; // if no referece white present it will give 0 for all. then it will go a little forward

  for (int s = 0; s < 6; s++) {
    int thisReading = 0;
    for (int x = 0; x < 10; x++)thisReading += analogReadForLDR(s);  // TAKING READINGS
    thisReading /= 10;


    if (abs(thisReading - calibratedData[s][0]) < 5 ) { //---------------------------------------------
      referenceWhite = thisReading;
      break;
    }
  }


  for (int s = 0; s < 6; s++) {

    int thisReading = 0;
    for (int x = 0; x < 10; x++)thisReading += analogReadForLDR(s);
    thisReading /= 10;

    Serial.print(thisReading);
    Serial.print(" ");

    for (int c = 1; c < 4; c++) {
      int calibratedColorDiff = calibratedData[s][c] - calibratedData[s][0];
      int currentColorDiff = thisReading - referenceWhite;
      // Serial.print(calibratedData[s][c]);
      // Serial.println();

      if (abs(currentColorDiff - calibratedColorDiff) < 2) { // color matching is in here
        floorColorGrid[s] = c;
        break;
      }
    }
  }
  
  Serial.println();
}


void firstArrowFollow(int boxColor) {
  readFloorColorGrid();
  
    for (int i = 0; i < 6; i++) {
      Serial.print(floorColorGrid[i]);
      Serial.print(" ");
    }
    
  Serial.println();
  int ws = weightedSumColor(boxColor);
  Serial.print("ws = ");
  Serial.println(ws);
  if (ws == 0)goF();
  if (ws < 0)goL();
  if (ws > 0)goR();
  goF();
  
}

void trailAndErrorArrowFollow_LoopOneArrow(int boxColor) {
  //We dont need this
}

int weightedSumColor(int boxColor) {
  int w[6] = { -3, -2, -1, 1, 2, 3};
  int sum = 0;
  for (int i = 0; i < 6; i++){
    if (floorColorGrid[i] == boxColor)sum += w[i];
  }
  return sum;
}


int analogReadForLDR(int i) {
  //06/09/2017
  //To be implemented
  delay(1);
  return analogRead(irPins[i]);
}

