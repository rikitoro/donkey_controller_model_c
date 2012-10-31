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
#include "PControlMethodParm.h"

/**
 * ��]���x���擾
 * @return ��]���x [rps]
 */
extern void C_setTargetValue(int target);
extern int C_getTargetValue(void);
extern void C_doControl();
extern float C_getControlMethodParm(void);
extern void C_setControlMethodParm(float parm);

#endif // _CONTROLLER