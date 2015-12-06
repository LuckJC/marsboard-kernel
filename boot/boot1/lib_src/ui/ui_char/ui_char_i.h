/*
*************************************************************************************
*                         			eGon
*					        Application Of eGon2.0
*
*				(c) Copyright 2006-2010, All winners Co,Ld.
*							All	Rights Reserved
*
* File Name 	: ui.c
*
* Author 		: javen
*
* Description 	: ͼ����ʾ�������������
*
* History 		:
*      <author>    		<time>       	<version >    		<desc>
*       javen     	   2010-09-10          1.0            create this file
*
*************************************************************************************
*/
#ifndef  __UI_CHAR_I_H__
#define  __UI_CHAR_I_H__


#include  "types.h"


typedef struct ui_char_info_t
{
    char   *crt_addr;                         //��ǰ������ʾ�ĵ�ַ
    __u32   rest_screen_height;               //ʣ��Ĵ洢��Ļ�߶ȣ�ʣ���ܸ߶�, �ַ���λ����
    __u32   rest_screen_width;                //ʣ��Ĵ洢��Ļ���, ʣ���ܿ��, �ַ���λ����
    __u32   rest_display_height;              //ʣ�����ʾ�߶�
    __u32   total_height;                     //������ʾ�ܵĸ߶�
    __u32   current_height;                   //��ǰ�Ѿ�ʹ�õĸ߶�
    __u32   x;                                //��ʾλ�õ�x����
    __u32   y;                                //��ʾλ�õ�y����
    int     word_size;						  //�ַ���С
}
_ui_char_info_t;




#endif   //__UI_CHAR_I_H__

