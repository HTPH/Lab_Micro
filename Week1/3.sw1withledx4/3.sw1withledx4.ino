int outputled[] = {23,22,21,19};
int sw1 = 15;
int buttonState = 0;
void allledon(){
  digitalWrite(23, HIGH);
  digitalWrite(22, HIGH);
  digitalWrite(21, HIGH);
  digitalWrite(19, HIGH);
}

void allledoff(){
  digitalWrite(23, LOW);
  digitalWrite(22, LOW);
  digitalWrite(21, LOW);
  digitalWrite(19, LOW);
}

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 4;i++){
    pinMode(outputled[i],OUTPUT);
  }
  pinMode(sw1,INPUT_PULLUP);
}

void loop() {
  buttonState = digitalRead(sw1);

  if (buttonState == LOW) {
    allledon();
  } else {
    allledoff();
  }

  delay(100);
}
