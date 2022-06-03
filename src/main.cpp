#include <Arduino.h>
#include "DigitalOut.h"

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:

  DigitalOut led(GPIO_NUM_18);
  led = 1;
  led = 0;
  led = 1;
  led = 0;

  while (true)
  {
    led = !led;

    delay(1000);
  }
}