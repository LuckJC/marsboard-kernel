/*
*************************************************************************************
*                         			eGon
*					        Application Of eGon2.0
*
*				(c) Copyright 2006-2010, All winners Co,Ld.
*							All	Rights Reserved
*
* File Name 	: BootMain_Private.h
*
* Author 		: javen
*
* Description 	: ��������˽�����ݽṹ
*
* History 		:
*      <author>    		<time>       	<version >    		<desc>
*       javen     	   2010-09-10          1.0            create this file
*
*************************************************************************************
*/
#ifndef  __SPRITE_RES_IMG__
#define  __SPRITE_RES_IMG__



typedef struct boot_global_info
{
    __s32              display_device;       //��ʾ��LCD��TV��HDMI��
    __s32              display_mode;         //��ʾģʽ
    __s32			   erase_flash;          //�Ƿ���Ҫ����nand flash
    char               user_reserved[512];   //�û����������������Զ���
}
boot_global_info_t;


#endif   //__SPRITE_RES_IMG__

