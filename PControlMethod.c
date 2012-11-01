#include "PControlMethod.h"

static float PC_kp = 0.0;
static int PC_prevControlValue = 0;

static int PC_truncate(int value);


//����p�����[�^��ݒ肷��
void PC_setControlParameter(float kp)
{
	PC_kp = kp;
}

//����ʂ��Z�o����
int PC_calcControlValue(int targetValue,int currentValue,float deltaTime)
{
	const float kp = PC_kp;
	const int deviation = targetValue - currentValue;
	const int calcValue = (int)(PC_prevControlValue + kp * deltaTime * 0.001 * deviation);
	const int controlValue = PC_truncate(calcValue);
	PC_prevControlValue = controlValue;
	
	return controlValue;
}	

//����������
void PC_initialize(void)
{
	PC_prevControlValue = 0;
}


//
static int PC_truncate(int value)
{
	const int Max = 100;
	const int Min = -100;
	
	if (value > Max) {
		return Max;
	} else if (value < Min) {
		return Min;
	} else {
		return value;
	}
}
