//*********************************************************************
//
//  Copyright (c) UESTC Roboteam 2011 �� All rights reserved.
// 
//  Sensor.c - ��������غ����ļ�
//
//      ���ļ��ǵ��ӿƼ�����������Ѳ�߻����˴���������ί���ṩ��ģ��
//  ����Ĵ�������غ����ļ����û�����������ĸ���������ʼ������ȡ��
//  ������������ʹ�á�
//
//  2011��10��29��
//
//********************************************************************

#include "MyF4Config.h"

extern enum dir direction;
#define lled  GPIOAin(1) 
#define mled 	GPIOAin(2) 
#define rled 	GPIOAin(3) 
//********************************************************************
// ������: SensorInit() 
// ˵  ��: ��������ȡ�˿ڵĳ�ʼ������
// ʱ  ��: 2011.10.29  
// ��  ��: ��
// ��  ��: ��
// ��  ��: ��
// ע  ��: 
//********************************************************************    
// �޸���:
// ʱ  ��:
// ��  ��:
//********************************************************************
void SensorInit(void)
{

   // ******* �û���Ӷ�ȡѲ�ߴ�������IO�ڳ�ʼ������ ********

   // ******* �û���ӱ��ϴ���������IO�ڵ��ж����ô��� ********
   // ˵�������ϴ�����ʹ��IO�ж϶�ȡ�������ӦЧ�ʡ�
   //       �����ж�ע��
		GPIO_InitTypeDef  GPIO_InitStructure;
	
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;             //����ѡ�е����Ź���ģΪ���ģʽ
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;            //����GPIO�������ʽPP�������
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;	
  	GPIO_Init(GPIOD, &GPIO_InitStructure); 
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;	
  	GPIO_Init(GPIOC, &GPIO_InitStructure); 
}


//********************************************************************
// ������: SensorRead() 
// ˵  ��: ��������ȡ�˿ڵĳ�ʼ������
// ʱ  ��: 2011.10.29  
// ��  ��: flag���ж�֮ǰ���������0����ֱ�ߣ����򣺹ս�
// ��  ��: ��
// ��  ��: pathinfo ��������ƫ����ߵ������
//                    0 :��ƫ��
//                    ��:��ƫ��Խ��Խ�󣬴�ʱ�ұߴ�����ѹ����
//                    ��:��ƫ��Խ��Խ�ң���ʱ��ߴ�����ѹ����
// ע  ��: ע�ⷽ�򣡣���
//********************************************************************    
// �޸���:
// ʱ  ��:
// ��  ��:
//********************************************************************

//4 3 2 1          8 7 6 5         10 9 8 7          15 14 13 12 11
//     



int16_t SensorRead(int16_t flag)
{
   int16_t pathinfo,put = 0;
   pathinfo =(GPIOD->IDR & 0x00ff) | (GPIOC->IDR & 0xff00);
	 if(pathinfo & 0x08)
		 put=16;
	 else	 if(pathinfo & 0x04)
		 put=13;
//	 else  if(pathinfo & 0x02)
//		 put=9;
	 else  if(pathinfo & 0x01)
		 put=9;
	 else  if(pathinfo & 0x80)
		 put=3;
	 else  if(pathinfo & 0x40)
		 put=2;	 
	 else  if(pathinfo & 0x20)
		 put=1;	 
		if(pathinfo & 0x1000)
		 put=-16;
	 else	 if(pathinfo & 0x2000)
		 put=-13;
	 else  if(pathinfo & 0x4000)
		 put=-11;
	 else  if(pathinfo & 0x8000)
		 put=-9;
	 else  if(pathinfo & 0x0100)
		 put=-3;	  
	 else  if(pathinfo & 0x0200)
		 put=-2;
	 else  if(pathinfo & 0x0400)
		 put=-1;	 
	 
	pathinfo = pathinfo | 0x02;
	 
	 
  switch(pathinfo & 0xffff)      // ���ݵ�ƽ�жϻ����˵�ƫ�������������Ӧ��ֵ
   {
		 case 0x0002: 
		 {
		 if(flag<-4)
			 put=-10;
		 else if(flag < 4 && flag > -4)
			 put = 0;
		 else
			 put=10;
		 }
		 break; 	//ȫ���� ʮ��·�� ̽��ʲô�� ���޸�
		 case 0xffff: 
		 {
			 put=0;	 break; 	//ȫ���� ʮ��·�� ̽��ʲô�� ���޸�
		 }
		 default: break; 
   }  
	 if(pathinfo & 0xff00 == 0xff00)
		 put =0;
	 else if(pathinfo & 0x00ff == 0x00ff)
		 put =0;	 
	 else if(my_abs(put)>6)
	 {
		 if(pathinfo & 0x10)
		 put=0;	
		 else  if(pathinfo & 0x0800)
		 put=0;	
		 		 else  if(pathinfo & 0x0400)
		 put=0;	
				 		 		 else  if(pathinfo & 0x20)
		 put=0;	
	 }
		return put;
}


//********************************************************************
// ������: IntDodge() 
// ˵  ��: �����жϷ�����
// ʱ  ��: 2011.10.29  
// ��  ��: ��
// ��  ��: ��
// ��  ��: ��
// ע  ��: ע�ⷽ�򣡣���
//********************************************************************    
// �޸���:
// ʱ  ��:
// ��  ��:
//********************************************************************
/*void IntDodge(void)
{
  // ******** �û���ӱ��ϴ��� *********
}
*/

//************************* End File *********************************
