#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "projdefs.h"

// LED pin (on Pico board)
#define LED_PIN 8  // Changed to GP8

// Blink task
void blink_task(void *pvParameters) {
    (void) pvParameters;  // Unused
    
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    
    while (1) {
        gpio_put(LED_PIN, 1);           // Turn LED on
        vTaskDelay(pdMS_TO_TICKS(500)); // Delay 500 ms
        gpio_put(LED_PIN, 0);           // Turn LED off
        vTaskDelay(pdMS_TO_TICKS(500)); // Delay 500 ms
    }
}

int main() {
    stdio_init_all();  // Optional: for USB printf

    // Create the blink task
    xTaskCreate(
        blink_task, // Task function
        "Blink",    // Name
        256,        // Stack size (words)
        NULL,       // Parameters
        1,          // Priority
        NULL        // Task handle
    );

    // Start the FreeRTOS scheduler
    vTaskStartScheduler();
    
    // Should never get here
    while (1);
}