/*
 * (C) Copyright 2012
 *     wangflord@allwinnertech.com
 *
 *
 */
#include <common.h>
#include <asm/arch/private_uboot.h>

struct spare_boot_head_t  uboot_spare_head = {
	                                  {
	      /* jump_instruction */          ( 0xEA000000 | ( ( ( sizeof( struct spare_boot_head_t ) + sizeof( int ) - 1 ) / sizeof( int ) - 2 ) & 0x00FFFFFF ) ),
							   		      UBOOT_MAGIC,
							   		      STAMP_VALUE,
							   		      ALIGN_SIZE,
							   		      0,
							   		      0,
							   		      UBOOT_VERSION,
							   		      UBOOT_PLATFORM
							 	      },
							 	      {
										  { 0 },		//dram para
							 	      	  1008,			//run core clock
							 	      	  1200,			//run core vol
							 	      	  0,			//uart port
							 	      	  {             //uart gpio
							 	      	    {2, 22, 2, -1, -1, -1, 0, 0},
		                                    {2, 23, 2, -1, -1, -1, 0, 0}
										  },
							 	      	  0,			//twi port
							 	      	  {             //twi gpio
							 	      	  	{2, 0, 2, -1, -1, -1, 0, 0},
		                                    {2, 1, 2, -1, -1, -1, 0, 0}
										  },
							 	      	  0,			//work mode
							 	      	  0,			//storage mode
							 	      	  { 0 },		//nand gpio
							 	      	  { 0 },		//nand spare data
							 	      	  { 0 },		//sdcard gpio
							 	      	  { 0 }, 		//sdcard spare data
							 	      	  { 0 }			//reserved data
							 	      }
							 	  };


/*******************************************************************************
*
*                  ����Boot_file_head�е�jump_instruction�ֶ�
*
*  jump_instruction�ֶδ�ŵ���һ����תָ�( B  BACK_OF_Boot_file_head )������
*תָ�ִ�к󣬳�����ת��Boot_file_head�����һ��ָ�
*
*  ARMָ���е�Bָ��������£�
*          +--------+---------+------------------------------+
*          | 31--28 | 27--24  |            23--0             |
*          +--------+---------+------------------------------+
*          |  cond  | 1 0 1 0 |        signed_immed_24       |
*          +--------+---------+------------------------------+
*  ��ARM Architecture Reference Manual�����ڴ�ָ�������½��ͣ�
*  Syntax :
*  B{<cond>}  <target_address>
*    <cond>    Is the condition under which the instruction is executed. If the
*              <cond> is ommitted, the AL(always,its code is 0b1110 )is used.
*    <target_address>
*              Specified the address to branch to. The branch target address is
*              calculated by:
*              1.  Sign-extending the 24-bit signed(wro's complement)immediate
*                  to 32 bits.
*              2.  Shifting the result left two bits.
*              3.  Adding to the contents of the PC, which contains the address
*                  of the branch instruction plus 8.
*
*  �ɴ˿�֪����ָ���������8λΪ��0b11101010����24λ����Boot_file_head�Ĵ�С��
*̬���ɣ�����ָ�����װ�������£�
*  ( sizeof( boot_file_head_t ) + sizeof( int ) - 1 ) / sizeof( int )    ����ļ�ͷ
*                                              ռ�õġ��֡��ĸ���
*  - 2                                         ��ȥPCԤȡ��ָ������
*  & 0x00FFFFFF                                ���signed-immed-24
*  | 0xEA000000                                ��װ��Bָ��
*
*******************************************************************************/
