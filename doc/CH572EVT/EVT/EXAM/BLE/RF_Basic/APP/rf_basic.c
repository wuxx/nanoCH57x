/********************************** (C) COPYRIGHT *******************************
 * File Name          : rf_basic.c
 * Author             : WCH
 * Version            : V1.0
 * Date               : 2024/08/15
 * Description        : 2.4G�����ģʽ�շ���������
 *
 *                      ��������
 *                      RFIP_SetTxPower
 *                      1. ֧��-20dBm ~ 4dBm ��̬����
 *
 *                      ����״̬�л��ȶ�ʱ��
 *                      RFIP_SetTxDelayTime
 *                      1.�����Ҫ�л�ͨ�����ͣ��ȶ�ʱ�䲻����80us
 *
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * SPDX-License-Identifier: Apache-2.0
 *******************************************************************************/

/******************************************************************************/
/* ͷ�ļ����� */
#include "rf_basic.h"

/*********************************************************************
 * GLOBAL TYPEDEFS
 */
#define  ALIGNED4(x)       ((x+3)/4*4)

rfipTx_t gTxParam;
rfipRx_t gRxParam;

__attribute__((__aligned__(4))) uint8_t TxBuf[64];
__attribute__((__aligned__(4))) uint8_t RxBuf[264]; // ����DMA buf����С��264�ֽ�

#define  MODE_RX     0
#define  MODE_TX     1

#define  WAIT_ACK         1               // �Ƿ�ʹ��ACK
#define  TEST_DATA_LEN    4               // ���ݳ���
#define  TEST_FREQUENCY   16              // ͨ��Ƶ��

//#define  TEST_MODE     MODE_TX            // ����ģʽ
#define  TEST_MODE     MODE_RX            // ����ģʽ

#define  RF_DEVICE_PERIDOC    1000

uint32_t volatile gTxCount;
uint32_t volatile gRxCount;

/******************************** ������غ��� ********************************/
/**
 * @brief   ���÷��͵�Ƶ��
 *
 * @param   f - ��Ҫ���õ�Ƶ��
 *
 * @return  None.
 */
__HIGH_CODE
void rf_tx_set_frequency( uint32_t f )
{
    gTxParam.frequency = f;
}

/*******************************************************************************
 * @brief   ���÷��͵ĵ�ַ
 *
 * @param   sync_word - ��Ҫ���õĽ����ַ
 *
 * @return  None.
 */
__HIGH_CODE
void rf_tx_set_sync_word( uint32_t sync_word )
{
    gTxParam.accessAddress = sync_word;
}

/*******************************************************************************
 * @brief   rf���������ӳ���
 *
 * @param   pBuf - ���͵�DMA��ַ
 *
 * @return  None.
 */
__HIGH_CODE
void rf_tx_start( uint8_t *pBuf )
{
    //    RFRole_Stop();
    // ���÷��͵�Ƶ��
    gTxParam.frequency = TEST_FREQUENCY;
    // ���͵�DMA��ַ
    gTxParam.txDMA = (uint32_t)pBuf;
    gTxParam.waitTime = 40*2; // �����Ҫ�л�ͨ�����ͣ��ȶ�ʱ�䲻����80us
    RFIP_StartTx( &gTxParam );
}

/******************************** ������غ��� ********************************/
/**
 * @brief   ���ý��յĵ�ַ
 *
 * @param   sync_word - ��Ҫ���õĽ����ַ
 *
 * @return  None.
 */
__HIGH_CODE
void rf_rx_set_sync_word( uint32_t sync_word )
{
    gRxParam.accessAddress = sync_word;
}

/*******************************************************************************
 * @fn      rf_rx_set_frequency
 *
 * @param   f - ��Ҫ���õ�Ƶ��
 *
 * @return  None.
 */
__HIGH_CODE
void rf_rx_set_frequency( uint32_t f )
{
    gRxParam.frequency = f;
}

/*******************************************************************************
 * @fn      rf_rx_start
 *
 * @brief   rf���������ӳ���
 *
 * @return  None.
 */
__HIGH_CODE
void rf_rx_start( void )
{
    // ���÷��͵�Ƶ��
    gRxParam.frequency = TEST_FREQUENCY;
    // ���ý��յĳ�ʱʱ�䣬0���޳�ʱ
    gRxParam.timeOut = 0;
    RFIP_SetRx( &gRxParam );
}

/*******************************************************************************
 * @fn      rf_rx_process_data
 *
 * @brief   rf�������ݴ���
 *
 * @return  None.
 */
__HIGH_CODE
void rf_rx_process_data( void )
{
    gRxCount ++;
    {
        uint8_t *pData = (uint8_t *)gRxParam.rxDMA;
//        PRINT("#R %d\n",(int8_t)pData[1]);
//        for( int i=0;i<4;i++ )
//        {
//            PRINT("%x\t",pData[i]);
//        }
//        PRINT("\n");
    }
}

/*******************************************************************************
 * @fn      LLE_IRQHandler
 *
 * @brief   LLE_IRQHandler
 *
 * @return  None.
 */
__INTERRUPT
__HIGH_CODE
void LLE_IRQHandler( void )
{
    LLE_LibIRQHandler( );
}

/*******************************************************************************
 * @fn      BB_IRQHandler
 *
 * @brief   BB_IRQHandler
 *
 * @return  None.
 */
__INTERRUPT
__HIGH_CODE
void BB_IRQHandler( void )
{
    BB_LibIRQHandler( );
}

/*******************************************************************************
 * @fn      RF_ProcessCallBack
 *
 * @brief   rf�жϴ������
 *
 * @param   sta - �ж�״̬.
 *          id - ����
 *
 * @return  None.
 */
