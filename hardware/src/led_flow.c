/**
 * @file    led_flow.c
 * @brief   流水灯功能实现。
 *          内部调用 blink() 逐个驱动 LED，形成流水效果。
 */
#include "led.h"       /* blink(), blink_param_t, LED_MAX_NUM */
#include "led_flow.h"

/**
 * @brief  执行一轮流水灯：LED1→LED2→LED3→LED4 依次亮灭。
 * @param  delay_ms: 每个 LED 点亮保持时间 (毫秒)
 *
 * 每轮步骤：
 *   亮 LED1 → 延时 → 灭 LED1 →
 *   亮 LED2 → 延时 → 灭 LED2 →
 *   亮 LED3 → 延时 → 灭 LED3 →
 *   亮 LED4 → 延时 → 灭 LED4
 *
 * 内部调用 blink()，不再直接操作 led_on() / led_off()。
 */
void led_flow(uint32_t delay_ms)
{
    blink_param_t param;
    uint8_t       i;

    param.on_ms  = delay_ms;
    param.off_ms = 0U;

    for (i = 0U; i < LED_MAX_NUM; i++) {
        param.led_num = i;
        blink(param);
    }
}
