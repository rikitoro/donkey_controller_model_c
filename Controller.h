/*
 * Controller.h
 * Controllerクラス
 *
 * クラス名: Controller(C)
 * 属性:
 * 操作: setTargetVale,
 * 関連: RotationSpeed(RS)
 */

#ifndef _CONTROLLER
#define _CONTROLLER

#include "MotorSpeed.h"
#include "MotorPwm.h"
#include "PControlMethod.h"
#include "PControlMethodParm.h"

/**
 * 目標回転速度を設定する
 * @param target 目標回転速度 [rps]
 */
extern void C_setTargetValue(int target);

/**
 * 目標回転速度を取得する
 * @return 目標回転速度 [rps]
 */
extern int C_getTargetValue(void);

/**
 * 1サイクル制御を行う
 */
extern void C_doControl();

/**
 * 1サイクル制御を行う
 */
extern void C_setControlParameter(float kp);

#endif // _CONTROLLER