/**
 * @file    led.h
 * @brief   LED 驱动头文件。
 *          头文件放声明和宏，具体实现放在 led.c。
 *          本头文件只在 led.c / led_flow.c 等底层模块中 include，
 *          main.c 不直接 include，从而通过 include 边界阻止 main.c 调用 led_on/led_off。
 */
#ifndef LED_H
#define LED_H

#include <stdint.h>
#include "stm32h7xx_hal.h"

#ifdef __cplusplus
extern "C" {
#endif

/* 宏定义：给 LED 使用的端口和引脚起名字 */
#define LED_GPIO_PORT GPIOB
#define LED1_PIN      GPIO_PIN_3
#define LED2_PIN      GPIO_PIN_4
#define LED3_PIN      GPIO_PIN_5
#define LED4_PIN      GPIO_PIN_6
#define LED_MAX_NUM   4U

/* 内联函数：编号越界检查，非法编号返回 0 */
static inline uint8_t is_valid_led(uint8_t led_num)
{
    return (led_num < LED_MAX_NUM);
}

/* 一次亮灭的参数 */
typedef struct
{
    uint8_t  led_num;   /* LED 编号 (0=LED1, 1=LED2, 2=LED3, 3=LED4) */
    uint32_t on_ms;     /* 点亮持续时间 (毫秒) */
    uint32_t off_ms;    /* 熄灭持续时间 (毫秒) */
} blink_param_t;

/* 底层单灯控制（仅供 blink / led_flow 等模块内部使用） */
void led_on(uint8_t led_num);
void led_off(uint8_t led_num);

/* 封装 led_on / led_off + 延时的单次亮灭 */
void blink(blink_param_t param);

#ifdef __cplusplus
}
#endif

#endif /* LED_H */
