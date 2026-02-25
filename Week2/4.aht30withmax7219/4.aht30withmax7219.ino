#include "LedController.hpp"
#include <Adafruit_AHTX0.h>

#define Pin_DIN 19
// D19
#define Pin_CS 18  // D18
#define Pin_CLK 5  // D5
Adafruit_AHTX0 aht;
LedController<1, 1> lc;
void setup() {
  Serial.begin(115200);
   if (! aht.begin()) {
    Serial.println("Could not find AHT? Check wiring");
    while (1) delay(10);
  }
  lc = LedController<1, 1>(Pin_DIN, Pin_CLK, Pin_CS);
  lc.setIntensity(8);
  lc.clearMatrix();
}
void loop() {
  sensors_event_t humidity, temp;
  aht.getEvent(&humidity, &temp);// populate temp and humidity objects with fresh data
  Serial.print("Temperature: "); 
  Serial.print((temp.temperature)); 
  Serial.println(" degrees C");
  Serial.print("Humidity: "); 
  Serial.print(humidity.relative_humidity); 
  Serial.println("% rH");


  int tempdata = (int)(temp.temperature * 10);
  int tentemp = (tempdata / 100);
  int singletemp = ((tempdata / 10) % 10);
  int decitemp = (tempdata % 10);
  // 306
  // 74.13%
  lc.setChar(0,7,'t',false);
  lc.setDigit(0, 6, tentemp, false);
  lc.setDigit(0, 5, singletemp, true);
  lc.setDigit(0, 4, decitemp, false);

   int humdata = (int)(humidity.relative_humidity * 10);
  int tenhum = (humdata / 100);
  int singlehum = ((humdata / 10) % 10);
  int decihum = (humdata % 10);
  // 306
  // 74.13%
  lc.setChar(0,3,'h',false);
  lc.setDigit(0, 2, tenhum, false);
  lc.setDigit(0, 1, singlehum, true);
  lc.setDigit(0, 0, decihum, false);

  delay(500);
}