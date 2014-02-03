#include "MyF4Config.h"

/*****************************************/
/*************ϵͳDMAͨ������*************/
/*****************************************/
void DMA_Config()
{
	DMA_InitTypeDef DMA_InitStructure;
	//��λDMA1��6ͨ��
	DMA_DeInit(DMA1_Stream6);
	DMA_InitStructure.DMA_PeripheralBaseAddr = SRC_Const_Buffer; //���������ַ
	DMA_InitStructure.DMA_MemoryBaseAddr = DST_Buffer; //�����ڴ��ַ
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory;//���赽�ڴ�
	DMA_InitStructure.DMA_BfferSize = BufferSize;//DMA�����С
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Enable;//�����ַ�Ĵ�������
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;//�ڴ��ַ�Ĵ�������
	DMA_InitStructure.DMA_peripheralDataSize = DMA_PeripheralDataSize_Word;//�������ݿ��
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Word;//�ڴ����ݿ��
	DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;//����ģʽ
	DMA_InitStructure.DMA_Priority = DMA_Priority_High;//���ȼ�
	//DMA_InitStructure.DMA_M2M = 
	DMA_Init(DMA1_Stream6);//��ʼ�������õĲ���
	DMA_ITConfig(DMA1_Stream6 , DMA_IT_TC , ENABLE);//����DMA��������ж�
	CurrDataCounter = DMA_GetCurrDataCounter(DMA1_Stream6);//������ǰ����������ֵ
}

/*****************************************/
/*************ϵͳSystick����*************/
/*****************************************/
void SysTick_Conf()
{
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);
	SysTick_SetReload(168);
	SysTick_CounterCmd(SysTick_Counter_Enable);
	SysTick_ITConfig(ENABLE);
}

/*****************************************/
/*************ϵͳNVIC����****************/
/*****************************************/
void NVIC_Config()
{
	NVIC_InitTypeDef   NVIC_InitStructure;
  //NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);         //�����ж����ȼ�����
	NVIC_InitStructure.NVIC_IRQChannel = DMA1_Stream6_IRQn;         //���û���õ�IRQͨ���������stm32f4xx.h
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00; //��ռ���ȼ�Ϊ0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;        //��Ӧ���ȼ�Ϊ0
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;           
  NVIC_Init(&NVIC_InitStructure);                         
}