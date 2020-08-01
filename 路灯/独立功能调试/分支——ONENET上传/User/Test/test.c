#include "test.h"
#include "bsp_esp8266.h"
#include "bsp_SysTick.h"
#include <stdio.h>  
#include <string.h>  
#include <stdbool.h>
#include "bsp_dht11.h"

char b[10];
char o,p,q,r,s,t,u;
char e,f;
int flag=0;
int flag1=0;
char *temp;
volatile uint8_t ucTcpClosedFlag = 0;
void HMISends(char *buf1)	;
char cStr [ 1500 ] = { 0 };
	char *devices_id="571226692";
	char *api_key="140LbO7t=U35hHD1VkxOFNU0a7g=";
	char *datastream_id="pm10";
	char *point_value="888";
/*��������״̬*/
 void  bianbie(char *a)
{
if(strcmp(a,"Sunny")==0||strcmp(a,"Clear")==0)
{
	macPC_Usart ( "%s","��");
flag=0;
}
else if(strcmp(a,"Cloudy")==0)
{
 macPC_Usart ( "%s","����");
flag=1;
}
else if(strcmp(a,"Partly Cloudy")==0)
  macPC_Usart ( "%s","������");
else if(strcmp(a,"Mostly Cloudy")==0)
  macPC_Usart ( "%s","�󲿶���");
else if(strcmp(a,"Overcast")==0)
  macPC_Usart ( "%s","��");
else if(strcmp(a,"Shower ")==0)
  macPC_Usart ( "%s","����");
else if(strcmp(a,"Thundershower")==0)
  macPC_Usart ( "%s","������");
else if(strcmp(a,"Thundershower with Hail")==0)
  macPC_Usart ( "%s","��������б���");
else if((strcmp(a,"Light Rain")==0)||(strcmp(a,"Light rain")==0))
{macPC_Usart ( "%s","С��");
flag=5;}
else if((strcmp(a,"Moderate Rain")==0)||(strcmp(a,"Moderate rain")==0))
{ macPC_Usart ( "%s","����");
flag=6;
}
else if((strcmp(a,"Heavy Rain")==0)||(strcmp(a,"Heavy rain")==0))
{ macPC_Usart ( "%s","����");
flag=4;
}
else if(strcmp(a,"Storm")==0)
  macPC_Usart ( "%s","����");
else if(strcmp(a,"Dust")==0)
  macPC_Usart ( "%s","����");
else if(strcmp(a,"Sand")==0)
  macPC_Usart ( "%s","��ɳ");
else if(strcmp(a,"Duststorm")==0)
  macPC_Usart ( "%s","ɳ����");
else if(strcmp(a,"Sandstorm")==0)
  macPC_Usart ( "%s","ǿɳ����");
else if(strcmp(a,"Foggy")==0)
{ macPC_Usart ( "%s","��");
flag=2;
}
else if(strcmp(a,"Haze")==0)
{ macPC_Usart ( "%s","��");
flag=3;
}
else if(strcmp(a,"Windy")==0)
  macPC_Usart ( "%s","��");
else if(strcmp(a,"Blustery")==0)
  macPC_Usart ( "%s","���");
else if(strcmp(a,"Hurricane")==0)
  macPC_Usart ( "%s","쫷�");
else if(strcmp(a,"Tropical Storm")==0)
  macPC_Usart ( "%s","�ȴ��籩");
else if(strcmp(a,"Tornado")==0)
  macPC_Usart ( "%s","�����");
else if(strcmp(a,"Cold")==0)
  macPC_Usart ( "%s","��");
else if(strcmp(a,"Hot")==0)
  macPC_Usart ( "%s","��");
else 
	macPC_Usart ( "%s",a);
}
/***************��ȡ�ַ���������������ʽ��ӡ********************/

