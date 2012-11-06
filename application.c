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

	// 比例制御のパラメータ設定
	C_setControlParameter(0.05);
	
	// モータ回転速度の目標値設定
	C_setTargetValue(64);
	C_start();
	
	while(1){ // 100[ms]ごとに1サイクル制御をおこなう。
		C_doControl();
		wait_ms(100);
		set_led((char)MS_getValue());		
	}
}

