#ifndef _TIMER_DRIVER
#define _TIMER_DRIVER

#pragma INTERRUPT int_tb2 // �^�C�}�[B2���荞�݃n���h��

void init_timer();
void set_timer_task(void (*task)());

#endif // _TIMER_DRIVER