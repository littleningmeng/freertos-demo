#ifndef CONFIG_H_
#define CONFIG_H_

#include "FreeRTOSConfig.h"

#define DEV_TEST
#define ENABLE_WORK_BLINK_TASK
#define DEBUG_PRINT_ON_UART

#define CONFIG_BLOCK_ADDRESS 0x1FC00

#define P_NAME "MiniRobot Rev.F"

#define H_INIT_EXTI
#define T_LAUNCH_ADC
#define T_LAUNCH_RADIO
#define T_LAUNCH_POWERMANAGMENT

#define T_LAUNCH_CONTROL
#define T_LAUNCH_MULTILOG_1
#define T_LAUNCH_MULTICONTROL

#define ACTIVATE_AUTO_SHUTDOWN

#define CONFIG_USE_LOG 1

// Task Names
#define STABILIZER_TASK_NAME  (const signed char *)"STABILIZER"
#define MONITOR_TASK_NAME     (const signed char *)"MONITOR"

// Task stack size
#define STABILIZER_TASK_STACKSIZE (1 * configMINIMAL_STACK_SIZE)
#define MONITOR_TASK_STACKSIZE    (1 * configMINIMAL_STACK_SIZE)

// Task priorities. Higher number higher priority
#define STABILIZER_TASK_PRIORITY  2
#define MONITOR_TASK_PRIORITY     1

// Task freq
//#define STABILIZER_TASK_FREQ  400
#define PM_TASK_FREQ            1

#if defined(UART_OUTPUT_TRACE_DATA) && defined(ADC_OUTPUT_RAW_DATA)
#  error "Can't define UART_OUTPUT_TRACE_DATA and ADC_OUTPUT_RAW_DATA at the same time"
#endif

#if defined(UART_OUTPUT_TRACE_DATA) && defined(T_LAUNCH_ACC)
#  error "UART_OUTPUT_TRACE_DATA and T_LAUNCH_ACC doesn't work at the same time yet due to dma sharing..."
#endif

#endif /* CONFIG_H_ */
