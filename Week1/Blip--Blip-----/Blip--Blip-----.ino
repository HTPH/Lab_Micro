int ledoutput =18;
void setup() {
  pinMode(ledoutput, OUTPUT);
}

void loop() {
  digitalWrite(ledoutput, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(200);                      // wait for a second
  digitalWrite(ledoutput, LOW);   // turn the ledoutput off by making the voltage LOW
  delay(400);                      // wait for a second
  digitalWrite(ledoutput, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(200);                      // wait for a second
  digitalWrite(ledoutput, LOW);   // turn the LED off by making the voltage LOW
  delay(1200);                      // wait for a second
}
