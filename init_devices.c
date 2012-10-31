#include "init_devices.h"
#include "sfr29.h"

#include "encoder_driver.h"
#include "led_driver.h"
#include "motor_driver.h"
#include "switch_driver.h"

void init_cpu();

void init_devices()
{
	init_cpu();	
	//
	init_led();
	init_switch();
	init_motor();
	init_encoder();
}




void init_cpu()
{
	prc2 = 1;			/*PACRの書込み許可*/
	pacr = 3;			/*80ピンに設定*/
	
	/*クロック設定*/
	prc0=1;
	cm21=0;
	cm06=0;
	prc0=0;
}

