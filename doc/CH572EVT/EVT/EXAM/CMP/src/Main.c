/********************************** (C) COPYRIGHT *******************************
 * File Name          : Main.c
 * Author             : WCH
 * Version            : V1.0
 * Date               : 2025/01/21
 * Description        : �Ƚ���������ʾ
 *********************************************************************************
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * Attention: This software (modified or not) and binary are used for 
 * microcontroller manufactured by Nanjing Qinheng Microelectronics.
 *******************************************************************************/

#include "CH57x_common.h"

volatile uint8_t cmp_Itfalg = 0;
const CMPOutSelTypeDef ITMode = cmp_out_sel_rise;

#define OUT_TO_TIM_CAP  1
/*********************************************************************
 * @fn      main
 *
 * @brief   ������
 *
 * @return  none
 */
int main()
{
    HSECFG_Capacitance( HSECap_18p );
    SetSysClock( CLK_SOURCE_HSE_PLL_100MHz );

    /* ���ô���1��������IO��ģʽ�������ô��� */
    GPIOA_SetBits( bTXD_0 );
    GPIOA_ModeCfg( bTXD_0, GPIO_ModeOut_PP_5mA );          // TXD-�������������ע������IO������ߵ�ƽ
    UART_Remap(ENABLE, UART_TX_REMAP_PA3, UART_RX_REMAP_PA2);
    UART_DefInit();
    PRINT( "Start @ChipID=%02X\n", R8_CHIP_ID );

    CMP_Init( cmp_sw_3, cmp_nref_level_800 );  //�ڲ��ο���ѹ��λ800mv

    CMP_INTCfg( ITMode, ENABLE );
    CMP_ClearITStatus();
    PFIC_EnableIRQ( CMP_IRQn );

#if OUT_TO_TIM_CAP //�Ƚ����������ʱ������
    CMP_OutToTIMCAPCfg( ENABLE );
    TMR_CAPTimeoutCfg( 0xFFFFFFFF ); // ���ò�׽��ʱʱ��
    R8_TMR_INT_FLAG |= RB_TMR_IF_DATA_ACT;
    TMR_CapInit( RiseEdge_To_RiseEdge );
#endif

    CMP_Enable();
    while (1)
    {
        if (cmp_Itfalg)
        {
            DelayUs (1);
            if (CMP_ReadAPROut())
            {
                PRINT ("CMP_1\n");
            }
            else
            {
                PRINT ("CMP_0\n");
            }
            cmp_Itfalg = 1;
            CMP_INTCfg (ITMode, ENABLE);
        }
#if OUT_TO_TIM_CAP
        if (R8_TMR_INT_FLAG & RB_TMR_IF_DATA_ACT)
        {
            R8_TMR_INT_FLAG |= RB_TMR_IF_DATA_ACT;
            PRINT ("c:%ld\r\n", R32_TMR_FIFO);
        }
#endif
    }
}

/*********************************************************************
 * @fn      CMP_IRQHandler
 *
 * @brief   CMP�жϺ���
 *
 * @return  none
 */
__INTERRUPT
__HIGH_CODE
void CMP_IRQHandler( void )
{
    if( CMP_GetITStatus() )
    {
        CMP_ClearITStatus();
        CMP_INTCfg( ITMode, DISABLE );
        cmp_Itfalg = 1;
    }
}
