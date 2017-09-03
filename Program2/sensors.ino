
void sharpIRBegin() {

  pinMode(FRONT_SENSOR_PIN, INPUT);
  pinMode(RIGHT_SENSOR_PIN, INPUT);
  pinMode(LEFT_SENSOR_PIN, INPUT);

  //Serial.println(">> ColorSensor : Begin");
}

void colorBegin() {

  if (color0.begin()) {
    //Serial.println(">> ColorSensor : Begin");
  } else {
    Serial.println(">> ColorSensor : Not Found");
    //while (1); // halt!
  }
}


void readColor() {

  //color0.setInterrupt(false);  // turn on LED
  delay(10);
  color0.getRawData(&red0, &green0, &blue0, &clr0);
  //color0.setInterrupt(true);   // turn off LED


  /*if ((red0 > WHITE_THERSOLD) && (blue0 > WHITE_THERSOLD) && (green0 > WHITE_THERSOLD)) {
    colorR0 = COLOR_OPEN;
    indicatorShow(10);    // All off
    }
    else */
  if (green0 > blue0 && green0 > red0 ) {
    colorR0 = COLOR_GREEN;              //GREEN
    indicatorShow(COLOR_GREEN);
  }

  else if (blue0 > red0 ) {
    colorR0 = COLOR_BLUE; //RED
    indicatorShow(COLOR_BLUE);
  }

  else if (((green0 - blue0) < RED_GB_GAP) || ((blue0 - green0) < RED_GB_GAP) ) {
    colorR0 = COLOR_RED;                                   //RED
    indicatorShow(COLOR_RED);
  }
  else {
    colorR0 = COLOR_OPEN;
    indicatorShow(0);    // All off
  }
  indicatorShow(colorR0);

}

// ---- Sonar Sensor Functions -----------------------------------------------------------------------

void sonarBegin() {

  /*Serial.println(">> ColorSensor : Begin");
    for (int i = 0; i < 3; i++) {
    pinMode(trigger[i], OUTPUT);
    pinMode(echo[i], INPUT);
    digitalWrite(trigger[i], LOW);
    }*/
}

int getDistance(int sensor) {

  /*digitalWrite(trigger[sensor], HIGH);
    delayMicroseconds(20);
    digitalWrite(trigger[sensor], LOW);

    duration = pulseIn(echo[sensor], HIGH, 30000);
    distance = duration / 58;

    if (distance > maxDistance) {
    distance = maxDistance;
    }
    return distance;*/
}

boolean readWalls(int *wall) {
  wall[RIGHT_SENSOR] = 0;
  wall[FRONT_SENSOR] = 0;
  wall[LEFT_SENSOR] = 0;

  //for (int i = 0; i < 5; i++) {
  wall[RIGHT_SENSOR] += digitalRead(RIGHT_SENSOR_PIN);
  wall[FRONT_SENSOR] += digitalRead(FRONT_SENSOR_PIN);
  wall[LEFT_SENSOR] += digitalRead(LEFT_SENSOR_PIN);
  //}
  /*
    if (wall[RIGHT_SENSOR] / 5.0 > 0.5) wall[RIGHT_SENSOR] = 1;
    else wall[RIGHT_SENSOR] = 0;

    if (wall[FRONT_SENSOR] / 5.0 > 0.5) wall[FRONT_SENSOR] = 1;
    else wall[FRONT_SENSOR] = 0;

    if (wall[LEFT_SENSOR] / 5.0 > 0.5) wall[LEFT_SENSOR] = 1;
    else wall[LEFT_SENSOR] = 0;
  */

  return true;
}



void compassBegin() {
  /*if (!compass.begin())
    {
    Serial.println("Ooops, no HMC5883 detected ... Check your wiring!");
    while (1);
    }

    displayCompassDetails();*/
}

void displayCompassDetails(void)
{
  /*sensor_t sensor;
    compass.getSensor(&sensor);
    Serial.println("------------------------------------");
    Serial.print  ("Sensor:       "); Serial.println(sensor.name);
    Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);
    Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);
    Serial.print  ("Max Value:    "); Serial.print(sensor.max_value); Serial.println(" uT");
    Serial.print  ("Min Value:    "); Serial.print(sensor.min_value); Serial.println(" uT");
    Serial.print  ("Resolution:   "); Serial.print(sensor.resolution); Serial.println(" uT");
    Serial.println("------------------------------------");
    Serial.println("");
    delay(500);*/
}

void readCompass() {
  /*sensors_event_t event;
    compass.getEvent(&event);



    // Hold the module so that Z is pointing 'up' and you can measure the heading with x&y
    // Calculate heading when the magnetometer is level, then correct for signs of axis.
    float heading = atan2(event.magnetic.y, event.magnetic.x);

    // Once you have your heading, you must then add your 'Declination Angle', which is the 'Error' of the magnetic field in your location.
    // Find yours here: http://www.magnetic-declination.com/
    // Mine is: -13* 2' W, which is ~13 Degrees, or (which we need) 0.22 radians
    // If you cannot find your Declination, comment out these two lines, your compass will be slightly off.
    float declinationAngle = 0.22;
    heading += declinationAngle;

    // Correct for when signs are reversed.
    if (heading < 0)
    heading += 2 * PI;

    // Check for wrap due to addition of declination.
    if (heading > 2 * PI)
    heading -= 2 * PI;

    // Convert radians to degrees for readability.
    float headingDegrees = heading * 180 / M_PI;

    Serial.print("Heading (degrees): "); Serial.println(headingDegrees);

    delay(500);*/
}

