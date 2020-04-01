#ifndef __PM_H__
#define __PM_H__

#include "config.h"
#include <stdbool.h>
#include <stm32f10x.h>

#define AVERAGE_TIMES        5
#define CH_VREF              ADC_Channel_0
#define ADC_SAMPLING_FREQ    PM_TASK_FREQ

// TIPS: 电池电压过低时ADC采样数据会不准，实测低于4.0V时的ADC都是不准的
#define PM_BAT_LOW_LIMIT              6.0  // 低电量告警
#define PM_BAT_MAX_VOLTAGE            8.2
#define PM_BAT_DIVIDER                3.0f
#define PM_BAT_ADC_FOR_8_2_VOLT       (int32_t)(((3.0f / PM_BAT_DIVIDER) / 2.8f) * 4096)
#define PM_BAT_COEFFICIENT            388.18f
#define PM_ADC_COMPENSATIION          133.18f
#define PM_POWER_PECENTAGE(v) (int)(100.0 * (voltage > (PM_BAT_MAX_VOLTAGE) ? (PM_BAT_MAX_VOLTAGE): voltage) / (PM_BAT_MAX_VOLTAGE))


#define PM_POWER_RCC_PERIPH       RCC_APB2Periph_GPIOA
#define PM_POWER_GPIO             GPIOA
#define PM_POWER_GPIO_PIN         GPIO_Pin_1
#define PM_POWER_GPIO_SPEED       GPIO_Speed_10MHz
#define PM_POWER_GPIO_MODE        GPIO_Mode_Out_PP

void pmInit(void);
bool pmTest(void);
void pmPowerOff(void);
float getBatteryVoltage(void);

#endif
