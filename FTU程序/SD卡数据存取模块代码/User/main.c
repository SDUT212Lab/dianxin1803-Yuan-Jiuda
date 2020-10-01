/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   SD���ļ�ϵͳ����
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:Ұ��  STM32 F103-�Ե� ������ 
  * ��̳    :http://www.firebbs.cn
  * �Ա�    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */
#include "stm32f10x.h"
#include "./sdio/bsp_sdio_sdcard.h"
#include "./usart/bsp_usart.h"	
#include "./led/bsp_led.h"
#include "ff.h"

/**
  ******************************************************************************
  *                              �������
  ******************************************************************************
  */
FATFS fs;													/* FatFs�ļ�ϵͳ���� */
FIL fnew;													/* �ļ����� */
FRESULT res_sd;                /* �ļ�������� */
UINT fnum;            					  /* �ļ��ɹ���д���� */
BYTE ReadBuffer[1024]={0};        /* �������� */
BYTE WriteBuffer[] =              /* д������*/
"�����Ƿ�������123\r\n";  

/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */
int main(void)
{
	/* ��ʼ��LED */
	LED_GPIO_Config();	
	LED_BLUE;
	USART_Config();	
  
	//���ⲿSD�������ļ�ϵͳ���ļ�ϵͳ����ʱ���SDIO�豸��ʼ��
	f_mount(&fs,"0:",1);
	


	
   f_open(&fnew, "0:FatFs��д�����ļ�.txt",FA_WRITE|FA_OPEN_ALWAYS );
	
    /* ��ָ���洢������д�뵽�ļ��� */
		f_write(&fnew,WriteBuffer,sizeof(WriteBuffer),&fnum);
	f_write(&fnew,WriteBuffer,sizeof(WriteBuffer),&fnum);
	f_write(&fnew,WriteBuffer,sizeof(WriteBuffer),&fnum);
	f_write(&fnew,WriteBuffer,sizeof(WriteBuffer),&fnum);
    f_close(&fnew);
	
	
	
  
	/* ����ʹ���ļ�ϵͳ��ȡ�������ļ�ϵͳ */
	f_mount(NULL,"0:",1);
  
  /* ������ɣ�ͣ�� */
	while(1)
	{
	}
}






///*----------------------- �ļ�ϵͳ���ԣ�д�� -----------------------------*/

//	
//	res_sd = f_open(&fnew, "0:FatFs��д�����ļ�.txt",FA_CREATE_ALWAYS | FA_WRITE );
//	if ( res_sd == FR_OK )
//	{
//    /* ��ָ���洢������д�뵽�ļ��� */
//		res_sd=f_write(&fnew,WriteBuffer,sizeof(WriteBuffer),&fnum);
//    f_close(&fnew);
//	}

//	
///*------------------- �ļ�ϵͳ���ԣ����� ------------------------------------*/

//	res_sd = f_open(&fnew, "0:FatFs��д�����ļ�.txt", FA_OPEN_EXISTING | FA_READ); 	 
//	if(res_sd == FR_OK)
//	{		
//		res_sd = f_read(&fnew, ReadBuffer, sizeof(ReadBuffer), &fnum); 
//    
//    
//	}
//	/* ���ٶ�д���ر��ļ� */
//	f_close(&fnew);	


//	

