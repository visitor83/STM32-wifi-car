#ifndef _MYF4CONFIG_H_
#define _MYF4CONFIG_H_

#include "stm32f4xx.h"
#include "arm_math.h"
#include "misc.h"
#include <stdarg.h>
#include "stdio.h"

//  ???????
#define my_abs(x)  ((x<0)?(0-(x)):(x))     // ????????
#define my_Nabs(x) ((x<0)?(x):(0-(x)))     // ???????????
//  ??????
#define Max(a,b)   (((a)<(b))?(b):(a))     // ????
#define Min(a,b)   (((a)>(b))?(b):(a))     // ????

enum   dir{d_right,d_left};

/************************************************/
/******************ϵͳ�ӿڶ���******************/
/************************************************/
//״̬�ƽӿڶ���
#define LED            GPIOE          //LED�����ڵ�GPIO�˿�
#define Red            GPIO_Pin_1     //LED�����ڵ�����
//USART1�ӿڶ���
#define COM_PORT1      USART3         //ϵͳ��USART1����ΪCOM1
#define GPIO_USART1    GPIOD          //ϵͳUSART1���ڵ�GPIO�˿�
#define COM1_TX        GPIO_Pin_8      //ϵͳUSART1�ķ�������
#define COM1_RX        GPIO_Pin_9      //ϵͳUSART1�Ľ�������
//USART2�ӿڶ���
#define COM_PORT2      USART3         //ϵͳ��USART2����ΪCOM2
#define GPIO_USART2    GPIOD          //ϵͳUSART2���ڵ�GPIO�˿�
#define COM2_TX        GPIO_Pin_5     //ϵͳUSART2�ķ�������
#define COM2_RX        GPIO_Pin_6     //ϵͳUSART2�Ľ�������

#define    BITBAND(addr, bitnum)    ((addr &0xF0000000)+0x2000000+((addr &0xFFFFF)<<5)+(bitnum<<2)) 
#define MEM_ADDR(addr) *((volatile unsigned long *)(addr)) 

#define BIT_ADDR(addr,bitnum)  MEM_ADDR(BITBAND(addr,bitnum)) 
#define GPIOA_ODR_Addr        (GPIOA_BASE+20)       //0x40020014 
#define GPIOB_ODR_Addr        (GPIOB_BASE+20)       //0x40020414 
#define GPIOC_ODR_Addr        (GPIOC_BASE+20)       //0x40020814 
#define GPIOD_ODR_Addr        (GPIOD_BASE+20)       //0x40020C14 
#define GPIOE_ODR_Addr        (GPIOE_BASE+20)       //0x40021014 
#define GPIOF_ODR_Addr        (GPIOF_BASE+20)       //0x40021414 
#define GPIOG_ODR_Addr        (GPIOG_BASE+20)       //0x40021814 
#define GPIOH_ODR_Addr        (GPIOH_BASE+20)       //0x40021C14 
#define GPIOI_ODR_Addr        (GPIOI_BASE+20)        //0x40022014 
#define GPIOA_IDR_Addr        (GPIOA_BASE+16)       //0x40020010 
#define GPIOB_IDR_Addr        (GPIOB_BASE+16)       //0x40020410 
#define GPIOC_IDR_Addr        (GPIOC_BASE+16)       //0x40020810 
#define GPIOD_IDR_Addr        (GPIOD_BASE+16)       //0x40020C10 
#define GPIOE_IDR_Addr        (GPIOE_BASE+16)        //0x40021010 
#define GPIOF_IDR_Addr        (GPIOF_BASE+16)        //0x40021410 
#define GPIOG_IDR_Addr        (GPIOG_BASE+16)       //0x40021810 
#define GPIOH_IDR_Addr       (GPIOF_BASE+16)     //0x40021C10 
#define GPIOI_IDR_Addr       (GPIOG_BASE+16)      //0x40022010 
#define GPIOAout(n)  BIT_ADDR(GPIOA_ODR_Addr,n)          //GPIOA????? 
#define GPIOAin(n)    BIT_ADDR(GPIOA_IDR_Addr,n)         //GPIOA????? 
#define GPIOBout(n)  BIT_ADDR(GPIOB_ODR_Addr,n)         //GPIOB????? 
#define GPIOBin(n)    BIT_ADDR(GPIOB_IDR_Addr,n)         //GPIOB????? 
#define GPIOCout(n)  BIT_ADDR(GPIOC_ODR_Addr,n)         //GPIOC????? 
#define GPIOCin(n)    BIT_ADDR(GPIOC_IDR_Addr,n)         //GPIOC????? 
#define GPIODout(n)  BIT_ADDR(GPIOD_ODR_Addr,n)          //GPIOD????? 
#define GPIODin(n)    BIT_ADDR(GPIOD_IDR_Addr,n)         //GPIOD????? 
#define GPIOEout(n)  BIT_ADDR(GPIOE_ODR_Addr,n)         //GPIOE????? 
#define GPIOEin(n)    BIT_ADDR(GPIOE_IDR_Addr,n)        //GPIOE????? 
#define GPIOFout(n)  BIT_ADDR(GPIOF_ODR_Addr,n)         //GPIOF????? 
#define GPIOFin(n)    BIT_ADDR(GPIOF_IDR_Addr,n)        //GPIOF????? 
#define GPIOGout(n)  BIT_ADDR(GPIOG_ODR_Addr,n)          //GPIOG????? 
#define GPIOGin(n)     BIT_ADDR(GPIOG_IDR_Addr,n)         //GPIOG????? 
#define GPIOHout(n)  BIT_ADDR(GPIOH_ODR_Addr,n)          //GPIOH????? 
#define GPIOHin(n)    BIT_ADDR(GPIOH_IDR_Addr,n)         //GPIOH????? 
#define GPIOIout(n)  BIT_ADDR(GPIOI_ODR_Addr,n)          //GPIOI????? 
#define GPIOIin(n)   BIT_ADDR(GPIOI_IDR_Addr,n)          //GPIOI????? 

extern u8 recevie_buf[100];
extern u8 recevie_flag;
extern uint8_t recevie_count;


/******************ϵͳ���ú�������**************/
void RCC_Config(void);       //ϵͳʱ������
void LED_Config(void);      //GPIO�˿�����
void USART_Config(void);     //USART�˿�����

/******************���ܺ�������******************/
int fputc(int ch , FILE *f);
void USART_printf(USART_TypeDef* USARTx, uint8_t *Data,...);
void delay_init(void);
void delay_ms(__IO uint32_t nTime);
void delay_us(__IO uint32_t nTime);
void TimingDelay_Decrement(void);




#endif 
