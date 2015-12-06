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
#include "usb_descriptor.h"
#include "usb_params.h"
#include "usb_register.h"
#include "usb_storage.h"

#include "string.h"
/*
************************************************************************************************************
*
*                                             dram_copy
*
*    �������ƣ�
*
*    �����б�	src_addr  Դ��ַ
*
*				dest_addr Ŀ�ĵ�ַ
*
*				bytes	  ���ݵ��ֽ���
*
*
*    ����ֵ  ��
*
*    ˵��    ��
*
*
************************************************************************************************************
*/
__s32 dram_copy(__u32 src_addr, __u32 dest_addr, __u32 bytes)
{
	memcpy((void *)src_addr, (void *)dest_addr, bytes);

	return 1;
}


