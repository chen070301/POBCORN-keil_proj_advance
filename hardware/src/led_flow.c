/**
 * @file    led_flow.c
 * @brief   流水灯状态机实现。
 *          根据全局 signal 切换三种流水灯模式。
 *          所有模式内部均通过 blink() 或 led_on/led_off 组合实现。
 */
#include "led.h"       /* blink(), blink_param_t, led_on(), led_off(), LED_MAX_NUM */
#include "led_flow.h"

/* 流水灯每步延时 (毫秒) */
#define FLOW_DELAY_MS 250U

/* 遥控器模拟信号：0=逐个, 1=两两, 2=一起 */
int signal = 0;

/* ------------------------------------------------------------------ */
/* 静态辅助函数：三种流水灯模式（均不对外暴露）                       */
/* ------------------------------------------------------------------ */

/**
 * @brief  逐个亮灭：LED1→LED2→LED3→LED4 依次亮灭。
 */
static void led_flow_single(void)
{
    blink_param_t param;
    uint8_t       i;

    param.on_ms  = FLOW_DELAY_MS;
    param.off_ms = 0U;

    for (i = 0U; i < LED_MAX_NUM; i++) {
        param.led_num = i;
        blink(param);
    }
}

/**
 * @brief  两两亮灭：LED1+LED2 亮灭 → LED3+LED4 亮灭。
 */
static void led_flow_pair(void)
{
    /* 左两颗 (LED1, LED2) */
    led_on(0U);
    led_on(1U);
    HAL_Delay(FLOW_DELAY_MS);
    led_off(0U);
    led_off(1U);

    /* 右两颗 (LED3, LED4) */
    led_on(2U);
    led_on(3U);
    HAL_Delay(FLOW_DELAY_MS);
    led_off(2U);
    led_off(3U);
}

/**
 * @brief  一起亮灭：四颗 LED 同时亮、同时灭。
 */
static void led_flow_all(void)
{
    led_on(0U);
    led_on(1U);
    led_on(2U);
    led_on(3U);
    HAL_Delay(FLOW_DELAY_MS);
    led_off(0U);
    led_off(1U);
    led_off(2U);
    led_off(3U);
    HAL_Delay(FLOW_DELAY_MS);
}

/* ------------------------------------------------------------------ */
/* 公共接口：状态机入口                                              */
/* ------------------------------------------------------------------ */

/**
 * @brief  状态机入口：读取全局 signal，执行对应流水灯模式。
 */
void led_flow_run(void)
{
    switch ((led_flow_mode_t)signal) {
    case LED_FLOW_MODE_SINGLE:
        led_flow_single();
        break;
    case LED_FLOW_MODE_PAIR:
        led_flow_pair();
        break;
    case LED_FLOW_MODE_ALL:
        led_flow_all();
        break;
    default:
        break;
    }
}
