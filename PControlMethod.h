/*
 * PControlMethod.h
 * PControlMethod�N���X
 *
 * �N���X��: PControlMethod(PC)
 * ����: hensa
 * ����: getControlParm,setControlParm,calcControlValue,initialize
 * �֘A:
 */
 
#ifndef _PCONTROLMETHOD
#define _PCONTROLMETHOD

#include "PControlMethodParm.h"

extern float PC_getControlParm(void);
extern void PC_setControlParm(float parm);
extern int PC_calcControlValue(int targvalue,int getvalue,float deltatime);
extern void PC_initialize(void);

#endif // _PCONTROLMETHOD