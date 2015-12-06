/*
*************************************************************************************
*                         			eGon
*					        Application Of eGon2.0
*
*				(c) Copyright 2006-2010, All winners Co,Ld.
*							All	Rights Reserved
*
* File Name 	: Parse_Picture.h
*
* Author 		: javen
*
* Description 	: ͼƬ����
*
* History 		:
*      <author>    		<time>       	<version >    		<desc>
*       javen     	   2010-09-10          1.0            create this file
*
*************************************************************************************
*/
#ifndef  __PARSE_PICTURE_H__
#define  __PARSE_PICTURE_H__

#include "types.h"

typedef struct tag_Picture
{
    void *Buffer;   		/* ���ͼƬ����     */
    __u32 BufferSize;   	/* buffer����       */

    __u32 BitCount; 		/* һ�����ص�bit��  */
    __u32 Width;    		/* ͼƬ���         */
    __u32 Height;   		/* ͼƬ�߶�         */
    __u32 RowSize;  		/* ͼƬһ�еĴ�С   */
}Picture_t;


int Parse_Pic_BMP_ByPath(char *Path, Picture_t *PictureInfo, unsigned address);

#endif   //__PARSE_PICTURE_H__

