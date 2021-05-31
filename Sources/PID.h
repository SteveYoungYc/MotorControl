/*
 * PID.h
 *
 *  Created on: May 17, 2021
 *      Author: Yc
 */

#ifndef PID_H_
#define PID_H_
/*
typedef struct
{
    float Kp; //比例系数Proportional
    float Ki; //积分系数Integral
    float Kd; //微分系数Derivative

    float Ek;  //当前误差
    float Ek1; //前一次误差 e(k-1)
    float Ek2; //再前一次误差 e(k-2)

} PID_IncTypeDef;

float PID_Inc(float SetValue, float ActualValue, PID_IncTypeDef *PID);
*/
#define PID_INTEGRAL_ON

typedef struct PID
{
    float P;
    float I;
    float D;
#ifdef PID_INTEGRAL_ON
    float Integral;    //位置式PID积分项
    float IntegralMax; //位置式PID积分项最大值，用于限幅
#endif
    float Last_Error; //上一次误差
    float OutputMax;  //位置式PID输出最大值，用于限幅
    float OutputMin;
} PID_IncTypeDef;

float PID_Cal(PID_IncTypeDef *pid, int NowValue, int AimValue);

#endif /* PID_H_ */
