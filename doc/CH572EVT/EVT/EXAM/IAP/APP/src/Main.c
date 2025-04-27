/********************************** (C) COPYRIGHT *******************************
 * File Name          : Main.c
 * Author             : WCH
 * Version            : V1.0
 * Date               : 2022/03/15
 * Description        : USB IAP APP����
 *********************************************************************************
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * Attention: This software (modified or not) and binary are used for 
 * microcontroller manufactured by Nanjing Qinheng Microelectronics.
 *******************************************************************************/

#include "CH57x_common.h"
#include "app_flag.h"

/*********************************************************************
 * @fn      DebugInit
 *
 * @brief   ���Գ�ʼ��
 *
 * @return  none
 */
void DebugInit(void)
{
    GPIOA_SetBits(bTXD_0);
    GPIOA_ModeCfg(bTXD_0, GPIO_ModeOut_PP_5mA); // TXD-�������������ע������IO������ߵ�ƽ
    UART_Remap(ENABLE, UART_TX_REMAP_PA3, UART_RX_REMAP_PA2);
    UART_DefInit();
}

/*********************************************************************
 * @fn      main
 *
 * @brief   ������
 *
 * @return  none
 */
int main()
{
    uint16_t i = 0;
    uint8_t  s = 0;

    LClk_Cfg(ENABLE);
    HSECFG_Capacitance(HSECap_18p);
    SetSysClock(CLK_SOURCE_HSE_PLL_100MHz);
    RTC_InitClock(Count_64);

    /* ���ô��ڵ��� */
    DebugInit();
    PRINT("Start @ChipID=%02x\n", R8_CHIP_ID);
    /* app�������ִ�и���䣬��֤app����ʧ��ʱ���´���Ȼ����IAP */
    SwitchImageFlag(FLAG_USER_CALL_APP);

    GPIOA_ModeCfg(GPIO_Pin_4, GPIO_ModeIN_PU);
    while (1)
    {
		PRINT("i:%d\n",i);
		i++;
		DelayMs(10);
		if (GPIOA_ReadPortPin(GPIO_Pin_4) == 0)
		{
			s++;
			//�������μ�⵽�������£���ת��IAP
			if(s >= 2)
			{
				jumpToIap();
			}
		}
		else
		{
			s = 0;
		}
		DelayMs(100);
    }
}
