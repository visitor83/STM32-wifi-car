#include "MyF4Config.h"
/*****************************************/
/*****************LED����*****************/
/*****************************************/
void LED_Config()
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	/************����״̬�Ƶ�����*************/	
	//����GPIOE��14�Ų���
	GPIO_InitStructure.GPIO_Pin= GPIO_Pin_8;                         //ѡ��GPIOE��14��
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;             //����ѡ�е����Ź���ģΪ���ģʽ
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;            //����GPIO�������ʽPP�������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;          //����GPIO��������Ƶ��2MHz
	//��ʼ�������õ�GPIOE����
	GPIO_Init(GPIOA , &GPIO_InitStructure);
}

