/*
 * RotationSpeed.h
 * RotationSpeed�N���X
 *
 * �N���X��: RotationSpeed(RS)
 * ����:
 * ����: getValue, getTargetValue, setTargetValue
 * �֘A: Tachometer(R)
 */
 
#ifndef _MOTOR_SPEED
#define _MOTOR_SPEED

#include "RotaryEncoder.h"

/**
 * ��]���x���擾
 * @return ��]���x [rps]
 */
extern int MS_getValue();

/**
 * �ڕW��]���x���擾
 * @return �ڕW��]���x [rps]
 */
extern int MS_getTargetValue();

/**
 * �ڕW��]���x��ݒ�
 * @param target �ڕW��]���x�̐ݒ�l [rps]
 */
extern void MS_setTargetValue(int target);

#endif // _ROTATION_SPEED