__HIGH_CODE
void RF_ProcessCallBack( rfRole_States_t sta,uint8_t id  )
{
    if( sta&RF_STATE_RX )
    {
        rf_rx_process_data();
#if( TEST_MODE == MODE_RX )
#if( WAIT_ACK )
        TxBuf[0] = 0x0d;
        TxBuf[1] = 0;
        rf_tx_start( TxBuf );
#else
        rf_rx_start( );
#endif
#endif
    }
    if( sta&RF_STATE_RX_CRCERR )
    {
//        PRINT("crc -err.\n");
#if( TEST_MODE == MODE_RX )
        rf_rx_start( );
#else
//        PRINT("nak@crc\n");
#endif
    }
    if( sta&RF_STATE_TX_FINISH )
    {
#if( WAIT_ACK )
        rf_rx_start( );
#endif
        gTxCount ++;
    }
    if( sta&RF_STATE_TIMEOUT )
    {
#if( TEST_MODE ==  MODE_RX )
#if WAIT_ACK
        PRINT("send error.\n");
#endif
        rf_rx_start( );
#endif
    }
}

/*********************************************************************
 * @fn      TMR0_IRQHandler
 *
 * @brief   TMR0�жϺ���
 *
 * @return  none
 */
__INTERRUPT
__HIGH_CODE
void TMR_IRQHandler(void) // TMR ��ʱ�ж�
{
    if(TMR_GetITFlag(TMR_IT_CYC_END))
    {
        TMR_ClearITFlag(TMR_IT_CYC_END); // ����жϱ�־
#if( TEST_MODE == MODE_RX )
        PRINT("rx-%d\n",gRxCount);
        gRxCount = 0;
#else
        // ��ʼ�����͵�����
        TxBuf[0] = TEST_DATA_LEN;
        TxBuf[1] ++;
        TxBuf[2] = 0x02;
        TxBuf[3] = 0x03;
        rf_tx_start( TxBuf );
#endif
    }
}

/*******************************************************************************
 * @fn      RFRole_Init
 *
 * @brief   RFӦ�ò��ʼ��
 *
 * @param   None.
 *
 * @return  None.
 */
void RFRole_Init(void)
{
    sys_safe_access_enable( );
    R32_MISC_CTRL = (R32_MISC_CTRL&(~(0x3f<<24)))|(0xe<<24);
    sys_safe_access_disable( );

#if(PHY_2G4_MODE == 1 )
    PKT_DET_CFG4(0x78);
#endif

    {
        rfRoleConfig_t conf ={0};
        conf.rfProcessCB = RF_ProcessCallBack;
        conf.processMask = RF_STATE_RX|RF_STATE_RX_CRCERR|RF_STATE_TX_FINISH|RF_STATE_TIMEOUT;
        RFRole_BasicInit( &conf );
    }
    TPROPERTIES_CFG Properties;
    {
        Properties.cfgVal = BB_WHITENING_OFF|TEST_PHY_MODE;
#if(TEST_PHY_MODE == PHY_MODE_2G4 )
        Properties.lengthCrc = CRC_LEN;
        Properties.ctlFiled = CTL_FILED;
        Properties.lengthAA = AA_LEN;
        Properties.lengthPreamble = PRE_LEN;
        Properties.dplEnable = DPL_EN;
        Properties.mode2G4 = MODE_2G4;
        Properties.bitOrderData = DATA_ORDER;
        Properties.crcXOREnable = CRC_XOR_EN;
#endif
        PRINT("cfgVal=%x\n",Properties.cfgVal);
    }

    // TX��ز�����ȫ�ֱ���
    {
        gTxParam.accessAddress = AA;
        gTxParam.accessAddressEx = AA_EX;
        gTxParam.crcInit = CRC_INIT;
        gTxParam.crcPoly = CRC_POLY;
        gTxParam.properties = Properties.cfgVal;
        gTxParam.waitTime = 80*2;
        gTxParam.txPowerVal = LL_TX_POWEER_0_DBM;
        gTxParam.txLen = TEST_DATA_LEN;
    }

    // RX��ز�����ȫ�ֱ���
    {
        gRxParam.accessAddress = AA;
        gRxParam.accessAddressEx = AA_EX;
        gRxParam.crcInit = CRC_INIT;
        gRxParam.crcPoly = CRC_POLY;
        gRxParam.properties = Properties.cfgVal;
        gRxParam.rxDMA = (uint32_t)RxBuf;
        gRxParam.rxMaxLen = TEST_DATA_LEN;
    }
    PFIC_EnableIRQ( BLEB_IRQn );
    PFIC_EnableIRQ( BLEL_IRQn );

#if( TEST_MODE == MODE_RX )
    PRINT("----------------- rx -----------------\n");
    gTxCount = 0;
    gRxCount = 0;
    PRINT("start rx...%d\n",GetSysClock());
    rf_rx_start();
    TMR_TimerInit( GetSysClock() / 2 ); // 500msͳ��һ��
    TMR_ITCfg(ENABLE, TMR_IT_CYC_END);  // �����ж�
    PFIC_EnableIRQ(TMR_IRQn);
#else
    PRINT("----------------- tx -----------------\n");
    gTxCount = 0;
    gRxCount = 0;
    PRINT("start tx timer...\n");
    TMR_TimerInit( GetSysClock() / RF_DEVICE_PERIDOC );

    TMR_ITCfg(ENABLE, TMR_IT_CYC_END); // �����ж�
    PFIC_EnableIRQ(TMR_IRQn);
#endif
}

/******************************** endfile @rf ******************************/
