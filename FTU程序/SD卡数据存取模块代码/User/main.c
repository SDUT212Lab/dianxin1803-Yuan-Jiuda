/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   SD卡文件系统例程
  ******************************************************************************
  * @attention
  *
  * 实验平台:野火  STM32 F103-霸道 开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :https://fire-stm32.taobao.com
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
  *                              定义变量
  ******************************************************************************
  */
FATFS fs;													/* FatFs文件系统对象 */
FIL fnew;													/* 文件对象 */
FRESULT res_sd;                /* 文件操作结果 */
UINT fnum;            					  /* 文件成功读写数量 */
BYTE ReadBuffer[1024]={0};        /* 读缓冲区 */
BYTE WriteBuffer[] =              /* 写缓冲区*/
"代码是否正常？123\r\n";  

/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{
	/* 初始化LED */
	LED_GPIO_Config();	
	LED_BLUE;
	USART_Config();	
  
	//在外部SD卡挂载文件系统，文件系统挂载时会对SDIO设备初始化
	f_mount(&fs,"0:",1);
	


	
   f_open(&fnew, "0:FatFs读写测试文件.txt",FA_WRITE|FA_OPEN_ALWAYS );
	
    /* 将指定存储区内容写入到文件内 */
		f_write(&fnew,WriteBuffer,sizeof(WriteBuffer),&fnum);
	f_write(&fnew,WriteBuffer,sizeof(WriteBuffer),&fnum);
	f_write(&fnew,WriteBuffer,sizeof(WriteBuffer),&fnum);
	f_write(&fnew,WriteBuffer,sizeof(WriteBuffer),&fnum);
    f_close(&fnew);
	
	
	
  
	/* 不再使用文件系统，取消挂载文件系统 */
	f_mount(NULL,"0:",1);
  
  /* 操作完成，停机 */
	while(1)
	{
	}
}






///*----------------------- 文件系统测试：写入 -----------------------------*/

//	
//	res_sd = f_open(&fnew, "0:FatFs读写测试文件.txt",FA_CREATE_ALWAYS | FA_WRITE );
//	if ( res_sd == FR_OK )
//	{
//    /* 将指定存储区内容写入到文件内 */
//		res_sd=f_write(&fnew,WriteBuffer,sizeof(WriteBuffer),&fnum);
//    f_close(&fnew);
//	}

//	
///*------------------- 文件系统测试：读出 ------------------------------------*/

//	res_sd = f_open(&fnew, "0:FatFs读写测试文件.txt", FA_OPEN_EXISTING | FA_READ); 	 
//	if(res_sd == FR_OK)
//	{		
//		res_sd = f_read(&fnew, ReadBuffer, sizeof(ReadBuffer), &fnum); 
//    
//    
//	}
//	/* 不再读写，关闭文件 */
//	f_close(&fnew);	


//	

