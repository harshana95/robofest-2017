void mazeRunAdvanced() {

  readWalls(wall);
  delay(1000);
  readWalls(wall);

  if (isMazeSolved == 0) {
    if (!wall[RIGHT_SENSOR]) {
      maze_turnRight();
      shiftDirVector(-1);
    }
    else if (!wall[FRONT_SENSOR]) {
      maze_goForward();
    }
    else if (!wall[LEFT_SENSOR]) {
      maze_turnLeft();
      shiftDirVector(1);
    }
    else {
      maze_turnBack();
      shiftDirVector(-2);
    }



    // go forward
    posX += dir[1][0];
    posY += dir[1][1];
    maze[posX][posY] = posCount;
    updateAddress(posX, posY);
    posCount++;



  } else {
    int rightCount, leftCount, frontCount, backCount;
    if (posX + dir[0][0] >= 0 && posX + dir[0][0] < 6 && posY + dir[0][0] >= 0 && posY + dir[0][0] < 6)
      rightCount = maze[posX + dir[0][0]][posY + dir[0][0]];
    else
      rightCount = -1;

    if (posX + dir[1][0] >= 0 && posX + dir[1][0] < 6 && posY + dir[1][0] >= 0 && posY + dir[1][0] < 6)
      frontCount = maze[posX + dir[1][0]][posY + dir[1][0]];
    else
      frontCount = -1;

    if (posX + dir[2][0] >= 0 && posX + dir[2][0] < 6 && posY + dir[2][0] >= 0 && posY + dir[2][0] < 6)
      leftCount = maze[posX + dir[2][0]][posY + dir[2][0]];
    else
      leftCount = -1;
    if (posX + dir[3][0] >= 0 && posX + dir[3][0] < 6 && posY + dir[3][0] >= 0 && posY + dir[3][0] < 6)
      backCount = maze[posX + dir[3][0]][posY + dir[3][0]];
    else
      backCount = -1;
    int countAroundMe[4] = {rightCount, frontCount , leftCount, backCount};
    int currentBestIndex = -1;
    int currentBestCount = -1;

    bool endLoop = false; // boolean to store whether the loop should break. (because in switch
    for (int i = 0; i < 4; i++) {
      //finding the index that where the count around me is MAX!
      for (int j = 0; j < 3; j++) {
        if (countAroundMe[j] > currentBestCount) {
          currentBestCount = countAroundMe[j];
          currentBestIndex = j;
        }
      }

      //checking the best move and see whether it is possible to turn to that side.
      if (currentBestIndex == 0 && !wall[RIGHT_SENSOR]) {
        // best move is to go right
        maze_turnRight();
        shiftDirVector(-1);
        break;

      } else if (currentBestIndex == 1 && !wall[FRONT_SENSOR]) {        // TODO: curreentBestIndex ???
        // best move is to go forward
        maze_goForward();
        break;
      } else if (currentBestIndex == 2 && !wall[LEFT_SENSOR]) {
        // best move is to go left
        maze_turnLeft();
        shiftDirVector(1);
        break;
      } else {
        // should be unlikely to happen. best position is in previous position. Causes an infinite loop.

      }
      countAroundMe[currentBestIndex] = -1;
      currentBestIndex = -1;
      currentBestCount = -1;
    }

    // go forward
    posX += dir[1][0];
    posY += dir[1][1];

  }

  Serial.print(posX);
  Serial.print(" ");
  Serial.print(posY);
  Serial.print(" ");
  Serial.print(posCount);
  Serial.println(" ");

  //loadEEPROM();
  printCurrentMaze();


}

void shiftDirVector(int c) {
  int tempDir[4][2];
  for (int i = 0; i < 4; i++) {
    tempDir[i][0] = dir[(i + 4 + c) % 4][0];
    tempDir[i][1] = dir[(i + 4 + c) % 4][1];
  }
  for (int i = 0; i < 4; i++) {
    dir[i][0] = tempDir[i][0];
    dir[i][1] = tempDir[i][1];
  }
}


void printCurrentMaze() {
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      if (maze[i][j] < 10)
        Serial.print(" ");
      Serial.print(maze[i][j]);
      Serial.print(" ");
    }
    Serial.print("\n");
  }

  Serial.println("----------------------------");

}
