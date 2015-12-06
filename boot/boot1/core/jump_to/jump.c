/*
**********************************************************************************************************************
*											        eGon
*						           the Embedded GO-ON Bootloader System
*									       eGON arm boot sub-system
*
*						  Copyright(C), 2006-2010, SoftWinners Microelectronic Co., Ltd.
*                                           All Rights Reserved
*
* File    : arm_swi
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
#include "include.h"

extern void jump_to( __u32 addr );
/*
************************************************************************************************************
*
*                                             function
*
*    �������ƣ�
*
*    �����б�
*
*    ����ֵ  ��
*
*    ˵��    ��
*
*
************************************************************************************************************
*/
void eGon2_jump_to(__u32 addr)
{
	eGon2_power_set_data_buffer(0x0e);
	eGon2_timer_exit();			//�ر�timer
    eGon2_key_exit();           //�رհ���
    eGon2_twi_exit();           //�ر�TWI�豸
    eGon2_block_device_exit(); //�ر��õ��Ĵ洢�豸
    close_sys_int( );      // close system interrupt
	eGon2_Int_Exit( );     // �ر������ж�
	disable_icache();      // �ر�icache
	mmu_disable();		   // �ر�mmu
    flush_dcache();		   // �ر�dcache
    disable_dcache();
    jump_to( addr );

    return;
}
/*
************************************************************************************************************
*
*                                             function
*
*    �������ƣ�
*
*    �����б�
*
*    ����ֵ  ��
*
*    ˵��    ��
*
*
************************************************************************************************************
*/
void eGon2_jump_to_android_linux(__s32 zero, __s32 mod_id, __u32 paddr, __u32 kernal_addr)
{
	void (*kernel_entry)(int zero, int arch, uint params);
	eGon2_power_set_data_buffer(0x0e);
	eGon2_timer_exit();			//�ر�timer
    eGon2_key_exit();           //�رհ���
    eGon2_twi_exit();           //�ر�TWI�豸
    eGon2_block_device_exit(); //�ر��õ��Ĵ洢�豸
    close_sys_int( );      // close system interrupt
	eGon2_Int_Exit( );     // �ر������ж�
	disable_icache();      // �ر�icache
	mmu_disable();		   // �ر�mmu
    flush_dcache();		   // �ر�dcache
    disable_dcache();

	kernel_entry = (void (*)(int, int, __u32))(kernal_addr);
	kernel_entry(zero, mod_id, paddr);

    return;
}
/*
************************************************************************************************************
*
*                                             function
*
*    �������ƣ�
*
*    �����б�
*
*    ����ֵ  ��
*
*    ˵��    ��
*
*
************************************************************************************************************
*/
void eGon2_jump_Fel( void )
{
	eGon2_power_set_data_buffer(0);
	eGon2_timer_exit();			//�ر�timer
    eGon2_key_exit();           //�رհ���
    eGon2_twi_exit();           //�ر�TWI�豸
	eGon2_block_device_exit(); //�ر��õ��Ĵ洢�豸
	close_sys_int( );                   // close system interrupt
	set_vect_high_addr( );              // set interrupt vector low address
	eGon2_Int_Exit( );     // �ر������ж�
	disable_icache();      // �ر�icache
	mmu_disable();		   // �ر�mmu
    flush_dcache();		   // �ر�dcache
    disable_dcache();
    {
    	__u32 timedly;

    	for(timedly = 0; timedly < 5000; timedly ++);
    }
	jump_to( FEL_BASE );

	return ;
}
/*
************************************************************************************************************
*
*                                             function
*
*    �������ƣ�
*
*    �����б�
*
*    ����ֵ  ��
*
*    ˵��    ��
*
*
************************************************************************************************************
*/
void eGon2_simple_jump_Fel( void )
{
	eGon2_timer_exit();	   //�ر�timer
    eGon2_key_exit();      //�رհ���
    eGon2_twi_exit();      //�ر�TWI�豸
	close_sys_int( );      // close system interrupt
	set_vect_high_addr( ); // set interrupt vector low address
	eGon2_Int_Exit( );     // �ر������ж�
	disable_icache();      // �ر�icache
	mmu_disable();		   // �ر�mmu
    flush_dcache();		   // �ر�dcache
    disable_dcache();
    {
    	__u32 timedly;

    	for(timedly = 0; timedly < 5000; timedly ++);
    }
	jump_to( FEL_BASE );

	return ;
}

/*
************************************************************************************************************
*
*                                             function
*
*    �������ƣ�
*
*    �����б�
*
*    ����ֵ  ��
*
*    ˵��    ��
*
*
************************************************************************************************************
*/
void eGon2_power_off(void)
{
	eGon2_power_set_data_buffer(0);
	eGon2_block_device_exit();
	eGon2_set_power_off_vol();

	for(;;);
}
