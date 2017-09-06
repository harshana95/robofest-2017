void solveMaze() {

  derriveWalls();

  int distance[36];
  BFS(distance);
  int exittime[36];
  DFS(exittime);

  Serial.println(F("Current maze"));
  printCurrentMaze();

  Serial.println(F("Walls in each cell"));
  printCurrentMazeWalls();

  Serial.println(F("Exit time from each cell using DFS"));
  printArr(exittime, 36);
  removeConflicts(distance, exittime);

  Serial.println(F("Distance from start cell using BFS (conflicts removed)"));
  printArr(distance, 36);

  findPath(distance);

  Serial.println(F("Command Queue"));
  printArr(solvedCommandQueue, 36);

}

void derriveWalls() {

}

void findPath(int* distance) {
  int currentFacingDir = 1; // facing north
  int pos = startXPosition * 6 + startYPosition;

  int eastDist, westDist, northDist, southDist;
  int distArr[4];
  int nextIndex;
  int solvedCommandQueueIndex = 0;

  int distCount = 0; // this will count the distance from BFS and follow while incrementing
  while (1) {
    Serial.println(pos);
    if (pos / 6 == finalXPosition and pos % 6 == finalYPosition) {
      if (boxXPosition == -1) { // box at north
        solvedCommandQueue[solvedCommandQueueIndex] = (-currentFacingDir + 4 + 1) % 4;
      } else if (boxXPosition == 6) { // box at south
        solvedCommandQueue[solvedCommandQueueIndex] = (-currentFacingDir + 4 + 3) % 4;
      }
      if (boxYPosition == -1) { // box at west
        solvedCommandQueue[solvedCommandQueueIndex] = (-currentFacingDir + 4 + 0) % 4;
      } else if (boxYPosition == 6) { // box at east
        solvedCommandQueue[solvedCommandQueueIndex] = (-currentFacingDir + 4 + 2) % 4;
      }
      solvedCommandQueueIndex++;
      solvedCommandQueue[solvedCommandQueueIndex] = 4;
      break;
    }
    distance[pos] = 255; // since current pos will never visit again
    if (pos - 1 > -1)
      westDist = distance[pos - 1];
    else
      westDist = 255;
    if (pos - 6 > -1)
      northDist = distance[pos - 6];
    else
      northDist = 255;
    if (pos + 1 < 36)
      eastDist = distance[pos + 1];
    else
      eastDist = 255;
    if (pos + 6 < 36)
      southDist = distance[pos + 6];
    else
      southDist = 255;

    distArr[0] = westDist; distArr[1] = northDist; distArr[2] = eastDist; distArr[3] = southDist;

    nextIndex = -1;
    for (int i = 0; i < 4; i++) {
      if (distArr[i] == distCount + 1) {
        nextIndex = i;
        break;
      }
    }

    distCount++;

    solvedCommandQueue[solvedCommandQueueIndex] = (-currentFacingDir + 4 + nextIndex) % 4;

    //checking for straight forward configurations
    /*if (solvedCommandQueueIndex > 0 and solvedCommandQueue[solvedCommandQueueIndex] == 0) {
      if (solvedCommandQueue[solvedCommandQueueIndex - 1] % 10 == 0) {
        solvedCommandQueueIndex--;
        solvedCommandQueue[solvedCommandQueueIndex] = (solvedCommandQueue[solvedCommandQueueIndex]/10 + 1)*10;
      }
    }*/
    
    solvedCommandQueueIndex++;
    currentFacingDir = nextIndex;
    switch (currentFacingDir) {
      case 0: pos = pos - 1; break;
      case 1: pos = pos - 6; break;
      case 2: pos = pos + 1; break;
      case 3: pos = pos + 6; break;
    }
  }

}

