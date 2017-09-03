int giveTheIndexOf(int *arr, int value, int n) {
  for (int i = 0; i < n; i++) {
    if (arr[i] >= value) {
      return i;
    }
  }
  Serial.println("OPTION NOT IN THE ARRAY");
}



int stepsToRotate(float angle, int spd) {
  int steps = 0;
  int spdIndex = 0;
  spdIndex = giveTheIndexOf(speedOptions, spd, noOfSpeedOptions);

  int dir;
  if (angle < 0) {
    dir = -1; angle = -1 * angle;
  } else {
    dir = 1;
  }

  int angleIndex;
  for (int i = 0; i < noOfRotateOptions; i++) {
    if (angleRotated[spdIndex][i] >= angle) {
      angleIndex = i;
      break;
    }
  }

  // LINEAR INTERPOLATION
  // y = Y_n-1 + (x - X_n-1)*tanz     tanz = (Y_n - Y_n-1)/(X_n - X_n-1)
  float tanz = (stepsGiven_Rotate[angleIndex] - stepsGiven_Rotate[angleIndex - 1]) / (angleRotated[spdIndex][angleIndex] - angleRotated[spdIndex][angleIndex - 1]);

  steps = stepsGiven_Rotate[angleIndex - 1] + (angle - angleRotated[spdIndex][angleIndex - 1]) * tanz;
  return dir*steps;
}





int stepsToForward(float distance, int spd) {
    int steps = 0;
  int spdIndex = 0;
  spdIndex = giveTheIndexOf(speedOptions, spd, noOfSpeedOptions);

  int distanceIndex;
  for (int i = 0; i < noOfDistanceOptions; i++) {
    if (distanceWentFoarward[spdIndex][i] >= distance) {
      distanceIndex = i;
      break;
    }
  }

  // LINEAR INTERPOLATION
  // y = Y_n-1 + (x - X_n-1)*tanz     tanz = (Y_n - Y_n-1)/(X_n - X_n-1)
  float tanz = (stepsGiven_Distance[distanceIndex] - stepsGiven_Distance[distanceIndex - 1]) / (distanceWentFoarward[spdIndex][distanceIndex] - distanceWentFoarward[spdIndex][distanceIndex - 1]);

  steps = stepsGiven_Distance[distanceIndex - 1] + (distance - distanceWentFoarward[spdIndex][distanceIndex - 1]) * tanz;
  return steps;
}
