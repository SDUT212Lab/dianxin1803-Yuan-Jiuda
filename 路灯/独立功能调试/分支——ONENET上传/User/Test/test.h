#ifndef  __TEST_H
#define	 __TEST_H



#include "stm32f10x.h"



/********************************** �û���Ҫ���õĲ���**********************************/
#define      macUser_ESP8266_ApSsid                       "143633"                //Ҫ���ӵ��ȵ������
#define      macUser_ESP8266_ApPwd                        "123456789"           //Ҫ���ӵ��ȵ����Կ

#define      macUser_ESP8266_TcpServer_IP                 "192.168.43.1"      //Ҫ���ӵķ������� IP
#define      macUser_ESP8266_TcpServer_Port               "8080"               //Ҫ���ӵķ������Ķ˿�



/********************************** �ⲿȫ�ֱ��� ***************************************/
extern volatile uint8_t ucTcpClosedFlag;



/********************************** ���Ժ������� ***************************************/
void ESP8266_update  ( void );
void CONNECT(void);
void ESP8266_Post_OneNet(char *devices_id,char *api_key,char *datastream_id,char *point_value);

#endif

