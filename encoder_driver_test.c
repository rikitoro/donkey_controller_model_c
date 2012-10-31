#include "sfr29.h"
#include "utility.h"
#include "led_driver.h"
#include "motor_driver.h"
#include "encoder_driver.h"

void encoder_driver_test_init();
void encoder_driver_test_show_led(float speed);

void encoder_driver_test()
{

	//	float motor_speed;
	int motor_speed;
	
	encoder_driver_test_init();


	set_l_motor_mode(MOTOR_FORWARD);
	set_l_motor_pwm(30);

	while(1) {
		/*
		wheel_speed = get_r_motor_speed();
		encoder_driver_test_show_led(wheel_speed);
		wait_ms(100);
		*/
	
		motor_speed = get_l_motor_speed();
		encoder_driver_test_show_led(motor_speed);
		wait_ms(100);

	}

}

void encoder_driver_test_init()
{
	prc2 = 1;			/*PACR�̏����݋���*/
	pacr = 3;			/*80�s���ɐݒ�*/
	
	/*�N���b�N�ݒ�*/
	prc0=1;
	cm21=0;
	cm06=0;
	prc0=0;
	
	//
	init_led();
	init_motor();
	//	
	init_encoder();
	
}

void encoder_driver_test_show_led(float speed) {
	set_led((char)speed);
}
