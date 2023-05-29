/**
 * @file keypad.h
 * @author manhph184545@sis.hust.edu.vn
 * @brief 4x4 Keypad library for ESP-IDF framework
 * @version 0.1
 * @date 2023-05-14
 * 
 */
#include <iostream>
#include "keypad.h"
#include <esp_log.h>
#include <memory.h>


#define NbrRows 4
#define NbrCols 4

const Pinsline[NbrRows] = {4, 5, 6, 7};
const PinsCol[NbrCols] = {0, 1, 2, 3};

const char keypad[NbrRows][NbrCols] = { 
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};  

void keypad_initalize(){
    for(int i = 0; i < NbrCols; i++){
        gpio_set_direction(PinsCol[i], GPIO_MODE_OUTPUT);
        gpio_set_level(PinsCol[i], 0);
    }
    for(int i = 0; i < NbrRows; i++){
        gpio_set_direction(Pinsline[i], GPIO_MODE_INPUT);
        gpio_set_pull_mode(Pinsline[i], GPIO_PULLUP_ONLY);
    }
}
void keypad_output_set(keypad_output_level_t col0, keypad_output_level_t col1, keypad_cols_t col2, keypad_cols_t col3){
    gpio_set_level(PinsCol[0], col0);
    gpio_set_level(PinsCol[1], col1);
    gpio_set_level(PinsCol[2], col2);
    gpio_set_level(PinsCol[3], col3);
}

char keypad_detect(keypad_cols_t col){
    if (gpio_get_level(PinsCol[0]) == 0)
        return keypad[0][col];
    else if (gpio_get_level(PinsCol[1]) == 0)
        return keypad[1][col];
    else if (gpio_get_level(PinsCol[2]) == 0)
        return keypad[2][col];
    else if (gpio_get_level(PinsCol[3]) == 0)
        return keypad[3][col];
    return 255;
}

char keypad_getkey(){
    keypad_output_set(LOW, HIGH, HIGH, HIGH);
    if(keyboard_detect(Col_0) != 255) {
        char a = keyboard_detect(Col_0);
        vTaskDelay(pdMS_TO_TICKS(300));
        return a;
    }
    
    keypad_output_set(HIGH, LOW, HIGH, HIGH);
    if(keyboard_detect(Col_1) != 255) {
        char a = keyboard_detect(Col_1);
        vTaskDelay(pdMS_TO_TICKS(300));
        return a;
    }
        keypad_output_set(HIGH, HIGH, LOW, HIGH);
    if(keyboard_detect(Col_2) != 255) {
        char a = keyboard_detect(Col_2);
        vTaskDelay(pdMS_TO_TICKS(300));
        return a;
    }
    
    keypad_output_set(HIGH, HIGH, HIGH, LOW);
    if(keyboard_detect(Col_3) != 255) {
        char a = keyboard_detect(Col_3);
        ESP_LOGI("Keypad","Press %c", a);
        vTaskDelay(pdMS_TO_TICKS(300));
        return a;
    } 
    vTaskDelay(pdMS_TO_TICKS(20));
    return 255;
}