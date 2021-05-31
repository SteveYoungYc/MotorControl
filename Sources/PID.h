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
    float Kp; //����ϵ��Proportional
    float Ki; //����ϵ��Integral
    float Kd; //΢��ϵ��Derivative

    float Ek;  //��ǰ���
    float Ek1; //ǰһ����� e(k-1)
    float Ek2; //��ǰһ����� e(k-2)

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
    float Integral;    //λ��ʽPID������
    float IntegralMax; //λ��ʽPID���������ֵ�������޷�
#endif
    float Last_Error; //��һ�����
    float OutputMax;  //λ��ʽPID������ֵ�������޷�
    float OutputMin;
} PID_IncTypeDef;

float PID_Cal(PID_IncTypeDef *pid, int NowValue, int AimValue);

#endif /* PID_H_ */
