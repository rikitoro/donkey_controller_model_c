#include "MotorPwm.h"

#include "motor_driver.h"

/**
 * ���[�^�ւ�PWM�M����ݒ肷��B
 * @param level duty��[%] (-100<= level <=100) level>0�̎��̓��[�^�����]�Alevel<0�̎��̓��[�^�[���t�]����B
 */
void MP_setLevel(int level)
{
	if ( level > 0 ) {
		set_r_motor_mode(MOTOR_FORWARD);
		set_r_motor_pwm(level);
	} else if ( level < 0 ) {
		set_r_motor_mode(MOTOR_REVERSE);
		set_r_motor_pwm(-level);
	} else {
		set_r_motor_mode(MOTOR_STOP);
		set_r_motor_pwm(0);
	}
}
