#ifndef INC_TIMER_H
#define INC_TIMER_H

#include <stdint.h>

#define CPU_FREQ (80000000)
#define SYSTICK_FREQ (1000)

uint64_t system_get_ticks(void);
void system_setup(void);
void system_delay(uint64_t milliseconds);

#endif // INC_SYSTEM_H
