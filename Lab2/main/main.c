/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <stdio.h>
#include <inttypes.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include "driver/gpio.h" // for GPIO
#include "esp_timer.h"   // for esp_timer_get_time()
#include "rom/gpio.h"    // for gpio_pad_select_gpio

#define BTN_NUM GPIO_NUM_27
#define DEBOUNCE_TIME 50

void printID(void *pvParameter)
{
    while (1)
    {
        printf("2013063\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

static uint32_t millis()
{
    return esp_timer_get_time() / 1000; // get current time (ms)
}

void printString(void *param)
{
    // setup button
    gpio_pad_select_gpio(BTN_NUM);
    gpio_set_direction(BTN_NUM, GPIO_MODE_INPUT);
    gpio_set_pull_mode(BTN_NUM, GPIO_PULLUP_ONLY);

    int lastSteadyState = 1; // the previous steady state from the input pin
    int previousState = 1;   // the previous state from the input pin
    int currentState;        // the current reading from the input pin

    uint32_t lastDebounceTime = 0; // the last time input pin was toggled

    while (1)
    {
        currentState = gpio_get_level(BTN_NUM); // read the state of the button:
        if (currentState != previousState)      // If the button changed, due to noise or pressing:
        {
            lastDebounceTime = millis();  // reset the debouncing timer
            previousState = currentState; // save the last state
        }

        if ((millis() - lastDebounceTime) > DEBOUNCE_TIME) // if button is pressing:
        {
            if (lastSteadyState == 1 && currentState == 0)
            {
                printf("ESP32\n");
            }
            // save the last steady state
            lastSteadyState = currentState;
        }
        vTaskDelay(20 / portTICK_PERIOD_MS);
    }
}

void app_main(void)
{
    xTaskCreate(&printString, "String", 2048, NULL, 5, NULL);
    xTaskCreate(&printID, "ID", 2048, NULL, 6, NULL);
}
