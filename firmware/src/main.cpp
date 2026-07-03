#include <Arduino.h>
// #include "../variants/battTester/variant.h"
#include <Wire.h>
#include <U8g2lib.h>
#include <U8x8lib.h>
// U8X8_SSD1306_128X32_WINSTAR_HW_I2C disp(U8X8_PIN_NONE, SCL, SDA);



// U8X8_SSD1306_128X32_UNIVISION_HW_I2C disp(U8X8_PIN_NONE);
U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C disp(U8G2_R0, U8X8_PIN_NONE);

void setup() {
  // SerialUSB.begin(115200);
  Wire.begin();
  disp.begin();
  disp.setPowerSave(0);

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

}

void loop() {
  static uint32_t counter = 0;
  static bool ledState = false;

  // disp.setFont(u8x8_font_chroma48medium8_r);
  // disp.drawString(0,1,"Hello World!");
  // disp.setInverseFont(1);
  // disp.drawString(0,0,"012345678901234567890123456789");
  // disp.setInverseFont(0);
  // disp.drawString(0,2,String(counter).c_str());
  // //u8x8.drawString(0,8,"Line 8");
  // //u8x8.drawString(0,9,"Line 9");
  // // disp.refreshDisplay();		// only required for SSD1606/7  


  disp.setFont(u8g2_font_ncenB14_tr);
  disp.firstPage();
  do {
    disp.setCursor(0, 20);
    disp.print(F("Hello World!"));
  } while ( disp.nextPage() );
  delay(1000);
  counter++;
  // delay(1000);
  digitalWrite(LED_BUILTIN, ledState); ledState = !ledState;
}

