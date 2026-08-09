/**
 * @file    led_flow.h
 * @brief   流水灯公共接口。
 *          只暴露状态机运行函数和模式枚举，不暴露底层 LED 操作。
 */
#ifndef LED_FLOW_H
#define LED_FLOW_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* 流水灯模式枚举（与遥控器信号 0/1/2 一一对应） */
typedef enum
{
    LED_FLOW_MODE_SINGLE = 0,   /* 逐个亮灭：LED1→LED2→LED3→LED4 */
    LED_FLOW_MODE_PAIR   = 1,   /* 两两亮灭：LED1+LED2 → LED3+LED4   */
    LED_FLOW_MODE_ALL    = 2,   /* 一起亮灭：四颗同时亮、同时灭       */
} led_flow_mode_t;

/* 模拟遥控器信号：0/1/2 对应三种模式，可通过调试器或代码直接赋值 */
extern int signal;

/**
 * @brief  状态机入口：读取 signal 并执行对应流水灯模式的一轮循环。
 * @note   阻塞式，放在 while(1) 中调用即可。
 *         signal = 0 → 逐个亮灭
 *         signal = 1 → 两两亮灭
 *         signal = 2 → 一起亮灭
 */
void led_flow_run(void);

#ifdef __cplusplus
}
#endif

#endif /* LED_FLOW_H */
