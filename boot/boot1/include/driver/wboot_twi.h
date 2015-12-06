/*
**********************************************************************************************************************
*											        eGon
*						           the Embedded GO-ON Bootloader System
*									       eGON twi sub-system
*
*						  Copyright(C), 2006-2010, SoftWinners Microelectronic Co., Ltd.
*                                           All Rights Reserved
*
* File    : wboot_twi.h
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
#ifndef	_WBOOT_TWI_H_
#define	_WBOOT_TWI_H_

typedef enum  wboot_twi_cmd_set
{
    WBOOT_TWI_SETFREQUENCY,                                  //����TWI����Ƶ��
    WBOOT_TWI_
}
wboot_twi_cmd_set_t;

//eGon2������twi������������������紫������ʹ�õ����ݽṹ
typedef struct  _twi_init_arg
{
	__u32   twi_control_index;      //TWI��������ţ�0��Ӧ������0,1��Ӧ������1����������
	__u32   twi_run_clock;          //TWI���е�ʱ��Ƶ�ʣ��� Hz Ϊ��λ
}
_twi_init_arg_t;

typedef struct  _twi_arg
{
    __u32    slave_addr;             //���豸��ַ
    __u32    slave_addr_flag;        //�����õ�ַ���  0��7bit�� 1��10bit
	__u8    *byte_addr;              //��Ҫ��д�������ڴ��豸�еĵ�ַ
	__u32    byte_addr_width;        //�����õ�ַ���  0��1��8 bit; ���������ִ����ֽ���
	__u32    byte_count;             //һ�ζ�дҪ��ɵ��ֽ���
	__u32    if_restart;             //�Ƿ���Ҫ����restart����
	__u8    *data;                   //���ݵĵ�ַ
}
_twi_arg_t;




#endif	//_WBOOT_TWI_H_

/* end of _WBOOT_TWI_H_ */