void removeConflicts(int* distance, int* exittime) {
  int eastDist, westDist, northDist, southDist;
  int distArr[4];

  int eastExittime, westExittime, northExittime, southExittime;
  int exittimeArr[4];
  int x, y;
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      x = 5 - i; y = 5 - j;

      if (y + 1 < 6) {
        eastDist = distance[x * 6 + y + 1];   eastExittime = exittime[x * 6 + y + 1];
      }
      else {
        eastDist = 255;  eastExittime = 0;
      }
      if (x - 1 >= 0) {
        northDist = distance[(x - 1) * 6 + y]; northExittime = exittime[(x - 1) * 6 + y];
      }
      else {
        northDist = 255; northExittime = 0;
      }
      if (y - 1 >= 0 && y - 1 < 6) {
        westDist = distance[x * 6 + y - 1]; westExittime = exittime[x * 6 + y - 1];
      }
      else {
        westDist = 255; westExittime = 0;
      }
      if (x + 1 >= 0 && x + 1 < 6) {
        southDist = distance[(x + 1) * 6 + y]; southExittime = exittime[(x + 1) * 6 + y];
      }
      else {
        southDist = 255; southExittime = 0;
      }

      distArr[0] = westDist; distArr[1] = northDist; distArr[2] = eastDist; distArr[3] = southDist;
      exittimeArr[0] = westExittime; exittimeArr[1] = northExittime; exittimeArr[2] = eastExittime; exittimeArr[3] = southExittime;
      for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 4; j++) {
          if (distArr[i] == 255 or distArr[j] == 255) continue;

          if (distArr[i] == distArr[j]) {
            if (exittimeArr[i] < exittimeArr[j]) { // find the best side to turn. make the unwanted path as 100. so robo will not go there.
              distArr[i] = 100;
            } else {
              distArr[j] = 100;
            }
          }
        }
      }


      for (int k = 0; k < 4; k++) {
        if (distArr[k] == 100) { // change where needed
          switch (k) {
            case 0: distance[x * 6 + y - 1] = 100; break;
            case 1: distance[(x - 1) * 6 + y] = 100; break;
            case 2: distance[x * 6 + y + 1] = 100; break;
            case 3: distance[(x + 1) * 6 + y] = 100; break;
          }
        }
      }


    }
  }
}





/*

  ---------> Y
  |
  |
  |
  v        -|- (5,5)
  X

*/

void BFS(int* distance) {
  mazeWalls[startXPosition][startYPosition] += 1; // back wall is always there in firstcell!!!!!!!!!!!!!!!!!!!!!!!!!!
  //edges are defined as walls in mazeWalls
  //nodes are defined as cells in maze
  int queue[36]; // can this be larger than 36??????? since there are loops????
  int queueP = 0; //points to the last element in the queue

  int visited[36];
  //initilialize queue with -1
  //initialize visited with 0;
  //initialize distance with 255;
  for (int i = 0; i < 36; i++) {
    visited[i] = 0; queue[i] = -1; distance[i] = 255;
  }

  queue[queueP] = startXPosition * 6 + startYPosition;
  distance[queue[0]] = 0; // start distance is 0

  int currentCell;
  int edges;
  int isWall;
  int depth = 0;

  while (1) {
    if (queueP < 0) {
      break;
    }
    currentCell = pop(queue, 36);
    //Serial.print("-----------------------------------------------------------\nChecking cell ");
    //Serial.println(currentCell);
    if (visited[currentCell]) {
      queueP--;
      continue;
    }

    visited[currentCell] = 1;
    edges = mazeWalls[currentCell / 6][currentCell % 6];
    queueP--;

    if (edges == -1) continue;

    depth += 1;

    //Serial.print("Going to Cell ");
    //Serial.println(currentCell);
    //Serial.print("walls ");
    //Serial.println(edges, BIN);
    for (int j = 0; j < 4; j++) {
      isWall = edges % 2;
      edges = edges >> 1;
      if (isWall)
        continue;

      queueP++;
      switch (j) {
        case 0: //No wall at south
          if (currentCell + 6 > 35) {
            queueP = -1;
            Serial.println("Out of the maze from south");
            continue;
          }
          if (visited[currentCell + 6]) {
            queueP--;
            continue;
          }
          queue[queueP] = currentCell + 6; distance[queue[queueP]] = distance[currentCell] + 1;
          break;
        case 1: //No wall at east
          if ((currentCell + 1) & 6 == 0) {
            queueP = -1;
            Serial.println("Out of the maze from east");
            continue;
          }
          if (visited[currentCell + 1]) {
            queueP--;
            continue;
          }
          queue[queueP] = currentCell + 1; distance[queue[queueP]] = distance[currentCell] + 1;
          break;
        case 2: //No wall at north
          if (currentCell - 6 < 0) {
            queueP = -1;
            Serial.println("Out of the maze from north");
            continue;
          }
          if (visited[currentCell - 6]) {
            queueP--;
            continue;
          }
          queue[queueP] = currentCell - 6; distance[queue[queueP]] = distance[currentCell] + 1;
          break;
        case 3: //No wall at west
          if (currentCell % 6 == 0) {
            queueP = -1;
            Serial.println("Out of the maze from west");
            continue;
          }
          if (visited[currentCell - 1]) {
            queueP--;
            continue;
          }
          queue[queueP] = currentCell - 1; distance[queue[queueP]] = distance[currentCell] + 1;
          break;

      }

    }
  }

  Serial.print("Optimum number of steps ");
  Serial.println(distance[currentCell]);

}


