#include "MyF4Config.h"

/*****************************************/
/**************ϵͳGPIO����***************/
/*****************************************/
//������GPIO�˿ڵĸ���
void GPIO_Config()
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	/************����״̬�Ƶ�����*************/	
	//����GPIOE��14�Ų���
	GPIO_InitStructure.GPIO_Pin= Red;                         //ѡ��GPIOE��14��
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;             //����ѡ�е����Ź���ģΪ���ģʽ
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;            //����GPIO�������ʽPP�������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;          //����GPIO��������Ƶ��2MHz
	//��ʼ�������õ�GPIOE����
	GPIO_Init(LED , &GPIO_InitStructure);
	
	/*****************************************/
	/************����USART1������*************/
	/*****************************************/
	//TX
	GPIO_InitStructure.GPIO_Pin = COM1_TX;                //ѡ��GPIOB��6��
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;          //����ѡ�е����Ź���ģʽ��IN������ģʽ��OUT�����ģʽ��AF������ģʽ��AN��ģ��ģʽ
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;        //����GPIO�������ʽ��PP�����������OD����©���
 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;      //����GPIO��������Ƶ��2MHz��25MHz��50MHz ��100MHz 
	GPIO_Init(GPIO_USART1, &GPIO_InitStructure);        //��ʼ�������õ�GPIOD����
  //RX
	GPIO_InitStructure.GPIO_Pin = COM1_RX;                //ѡ��GPIOB��7��
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;          //����ѡ�е����Ź���ģʽ��IN������ģʽ��OUT�����ģʽ��AF������ģʽ��AN��ģ��ģʽ
	//��ʼ�������õ�GPIOB����                            
  GPIO_Init(GPIO_USART1 , &GPIO_InitStructure);
	
	/*****************************************/
	/************����USART2������*************/
	/*****************************************/
	//TX
	GPIO_InitStructure.GPIO_Pin = COM2_TX;                
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;          
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;        
 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;      
	GPIO_Init(GPIO_USART2, &GPIO_InitStructure);       
  //RX
	GPIO_InitStructure.GPIO_Pin = COM2_RX;               
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;          
	//��ʼ�������õ�GPIOB����                            
  GPIO_Init(GPIO_USART2 , &GPIO_InitStructure);        
}

/*****************************************/
/**********ϵͳUSART�˿�����**************/
/*****************************************/
void USART_Config()
{
	USART_InitTypeDef USART_InitStructure;     //����USART��ʼ���ṹ��
	USART_Cmd(COM_PORT1 , DISABLE);          //�رմ���
	//GPIOA��2��3�Ÿ���ΪUSART1������
  GPIO_PinAFConfig(GPIO_USART1 , GPIO_PinSource6 , GPIO_AF_USART1);
  GPIO_PinAFConfig(GPIO_USART1 , GPIO_PinSource7 , GPIO_AF_USART1);
	
	//����1��������
	USART_InitStructure.USART_BaudRate = 115200;                                      //�����ʣ�115200��57600��38400��9600��4800��2400��1200
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;                       //��ʾһ��֡�з��ͻ��߽��յ�������λ
  USART_InitStructure.USART_StopBits = USART_StopBits_1;                            //ֹͣλ
  USART_InitStructure.USART_Parity = USART_Parity_No;                               //��żģʽ
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;   //ʹ�ܻ�ر�Ӳ��������ģʽ
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;                   //ʹ�ܻ�رշ��ͺͽ���ģʽ   

	USART_Init(COM_PORT1 , &USART_InitStructure);
	//ʹ��USART1
	USART_Cmd(COM_PORT1 , ENABLE);
	
	GPIO_PinAFConfig(GPIO_USART2 , GPIO_PinSource5 , GPIO_AF_USART2);
  GPIO_PinAFConfig(GPIO_USART2 , GPIO_PinSource7 , GPIO_AF_USART2);
	
	//����2��������
	USART_InitStructure.USART_BaudRate = 115200;                                        //�����ʣ�115200��57600��38400��9600��4800��2400��1200
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;                       //��ʾһ��֡�з��ͻ��߽��յ�������λ
  USART_InitStructure.USART_StopBits = USART_StopBits_1;                            //ֹͣλ
  USART_InitStructure.USART_Parity = USART_Parity_No;                               //��żģʽ
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;   //ʹ�ܻ�ر�Ӳ��������ģʽ
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;                   //ʹ�ܻ�رշ��ͺͽ���ģʽ   

	USART_Init(COM_PORT2 , &USART_InitStructure);
	//ʹ��USART2
	USART_Cmd(COM_PORT2 , ENABLE);
}
