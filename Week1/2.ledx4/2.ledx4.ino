int outputled[] = {23,22,21,19};
void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 4;i++){
    pinMode(outputled[i],OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 4;i++){
    digitalWrite(outputled[i], HIGH);
    delay(700);
    digitalWrite(outputled[i], LOW);
    
  }
}
