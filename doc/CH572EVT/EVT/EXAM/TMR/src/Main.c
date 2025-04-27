/********************************** (C) COPYRIGHT *******************************
 * File Name          : Main.c
 * Author             : WCH
 * Version            : V1.0
 * Date               : 2020/08/06
 * Description        : ��ʱ������
 *********************************************************************************
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * Attention: This software (modified or not) and binary are used for 
 * microcontroller manufactured by Nanjing Qinheng Microelectronics.
 *******************************************************************************/

#include "CH57x_common.h"

#define  TIM_MODE      0
#define  PWM_MODE      0
#define  CAP_MODE      0
#define  COUNT_MODE    1
#define  PWM_DMAMODE   0
#define  ENC_MODE      0

__attribute__((aligned(4))) uint32_t CapBuf[100];
__attribute__((aligned(4))) uint32_t PwmBuf[100];

volatile uint8_t capFlag = 0;

#define  g_10us  (FREQ_SYS/100000)

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
    GPIOA_ModeCfg(bRXD_0, GPIO_ModeIN_PU);      // RXD-������������
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
    uint8_t i;

    HSECFG_Capacitance(HSECap_18p);
    SetSysClock(CLK_SOURCE_HSE_PLL_100MHz);

    /* ���ô��ڵ��� */
    DebugInit();
    PRINT("Start @ChipID=%02X %s %s\r\n", R8_CHIP_ID, __DATE__, __TIME__);


#if 1
    GPIOA_ModeCfg(GPIO_Pin_11, GPIO_ModeOut_PP_5mA);


    while(1) {

        GPIOA_SetBits(GPIO_Pin_11);
        mDelaymS(100);
        GPIOA_ResetBits(GPIO_Pin_11);
        mDelaymS(100);
    }
#endif

#if TIM_MODE  /* ��ʱ�����趨100ms��ʱ������IO�����ƣ� PA6-LED */
    GPIOA_SetBits(GPIO_Pin_6);
    GPIOA_ModeCfg(GPIO_Pin_6, GPIO_ModeOut_PP_5mA);
    GPIOA_ResetBits(GPIO_Pin_6);
    while(1);
    TMR_TimerInit(FREQ_SYS / 10);        // ���ö�ʱʱ�� 100ms
    TMR_ITCfg(ENABLE, TMR_IT_CYC_END);    // �����ж�
    PFIC_EnableIRQ(TMR_IRQn);
#endif

#if PWM_MODE /* ��ʱ����PWM��� */

    GPIOA_ResetBits(GPIO_Pin_7); // ����PWM�� PA7
    GPIOA_ModeCfg(GPIO_Pin_7, GPIO_ModeOut_PP_5mA);
    TMR_PWMInit(High_Level, PWM_Times_1);
    TMR_PWMCycleCfg(g_10us * 10); // ���� 100us  ���67108864
    TMR_PWMActDataWidth(g_10us/2 * 10);  // ռ�ձ� 50%, �޸�ռ�ձȱ�����ʱ�رն�ʱ��
    TMR_PWMEnable();
    TMR_Enable();

#endif

#if CAP_MODE                               /* ��ʱ����CAP��׽�� */
    GPIOA_ResetBits(GPIO_Pin_7);           // ���ò�׽�� PA7
    GPIOA_ModeCfg(GPIO_Pin_7, GPIO_ModeIN_PU);

    TMR_CapInit(Edge_To_Edge);
    TMR_CAPTimeoutCfg(0xFFFFFFFF); // ���ò�׽��ʱʱ��
    TMR_DMACfg(ENABLE, (uint16_t)(uint32_t)&CapBuf[0], (uint16_t)(uint32_t)&CapBuf[100], Mode_Single);
    TMR_ITCfg(ENABLE, TMR_IT_DMA_END); // ����DMA����ж�
    PFIC_EnableIRQ(TMR_IRQn);

    while(capFlag == 0);
    capFlag = 0;
    for(i = 0; i < 100; i++)
    {
        PRINT("%08ld ", CapBuf[i] & 0x1ffffff); // 26bit, ���λ��ʾ �ߵ�ƽ���ǵ͵�ƽ
    }
    PRINT("\n");

#endif

#if COUNT_MODE   /* ��ʱ������������ */
    GPIOA_ModeCfg(GPIO_Pin_7, GPIO_ModeIN_PD);

    TMR_EXTSingleCounterInit(FallEdge_To_FallEdge);
    TMR_CountOverflowCfg(1000); // ���ü�������1000

    /* ������������жϣ�����1000�����ڽ����ж� */
    TMR_ClearITFlag(TMR_IT_CYC_END);
    PFIC_EnableIRQ(TMR_IRQn);
    TMR_ITCfg(ENABLE, TMR_IT_CYC_END);

    do
    {
        /* 1s��ӡһ�ε�ǰ����ֵ�������������Ƶ�ʽϸߣ����ܺܿ�����������Ҫ��ʵ������޸� */
        mDelaymS(1000);
        PRINT("=%ld \r\n", TMR_GetCurrentCount());
    } while(1);

