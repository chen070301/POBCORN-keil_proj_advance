/**
 * @file    led.c
 * @brief   LED 驱动实现文件。
 */
#include "led.h"

/* 引脚查找表：索引 0~3 对应 LED1~LED4 */
static const uint16_t led_pins[LED_MAX_NUM] = {
    LED1_PIN,
    LED2_PIN,
    LED3_PIN,
    LED4_PIN,
};

/**
 * @brief  点亮指定 LED
 * @param  led_num: LED 编号 (0=LED1, 1=LED2, 2=LED3, 3=LED4)
 */
void led_on(uint8_t led_num)
{
    if (!is_valid_led(led_num)) {
        return;
    }
    HAL_GPIO_WritePin(LED_GPIO_PORT, led_pins[led_num], GPIO_PIN_SET);
}

/**
 * @brief  熄灭指定 LED
 * @param  led_num: LED 编号 (0=LED1, 1=LED2, 2=LED3, 3=LED4)
 */
void led_off(uint8_t led_num)
{
    if (!is_valid_led(led_num)) {
        return;
    }
    HAL_GPIO_WritePin(LED_GPIO_PORT, led_pins[led_num], GPIO_PIN_RESET);
}

/**
 * @brief  单次亮灭：亮 on_ms 毫秒 → 灭 off_ms 毫秒
 * @param  param: 亮灭参数结构体 (LED 编号、亮时长、灭时长)
 */
void blink(blink_param_t param)
{
    if (!is_valid_led(param.led_num)) {
        return;
    }
    led_on(param.led_num);
    HAL_Delay(param.on_ms);
    led_off(param.led_num);
    HAL_Delay(param.off_ms);
}
