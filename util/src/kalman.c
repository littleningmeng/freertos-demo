#include "kalman.h"
#include <stm32f10x.h>

static float angle, gyro;
const  uint8_t C_0 = 1;
const  float Q_angle = 0.002, Q_gyro = 0.002, R_angle = 0.5;
static float dt;
static float P[2][2] = {{ 1 , 0 }, { 0 , 1 }};
static float Pdot[4] = { 0 , 0 , 0 , 0 };
static float q_bias , angle_err , PCt_0 , PCt_1 , E , K_0 , K_1 , t_0 , t_1;

void kalmanInit(float _dt)
{
    dt = _dt;
}

void kalmanFilter(float angle_m, float gyro_m, float *angle_f, float *gyro_f)
{
	angle += (gyro_m - q_bias) * dt;

	Pdot[0] = Q_angle - P[0][1] - P[1][0];
	Pdot[1] = -P[1][1];
	Pdot[2] = -P[1][1];
	Pdot[3] = Q_gyro;

	P[0][0] += Pdot[0] * dt;
	P[0][1] += Pdot[1] * dt;
	P[1][0] += Pdot[2] * dt;
	P[1][1] += Pdot[3] * dt;

	angle_err = angle_m - angle;

	PCt_0 = C_0 * P[0][0];
	PCt_1 = C_0 * P[1][0];

	E = R_angle + C_0 * PCt_0;

	K_0 = PCt_0 / E;
	K_1 = PCt_1 / E;

	t_0 = PCt_0;
	t_1 = C_0 * P[0][1];

	P[0][0] -= K_0 * t_0;
	P[0][1] -= K_0 * t_1;
	P[1][0] -= K_1 * t_0;
	P[1][1] -= K_1 * t_1;

	angle  += K_0 * angle_err;
	q_bias += K_1 * angle_err;
	gyro = gyro_m - q_bias;

	*angle_f = angle;
	*gyro_f = gyro;
}
