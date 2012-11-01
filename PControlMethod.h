/**
 * PControlMethod.h
 * PControlMethodクラス
 *
 * クラス名: PControlMethod(PC)
 * 属性: 
 * 操作: getControlParm,setControlParm,calcControlValue,initialize
 * 関連:
 */
 
#ifndef _PCONTROLMETHOD
#define _PCONTROLMETHOD

#include "PControlMethodParm.h"

/**
 * 制御量を算出する
 * @return 制御量 (-100~100)
 * @param target モータ回転速度目標値
 * @param current モータ回転速度計測値
 * @param deltatime 制御周期[ms]
 */
extern int PC_calcControlValue(int target,int current, float deltatime);

/**
 * 比例制御パラメータを設定する
 * @param kp 比例制御パラメータの設定値
 */
extern void PC_setControlParameter(float kp);

/**
 * 制御量を初期化する
 */
extern void PC_initialize(void);

#endif // _PCONTROLMETHOD