void DFS(int* exittime) {

  int queue[36]; // can this be larger than 36??????? since there are loops????
  int queueP = 0; //points to the last element in the queue


  int visited[36];
  //initilialize queue with -1
  //initialize visited with 0;
  //initialize distance with 255;
  for (int i = 0; i < 36; i++) {
    visited[i] = 0; queue[i] = -1; exittime[i] = 0;
  }

  queue[queueP] = startXPosition * 6 + startYPosition;

  int currentCell;
  int edges;
  int isWall;
  int extime = 0;

  while (1) {
    if (queueP < 0)
      break;
    currentCell = queue[queueP];
    //Serial.print("-----------------------------------------------------------\nChecking cell ");
    //Serial.println(currentCell);
    if (visited[currentCell]) {
      queueP--;
      continue;
    }

    visited[currentCell] = 1;
    edges = mazeWalls[currentCell / 6][currentCell % 6];
    queueP--;

    if (edges == -1) continue;

    extime += 1;
    exittime[currentCell] = extime;
    //Serial.print("Going to Cell ");
    //Serial.println(currentCell);

    for (int j = 0; j < 4; j++) {
      isWall = edges % 2;
      edges = edges >> 1;
      if (isWall)
        continue;

      queueP++;
      switch (j) {
        case 0: //No wall at south
          if (currentCell + 6 > 35) {
            queueP = -1;
            Serial.println("Out of the maze from south");
            continue;
          }
          if (visited[currentCell + 6]) {
            queueP--;
            continue;
          }
          queue[queueP] = currentCell + 6; break;
        case 1: //No wall at east
          if ((currentCell + 1) & 6 == 0) {
            queueP = -1;
            Serial.println("Out of the maze from east");
            continue;
          }
          if (visited[currentCell + 1]) {
            queueP--;
            continue;
          }
          queue[queueP] = currentCell + 1; break;
        case 2: //No wall at north
          if (currentCell - 6 < 0) {
            queueP = -1;
            Serial.println("Out of the maze from north");
            continue;
          }
          if (visited[currentCell - 6]) {
            queueP--;
            continue;
          }
          queue[queueP] = currentCell - 6; break;
        case 3: //No wall at west
          if (currentCell % 6 == 0) {
            queueP = -1;
            Serial.println("Out of the maze from west");
            continue;
          }
          if (visited[currentCell - 1]) {
            queueP--;
            continue;
          }
          queue[queueP] = currentCell - 1; break;

      }

    }
    //printArr(exittime,36);
  }

}

int pop(int*arr, int n) {
  int x = arr[0];
  for (int i = 0; i < n - 1; i++) {
    arr[i] = arr[i + 1];
  }
  return x;
}

void printArr(int* arr, int n) {
  for (int i = 0; i < n; i++) {
    Serial.print(arr[i]);
    if (arr[i] > 99)
      Serial.print(" ");
    else if (arr[i] > 9 or arr[i] < 0)
      Serial.print("  ");
    else
      Serial.print("   ");
    if ((i + 1) % 6 == 0) Serial.println("");
  }
  Serial.println("");
}

