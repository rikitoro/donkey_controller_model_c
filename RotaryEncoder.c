#include "RotaryEncoder.h"
#include "encoder_driver.h"

/**
 * ��]���x���擾
 * @return ��]���x [rps]
 */
int RE_getValue()
{
	return get_r_motor_speed();
}
