/*
**********************************************************************************************************************
*											        eGon
*						           the Embedded GO-ON Bootloader System
*									       eGON mod demo sub-system
*
*						  Copyright(C), 2006-2010, SoftWinners Microelectronic Co., Ltd.
*                                           All Rights Reserved
*
* File    : magic.c
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
#include  "egon2.h"
#include  "CardMain.h"

#pragma arm section rodata="EGON2_MAGIC"
const eGon2_mod_t modinfo =
{
    {'e','G','o','n','2','a','p','p'},		//MAGIC�ַ������ڱ�ʶ��eGON2������/Ӧ�ô���
    0x01000000,                			//�汾
    0x0,                                    	//ģ���ID��ÿ��elf��Ӧ����һ��ģ��ID��������������Ӧ�ã��Ҹ�����ͬ
    BootMain,                          		//pcb���һ��������׵�ַ
    0						//���������б��г�����������Ҫ��7������
};
#pragma arm section
