#include <M5Stack.h>
#include <Wire.h>
#include "PMserial.h"
SerialPM pms(PMSA003, 16, 17);
void setup() {
  // put your setup code here, to run once:
  M5.begin(true, true, true, true);
  M5.Power.begin();
  M5.Lcd.setBrightness(20); //バックライトの明るさを0（消灯）～255（点灯）で制御

//  Serial.begin(9600);
  pms.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  pms.read();  
  Serial.printf("PM1.0=%d, PM2.5=%d, PM10=%d [ug/m3]\r\n",pms.pm01, pms.pm25, pms.pm10);
  Serial.printf("PM0.3=%d, PM0.5=%d, PM1.0=%d, PM2.5=%d, PM5.0=%d, PM10=%d [pcs/100cc]\r\n",pms.n0p3, pms.n0p5, pms.n1p0, pms.n2p5, pms.n5p0, pms.n10p0);

  M5.Lcd.setTextSize(1);
  M5.Lcd.printf("PM1.0=%d, PM2.5=%d, PM10=%d [ug/m3]\r\n",pms.pm01, pms.pm25, pms.pm10);  
  M5.Lcd.printf("PM0.3=%d, PM0.5=%d, PM1.0=%d, PM2.5=%d, PM5.0=%d, PM10=%d [pcs/100cc]\r\n",pms.n0p3, pms.n0p5, pms.n1p0, pms.n2p5, pms.n5p0, pms.n10p0);

  delay(10000); 
}
