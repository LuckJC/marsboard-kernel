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
#ifndef  __UI_CONTROL_I_H__
#define  __UI_CONTROL_I_H__


typedef struct  _progressbar_t
{
	int  x1;					//���Ͻ�x����
	int  y1;					//���Ͻ�y����
	int  x2;					//���½�x����
	int  y2;					//���½�y����
	int  st_x;					//�ڲ���ʼ���x����
	int  st_y;					//�ڲ���ʼ���y����
	int  pr_x;					//��ǰ�������ڵ�x����
	int  pr_y;					//��Ч
	int  thick;					//��ĺ�ȣ���Ե���
	int  width;					//������
	int  height;				//����߶�
	int  frame_color;			//�߿���ɫ
	int  progress_color;		//�ڲ���ɫ
	int  progress_ratio;		//��ǰ���Ȱٷֱ�
}
progressbar_t;




#endif   //__UI_CONTROL_I_H__

