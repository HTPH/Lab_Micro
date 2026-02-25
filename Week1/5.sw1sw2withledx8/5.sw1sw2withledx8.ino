int outputled[] = {23, 22, 21, 19, 18, 5, 17, 16};
int sw1 = 15;
int sw2 = 4;

int direction = 1;  
int currentLED = 0;

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(outputled[i], OUTPUT);
  }
  pinMode(sw1, INPUT_PULLUP);
  pinMode(sw2, INPUT_PULLUP);
}

void loop() {

  if (digitalRead(sw1) == LOW) {
    direction = 1;
  }

  if (digitalRead(sw2) == LOW) {
    direction = -1;
  }

  for (int i = 0; i < 8; i++) {
    digitalWrite(outputled[i], LOW);
  }

  digitalWrite(outputled[currentLED], HIGH);

  delay(200);   

  currentLED += direction;

  if (currentLED > 7) currentLED = 0;
  if (currentLED < 0) currentLED = 7;
}
