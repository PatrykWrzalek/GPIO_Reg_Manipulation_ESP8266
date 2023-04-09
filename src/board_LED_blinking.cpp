extern "C"
{
// All visible C library function prototypes go here.
#include "esp8266_peri.h"
#include "board_LED_blinking.h"

    void board_LED_init()
    {
        GPF(2) = GPFFS(GPFFS_GPIO(2));  // Set mode to GPIO
        GPC(2) = (GPC(2) & (0xF << 7)); // SOURCE(GPIO) | DRIVER(NORMAL) | INT_TYPE(UNCHANGED) | WAKEUP_ENABLE(DISABLED)
        ESP8266_REG(0x310) = (1 << 2);  // Enable
    }

    void board_LED_blinking()
    {
        GPO ^= (1 << 2); // Toggle PIN2 (board_led)
    }
}
