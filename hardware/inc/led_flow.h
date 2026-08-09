/**
 * @file    led_flow.h
 * @brief   流水灯功能头文件。
 *          调用 led_flow() 一次即完成一轮 LED1→LED4 依次亮灭。
 */
#ifndef LED_FLOW_H
#define LED_FLOW_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief  执行一轮流水灯：LED1→LED4 依次亮起再熄灭。
 * @param  delay_ms: 每个 LED 点亮保持时间 (毫秒)
 * @note   阻塞式调用，放在 while(1) 中即可循环流水。
 */
void led_flow(uint32_t delay_ms);

#ifdef __cplusplus
}
#endif

#endif /* LED_FLOW_H */
