#include "sfr29.h"
#include "timer_driver.h"
#include "Controller.h"

//static void (*timer_task)() = null_task;
//static cnt = 0;

void init_timer()
{
	
	
	/*�^�C�}B2�̐ݒ�*/
	tck1_tb2mr=1;			/*�^�C�}���[�h:f32*/
	tb2=6250-1;			/*100Hz�ŃA���_�[�t���[*/
	tb2s = 1;			/*tb2�J�E���g�X�^�[�g*/
	/*�^�C�}A2�̐ݒ�*/
	ta2mr	=0x01;			/*�C�x���g���[�h*/
	trgsr	=0x04;			/*�^�C�}B2�̃A���_�[�t���[���J�E���g*/	
	ta2	= 10-1;			/*100[ms]�Ŋ����ݔ���*/
	ta2s	=0;			/*ta2�J�E���g�X�g�b�v*/
	
	ta2ic	=2;			/*���荞�݃��x��2*/

	/* �����݋���*/  

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
