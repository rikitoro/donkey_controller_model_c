#include "sfr29.h"
#include "encoder_driver.h"

#pragma INTERRUPT int_tb1		/*�^�C�}B1�A���_�[�t���[���荞��*/
#pragma INTERRUPT int_int1		/*�E�ԗ�A��*/
#pragma INTERRUPT int_int2		/*�E�ԗ�B��*/
#pragma INTERRUPT int_int3		/*���ԗ�A��*/
#pragma INTERRUPT int_int4		/*���ԗ�B��*/

//
const int CPR = 32;			// ���[�^1��]������̃G���R�[�_�J�E���g��
const float DELTA_T = 20.0; // �^�C�}�[���� 20 [ms]


/*�O���[�o���ϐ�*/
int countR = 0;	// �E���[�^���G���R�[�_�̃J�E���g�l
int countL = 0; // �����[�^���G���R�[�_�̃J�E���g�l
int countR_prev = 0;
int countL_prev = 0;

void init_encoder()
{
	/*�^�C�}B1�̐ݒ�*/
	tck1_tb1mr=1;		/*�^�C�}�[���[�h�Ff32*/
	tb1=2*6250-1;			/*20ms�Ŋ��荞�ݔ���*/
	ilvl0_tb1ic=1;		/*���荞�݃��x��1*/
	tb1s = 1;			/*�J�E���g�X�^�[�g*/

	/*INT���荞�ݐݒ�*/
	ilvl2_int1ic=1;			/*INT1���荞�݃��x��4*/
	ilvl2_int2ic=1;			/*INT2���荞�݃��x��4*/
	ilvl2_int3ic=1; 		/*INT3���荞�݃��x��4*/
	ilvl2_int4ic=1; 		/*INT4���荞�݃��x��4*/

	ifsr = 0x5e;			/*INT1,2,3,4 ���G�b�W�Ŋ��荞��*/
			
	/* �����݋���*/ 
	#pragma ASM
		FSET I
	#pragma ENDASM
}


int get_r_motor_speed()
{
	const float coeff = 1000.0 / (CPR * DELTA_T);
	
	int cnt = countR_prev;
	int speed = (int) (coeff * cnt);	 	
	return cnt;
}

int get_l_motor_speed()
{
	
	const float coeff = 1000.0 / (CPR * DELTA_T);
	
	int cnt = countL_prev;
	int speed = (int) (coeff * cnt);	 	
	return cnt;

}



/******************************************************************************
	�O��(INT1)���荞�݃n���h��
******************************************************************************/
void int_int1(void)
{
	if (!p8_3)
	{/* ����������G�b�W�̏ꍇ */
		if (p8_4) {
			-countR;
		} else {
			++countR;
		}
	} else {/* �����オ��G�b�W�̏ꍇ */
		if (p8_4) {
			++countR;
		} else {
			--countR;
		}
	}
	ir_int1ic = 0;		/* �����ݗv���N���A */
}

/******************************************************************************
	�O��(INT2)���荞�݃n���h��
******************************************************************************/
void int_int2(void)
{
	if (!p8_4) {/* ����������G�b�W�̏ꍇ */
		if (p8_3) {
			++countR;
		} else {
			--countR;
		}
	} else {/* �����オ��G�b�W�̏ꍇ */
		if (p8_3) {
			--countR;
		} else {
			++countR;
		}
	}
	ir_int2ic = 0;		/* �����ݗv���N���A */
}


/******************************************************************************
	�O��(INT3)���荞�݃n���h��
******************************************************************************/
void int_int3(void)
{
	if (!p1_5) {/* ����������G�b�W�̏ꍇ */
		if (p1_6) {
			--countL;
		} else {
			++countL;
		}
	} else {/* �����オ��G�b�W�̏ꍇ */
		if (p1_6) {
			++countL;
		} else {
			--countL;
		}
	}
	ir_int3ic = 0;		/* �����ݗv���N���A */
}

/******************************************************************************
	�O��(INT4)���荞�݃n���h��
******************************************************************************/
void int_int4(void)
{
	if (!p1_6) {/* ����������G�b�W�̏ꍇ */
		if (p1_5) {
			++countL;
		} else {
			--countL;
		}
	} else {/* �����オ��G�b�W�̏ꍇ */
		if (p1_5) {
			--countL;
		} else {
			++countL;
		}
	}
	ir_int4ic = 0;		/* �����ݗv���N���A */
}


/******************************************************************************
	�^�C�}B1�A���_�t���[���荞�݃n���h��(50Hz)
******************************************************************************/
void int_tb1(void)
{
	// �J�E���g���̕ێ�
	countR_prev = countR;
	countL_prev = countL;
	
	// �J�E���g���̃��Z�b�g
	countR = 0;
	countL = 0;
	
	//
	ir_tb1ic = 0;		/* �����ݗv���N���A */	
	
}
