/*
************************************************************************************************************************
*                                                         eGON
*                                         the Embedded GO-ON Bootloader System
*
*                             Copyright(C), 2006-2009, SoftWinners Microelectronic Co., Ltd.
*											       All Rights Reserved
*
* File Name   : misc.c
*
* Author      : Gary.Wang
*
* Version     : 1.1.0
*
* Date        : 2009.04.03
*
* Description :
*
* Others      : None at present.
*
*
* History     :
*
*  <Author>        <time>       <version>      <description>
*
* Gary.Wang      2009.04.03       1.1.0        build the file
*
************************************************************************************************************************
*/

#include "types.h"


/*******************************************************************************
*��������: g_mod
*����ԭ�ͣ�uint32 g_mod( __u32 dividend, __u32 divisor, __u32 *quot_p )
*��������: ��nand flash��ĳһ�����ҵ�һ����ñ��ݽ������뵽RAM�С�����ɹ�����
*          ��OK�����򣬷���ERROR��
*��ڲ���: dividend          ���롣������
*          divisor           ���롣����
*          quot_p            �������
*�� �� ֵ: ����
*******************************************************************************/
__u32 nand_g_mod( __u32 dividend, __u32 divisor, __u32 *quot_p )
{
	if( divisor == 0 )
	{
		*quot_p = 0;
		return 0;
	}
	if( divisor == 1 )
	{
		*quot_p = dividend;
		return 0;
	}

	for( *quot_p = 0; dividend >= divisor; ++(*quot_p) )
		dividend -= divisor;
	return dividend;
}




/* end of misc.c */
