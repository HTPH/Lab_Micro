int outputled[] = { 23, 22, 21, 19, 18, 5, 17, 16 }; 
int sw1 = 15;
int timestate = 0;
int delaytime = 200;
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
      delay(200);
      for (int i = 0; i < 8; i++) {
        digitalWrite(outputled[i], LOW);
      }
      delay(delaytime);
      delaytime = delaytime + 100;
    }

  } else {
    for (int i = 0; i < 8; i++) {
      digitalWrite(outputled[i], LOW);
    }
    timestate = 0;
    delaytime = 200;
  }
}