void jiequ(int a2,char*b2,int c)
{
		int i=0,m=0,k=0;
	printf("t%d.txt=\"",c);
	 while(b2[i])
	 {
				 if(b2[i++]=='"')
					 m++;
				if(m==a2)
				{
					while(b2[i]!='"')
						{	
							 b[k++]=b2[i++]; 
						}
						b[k]='\0';
						bianbie(b);
									    printf("\"");
			    printf("\xff\xff\xff");
						switch(flag)
						{
							case 0:     																															  break;//��
							case 1:    printf("p%d.pic=1",flag1); printf("\xff\xff\xff");   break;//����
							case 2:    printf("p%d.pic=6",flag1); printf("\xff\xff\xff"); break;//��11
							case 3:    printf("p%d.pic=3",flag1); printf("\xff\xff\xff");   break;//����5
							case 4:    printf("p%d.pic=4",flag1); printf("\xff\xff\xff");   break;//����6
							case 5:    printf("p%d.pic=7",flag1); printf("\xff\xff\xff"); break;//С��12
							case 6:    printf("p%d.pic=5",flag1); printf("\xff\xff\xff");   break;//����9	
						}
							flag=0;
						return ;
				}		
	}
}
/**************ͨ��ESP8266����API�ӿ�*****************/
void CONNECT(void)
{
	ESP8266_Rst();	
	
	macESP8266_CH_ENABLE();
	ESP8266_AT_Test ();
	ESP8266_Net_Mode_Choose ( STA ); 
  while ( ! ESP8266_JoinAP ( macUser_ESP8266_ApSsid, macUser_ESP8266_ApPwd ) );	
	ESP8266_Enable_MultipleId ( DISABLE );
	while ( ! ESP8266_Link_Server ( enumTCP, "183.230.40.33", "80", Single_ID_0 ) );
}

void ESP8266_Post_OneNet(char *devices_id,char *api_key,char *datastream_id,char *point_value)
{
  
	char cStr [ 1500 ] = { 0 };
		    
    u16 length=0;
    char post_str[100]={0};  
    char *post_p1=0;
    char *post_p2=0;
    char check[1]={0};
            sprintf((char*)post_str,"{\"%s\":%s}",datastream_id,point_value);
            length = strlen(post_str);
            sprintf ( cStr,"POST /devices/%s/datapoints?type=3 HTTP/1.1\r\napi-key: %s\r\nHost: api.heclouds.com\r\nContent-Length: %d\r\n\r\n%s",devices_id,api_key,length,post_str );
        if(ESP8266_Get_LinkStatus()==3)
    {       
 			ESP8266_UnvarnishSend ();	//͸������
           
            ESP8266_SendString ( ENABLE, cStr, 0, Single_ID_0 );
            Delay_ms ( 500 );
            if((post_p1=(char*)strstr((const char*)strEsp8266_Fram_Record .Data_RX_BUF,"errno")),(post_p1!=NULL)) //Ѱ��POST��OneNet���صĿ�ʼ��
            {
                if((post_p2=(char*)strstr((const char*)post_p1,"}")),(post_p2!=NULL))//Ѱ��POST��OneNet���صĽ�����
                {
                    post_p2=strtok((post_p1),":");
                    post_p2=(char*)strtok(NULL,",");
                    sprintf((char*)check,"%s",post_p2);
                    if(check[0]=='0')//�ж�OneNET�Ƿ���յ������ˣ�errno:0��ʾ�޴���OneNET���յ�����
                    {   
                        printf("\r\nOneNET���յ�����!\r\n");
                    }
                    else
                        printf("\r\nOneNETû�н��յ�����!\r\n");
                }
            }
                        ESP8266_ExitUnvarnishSend (); //�˳�͸��
                        ESP8266_Cmd ( "AT+CIPMODE=0", "OK", 0, 200 );//�ر�͸��ģʽ
    }
        
  else{
      //
       ESP8266_ExitUnvarnishSend (); //�˳�͸��
       ESP8266_Cmd ( "AT+CIPMODE=0", "OK", 0, 200 );//�ر�͸��ģʽ
      printf("�������ӡ�������");
  while ( ! ESP8266_JoinAP ( macUser_ESP8266_ApSsid, macUser_ESP8266_ApPwd ) );	
            
	while ( ! ESP8266_Link_Server ( enumTCP, "183.230.40.33", "80", Single_ID_0 ) );
           }  
		
	}

	
extern	char *yjd;
extern	char *valuee;
void ESP8266_update ( void )
{
	 
	CONNECT();
//���������벻ͬ��������
ESP8266_Post_OneNet(devices_id,api_key,datastream_id,point_value);
ESP8266_Post_OneNet(devices_id,api_key,yjd,valuee);

}
