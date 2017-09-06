void calibrateColorLDR() {
  calibrateFor(0);
  calibrateFor(1);
  calibrateFor(2);
  calibrateFor(3);
}


void calibrateFor(int clr) {
  int arr[] = {0, 0, 0, 0, 0, 0};
  int noOfReadings = 100;

  beep(2);
  delay(3000);
  beep(1);

  // first reading to find the average
  for (int i = 0; i < noOfReadings; i++) {
    readSensorLine(reading);
    for (int j = 0; j < 6; j++) {
      arr[j] += reading[j];
    }
  }
  for (int j = 0; j < 6; j++) {
    arr[j] /= noOfReadings;
  }
  
  int maxArr[] = {0, 0, 0, 0, 0, 0};
  int minArr[] = {0, 0, 0, 0, 0, 0};
  int maxCount = 0, minCount = 0;
  
  // finding the max min sum
  for (int i = 0; i < noOfReadings; i++) {
    readSensorLine(reading);
    for (int j = 0; j < 6; j++) {
      if (arr[j] < reading[j]) {
        maxArr[j] += reading[j];
        maxCount++;
      } else {
        minArr[j] += reading[j];
        minCount++;
      }
    }
  }

  // finding max min avg
  for (int j = 0; j < 6; j++) {
    maxArr[j] /= maxCount;
    minArr[j] /= minCount;
  }

  // finding avg larger than max avg
  // finding avg smaller than min avg
  int maxArr2[] = {0,0,0,0,0,0};
  int minArr2[] = {0,0,0,0,0,0};
  int maxCount2=0,minCount2=0;
  for (int i = 0; i < noOfReadings; i++) {
    readSensorLine(reading);
    for (int j = 0; j < 6; j++) {
      if (maxArr[j] < reading[j]) {
        maxArr2[j] += reading[j];
        maxCount2++;
      }
      if (minArr[j] > reading[j]) {
        minArr2[j] += reading[j];
        minCount2++;
      }
    }
  }
  for (int j = 0; j < 6; j++) {
    maxArr2[j] /= maxCount2;
    minArr2[j] /= minCount2;
  }
  
  for (int j = 0; j < 6; j++) {
    calibratedData[j][clr][1] = maxArr2[j];
    calibratedData[j][clr][0] = minArr2[j];
  }
  beep(3);
}