#endif

#if PWM_DMAMODE   /* ��ʱ��,DMA PWM.*/
    GPIOA_ModeCfg(GPIO_Pin_7, GPIO_ModeOut_PP_5mA);

    PRINT("TMR DMA PWM\n");
    TMR_PWMCycleCfg(g_10us * 200); // ���� 2000us
    for(i=0; i<50; i++)
    {
      PwmBuf[i]=(g_10us/2 * 10) * i;
    }
    for(i=50; i<100; i++)
    {
      PwmBuf[i]=(g_10us/2 * 10)*(100-i);
    }
    TMR_PWMInit(Low_Level, PWM_Times_16);
    TMR_DMACfg(ENABLE, (uint32_t)&PwmBuf[0], (uint32_t)&PwmBuf[100], Mode_LOOP);
    TMR_PWMEnable();
    TMR_Enable();
    /* ������������жϣ�����100�����ڽ����ж� */
    TMR_ClearITFlag(TMR_IT_DMA_END);
    TMR_ITCfg(ENABLE, TMR_IT_DMA_END);
    PFIC_EnableIRQ(TMR_IRQn);
#endif

#if ENC_MODE   /* ������.*/

    /* ENC���ߵ�ƽ�źţ�����IOΪ�������� */
    GPIOA_ModeCfg(GPIO_Pin_7, GPIO_ModeIN_PD);
    GPIOA_ModeCfg(GPIO_Pin_2, GPIO_ModeIN_PD);

    /* ENCģʽ���ã��趨������ֵΪ���ֵ����T1,T2���ؼ���ģʽ */
    ENC_Config(ENABLE, 0xFFFF, Mode_T1T2);

    /* ��ʾ�������ж� */
    ENC_ITCfg(ENABLE, RB_IE_DIR_INC);       // ʹ��ǰ���ж�
    ENC_ITCfg(ENABLE, RB_IE_DIR_DEC);       // ʹ�ܺ����ж�
    PFIC_EnableIRQ(ENCODE_IRQn);

    /* ��ʾ����������˯�� */
#if 0
    PWR_PeriphWakeUpCfg(ENABLE, RB_SLP_ENC_WAKE, Fsys_Delay_4096);
    PRINT("sleep mode sleep \n");
    DelayMs(2);
    LowPower_Sleep( RB_PWR_RAM12K | RB_PWR_XROM | RB_PWR_EXTEND);
    PRINT("wake.. \n");
#endif

    while(1)
    {
        DelayMs(300);
        PRINT("%d\n", ENC_GetCurrentDir);       // ��ȡ��������ǰ����
        PRINT("cnt:%d\n",ENC_GetCurrentCount);  // ��ȡ��������ǰ����ֵ
    }
#endif

    while(1);
}

/*********************************************************************
 * @fn      TMR_IRQHandler
 *
 * @brief   TMR�жϺ���
 *
 * @return  none
 */
__INTERRUPT
__HIGH_CODE
void TMR_IRQHandler(void) // TMR0 ��ʱ�ж�
{
    if(TMR_GetITFlag(TMR_IT_CYC_END))
    {
        TMR_ClearITFlag(TMR_IT_CYC_END); // ����жϱ�־
#if TIM_MODE
        GPIOA_InverseBits(GPIO_Pin_6);
#endif
#if CAP_MODE
        TMR_ITCfg(DISABLE, TMR_IT_DMA_END);  // ʹ�õ���DMA����+�жϣ�ע����ɺ�رմ��ж�ʹ�ܣ������һֱ�ϱ��жϡ�
        capFlag = 1;
#endif
#if COUNT_MODE
        /* ������������Ӳ���Զ����㣬���¿�ʼ���� */
        /* �û������������Ҫ�Ĵ��� */
#endif
#if PWM_DMAMODE
        TMR_ITCfg(DISABLE, TMR_IT_DMA_END);  // ʹ�õ���DMA����+�жϣ�ע����ɺ�رմ��ж�ʹ�ܣ������һֱ�ϱ��жϡ�
        PRINT("DMA end\n");
        /* DMA ���� */
        /* �û������������Ҫ�Ĵ��� */
#endif
    }
}

/*********************************************************************
 * @fn      ENCODER_IRQHandler
 *
 * @brief   Encoder�жϺ���
 *
 * @return  none
 */
__INTERRUPT
__HIGH_CODE
void ENCODER_IRQHandler( void )
{
    if(ENC_GetITFlag(RB_IF_DIR_INC))
    {
        PRINT("INC\n");
        ENC_ClearITFlag(RB_IF_DIR_INC);
    }
    if(ENC_GetITFlag(RB_IF_DIR_DEC))
    {
        PRINT("DEC\n");
        ENC_ClearITFlag(RB_IF_DIR_DEC);
    }
}
