#ifndef __Battery_Test_H
#define	__Battery_Test_H


#include "stm32f10x.h"

/*
	ע��
	Test_NumberΪÿ�μ�����
	Test_Delay Ϊÿ�μ��ʱ��������λ�Ǻ���ms
*/

#define    Test_Number                          10
#define    Test_Delay                           1000				//ms


void Battery_Charge_Test(void);
void Battery_Discharge_Test(void);






#endif /* __Battery_Test_H */

