/**
 * PControlMethod.h
 * PControlMethod�N���X
 *
 * �N���X��: PControlMethod(PC)
 * ����: 
 * ����: getControlParm,setControlParm,calcControlValue,initialize
 * �֘A:
 */
 
#ifndef _PCONTROLMETHOD
#define _PCONTROLMETHOD

#include "PControlMethodParm.h"

/**
 * ����ʂ��Z�o����
 * @return ����� (-100~100)
 * @param target ���[�^��]���x�ڕW�l
 * @param current ���[�^��]���x�v���l
 * @param deltatime �������[ms]
 */
extern int PC_calcControlValue(int target,int current, float deltatime);

/**
 * ��ᐧ��p�����[�^��ݒ肷��
 * @param kp ��ᐧ��p�����[�^�̐ݒ�l
 */
extern void PC_setControlParameter(float kp);

/**
 * ����ʂ�����������
 */
extern void PC_initialize(void);

#endif // _PCONTROLMETHOD