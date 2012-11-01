#include "sfr29.h"

#include "init_devices.h"
#include "utility.h"
#include "led_driver.h"

#include "MotorSpeed.h"
#include "MotorPwm.h"
#include "Controller.h"
#include "PControlMethod.h"
#include "PControlMethodParm.h"
#include "RotaryEncoder.h"

//void init();
void test_RS();
void test_P();
void test_C();
void test_PCP();
void test_PC();
void test_T();


void main() 
{
	init_devices();
	//test_RS();
	//test_P();
	test_C();
	//test_PCP();
	//test_PC();
	//test_T();
}

void test_C() {

	C_setControlParameter(0.05);
	C_setTargetValue(62);
	//;set_timer_task(C_doControl);

	while(1){
		C_doControl();
		wait_ms(100);
		set_led((char)MS_getValue());
	}
}

void test_P() {
	
	MP_setLevel(30);
	wait_ms(2000);
	MP_setLevel(60);
	wait_ms(2000);
	MP_setLevel(-30);
	wait_ms(2000);
	MP_setLevel(-60);
	wait_ms(2000);
	MP_setLevel(0);
	
}

void test_RS() {
	
	while(1) {
		set_led((char)MS_getValue());
		wait_ms(100);
		/*
		set_led(RS_getTargetValue());
		wait_ms(1000);		
		RS_setTargetValue(50.0);
		set_led(RS_getTargetValue());
		wait_ms(1000);
		RS_setTargetValue(120.0);
		set_led(RS_getTargetValue());
		wait_ms(1000);
		*/
	}
}	 


void test_PC() {
	PC_initialize();
	PC_setControlParameter(1.0);
	MP_setLevel(20);
	
	/*
	while(1) {
		set_led((char)PC_calcControlValue(20,T_getValue()));
		wait_ms(100);
	}
	*/
	
	while(1) {
		MP_setLevel(PC_calcControlValue(30,RE_getValue(),0));
		wait_ms(4);
	}
	
}

void test_T()
{
	MP_setLevel(20);

	
	while(1) {
		set_led((char)RE_getValue());
		wait_ms(100);
	}
	
}
