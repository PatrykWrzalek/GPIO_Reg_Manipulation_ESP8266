#include <Arduino.h>
#define board_LED 2

void setup() // put your setup code here, to run once:
{
  GPF(board_LED) = GPFFS(GPFFS_GPIO(board_LED));  // Set mode to GPIO
  GPC(board_LED) = (GPC(board_LED) & (0xF << 7)); // SOURCE(GPIO) | DRIVER(NORMAL) | INT_TYPE(UNCHANGED) | WAKEUP_ENABLE(DISABLED)
  ESP8266_REG(0x310) = (1 << board_LED);          // Enable
}

void loop() // put your main code here, to run repeatedly:
{
  GPOS = (1 << board_LED); // Set high state on GPO board_LED
  delay(1000);
  GPOC = (1 << board_LED); // Clear high state on GPO board_LED
  delay(1000);
}