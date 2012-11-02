#include "sfr29.h"
	

#include "init_devices.h"
#include "utility.h"
#include "led_driver.h"

#include "MotorSpeed.h"
#include "Controller.h"

void test_C();


void main() 
{
	init_devices();
	test_C();
}

void test_C() {

	// ��ᐧ��̃p�����[�^�ݒ�
	C_setControlParameter(0.05);
	
	// ���[�^��]���x�̖ڕW�l�ݒ�
	C_setTargetValue(64);
	C_start();
	
	while(1){ // 100[ms]���Ƃ�1�T�C�N������������Ȃ��B
		C_doControl();
		wait_ms(100);
		set_led((char)MS_getValue());
		
	}
}

