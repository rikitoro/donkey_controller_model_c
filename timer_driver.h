#ifndef _TIMER_DRIVER
#define _TIMER_DRIVER

#pragma INTERRUPT int_tb2 // �^�C�}�[B2���荞�݃n���h��

extern void init_timer();
extern void set_timer_task(void (*task)());
extern void null_task();

#endif // _TIMER_DRIVER