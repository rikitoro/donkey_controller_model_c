/*
 * Pwm.h
 * Pwm�N���X (ControlLever�N���X������)
 *
 * �N���X��: Pwm(P)
 * ����:
 * ����: setLevel
 * �֘A:
 */
 
#ifndef _MOTORPWM
#define _MOTORPWM

/**
 * ���[�^�ւ�PWM�M����ݒ肷��B
 * @param level duty��[%] (-100<= level <=100) level>0�̎��̓��[�^�����]�Alevel<0�̎��̓��[�^�[���t�]����B
 */
extern void MP_setLevel(int level);

#endif // _MOTORPWM