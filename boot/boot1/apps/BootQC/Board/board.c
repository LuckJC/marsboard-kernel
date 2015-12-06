/*
*************************************************************************************
*                         			eGon
*					        Application Of eGon2.0
*
*				(c) Copyright 2006-2010, All winners Co,Ld.
*							All	Rights Reserved
*
* File Name 	: Board.c
*
* Author 		: javen
*
* Description 	: ��������
*
* History 		:
*      <author>    		<time>       	<version >    		<desc>
*       javen     	   2010-09-10          1.0            create this file
*
*************************************************************************************
*/

#include "include.h"
#include "common_res.h"

/*
*******************************************************************************
*                     BoardInit_Display
*
* Description:
*    ���� display ����
*
* Parameters:
*    void
*
* Return value:
*    0 : �ɹ�
*   !0 : ʧ��
*
* note:
*    void
*
*******************************************************************************
*/
__s32 BoardInit_Display(__s32 source, __s32 mode)
{
    __s32 ret = 0;
    __s32 source_type, tv_mode, dislpay_device;

    board_res.display_source = source;
    if((source < 0) || (mode < 0))
    {
        board_res.display_source = -1;
        return 0;
    }
    ret = wBoot_driver_install("c:\\drv_de.drv");
    if(ret != 0)
    {
        DMSG_PANIC("ERR: wBoot_driver_install display driver failed\n");
        return -1;
    }
	//��ǰ����ʾ�豸
	board_res.disp_hd = wBoot_driver_open(EGON2_EMOD_TYPE_DRV_DISP, NULL);
    if(board_res.disp_hd == NULL)
    {
        DMSG_PANIC("ERR: open display driver failed\n");
        return -1;
    }
    source_type = 0;
    tv_mode     = 0;
    switch(source)
    {
        case 1:                                 //CVBS
            source_type = DISP_OUTPUT_TYPE_TV;
            tv_mode = DISP_TV_CVBS;
            break;
        case 2:                                 //YPBPR
            source_type = DISP_OUTPUT_TYPE_TV;
            tv_mode = DISP_TV_YPBPR;
            break;
//        case 3:                                 //SVIDEO
//            source_type = DISP_OUTPUT_TYPE_TV;
//            tv_mode = DISP_TV_SVIDEO;
//            break;
        case 3:                                 //HDMI
            source_type = DISP_OUTPUT_TYPE_HDMI;
            break;
        case 4:                                 //VGA
            source_type = DISP_OUTPUT_TYPE_VGA;
            break;
        default:
            source_type = DISP_OUTPUT_TYPE_LCD;
            break;
    }
    dislpay_device = (source_type << 16) | (tv_mode << 8) | ((mode << 0));
    //����ʾ��Ļ
    ret = De_OpenDevice(dislpay_device);
    if(ret != 0)
    {
        DMSG_PANIC("ERR: De Open LCD or TV failed\n");
        return -1;
    }
	board_res.layer_hd = De_RequestLayer(DISP_LAYER_WORK_MODE_NORMAL);
	if(board_res.layer_hd == NULL)
	{
        DMSG_PANIC("ERR: De_RequestLayer failed\n");
        return -1;
	}

	//wBoot_block_init();
	LCD_DisplayInit();

    return 0;
}

/*
*******************************************************************************
*                     BoardExit_Display
*
* Description:
*    ж�� display ����
*
* Parameters:
*    void
*
* Return value:
*    0 : �ɹ�
*   !0 : ʧ��
*
* note:
*    void
*
*******************************************************************************
*/
__s32 BoardExit_Display(void)
{
    if(board_res.display_source < 0)
    {
        return 0;
    }
    if(board_res.disp_hd == NULL)
    {
        DMSG_PANIC("ERR: display driver not open yet\n");
    }
	else
	{
	    //�˳���ʾ������ֻ�ر��жϣ����ǲ��ر���Ļ
		wBoot_driver_ioctl(board_res.disp_hd, DISP_CMD_SET_EXIT_MODE, DISP_EXIT_MODE_CLEAN_PARTLY, 0);
		//wBoot_driver_ioctl(display_hd, DISP_CMD_LCD_OFF, 0, 0);
		wBoot_driver_close(board_res.disp_hd);
	}

    return wBoot_driver_uninstall(EGON2_EMOD_TYPE_DRV_DISP);
}

/*
*******************************************************************************
*                     BoardInit
*
* Description:
*    Ӳ����ʼ����
*
* Parameters:
*    :  input.  Boot�׶εĲ�����
*
* Return value:
*    ����Ӳ����ʼ���Ľ�����ɹ�����ʧ�ܡ�
*
* note:
*    ��
*
*******************************************************************************
*/
__s32 BoardInit(void)
{
    /* ��ʼ�� WatchDog */

    /* ��ʼ�� PIO */

    /* ��ʼ�� Jtag */

    /* ��ʼ�� Uart */
    /* ��ʼ�� Key */
    /* ��ʼ�� IR */

    /* ��ʼ�� FM */

    /* ��ʼ�� ��ʾ��� */
    //BoardInit_Display();

    return 0;
}

/*
*******************************************************************************
*                     BoardExit
*
* Description:
*    �ر����е�Ӳ����Դ��
*
* Parameters:
*    :  input.  Boot�׶εĲ�����
*
* Return value:
*    ���سɹ�����ʧ�ܡ�
*
* note:
*    ��
*
*******************************************************************************
*/
__s32 BoardExit(void)
{
    /* �ر� ��ʾ��� */
    BoardExit_Display();

    /* �ر� FM */

    /* �ر� IR */

    /* �ر� Key */
    /* �ر� Uart */

    /* �ر� Jtag */

    /* �ر� PIO */

    /* �ر� WatchDog */
    return 0;
}


