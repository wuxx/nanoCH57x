/********************************** (C) COPYRIGHT *******************************
 * File Name          : startup_CH59x.s
 * Author             : WCH
 * Version            : V1.0.0
 * Date               : 2021/02/25
 * Description        :
 *********************************************************************************
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * Attention: This software (modified or not) and binary are used for 
 * microcontroller manufactured by Nanjing Qinheng Microelectronics.
 *******************************************************************************/

	.section	.init,"ax",@progbits
	.global	_start
	.align	1
_start:
	j	0x37000

