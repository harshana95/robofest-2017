/*
  This code runs after lifting the box
*/

//int RED = 1, GREEN = 2, BLUE = 3;

#include <math.h>    // (no semicolon)

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
  readColor();

  return color;

}

void start(int boxColor) {
  //This uses the colour reading as 1-RED,2-GREEN.3=BLUE

  int directions = 5;
  int gap = 15; //degrees
  int steps = 5;
  int stepSize = 40; //mm

  Serial.println("Starting the arrow finding algo");
  Serial.print(directions);
  Serial.print(" directions will be checked with ");
  Serial.print(gap);
  Serial.print(" deg betweeen two directions.");
  Serial.println("");
  Serial.print(steps);
  Serial.print(" steps of length ");
  Serial.print(stepSize);
  Serial.print("cm ");

  int reading[directions][steps];

  turnCW(-1 * gap * (directions - 1) / 2);

  for (int d = 0; d < directions; d++) {
    for (int s = 0; s < steps; s++) {
      reading[d][s] = 0;
      if (getColorReading() == boxColor) {
        reading[d][s]++;
      }
      if (s != steps - 1) {
        goFoward(stepSize);
      }
    }

    for (int s = 0; s < steps; s++) {
      if (getColorReading() == boxColor) {
        reading[d][s]++;
      }
      if (s != steps - 1) {
        goFoward(-stepSize);
      }
    }

    turnCW(gap);
  }

  Serial.println("The matrix of readings:");
  Serial.println("Row= step, Col=Direction");
  for (int s = 0; s < steps; s++) {
    for (int d = 0; d < directions; d++) {
      Serial.print(reading[d][s]);
      Serial.print(" ");
    }
    Serial.println("");
  }


  turnCW(-1 * gap * (directions - 1) / 2);
  //NOW WE ARE AT THE CENTER AGAIN!

  int arcSum[steps];

  for (int s = 0; s < steps; s++) {
    arcSum[s] = 0;
    for (int d = 0; d < directions; d++) {
      arcSum[s] += reading[s][d];
    }
  }


  //Trying to find the starting point of the arrow
  //We use polar coordinates asuming our current position to be the origin
  int startR = 0;
  float startTheta = 0.0;

  for (int s = 0; s < steps; s++) {
    if (arcSum[s] != 0) {
      startR = s;
      break;
    }
  }

  for (int d = 0; d < directions; d++) {
    startTheta += (reading[startR][d] * d);
  }
  startTheta /= arcSum[startR];

  startTheta -= (directions/2);
  startTheta *= gap;

  Serial.println("The starting point of the arrow is: ");
  Serial.print("R= ");
  Serial.print(startR);
  Serial.print(" Theta = ");
  Serial.print(startTheta);
  Serial.println("");

  //Going to the starting point of the arrow
  turnCW(startTheta);
  goFoward(startR);


  //Trying to find the angle
  int totalReadingSum = 0;
  for (int s = 0; s < steps; s++) {
    totalReadingSum += arcSum[s];
  }


  float angleToTurn = 0;
  for (int d = 0; d < directions; d++) {
    for (int s = 0; s < steps; s++) {
      if (reading[d][s] != 0) {
        float theta = gap * (d - (directions / 2));
        float deltaY = startR * sin(startTheta) - s * sin(theta);
        float deltaX = s * cos(theta) - startR * cos(startTheta);
        float angle = atan(deltaY / deltaX) * (180.0 / 3.14);

        angleToTurn += angle * reading[d][s];
      }
    }
  }

  angleToTurn /= totalReadingSum;

  //Turning the angle and moving forward
  turnCW(angleToTurn);
  goFoward(100);



}

