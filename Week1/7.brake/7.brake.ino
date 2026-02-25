int outputled[] = { 23, 22, 21, 19, 18, 5, 17, 16 };
int sw1 = 15;
int timestate = 0;

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(outputled[i], OUTPUT);
  }
  pinMode(sw1, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {

  Serial.println(timestate);

  if (digitalRead(sw1) == LOW) {
    if (timestate >= 9) {
      for (int i = 0; i < 8; i++) {
        digitalWrite(outputled[i], HIGH);
      }
    } else {
      for (int i = 0; i < 8; i++) {
        digitalWrite(outputled[i], HIGH);
      }
      timestate++;
      delay(400);
      for (int i = 0; i < 8; i++) {
        digitalWrite(outputled[i], LOW);
      }
      delay(400);
    }

  } else {
    for (int i = 0; i < 8; i++) {
      digitalWrite(outputled[i], LOW);
    }
    timestate = 0;
  }
}
