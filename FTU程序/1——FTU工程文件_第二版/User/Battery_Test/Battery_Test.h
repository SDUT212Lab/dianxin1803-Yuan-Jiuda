#ifndef __Battery_Test_H
#define	__Battery_Test_H


#include "stm32f10x.h"

/*
	注：
	Test_Number为每次检测次数
	Test_Delay 为每次检测时间间隔，单位是毫秒ms
*/

#define    Test_Number                          10
#define    Test_Delay                           1000				//ms


void Battery_Charge_Test(void);
void Battery_Discharge_Test(void);






#endif /* __Battery_Test_H */

