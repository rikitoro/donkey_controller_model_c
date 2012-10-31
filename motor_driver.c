#include "sfr29.h"
#include "motor_driver.h"


// ���[�^�֘A�|�[�g�A���W�X�^�̒�`
#define FORWARD_L	p8_0
#define REVERSE_L	p7_7
#define PWM_L		ta3

#define FORWARD_R	p7_4
#define REVERSE_R	p7_3
#define PWM_R		ta1


// ���[�^�g�p���̏�����
void init_motor()
{
	// ���[�^����p�|�[�g�o�͐ݒ�
	pd8 = 0x01;
	pd7 = 0x98;
	
	// �^�C�}A3�̐ݒ� �����[�^PWM�o�͗p
	ta3mr = 0x27;		// �p���X�ϒ�MODE, 8bit�p���X�ϒ�, count source f1
	ta3   = 0x0000;		// count�����l
	ta3s  = 1;			// TA3�J�E���g�J�n
	
	// �^�C�}A1�̐ݒ� �E�ԗ�PWM�o�͗p
	ta1mr = 0x27;		// �p���X�ϒ�MODE, 8bit�p���X�ϒ�, count source f1
	ta1   = 0x0000; 	// count�����l
	ta1s  = 1;			// TA1�J�E���g�J�n
}	


void set_l_motor_mode(enum MotorMode mode)
{
	if (mode == MOTOR_FORWARD) {
		REVERSE_L = 1;
		FORWARD_L = 0;
	} else if (mode == MOTOR_REVERSE) {
		FORWARD_L = 1;
		REVERSE_L = 0;
	} else {
		FORWARD_L = 1;
		REVERSE_L = 1;
	}		
}


void set_r_motor_mode(enum MotorMode mode)
{
	if (mode == MOTOR_FORWARD) {
		REVERSE_R = 1;
		FORWARD_R = 0;
	} else if (mode == MOTOR_REVERSE) {
		FORWARD_R = 1;
		REVERSE_R = 0;
	} else {
		FORWARD_R = 1;
		REVERSE_R = 1;
	}		
}


void set_r_motor_pwm(int pwm)
{
	int scaled_pwm = (5 * pwm) / 2;
	PWM_R = (scaled_pwm << 8) | 0x00;
}



void set_l_motor_pwm(int pwm)
{
	int scaled_pwm = (5 * pwm) / 2;
	PWM_L = (scaled_pwm << 8) | 0x00;
}
