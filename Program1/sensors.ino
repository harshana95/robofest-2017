/****************************************************************************
  Functions

  void    irSensorsBegin, sonarBegin, irSensorsOutput
  array   readLine(*sensorValues)
  String  readLineString
  int     getSonarDistance
****************************************************************************/

void irSensorsBegin() {

  for (int i = 0; i < NUM_SENSORS; i++) {
    pinMode(irPins[i], INPUT);
  }
  Serial.println(">> IRSensors : Begin...");

}

void sonarBegin() {

  /*Serial.println(">> Sonar : Begin");

  pinMode(PIN_TRIGGER, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  digitalWrite(PIN_TRIGGER, LOW);*/
}

void irSensorsOutput() {

  for (int i = 0; i < NUM_SENSORS; i++) {
    pinMode(irPins[i], OUTPUT);
  }
  for (int i = 0; i < NUM_SENSORS; i++) {
    digitalWrite(irPins[i], LOW);
  }
  Serial.println(">> IRSensors : DisplayMode");

}

//readSensorLine(unsigned int *sensor_values)
int readSensorLine(unsigned int *sensor_values)
{
  weight = 0;
  sum = 0;
  allIn = false;
  allOut = false;
  irLineString = "";

  for (int i = 0; i < NUM_SENSORS; i++) {
    value = irSensorRead(i);

    sensor_values[i] = value;
    weight += value * (i * 10);
    sum += value;
    irLineString = (String)value + " " + irLineString;
  }

  if (sum == NUM_SENSORS) allIn = true;
  if (sum == 0) allOut = true;

  if (allOut)
  {
    if ((lastReading > RIGHT_EDGE_READING) && (CENTER_EDGE_READING - 10 > lastReading )) {        // <---***>
      lastReading = RIGHT_EDGE_READING;

    } else if ((LEFT_EDGE_READING > lastReading) && ( lastReading  > CENTER_EDGE_READING) + 10) { // <***--->
      lastReading = LEFT_EDGE_READING;

    } else if (lastReading == CENTER_EDGE_READING) {                                       // <--**-->
      lastReading = CENTER_EDGE_READING;
    }
  } else {
    lastReading = weight / sum;
  }

  return lastReading;
}

int irSensorRead(int num) {
  int reading = analogRead(irPins[num] - 14);

  reading = (reading > 512);
  if (lineType == WHITE) reading = 1 - reading;

  //reading = reading; //BLACK=0, WHITE=1
  return reading;
}



int getSonarDistance() {

  /*digitalWrite(PIN_TRIGGER, HIGH);
  delayMicroseconds(20);
  digitalWrite(PIN_TRIGGER, LOW);

  duration = pulseIn(PIN_ECHO, HIGH, 30000);
  distance = duration / 58;

  if (distance > maxDistance) {
    //distance = maxDistance;
  }
  return distance;*/
}

