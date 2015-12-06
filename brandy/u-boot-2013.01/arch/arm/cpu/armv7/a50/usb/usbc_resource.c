/*
********************************************************************************************************************
*                                              usb controller
*
*                              (c) Copyright 2007-2009,
*										All	Rights Reserved
*
* File Name 	: usbc.c
*
* Author 		: daniel
*
* Version 		: 1.0
*
* Date 			: 2009.09.01
*
* Description 	: ������suniiƽ̨��USB������������
*
* History 		:
*
********************************************************************************************************************
*/
#include  "usbc_i.h"


/*
*******************************************************************************
*                     usb_open_clock
*
* Description:
*    void
*
* Parameters:
*    void
*
* Return value:
*    void
*
* note:
*    void
*
*******************************************************************************
*/
int usb_open_clock(void)
{
    u32 reg_value = 0;

    //Gating AHB clock for USB_phy0
	reg_value = readl(SUNXI_CCM_BASE + 0x60);
	reg_value |= (1 << 24);
	writel(reg_value, (SUNXI_CCM_BASE + 0x60));

    //delay to wati SIE stable
	__msdelay(2);

    /* AHB reset */
    reg_value = readl(SUNXI_CCM_BASE + 0x2C0);
    reg_value |= (1 << 24);
    writel(reg_value, (SUNXI_CCM_BASE + 0x2C0));
    __msdelay(2);

	//Enable module clock for USB phy0
	reg_value = readl(SUNXI_CCM_BASE + 0xcc);
	reg_value |= (1 << 0) | (1 << 8);
	writel(reg_value, (SUNXI_CCM_BASE + 0xcc));

	//delay some time
	__msdelay(10);

	return 0;
}
/*
*******************************************************************************
*                     usb_op_clock
*
* Description:
*    void
*
* Parameters:
*    void
*
* Return value:
*    void
*
* note:
*    void
*
*******************************************************************************
*/
int usb_close_clock(void)
{
    u32 reg_value = 0;

    //��usb ahbʱ��
	reg_value = readl(SUNXI_CCM_BASE + 0x60);
	reg_value &= ~(1 << 24);
	writel(reg_value, (SUNXI_CCM_BASE + 0x60));
    //��sie��ʱ�ӱ���
	__msdelay(10);

    /* AHB reset */
    reg_value = readl(SUNXI_CCM_BASE + 0x2C0);
    reg_value &= ~(1 << 24);
    writel(reg_value, (SUNXI_CCM_BASE + 0x2C0));
    __msdelay(2);

	//��USB phyʱ��
	reg_value = readl(SUNXI_CCM_BASE + 0xcc);
	reg_value &= ~((1 << 0) | (1 << 8));
	writel(reg_value, (SUNXI_CCM_BASE + 0xcc));

	//��ʱ
	__msdelay(10);

	return 0;
}


