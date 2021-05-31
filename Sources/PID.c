/*
 * PID.c
 *
 *  Created on: May 17, 2021
 *      Author: Yc
 */
#include "PID.h"

#define PID_INTEGRAL_ON

float PID_Cal(PID_IncTypeDef *pid, int NowValue, int AimValue)
{

    float iError, //当前误差
        Output;   //控制输出

    iError = AimValue - NowValue; //计算当前误差

#ifdef PID_INTEGRAL_ON
    pid->Integral += pid->I * iError;                                                      //位置式PID积分项累加
    pid->Integral = pid->Integral > pid->IntegralMax ? pid->IntegralMax : pid->Integral;   //积分项上限幅
    pid->Integral = pid->Integral < -pid->IntegralMax ? -pid->IntegralMax : pid->Integral; //积分项下限幅
#endif

    Output = pid->P * iError                        //比例P
             + pid->D * (iError - pid->Last_Error); //微分D

#ifdef PID_INTEGRAL_ON
    Output += pid->Integral; //积分I
#endif

    Output = Output > pid->OutputMax ? pid->OutputMax : Output;   //控制输出上限幅
    Output = Output < pid->OutputMin ? pid->OutputMin : Output; //控制输出下限幅

    pid->Last_Error = iError; //更新上次误差，用于下次计算
    return Output;            //返回控制输出值
}
