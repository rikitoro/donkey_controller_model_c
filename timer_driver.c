#include "sfr29.h"
#include "timer_driver.h"
//#pragma INTERRUPT int_tb2 // タイマーB2割り込みハンドラ

static void (*timer_task)() = null_task;

void init_timer()
{
	/*タイマB2の設定*/
	tck1_tb2mr=1;		/*タイマーモード：f32*/
	tb2=5*6250-1;		/*50msで割り込み発生*/
	ilvl0_tb2ic=1;		/*割り込みレベル1*/
	tb2s = 1;			/*カウントスタート*/

	/* 割込み許可*/ 

//	#pragma ASM
//		FSET I
//	#pragma ENDASM
}


void set_timer_task(void (*task)())
{
	timer_task = task;
}



void null_task()
{
}

/******************************************************************************
	タイマB2アンダフロー割り込みハンドラ(20Hz)
******************************************************************************/
void int_tb2(void)
{
	C_doControl();
	//(*timer_task)();
	ir_tb2ic = 0;
}
