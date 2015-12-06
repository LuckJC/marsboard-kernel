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
#ifndef  __UI_H__
#define  __UI_H__

#include  "types.h"
#include  "display_interface/display_interface.h"

#define BAS_SCREEN_SIZE                (3072000)
#define DECOMPRESS_UI_PIC_MAX           8
#define FILE_NAME_MAX                   16

typedef struct __display_info_set
{
    __u8   *screen_buf;                       //�洢��Ļ��ַ
    __u32   screen_height;                    //�洢��Ļ�߶ȣ��ַ���λ����
    __u32   screen_width;                     //�洢��Ļ���
    __u8   *crt_addr;                         //��ǰ������ʾ�ĵ�ַ
    __u8   *fb_addr;                          //ͼ���ַ
    __u32   rest_screen_height;               //ʣ��Ĵ洢��Ļ�߶ȣ�ʣ���ܸ߶�, �ַ���λ����
    __u32   rest_screen_width;                //ʣ��Ĵ洢��Ļ���, ʣ���ܿ��, �ַ���λ����
    __u32   rest_display_height;              //ʣ�����ʾ�߶�
    __u32   total_height;                     //������ʾ�ܵĸ߶�
    __u32   current_height;                   //��ǰ�Ѿ�ʹ�õĸ߶�
    __u32   x;                                //��ʾλ�õ�x����
    __u32   y;                                //��ʾλ�õ�y����
}
display_info_set_t;


typedef struct _shell_char_t
{
    char    name;                             //�ַ���ʹ����32λ������ʵ����һ��char����
    __u32   x;                                //��ʾ�ַ���x����
    __u32   y;                                //��ʾ�ַ���y����
    __u32   width;                            //�ַ�����ʾ���
    __u32   *addr;                            //�ַ���ʾʱ�����ʼ��ַ
}
_shell_char_set_t;

typedef struct _debug_shell_t
{
    __u32                index;               //��¼��ǰ���ڴ�ӡ���ַ������
    __u32                tail;                //ĩβ�ַ���ţ������ڵ��ַ�
    _shell_char_set_t    str[260];            //�������ڴ�ӡ���ַ�
}
_debug_shell_set_t;



typedef struct _cursor_t
{
    volatile __u32       x;                   //����x����
    volatile __u32       y;                   //����y����

}
_cursor_set_t;


typedef  __disp_layer_info_t   display_layer_info_t;


extern   __u32   WORD_SIZE;
//---------------------------------------------------------------
//  �� ����
//---------------------------------------------------------------
#define  BOOT_PICTURE_TYPE_NULL         0x00
#define  BOOT_PICTURE_TYPE_BMP          0x01
#define  BOOT_PICTURE_TYPE_JPG          0x02

extern   int  LCD_DisplayInit(void);
extern   int  LCD_Change_frame_buffer(__u8 *addr);
extern   void debug_printf( const char * str, ...);
extern   int  debug_setdisplay_color(__u32 user_set_color);
extern   int  debug_setdisplay_clear(void);

#endif   //__UI_H__

