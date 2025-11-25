#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "FreeRTOS.h"
#include "task.h"

// LED pin (on Pico board)
#define LED_PIN 25

// Blink task
void blink_task(void *pvParameters) {
    (void) pvParameters;  // Unused
    
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    
    while (1) {
        gpio_put(LED_PIN, 1);
        vTaskDelay(pdMS_TO_TICKS(500));
        gpio_put(LED_PIN, 0);
        vTaskDelay(pdMS_TO_TICKS(500));
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
