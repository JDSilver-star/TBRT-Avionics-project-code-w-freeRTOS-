#include "stdlib.h"
#include "FreeRTOS.h"
#include "task.h"
#include <stdbool.h>   // for true/false
#include "projdefs.h"

// LED pin (on Pico board)
#define LED_PIN 25

// Blink task
void blink_task(void *pvParameters) {
    (void) pvParameters;  // Unused

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, true);

    while (1) {
        gpio_put(LED_PIN, 1);             // LED ON  // Delay 500 ms           // LED OFF   // Delay 500 ms
    }
}

int main() {
    stdio_init_all();  // Initialize USB output (optional)

    // Create the blink task
    xTaskCreate(blink_task, "Blink", 128, NULL, 1, NULL);

    // Start the FreeRTOS scheduler
    vTaskStartScheduler();

    while (1); // Should never reach here
}
