/*#include "MyF4Config.h"   //ͷ�ļ�  ��ֲ�Ļ���ô�����ý��˰�


#define USE_FLASH   //��STM32�û���ע�� ����ʹ��FLASH���������и���
#define PRINTF(Data,value)   USART_printf( USART3, Data,value) 
#define SCANF        




void Insert_param(uint8_t *name,u32 value) //
void communication_checkEvent();






#ifdef USE_FLASH


//�����б�  ����Ҳ��д�ɺ�������ɾ���ĸ�ʽ�� ��������̫�鷳 
typedef struct
{
    float acc_offset[3];
    float acc_gain[3];
    float gyr_offset[3];
    float gyr_gain[3];
    float mag_offset[3];
    float mag_gain[3];
} param_t;
static param_t param_ram;
static const param_t * param_flash = (const param_t *)PARAM_FLASH_ADDRESS;

int32_t flash_erase(const uint32_t * page);
int32_t flash_write(const uint32_t * target,const uint32_t * source,int32_t length);


#endif /* USE_FLASH */ */