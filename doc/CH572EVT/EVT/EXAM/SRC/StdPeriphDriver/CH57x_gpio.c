/********************************** (C) COPYRIGHT *******************************
 * File Name          : CH57x_gpio.c
 * Author             : WCH
 * Version            : V1.2
 * Date               : 2021/11/17
 * Description        : source file(ch572/ch570)
 *********************************************************************************
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * Attention: This software (modified or not) and binary are used for 
 * microcontroller manufactured by Nanjing Qinheng Microelectronics.
 *******************************************************************************/

#include "CH57x_common.h"

/*********************************************************************
 * @fn      GPIOA_ModeCfg
 *
 * @brief   GPIOA�˿�����ģʽ����
 *
 * @param   pin     - PA0-PA15
 * @param   mode    - �����������
 *
 * @return  none
 */
void GPIOA_ModeCfg(uint32_t pin, GPIOModeTypeDef mode)
{
    switch(mode)
    {
        case GPIO_ModeIN_Floating:
            R32_PA_PD_DRV &= ~pin;
            R32_PA_PU &= ~pin;
            R32_PA_DIR &= ~pin;
            break;

        case GPIO_ModeIN_PU:
            R32_PA_PD_DRV &= ~pin;
            R32_PA_PU |= pin;
            R32_PA_DIR &= ~pin;
            break;

        case GPIO_ModeIN_PD:
            R32_PA_PD_DRV |= pin;
            R32_PA_PU &= ~pin;
            R32_PA_DIR &= ~pin;
            break;

        case GPIO_ModeOut_PP_5mA:
            R32_PA_PD_DRV &= ~pin;
            R32_PA_DIR |= pin;
            break;

        case GPIO_ModeOut_PP_20mA:
            R32_PA_PD_DRV |= pin;
            R32_PA_DIR |= pin;
            break;

        default:
            break;
    }
}

/*********************************************************************
 * @fn      GPIOA_ITModeCfg
 *
 * @brief   GPIOA�����ж�ģʽ����
 *
 * @param   pin     - PA0-PA15
 * @param   mode    - ��������
 *
 * @return  none
 */
void GPIOA_ITModeCfg(uint32_t pin, GPIOITModeTpDef mode)
{
    switch(mode)
    {
        case GPIO_ITMode_LowLevel: // �͵�ƽ����
            R16_PA_INT_MODE &= ~pin;
            R32_PA_CLR |= pin;
            break;

        case GPIO_ITMode_HighLevel: // �ߵ�ƽ����
            R16_PA_INT_MODE &= ~pin;
            R32_PA_OUT |= pin;
            break;

        case GPIO_ITMode_FallEdge: // �½��ش���
            R16_PA_INT_MODE |= pin;
            R32_PA_CLR |= pin;
            break;

        case GPIO_ITMode_RiseEdge: // �����ش���
            R16_PA_INT_MODE |= pin;
            R32_PA_OUT |= pin;
            break;

        default:
            break;
    }
    R16_PA_INT_IF = pin;
    R16_PA_INT_EN |= pin;
}

/*********************************************************************
 * @fn      GPIOPinRemap
 *
 * @brief   ���蹦������ӳ��
 *
 * @param   s       - �Ƿ�ʹ��ӳ��
 * @param   perph   - д�����ӳ���ϵ�����GPIO_pins_remap_define
 *
 *
 * @return  none
 */
void GPIOPinRemap(FunctionalState s, uint16_t perph)
{
    if(s)
    {
        R16_PIN_ALTERNATE_H |= perph;
    }
    else
    {
        R16_PIN_ALTERNATE_H &= ~perph;
    }
}

/*********************************************************************
 * @fn      GPIOADigitalCfg
 *
 * @brief   I/O pin���ֹ��ܿ���
 *
 * @param   s       - �Ƿ�򿪶�ӦI/O pin���ֹ���
 * @param   pin     - PA0-PA11
 */
void GPIOADigitalCfg(FunctionalState s, uint16_t pin)
{
    if(s)
    {
        R16_PIN_ALTERNATE &= ~pin;
    }
    else
    {
        R16_PIN_ALTERNATE |= pin;
    }
}

