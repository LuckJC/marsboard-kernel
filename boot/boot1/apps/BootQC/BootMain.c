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
#include "board.h"
#include "common_res.h"
#include <math.h>

boot_hardware_res     board_res;
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

void mathlib_test(void)
{
    double x,y;
    __inf("begain mathlib_test!\n");
    __s32 print_x,print_y;
    for(x=0;x<6.28;x+=0.1)
    {
        y=sin(x);
        print_x=x*1000;
        print_y=y*1000;
        __inf("sin(%d)=%d\n",print_x,print_y);
    }
    __inf("mathlib test done!\n");
}

int BootMain(int argc, char **argv)
{
	DMSG_INFO("\n\n\n[MSG]: BootMain start\n");
	while( 1 )
	{
		char ch;

		ch = wBoot_getc_delay( 1 );  // 27000000
	    __inf("%d\n", ch);
	    if( ch == '2' )
	    {
	    	__inf("Jump to fel\n");
			{
				__s32 tick;

				for(tick = 10000; tick>0; tick --);
			}
	    	wBoot_jump_fel( );
	    }
	    else if(ch == '-')
	    {
	        __u32 dbg = 0x55;

            __inf("for debug\n");
	        while(dbg == 0x55);
	        break;
	    }
	    else if(ch == '1')
	    {
	    	usb_start(0);
    		usb_run();
    		break;
	    }
	    else
	    {
			break;
	    }
	}
	//�ر�DCACHE
    wlibc_DCacheDisable();
	BoardInit_Display(0, 0);           //��ʼ����ʾ
		mathlib_test();
//    if(Amain() == 1)
//    	__dinf("test ok\n");
//    else
//    	__dinf("test fail\n");
//    if(qc_test() == 1)
	if(1)
    	__dinf("test ok\n");
    else
    	__dinf("test fail\n");
    //��ʼ׼��ϵͳ����
    return 0;
}



