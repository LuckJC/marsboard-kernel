/*
**********************************************************************************************************************
*											        eGon
*						                     the Embedded System
*									       script parser sub-system
*
*						  Copyright(C), 2006-2010, SoftWinners Microelectronic Co., Ltd.
*                                           All Rights Reserved
*
* File    : standby.c
*
* By      : Jerry
*
* Version : V2.00
*
* Date	  :
*
* Descript:
**********************************************************************************************************************
*/
#include "include.h"
#include "arm_a8.h"
/*
************************************************************************************************************
*
*                                             eGon2_int_enter_standby
*
*    �������ƣ�
*
*    �����б�
*
*
*
*    ����ֵ  ��
*
*    ˵��    ��	����standby
*				1) ���DMA PENDING������DMA enable
*				2) �ر�DMA AHB
*
************************************************************************************************************
*/
//static int int_reggroup_value[36];

int standby_int_init(void)
{
//	int	  i;
//	int   *addr;

	asm("mrs r0, cpsr");
	asm("orr r0, r0, #(0x40|0x80)");
	asm("msr cpsr_c, r0");

	//�����жϼĴ���ֵ
//	addr = (int *)(0x01c20400);
//	for(i=1;i<36;i++)
//	{
//		int_reggroup_value[i] = *(addr + i);
//	}

    return 0;
}
/*
************************************************************************************************************
*
*                                             eGon2_int_exit_standby
*
*    �������ƣ�
*
*    �����б�
*
*
*
*    ����ֵ  ��
*
*    ˵��    ��	�˳�standby
*				1) ��DMA AHB
*				2) ���DMA PENDING���ָ�DMA enable
*
*
************************************************************************************************************
*/
int standby_int_exit(void)
{
//	int	  i;
//	int   *addr;
//
//	//�����жϼĴ���ֵ
//	addr = (int *)(0x01c20400);
//	if(!int_reggroup_value)
//	{
//		return -1;
//	}
//	for(i=1;i<36;i++)
//	{
//		*(addr + i) = int_reggroup_value[i];
//	}

	asm("mrs r0, cpsr");
	asm("bic r0, r0, #(0x40|0x80)");
	asm("msr cpsr_c, r0");

    return 0;
}


int standby_int_query(void)
{
//	__u32 reg_val;
//
//	reg_val = INTC_REG_IRQ_PENDCLR0;
//	if(reg_val & 1)
//	{
//		INTC_REG_IRQ_PENDCLR0 = reg_val;
//
//		return 1;
//	}

	return 0;
}

