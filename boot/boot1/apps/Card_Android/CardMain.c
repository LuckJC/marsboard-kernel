/*
**********************************************************************************************************************
*											        eGon
*						           the Embedded GO-ON Bootloader System
*									       eGON arm boot sub-system
*
*						  Copyright(C), 2006-2010, SoftWinners Microelectronic Co., Ltd.
*                                           All Rights Reserved
*
* File    : BootMain.c
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
#include "card_sprite.h"
#include "part_info.h"
#include "common_res.h"
#include "card_sprite_res.h"


boot_hardware_res     board_res;
int					  force_debug = 0;
int					  cue;


extern  __u32 usb_start(void);
extern  __u32 usb_run(void);
/*
*******************************************************************************
*                     BootMain
*
* Description:
*    BOOT��Ӧ�ó���
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
int BootMain(int argc, char **argv)
{
	__s32                 ret;
    int                   erase_flash;
	MBR					  mbr_info;
    boot_global_info_t   *global_info;

    DMSG_INFO("big firmware! here we go !\n");
	DMSG_INFO("Sprite start\n");
	{
		char ch;

		ch = wBoot_getc_delay( 1 );  // 27000000
	    __inf("%d\n", ch);

	    switch(ch)
	   	{
	   		case '1':
	   		{
	   			usb_start();
	    		usb_run();
	    		break;
	   		}
	   		case '2':
	   		{
	   			__inf("Jump to fel\n");
	   			wBoot_jump_fel( );
	   			break;
	   		}
	   		case '-':
	   		{
	   			__u32 dbg = 0x55;

	            __inf("hold\n");
		        while(dbg == 0x55);
		        break;
	   		}
	   		case '+':
	   		{
	   			force_debug = 1;
	        	break;
	   		}
	   		default:
	   			break;
	   	}
	}
	*(volatile unsigned int *)(0x1c20C00 + 0x118) = 0;
	*(volatile unsigned int *)(0x1c20C00 + 0x11C) = 3;
	//���ݳ�ʼ��
	memset(&board_res, 0, sizeof(boot_hardware_res));
    //�����ڴ棬����һ�������ű�
    global_info = (boot_global_info_t *)wBoot_malloc(sizeof(boot_global_info_t));
    if(!global_info)
    {
        __wrn("unable to malloc memory for bootini\n");

        return -1;
    }
    //��������ű�
    memset(global_info, 0, sizeof(boot_global_info_t));
    ret = script_patch("c:\\boot.ini", global_info, 0);
    if(ret < 0)
    {
        __wrn("unable to parser boot.ini\n");

        return -1;
    }
    //��ʼ����ʾ�豸
    __inf("display init\n");
    cue = -1;
    if(boot_ui_init(global_info->display_device, global_info->display_mode) >= 0)
    {
    	//�����ַ���ʾ
    	__inf("char init\n");
    	boot_ui_char_init(0);
    	cue = 0;
    }
    sprite_led_init();
    sprite_wrn_init();
    //��ȡMBR��Ϣ
    __inf("mbr fetch\n");
	ret = card_mbr_info((void *)&mbr_info);
	if(ret < 0)
	{
		__wrn("unable to get mbr info\n");

        return -1;
	}
	boot_ui_check_device_open();
    
	ret = wBoot_script_parser_fetch("platform", "eraseflag", &erase_flash, 1);
	if((!ret) && (erase_flash))
	{
		erase_flash = 1;
	}
	else
	{
		erase_flash = 0;
	}
    
    //��ʼ׼��ϵͳ����
    ret = card_sprite((void *)&mbr_info,erase_flash, cue);

	sprite_wrn_exit();
	sprite_led_exit(ret);
	if(!ret)
	{
		char	buffer[512];

		board_res.led_status[0] = CARD_SPRITE_SUCCESSED;
		sprite_wrn("CARD OK\n");

		__inf("get work mode\n");
		memset(buffer, 0, 512);
		wBoot_block_dread(15, 1, buffer);
		if(strcmp(buffer, "1234567890abcdefghijklmnopqrstuvwxyz"))
		{
			__inf("try to close\n");
			wBoot_timer_delay(3000);

			wBoot_power_set_off();
		}
		else
		{
			int ret;

			__inf("try to format\n");
			wBoot_timer_delay(500);
			ret = FormatDisk();
			__inf("format %d\n", ret);
			WATCHDOG_REG_MODE = 0x0;
			wBoot_timer_delay(500);
			WATCHDOG_REG_MODE = 0x3;
		}
	}
	else
	{
		board_res.led_status[0] = CARD_SPRITE_FAIL;
	}
	{
		__u32 dbg = 0x55;

		while(dbg == 0x55);
	}

    return 0;
}

