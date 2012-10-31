#include "sfr29.h"
#include "timer_driver.h"

#pragma INTERRUPT int_tb2 // �^�C�}�[B2���荞�݃n���h��

void dummy_timer_task();
static void (*timer_task)() = dummy_timer_task;

void init_timer()
{
	/*�^�C�}B2�̐ݒ�*/
	tck1_tb2mr=1;		/*�^�C�}�[���[�h�Ff32*/
	tb2=5*6250-1;		/*50ms�Ŋ��荞�ݔ���*/
	ilvl0_tb2ic=1;		/*���荞�݃��x��1*/
	tb2s = 1;			/*�J�E���g�X�^�[�g*/

	/* �����݋���*/ 

	#pragma ASM
		FSET I
	#pragma ENDASM
}


void set_timer_task(void (*task)())
{
	timer_task = task;
}


/*******************
 private functions
*******************/

void dummy_timer_task()
{
}

/******************************************************************************
	�^�C�}B2�A���_�t���[���荞�݃n���h��(20Hz)
******************************************************************************/
void int_tb2(void)
{
	(*timer_task)();
	ir_tb2ic = 0;
}
