#include "Controller.h"

const int DeltaTime = 100; // [ms]

void C_setTargetValue(int target)
{
	MS_setTargetValue(target);
}

int C_getTargetValue(void)
{
	return MS_getTargetValue();
}

float C_getControlMethodParm(void)
{
	return PCP_getKParm();
}

void C_setControlMethodParm(float parm)
{
	PCP_setKParm(parm);
}

void C_doControl() {
	MP_setLevel(PC_calcControlValue(MS_getTargetValue(),MS_getValue(),DeltaTime));
}
