#include "DHTesp.h"
#include <TM1638plus.h>


#define DHTpin 18
#define pin_STB 21
#define pin_CLK 22
#define pin_DIO 23

TM1638plus tm(pin_STB, pin_CLK, pin_DIO, false);
DHTesp dht;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(200);
  tm.displayBegin();
  tm.brightness(6);
  dht.setup(DHTpin, DHTesp::DHT22);
}

void loop() {
  // put your main code here, to run repeatedly:
  int intData, singleData;
  tm.reset();
  float humid = dht.getHumidity();
  float temp = dht.getTemperature();

  Serial.print("Temp : ");
  Serial.println(temp);
  Serial.print("humid : ");
  Serial.println(humid);

  int Datatemp = (int)(temp * 10);
  int decitemp = (Datatemp % 10);
  int singletemp = ((Datatemp / 10) % 10);
  int tentemp = (Datatemp / 100);

  
  tm.displayASCII(0, 't',tm.DecPointOff);
  tm.displayHex(1, tentemp);
  tm.displayASCII(2, 0x30 + singletemp,tm.DecPointOn);
  tm.displayHex(3, decitemp);


 int Datahum = (int)(humid * 10);
  int decihum = (Datahum % 10);
  int singlehum = (Datahum / 10) % 10;
  int tenhum = (Datahum / 100);

  tm.displayASCII(4, 'h',tm.DecPointOff);
  tm.displayHex(5,tenhum);
  tm.displayASCII(6,0x30 + singlehum,tm.DecPointOn);
  tm.displayHex(7,decihum);
  






  delay(2000);
}
