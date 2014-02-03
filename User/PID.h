//*********************************************************************
//
//  Copyright (c) UESTC Roboteam 2011 �� All rights reserved.
// 
//  PID.H - PID�㷨�ļ�
//
//      ���ļ��ǵ��ӿƼ�����������Ѳ�߻����˴���������ί���ṩ��ģ��
//  �����PID�㷨ͷ�ļ����û���ֱ�ӵ������еĺ������㷨�����ʼ����
//  ��ͳһ�����μ��㣬���Ч�ʡ�
//
//  2011��10��29��
//
//********************************************************************

#ifndef _PID_H_
#define _PID_H_
#include "MyF4Config.h"


// ���º궨�����û����ݻ����˵����趨
#define epsilon   2           // ����������ֵ
#define dt        1       // ��������
#define MAX       9000           // ����������
#define MIN       -9000          // ��С�������
static float Kp = 1000   ;      // ����ϵ��
static float Kd = 2500    ;    // ΢��ϵ��
static float Ki   =     0 ;      // ����ϵ��



float PIDcal(float setpoint,float actual_position)
{
	static float pre_error = 0;         // ����ǰһ�����
	static float integral = 0;          // ����������ۼ�ֵ
	float error;                        // �����������
	float derivative;                   // ����΢����
	float output;                       // �������

	// �������
	error = setpoint -actual_position;

	// �����������ã�����С������²������ִ�����֤�ȶ���
	if(my_abs(error) > epsilon)
	{
	   integral = integral + error*dt;   // ������
	}

	derivative = (error - pre_error)/dt; // ΢����

	output = Kp*error + Ki*integral + Kd*derivative; // �������ϵ���õ�PID���

	// ����޷���ȷ���������̫����
	if(output > MAX)
	{
		output = MAX;
	}
	else if(output < MIN)
	{
		output = MIN;
	}

        // �������
        pre_error = error;

        return output;
}



void Change_mypid(u8 which,float value)
{
				switch(which)
		  	{
					case 1:
					{
						Kp = value;		
				    break;
					}
					case 2:
					{
						Kd = value;		
				    break;
					}
				 case 3:
					{
						Ki = value;		
				    break;
					}
		    }
}
#endif 

//************************* End File *********************************
