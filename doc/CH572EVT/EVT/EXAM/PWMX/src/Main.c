/********************************** (C) COPYRIGHT *******************************
 * File Name          : Main.c
 * Author             : WCH
 * Version            : V1.0
 * Date               : 2020/08/06
 * Description 		   : PWM1-5������ʾ
 *********************************************************************************
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * Attention: This software (modified or not) and binary are used for 
 * microcontroller manufactured by Nanjing Qinheng Microelectronics.
 *******************************************************************************/

#include "CH57x_common.h"

#define  PWM8     1
#define  PWM16    0


/*********************************************************************
 * @fn      main
 *
 * @brief   ������
 *
 * @return  none
 */
int main()
{
    HSECFG_Capacitance(HSECap_18p);
    SetSysClock(CLK_SOURCE_HSE_PLL_100MHz);

#if PWM8

    /* ����GPIO */
    GPIOA_ModeCfg(GPIO_Pin_7, GPIO_ModeOut_PP_5mA);  // PA7 - PWM1
    GPIOA_ModeCfg(GPIO_Pin_2, GPIO_ModeOut_PP_5mA);  // PA2 - PWM2
    GPIOA_ModeCfg(GPIO_Pin_3, GPIO_ModeOut_PP_5mA);  // PA3 - PWM3
    GPIOA_ModeCfg(GPIO_Pin_4, GPIO_ModeOut_PP_5mA);  // PA4 - PWM4
    GPIOA_ModeCfg(GPIO_Pin_8, GPIO_ModeOut_PP_5mA);  // PA8 - PWM5

    PWMX_CLKCfg(4);                                  // cycle = 4/Fsys
    PWMX_CycleCfg(PWMX_Cycle_64);                    // ���� = 64*cycle

    PWMX_ACTOUT(CH_PWM1, 64 / 4, Low_Level, ENABLE);  // 25% ռ�ձ�
    PWMX_ACTOUT(CH_PWM2, 64 / 4, Low_Level, ENABLE);  // 25% ռ�ձ�
    PWMX_ACTOUT(CH_PWM3, 64 / 4, Low_Level, ENABLE);  // 25% ռ�ձ�
    PWMX_ACTOUT(CH_PWM4, 64 / 4, Low_Level, ENABLE);  // 25% ռ�ձ�
    PWMX_ACTOUT(CH_PWM5, 64 / 4, Low_Level, ENABLE);  // 25% ռ�ձ�

#endif

#if PWM16

    /* ����GPIO */
    GPIOA_ModeCfg(GPIO_Pin_7, GPIO_ModeOut_PP_5mA);  // PA7 - PWM1
    GPIOA_ModeCfg(GPIO_Pin_2, GPIO_ModeOut_PP_5mA);  // PA2 - PWM2
    GPIOA_ModeCfg(GPIO_Pin_3, GPIO_ModeOut_PP_5mA);  // PA3 - PWM3
    GPIOA_ModeCfg(GPIO_Pin_4, GPIO_ModeOut_PP_5mA);  // PA4 - PWM4
    GPIOA_ModeCfg(GPIO_Pin_8, GPIO_ModeOut_PP_5mA);  // PA8 - PWM5

    PWMX_CLKCfg(4);                                   // cycle = 4/Fsys
    PWM_16bit_CycleEnable();                          // 16λ��ʹ��
    PWMX_16bit_CycleCfg(CH_PWM_ALL, 60000);           // 16 ���ݿ��ʱ��PWMʱ������
    PWMX_16bit_ACTOUT(CH_PWM1, 30000, Low_Level, ENABLE);  // 50%ռ�ձ�
    PWMX_16bit_ACTOUT(CH_PWM2, 15000, Low_Level, ENABLE);  // 25%ռ�ձ�
    PWMX_16bit_ACTOUT(CH_PWM3, 45000, Low_Level, ENABLE);  // 75%ռ�ձ�
    PWMX_16bit_ACTOUT(CH_PWM4, 30000, High_Level, ENABLE); // 50%ռ�ձ�
    PWMX_16bit_ACTOUT(CH_PWM5, 15000, High_Level, ENABLE); // 25%ռ�ձ�

#endif

    while(1);
}
