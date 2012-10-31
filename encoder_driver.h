#ifndef _ENCODER_DRIVER
#define _ENDOCER_DRIVER

#pragma INTERRUPT int_tb1		/*�^�C�}B1�A���_�[�t���[���荞��*/
#pragma INTERRUPT int_int1		/*�E�ԗ�A��*/
#pragma INTERRUPT int_int2		/*�E�ԗ�B��*/
#pragma INTERRUPT int_int3		/*���ԗ�A��*/
#pragma INTERRUPT int_int4		/*���ԗ�B��*/

/**
 * ���[�^���G���R�[�_�g�p���̏�����
 */
void init_encoder();

/**
 * �E���[�^�̉�]���x���擾����
 * @return �E�ԗւ̉�]���x [rps]
 */
//float get_r_motor_speed();
int get_r_motor_speed();

/**
 * ���ԗւ̉�]���x���擾����
 * @return ���ԗւ̉�]���x [rps]
 */
//float get_l_motor_speed();
int get_l_motor_speed();

#endif // _ENCODER_DRIVER