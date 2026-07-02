#include <Arduino.h>
#include "../variants/battTester/variant.h"


void setup() {
  // put your setup code here, to run once:
  SerialUSB.begin(115200);


  pinMode(LED_BUILTIN, OUTPUT);
  
}

void loop() {
  SerialUSB.println("Hlep me!");
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}

