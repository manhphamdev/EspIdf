#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "driver/gpio.h"
#include "sdkconfig.h"

#define LED 2
int count = 0;

void task_hello(void *pvParameter) {
    while (1) {
        printf("hello world \n");
        printf("%d\n", xPortGetCoreID());
       // vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void task_blink(void *pvParameter) {
    gpio_pad_select_gpio(LED);
    gpio_set_direction(LED, GPIO_MODE_OUTPUT);

    while (1) {
        gpio_set_level(LED, 0);
      //  vTaskDelay(pdMS_TO_TICKS(3000));
        printf("Led is on\n");
        
        gpio_set_level(LED, 1);
      //  vTaskDelay(pdMS_TO_TICKS(300));
        printf("Led is off\n");
        printf("%d\n", xPortGetCoreID());
    }
}

void app_main(void) {
    xTaskCreatePinnedToCore(&task_hello, "hello task", 2048, NULL, 4, NULL, 1);
    xTaskCreate(&task_blink, "blink task", 2048, NULL, 5, NULL);
}
