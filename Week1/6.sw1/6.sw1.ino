int outputled[] = { 23, 22, 21, 19, 18, 5, 17, 16 };
int sw1 = 15;

int currentLED = 0;
int statesw = 1;
bool canswitch = true;

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(outputled[i], OUTPUT);
  }
  pinMode(sw1, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  Serial.print("canswitch :");
  Serial.println(canswitch);
  Serial.print("statesw :");
  Serial.println(statesw);

  if (digitalRead(sw1) == HIGH && canswitch == false) {
    canswitch = true;
  }

  if (digitalRead(sw1) == LOW && canswitch == true) {
    canswitch = false;
    statesw++;
    if (statesw == 5) {
      statesw = 1;
    }
  }

  if (statesw == 1) {
    for (int i = 0; i < 8; i++) {
      digitalWrite(outputled[i], LOW);
    }

    digitalWrite(outputled[currentLED], HIGH);
    delay(200);

    currentLED = currentLED - 1;

    if (currentLED < 0) currentLED = 7;
  } else if (statesw == 2) {
    for (int i = 0; i < 8; i++) {
      digitalWrite(outputled[i], LOW);
    }

    digitalWrite(outputled[currentLED], HIGH);
  } else if (statesw == 3) {
    for (int i = 0; i < 8; i++) {
      digitalWrite(outputled[i], LOW);
    }

    digitalWrite(outputled[currentLED], HIGH);
    delay(200);

    currentLED = currentLED + 1;

    if (currentLED > 7) currentLED = 0;
  } else if (statesw == 4) {
    for (int i = 0; i < 8; i++) {
      digitalWrite(outputled[i], LOW);
    }
    digitalWrite(outputled[currentLED], HIGH);
  }
}
