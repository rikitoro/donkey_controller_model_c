#ifndef _LED_DRIVER
#define _LED_DRIVER

/**
 * LED�g�p���̏�����
 */
void init_led();

/**
 * LED7~0��_������
 * @param pattern LED�_���p�^�[��
 */
void set_led(char pattern);

#endif // _LED_DRIVER