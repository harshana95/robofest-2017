
void pickBox() {

  attachServos();
  pick.write(150);
  delay(1000);
  grab.write(30);
  delay(500);
  detachServos();
  Serial.println(">> Pick : Complete");

}

void dropBox() {
  attachServos();
  grab.write(90);
  delay(500);
  pick.write(70);
  delay(500);
  detachServos();
  Serial.println(">> Drop : Complete");
}

void stand() {
  attachServos();
  grab.write(30);
  delay(500);
  pick.write(70);
  delay(1000);
  detachServos();
}

void attachServos() {
  pick.attach(PIN_PICK_COLLECT);
  grab.attach(PIN_SERVO_LIFT);
}

void detachServos() {
  pick.detach();
  grab.detach();
}


