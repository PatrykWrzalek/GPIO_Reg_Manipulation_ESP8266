#include <Arduino.h>
#include "board_LED_blinking.h"

void setup() // put your setup code here, to run once:
{
  board_LED_init();
}

void loop() // put your main code here, to run repeatedly:
{
  board_LED_blinking();
  delay(500);
}