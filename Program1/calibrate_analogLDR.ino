void calibrateColorLDR() {
  calibrateFor(0);
  calibrateFor(1);
  calibrateFor(2);
  calibrateFor(3);
}


void calibrateFor(int clr) {
  Serial.print("Calibrating color : ");
  Serial.print(clr + 1);
  Serial.println();
  long arr[] = {0, 0, 0, 0, 0, 0};
  int noOfReadings = 100;

  beep(2);
  delay(5000);
  beep(1);

  // first reading to find the average
  for (int i = 0; i < noOfReadings; i++) {

    for (int j = 0; j < 6; j++) {
      arr[j] += analogReadForLDR(j);
    }
  }
  for (int j = 0; j < 6; j++) {
    arr[j] /= noOfReadings;
  }

  /*int maxArr[] = {0, 0, 0, 0, 0, 0};
  int minArr[] = {0, 0, 0, 0, 0, 0};
  int maxCount[] = {0, 0, 0, 0, 0, 0};
  int minCount[] = {0, 0, 0, 0, 0, 0};

  // finding the max min sum
  for (int i = 0; i < noOfReadings; i++) {

    for (int j = 0; j < 6; j++) {
      if (arr[j] < analogReadForLDR(j)) {
        maxArr[j] += analogReadForLDR(j);
        maxCount[j] += 1;
      } else {
        minArr[j] += analogReadForLDR(j);
        minCount[j] += 1;
      }
    }
  }

  // finding max min avg
  for (int j = 0; j < 6; j++) {
    if (maxCount[j] != 0)
      maxArr[j] /= maxCount[j];
    if (minCount[j] != 0)
      minArr[j] /= minCount[j];
  }
  
  // finding avg larger than max avg
  // finding avg smaller than min avg
  int maxArr2[] = {0, 0, 0, 0, 0, 0};
  int minArr2[] = {0, 0, 0, 0, 0, 0};
  int maxCount2[] = {0, 0, 0, 0, 0, 0};
  int minCount2[] = {0, 0, 0, 0, 0, 0};
  for (int i = 0; i < noOfReadings; i++) {

    for (int j = 0; j < 6; j++) {
      if (maxArr[j] < analogReadForLDR(j)) {
        maxArr2[j] += analogReadForLDR(j);
        maxCount2[j] += 1;
      }
      if (minArr[j] > analogReadForLDR(j)) {
        minArr2[j] += analogReadForLDR(j);
        minCount2[j] += 1;
      }
    }
  }
  for (int j = 0; j < 6; j++) {
    if (maxCount2[j] != 0)
      maxArr2[j] /= maxCount2[j];
    if (minCount2[j] != 0)
      minArr2[j] /= minCount2[j];
  }*/

  for (int j = 0; j < 6; j++) {
    calibratedData[j][clr] = arr[j];

  }
  Serial.println("avg");
  for (int j = 0; j < 6; j++) {
    Serial.print(calibratedData[j][clr]);
    Serial.print(" ");
  }
  Serial.println("");
  beep(3);
}

