/*
  This code runs after lifting the box
*/

//int RED = 1, GREEN = 2, BLUE = 3;

void turnCW(int degrees) {
  //I am assuming that this function can turn the robot clockwise to 10 degrees
  motorRotate(degrees);
}

void goFoward(int mm) {
  if (mm > 0) {
    motorWrite(mm, 1 , 1);
  } else {
    motorWrite(mm, -1 , -1);
  }
}

int getColorReading() {
  //This function can get the colour reading as 1-RED,2-GREEn.3=BLUE
  // TODO
}

void start(int boxColor) {
  //This uses the colour reading as 1-RED,2-GREEN.3=BLUE
  int hits[9];
  int center = 4;
  turnCW(-40);

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 10; j++) {
      goFoward(15);
      if (boxColor == getColorReading())hits[i]++;
    }
    for (int j = 0; j < 10; j++) {
      goFoward(-15);
      if (boxColor == getColorReading())hits[i]++;
    }
    turnCW(10);
  }

  int maxIndex = 0;
  int maxHits = 0;
  for (int i = 0; i < 9; i++) {
    if (hits[i] > maxHits) {
      maxHits = hits[i];
      maxIndex = i;
    }
  }

  turnCW(-10 * (8 - maxIndex));
  goFoward(10);
}
