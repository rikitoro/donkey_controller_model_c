#include "sfr29.h"
#include "timer_driver.h"
#include "Controller.h"

//static void (*timer_task)() = null_task;
//static cnt = 0;

void init_timer()
{
	
	
	/*タイマB2の設定*/
	tck1_tb2mr=1;			/*タイマモード:f32*/
	tb2=6250-1;			/*100Hzでアンダーフロー*/
	tb2s = 1;			/*tb2カウントスタート*/
	/*タイマA2の設定*/
	ta2mr	=0x01;			/*イベントモード*/
	trgsr	=0x04;			/*タイマB2のアンダーフローをカウント*/	
	ta2	= 10-1;			/*100[ms]で割込み発生*/
	ta2s	=0;			/*ta2カウントストップ*/
	
	ta2ic	=2;			/*割り込みレベル2*/

	/* 割込み許可*/  

//	#pragma ASM
//		FSET I
//	#pragma ENDASM
}

void timer_start()
{
	ta2s = 1;
}

void timer_stop()
{
	ta2s = 0;
}


/*
void set_timer_task(void (*task)())
{
	timer_task = task;
}
*/

/*
void null_task()
{
}
*/

void int_ta2(void)
{
	//(*timer_task)();
	//ir_tb2ic = 0;
}
