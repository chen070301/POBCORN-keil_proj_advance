/**
 * @file    led_flow.c
 * @brief   流水灯功能实现。
 *          使用 led_on/led_off 逐个驱动 LED，形成流水效果。
 */
#include "led_flow.h"
#include "led.h"
#include "stm32h7xx_hal.h"

/**
 * @brief  执行一轮流水灯：LED1→LED2→LED3→LED4 依次亮灭。
 * @param  delay_ms: 每个 LED 点亮保持时间 (毫秒)
 *
 * 每轮步骤：
 *   亮 LED1 → 延时 → 灭 LED1 →
 *   亮 LED2 → 延时 → 灭 LED2 →
 *   亮 LED3 → 延时 → 灭 LED3 →
 *   亮 LED4 → 延时 → 灭 LED4
 */
void led_flow(uint32_t delay_ms)
{
    uint8_t i;
    for (i = 0U; i < LED_MAX_NUM; i++) {
        led_on(i);
        HAL_Delay(delay_ms);
        led_off(i);
    }
}
