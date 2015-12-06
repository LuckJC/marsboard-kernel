/*
**********************************************************************************************************************
*											        eGon
*						           the Embedded GO-ON Bootloader System
*									       eGON arm boot sub-system
*
*						  Copyright(C), 2006-2010, SoftWinners Microelectronic Co., Ltd.
*                                           All Rights Reserved
*
* File    :
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
#ifndef  __BOOT_HARDWARE_RES_H__
#define  __BOOT_HARDWARE_RES_H__

#include  "types.h"

#define    CARD_SPRITE_SUCCESSED               1
#define    CARD_SPRITE_FAIL					  -1
#define    CARD_SPRITE_NORMAL				   0

typedef struct
{
    unsigned    layer_hd;                     //������ʾ��ͼ����
    unsigned    disp_hd;                      //��ʾ�������
    unsigned    led_hd[32];                   //����LED����ʾ�����32��
    unsigned    tmr_hd;                       //TIMER���
    int			led_count;					  //ʵ�ʵ�LED�ĸ���
    int         led_status[32];               //ÿ��LED��Ӧ��״̬
    int         display_source;
}
boot_hardware_res;

extern  boot_hardware_res     board_res;

#endif   //__BOOT_HARDWARE_RES_H__

