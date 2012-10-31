/**
 * ���[�^�[�쓮�p�h���C�o�B
 * ����)�^�C�}�[A1�����A3�𗘗p����(PWM�M���o��)
 */

#ifndef _MOTOR_DRIVER
#define _MOTOR_DRIVER


/**
 * ���[�^�[�̓��샂�[�h
 */
enum MotorMode {
	MOTOR_STOP    = 0,
	MOTOR_FORWARD = 1,
	MOTOR_REVERSE = 2,
};


/**
  * ���[�^�[�g�p���̏�����
  */
void init_motor();


/**
  * �E���[�^�[�̓��샂�[�h��ݒ肷��
  * @param mode MOTOR_STOP: ��~�AMOTOR_FORWARD: ���]�AMOTOR_REVERSE: �t�]
  */
void set_r_motor_mode(enum MotorMode mode);

/**
  * �����[�^�[�̓��샂�[�h��ݒ肷��
  * @param mode MOTOR_STOP: ��~�AMOTOR_FORWARD: ���]�AMOTOR_REVERSE: �t�]
  */
void set_l_motor_mode(enum MotorMode mode);

/**
  * �E���[�^�[��duty�� pwm %�ŋ쓮����
  * @param pwm duty�� [%] (0<= pwm <=100)	
  */
void set_r_motor_pwm(int pwm);

/**
  * �����[�^�[��duty�� pwm %�ŋ쓮����
  * @param pwm duty�� [%] (0<= pwm <=100)	
  */
void set_l_motor_pwm(int pwm);

#endif // _MOTOR_DRIVER