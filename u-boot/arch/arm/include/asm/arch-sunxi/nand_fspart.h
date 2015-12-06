/*
*********************************************************************************************************
*											        eBase
*
*
*
*						        (c) Copyright 2006-2010, AW China
*											All	Rights Reserved
*
* File    	: 	egon_drv_common_inc.h
* Date	:	2010-09-25
* By      	: 	holigun
* Version 	: 	V1.00
*********************************************************************************************************
*/
#ifndef	_NAND_MBR_H_
#define	_NAND_MBR_H_

#define     DOWNLOAD_MAP_NAME   "dlinfo.fex"
/* MBR       */
#define     MBR_SIZE			(16*1024)
#define   	MBR_MAGIC			"softw411"
#define     MBR_START_ADDRESS	0x00000000
#define     MBR_MAX_PART_COUNT	120
#define     MBR_COPY_NUM        4    //mbr�ı�������
#define     MBR_RESERVED          	(MBR_SIZE - 32 - (MBR_MAX_PART_COUNT * sizeof(PARTITION)))   //mbr�����Ŀռ�
#define     DL_RESERVED           	(DL_SIZE - 32 - (MBR_MAX_PART_COUNT * sizeof(dl_one_part_info)))

//������Ϣ, 64byte
typedef struct tag_PARTITION
{
	unsigned  int       addrhi;				//��ʼ��ַ, ������Ϊ��λ
	unsigned  int       addrlo;				//
	unsigned  int       lenhi;				//����
	unsigned  int       lenlo;				//
	unsigned  char      classname[16];		//���豸��
	unsigned  char      name[16];			//���豸��
	unsigned  int       user_type;          //�û�����
	unsigned  int       keydata;            //�ؼ����ݣ�Ҫ����������ʧ
	unsigned  int       ro;                 //��д����
	unsigned  char      reserved[68];		//�������ݣ�ƥ�������Ϣ128�ֽ�
} __attribute__ ((packed))PARTITION;
//MBR��Ϣ
typedef struct tag_MBR
{
	unsigned  int       crc32;				        // crc 1k - 4
	unsigned  int       version;			        // �汾��Ϣ�� 0x00000100
	unsigned  char 	    magic[8];			        //"softw411"
	unsigned  int 	    copy;				        //����
	unsigned  int 	    index;				        //�ڼ���MBR����
	unsigned  int       PartCount;			        //��������
	unsigned  int       stamp[1];					//����
	PARTITION           array[MBR_MAX_PART_COUNT];	//
	unsigned  char      res[MBR_RESERVED];
}__attribute__ ((packed)) MBR;

typedef struct tag_one_part_info
{
	unsigned  char      name[16];           //����д���������豸��
	unsigned  int       addrhi;             //����д�����ĸߵ�ַ��������λ
	unsigned  int       addrlo;             //����д�����ĵ͵�ַ��������λ
	unsigned  int       lenhi;				//����д�����ĳ��ȣ���32λ��������λ
	unsigned  int       lenlo;				//����д�����ĳ��ȣ���32λ��������λ
	unsigned  char      dl_filename[16];    //����д�������ļ����ƣ����ȹ̶�16�ֽ�
	unsigned  char      vf_filename[16];    //����д������У���ļ����ƣ����ȹ̶�16�ֽ�
	unsigned  int       encrypt;            //����д�����������Ƿ���м��� 0:����   1��������
	unsigned  int       verify;             //����д�����������Ƿ����У�� 0:��У�� 1��У��
}
dl_one_part_info;
//������д��Ϣ
typedef struct tag_download_info
{
	unsigned  int       crc32;				        		        //crc
	unsigned  int       version;                                    //�汾��  0x00000101
	unsigned  char 	    magic[8];			        		        //"softw311"
	unsigned  int       download_count;             		        //��Ҫ��д�ķ�������
	unsigned  int       stamp[3];									//����
	dl_one_part_info	one_part_info[MBR_MAX_PART_COUNT];	//��д��������Ϣ
	unsigned  char      res[DL_RESERVED];
}
download_info;

#endif	//_NAND_MBR_H_

/* end of _NAND_MBR_H_ */

