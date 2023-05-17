#ifndef KEYPAD_H
#define KEYPAD_H

/**
 * @file keypad.h
 * @author manhph184545@sis.hust.edu.vn
 * @brief 4x4 Keypad library for ESP-IDF framework
 * @version 0.1
 * @date 2023-05-14
 * 
 */

#include <driver/gpio.h>

#define KEYPAD_DEBOUNCING 200   ///< time in ms
#define KEYPAD_STACKSIZE  5

typedef enum{
    LOW,
    HIGH
} keypad_output_level_t;

typedef enum{
    Col_0,
    Col_1,
    Col_2,
    Col_3
} keypad_cols_t;

void keypad_output_set(keypad_output_level_t col0, keypad_output_level_t col1, keypad_cols_t col2, keypad_cols_t col3);

void keypad_initalize();

char keypad_detect(keypad_cols_t col);

char keypad_getkey();

void check_password(char* keyBuffer, char* defaultPassword)


#endif