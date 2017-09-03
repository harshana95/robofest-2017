

int path[] = {FRONT, LEFT, RIGHT, RIGHT, LEFT, FRONT, FRONT, LEFT, FRONT, BACK, FRONT, RIGHT, FRONT,
              RIGHT, RIGHT, LEFT, FRONT, RIGHT, BACK, FRONT, FRONT, FRONT, LEFT, RIGHT, RIGHT, FRONT,
              RIGHT, FRONT, FRONT, FRONT, FRONT, BACK, FRONT, FRONT, RIGHT, FRONT
             };


int lenIndex = sizeof(path);
int curIndex = 0;

void mazeOption1() {

 /* if (curIndex < lenIndex) {
    if (path[curIndex] == FRONT) maze_goForward();
    else if (path[curIndex] == LEFT) maze_turnLeft();
    else if (path[curIndex] == RIGHT) maze_turnRight();
    else if (path[curIndex] == BACK) maze_turnBack();

    curIndex++;
  }
  delay(100);
*/
}




/*
  void mazeRun() {
  readWalls(wall);
  delay(1000);
  readWalls(wall);
  //mySerial.print(wall[0] + 2 * wall[1] + 4 * wall[2]);

  if (debug) {
    Serial.print(wall[2]);
    Serial.print(wall[1]);
    Serial.print(wall[0]);
    Serial.print("\t");
    //Serial.println();
  }

  // 1== Have a wall
  // 0== Open Space


  // Right Hand Rule                                 // Decisions
  if (!wall[RIGHT_SENSOR]) maze_turnRight();         // 00* | 110 010 100 000
  else if (!wall[FRONT_SENSOR]) maze_goForward();    // 0*0 | 001 101
  else if (!wall[LEFT_SENSOR] ) maze_turnLeft();     // *00 | 011
  else maze_turnBack();                              //     | 111


    // Left Hand Rule
    if (leftDist > maze_THERSOLD_FOR_WALL) maze_turnLeft();
    else if (frontDist > maze_THERSOLD_FOR_WALL) maze_goForward();
    else if (rightDist > maze_THERSOLD_FOR_WALL) maze_turnRight();
    else maze_turnBack();


  }


  void turnLeft_1(){
  //This is just for calibration
  motorForward(500);
  motorRotate(10);
  delay(50);
  motorRotate(10);
  delay(50);
  motorRotate(10);
  delay(50);
  motorRotate(10);
  delay(50);
  motorRotate(10);
  delay(50);
  motorRotate(10);
  delay(50);
  motorRotate(10);
  delay(50);
  motorRotate(10);
  delay(50);
  motorRotate(10);
	delay(50);
  motorRotate(15);
  delay(50);
	motorForward(500);
  }

*/




