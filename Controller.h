/*
 * Controller.h
 * Controller�N���X
 *
 * �N���X��: Controller(C)
 * ����:
 * ����: setTargetVale,
 * �֘A: RotationSpeed(RS)
 */

#ifndef _CONTROLLER
#define _CONTROLLER

#include "MotorSpeed.h"
#include "MotorPwm.h"
#include "PControlMethod.h"

/**
 * �ڕW��]���x��ݒ肷��
 * @param target �ڕW��]���x [rps]
 */
extern void C_setTargetValue(int target);

/**
 * �ڕW��]���x���擾����
 * @return �ڕW��]���x [rps]
 */
extern int C_getTargetValue(void);

/**
 * 1�T�C�N��������s��
 */
extern void C_doControl();

/**
 * 1�T�C�N��������s��
 */
extern void C_setControlParameter(float kp);


/**
 * ������J�n����
 */
extern void C_start();

/**
 * ������~����
 */
extern void C_stop();


#endif // _CONTROLLER