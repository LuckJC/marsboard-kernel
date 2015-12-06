/*
********************************************************************************************************************
*                                              usb controller
*
*                              (c) Copyright 2007-2009, daniel.China
*										All	Rights Reserved
*
* File Name 	: usbc_i.h
*
* Author 		: daniel
*
* Version 		: 1.0
*
* Date 			: 2009.09.15
*
* Description 	: ������suniiƽ̨��USB������������
*
* History 		:
*
********************************************************************************************************************
*/
#ifndef  __USBC_I_H__
#define  __USBC_I_H__

#include  <common.h>
#include  <asm/arch/usb.h>
#include  <asm/arch/cpu.h>
#include  <asm/arch/clock.h>

#define  USBC_MAX_OPEN_NUM    8

/* ��¼USB�Ĺ�����Ϣ */
typedef struct __fifo_info{
    uint port0_fifo_addr;
	uint port0_fifo_size;

    uint port1_fifo_addr;
	uint port1_fifo_size;

	uint port2_fifo_addr;
	uint port2_fifo_size;
}__fifo_info_t;

/* ��¼��ǰUSB port���е�Ӳ����Ϣ */
typedef struct __usbc_otg{
    uint port_num;
	uint base_addr;        /* usb base address 		*/

	uint used;             /* �Ƿ����ڱ�ʹ��   		*/
    uint no;               /* �ڹ��������е�λ�� 		*/
}__usbc_otg_t;

#endif   //__USBC_I_H__

