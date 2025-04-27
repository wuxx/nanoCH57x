/********************************** (C) COPYRIGHT *******************************
 * File Name          : Main.c
 * Author             : WCH
 * Version            : V1.0
 * Date               : 2022/03/15
 * Description        : USB IAP����
 *********************************************************************************
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * Attention: This software (modified or not) and binary are used for 
 * microcontroller manufactured by Nanjing Qinheng Microelectronics.
 *******************************************************************************/

#include "CH57x_common.h"
#include "iap.h"

/*********************************************************************
 * @fn      Main_Circulation
 *
 * @brief   IAP��ѭ��,�����ram�����У������ٶ�.
 *
 * @param   None.
 *
 * @return  None.
 */
__attribute__((section(".highcode")))
void Main_Circulation()
{
    uint16_t j = 0;
    while (1)
    {
        j++;
        if (j > 5)//100us����һ������
        {
            j = 0;
            USB_DevTransProcess();//���ò�ѯ��ʽ����usb��������ʹ���жϡ�
        }
        DelayUs(20);
        g_tcnt++;
        if (g_tcnt > 3000000)
        {
            //1����û�в���������app
            R8_USB_CTRL = RB_UC_RESET_SIE;
            R16_PIN_ALTERNATE &= ~(RB_UDP_PU_EN | RB_PIN_USB_EN);
            DelayMs(10);
            jumpApp();
        }
    }
}

IAPDataFlashInfo_t p_image_flash;

/*********************************************************************
 * @fn      main
 *
 * @brief   ������
 *
 * @return  none
 */
int main()
{
    uint16_t i;
    uint8_t  s;

    HSECFG_Capacitance(HSECap_18p);
    SetSysClock(CLK_SOURCE_HSE_PLL_100MHz);

#if USE_FLASHROM_FLAG
    FLASH_ROM_READ(IAP_FLAG_DATAFLASH_ADD, &p_image_flash, 4);
    if ((p_image_flash.ImageFlag != FLAG_USER_CALL_IAP))
    {
        jumpApp();
    }
#else
    //��ʼ������Ϊ�������롣Ϊ�˼�С�����С�����üĴ�����д��
    R32_PA_PD_DRV &= ~GPIO_Pin_4;
    R32_PA_PU |= GPIO_Pin_4;
    R32_PA_DIR &= ~GPIO_Pin_4;
    //
    DelayMs(10);
    if (GPIOA_ReadPortPin(GPIO_Pin_4))
    {
        DelayMs(5);
        if (GPIOA_ReadPortPin(GPIO_Pin_4))
        {
            //����ǰ�ж��Ƿ����iap��û�а�������
            jumpApp();
        }
    }
#endif
    R16_PIN_ALTERNATE &= ~RB_PIN_DEBUG_EN;R16_PIN_ALTERNATE &= ~RB_PIN_DEBUG_EN;//ʹ��USBҪ�ص����ߵ���
    /* USB��ʼ�� */
    R8_USB_CTRL = 0x00; // ���趨ģʽ,ȡ�� RB_UC_CLR_ALL

    R8_UEP4_1_MOD = RB_UEP4_RX_EN | RB_UEP4_TX_EN | RB_UEP1_RX_EN | RB_UEP1_TX_EN; // �˵�4 OUT+IN,�˵�1 OUT+IN
    R8_UEP2_3_MOD = RB_UEP2_RX_EN | RB_UEP2_TX_EN | RB_UEP3_RX_EN | RB_UEP3_TX_EN; // �˵�2 OUT+IN,�˵�3 OUT+IN

    R16_UEP0_DMA = (uint16_t)(uint32_t)EP0_Databuf;
    R16_UEP1_DMA = (uint16_t)(uint32_t)EP1_Databuf;
    R16_UEP2_DMA = (uint16_t)(uint32_t)EP2_Databuf;
    R16_UEP3_DMA = (uint16_t)(uint32_t)EP3_Databuf;

    R8_UEP0_CTRL = UEP_R_RES_ACK | UEP_T_RES_NAK;
    R8_UEP1_CTRL = UEP_R_RES_ACK | UEP_T_RES_NAK | RB_UEP_AUTO_TOG;
    R8_UEP2_CTRL = UEP_R_RES_ACK | UEP_T_RES_NAK | RB_UEP_AUTO_TOG;
    R8_UEP3_CTRL = UEP_R_RES_ACK | UEP_T_RES_NAK | RB_UEP_AUTO_TOG;
    R8_UEP4_CTRL = UEP_R_RES_ACK | UEP_T_RES_NAK;

    R8_USB_DEV_AD = 0x00;
    R8_USB_CTRL = RB_UC_DEV_PU_EN | RB_UC_INT_BUSY | RB_UC_DMA_EN;  // ����USB�豸��DMA�����ж��ڼ��жϱ�־δ���ǰ�Զ�����NAK
    R16_PIN_ALTERNATE |= RB_PIN_USB_EN | RB_UDP_PU_EN;              // ��ֹUSB�˿ڸ��ռ���������
    R8_USB_INT_FG = 0xFF;                                           // ���жϱ�־
    R8_UDEV_CTRL = RB_UD_PD_DIS | RB_UD_PORT_EN;                    // ����USB�˿�
    R8_USB_INT_EN = 0;  //��ֹusb�жϣ����ò�ѯ��ʽ

    /* ����highcode��ѭ�� */
    Main_Circulation();
}
