void debugProcedure() {
  //Go forward 1 feet
  goF();
  delay(1000);
  goFF();
  delay(1000);

  //Take 2 clock wise 90 deg turns
  turnCW(90);
  turnCW(90);

  //Take 2 anti cock wise 90 deg turns
  turnCW(-90);
  turnCW(-90);

  //Go backward 1 feet
  goB();
  delay(1000);
  goBB();
  delay(1000);

  //print wall readings (3 times with 4 sec delays)
  for (int j = 0; j < 3; j++) {
    readWalls(wall);
    for (int i = 0; i < 3; i++) {
      Serial.print(wall[i]);
      Serial.print(" ");
    }
    Serial.println();
    delay(4000);
  }

  //Print LDR readings (3 times with 4 sec delays)
  for (int j = 0; j < 3; j++) {
    readSensorLine(reading);
    for (int i = 0; i < 6; i++) {
      Serial.print(reading[i]);
      Serial.print(" ");
    }
    Serial.print("Weighted sum= ");
    Serial.print(updatedWeightedSum());
    Serial.println();
    delay(4000);
  }

  //Print colour readings (3 times with 4 sec delays)
  for (int j = 0; j < 3; j++) {
    Serial.print("Floor = ");
    printColor(getColorReading());
    Serial.print(" Box= ");
    printColor(readBoxColor());
    Serial.println("");
    delay(4000);
  }


  void printColor(int c){
    if(c==1) Serial.print("R");
    if(c==2) Serial.print("G");
    if(c==3) Serial.print("B");
    if(c<1 or c>3) Serial.print("N");
  }




}
