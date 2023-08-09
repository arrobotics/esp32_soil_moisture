#include <Arduino.h>
#include <U8g2lib.h>

#define SOIL_MOISTURE_PIN A0
#define OLED_SCL 15
#define OLED_SDA 4

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, OLED_SCL, OLED_SDA);

void setup() {
  Serial.begin(9600);
  u8g2.begin();
}

void loop() {
  int soilMoistureValue = analogRead(SOIL_MOISTURE_PIN);
  int percentage = map(soilMoistureValue, 1023, 0, 0, 100);

  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB14_tr);
u8g2.setFont(u8g2_font_t0_14_tr);  
  u8g2.setCursor(5, 20);
  u8g2.print("Soil Moisture:");
  u8g2.setCursor(15, 40);
  u8g2.print(percentage);
  u8g2.print("%");
  u8g2.sendBuffer();

  delay(1000); // Update every second
}