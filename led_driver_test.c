#include "sfr29.h"
#include "utility.h"
#include "led_driver.h"


void led_driver_test_init();

void led_driver_test()
{
	char pattern = 0;

	led_driver_test_init();
		
	while(1) {
	set_led(pattern);
	wait_ms(500);
	pattern++;
	}
}

void led_driver_test_init() 
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
}
