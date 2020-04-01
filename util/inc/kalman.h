#ifndef __KALMAN_H__
#define __KALMAN_H__

void kalmanInit(float dt);
void kalmanFilter(float angle_m, float gyro_m, float *angle_f, float *gyro_f);

#endif
