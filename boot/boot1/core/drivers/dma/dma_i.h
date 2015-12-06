/*
**********************************************************************************************************************
*											        eGon
*						           the Embedded GO-ON Bootloader System
*									       eGON driver sub-system
*
*						  Copyright(C), 2006-2010, SoftWinners Microelectronic Co., Ltd.
*                                           All Rights Reserved
*
* File    : dmac_i.h
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
#ifndef	_EGON2_DMAC_I_H_
#define	_EGON2_DMAC_I_H_

#define CFG_SW_DMA_NORMAL_MAX       8
#define CFG_SW_DMA_DEDICATE_MAX     8

#define CFG_SW_DMA_NORMAL_BASE              (DMAC_REGS_BASE + 0x100              )
#define CFS_SW_DMA_NORMAL0                  (CFG_SW_DMA_NORMAL_BASE + 0x20 * 0   )
#define CFS_SW_DMA_NORMAL1                  (CFG_SW_DMA_NORMAL_BASE + 0x20 * 1   )
#define CFS_SW_DMA_NORMAL2                  (CFG_SW_DMA_NORMAL_BASE + 0x20 * 2   )
#define CFS_SW_DMA_NORMAL3                  (CFG_SW_DMA_NORMAL_BASE + 0x20 * 3   )
#define CFS_SW_DMA_NORMAL4                  (CFG_SW_DMA_NORMAL_BASE + 0x20 * 4   )
#define CFS_SW_DMA_NORMAL5                  (CFG_SW_DMA_NORMAL_BASE + 0x20 * 5   )
#define CFS_SW_DMA_NORMAL6                  (CFG_SW_DMA_NORMAL_BASE + 0x20 * 6   )
#define CFS_SW_DMA_NORMAL7                  (CFG_SW_DMA_NORMAL_BASE + 0x20 * 7   )

#define CFG_SW_DMA_DEDICATE_BASE            (DMAC_REGS_BASE + 0x300               )
#define CFG_SW_DMA_DEDICATE0                (CFG_SW_DMA_DEDICATE_BASE + 0x20 * 0 )
#define CFG_SW_DMA_DEDICATE1                (CFG_SW_DMA_DEDICATE_BASE + 0x20 * 1 )
#define CFG_SW_DMA_DEDICATE2                (CFG_SW_DMA_DEDICATE_BASE + 0x20 * 2 )
#define CFG_SW_DMA_DEDICATE3                (CFG_SW_DMA_DEDICATE_BASE + 0x20 * 3 )
#define CFG_SW_DMA_DEDICATE4                (CFG_SW_DMA_DEDICATE_BASE + 0x20 * 4 )
#define CFG_SW_DMA_DEDICATE5                (CFG_SW_DMA_DEDICATE_BASE + 0x20 * 5 )
#define CFG_SW_DMA_DEDICATE6                (CFG_SW_DMA_DEDICATE_BASE + 0x20 * 6 )
#define CFG_SW_DMA_DEDICATE7                (CFG_SW_DMA_DEDICATE_BASE + 0x20 * 7 )

#define CFG_SW_DMA_OTHER_BASE               (DMAC_REGS_BASE + 0x300 + 0x10       )
#define CFG_SW_DMA_DEDICATE0_OTHER          (CFG_SW_DMA_OTHER_BASE + 0x20 * 0    )
#define CFG_SW_DMA_DEDICATE1_OTHER          (CFG_SW_DMA_OTHER_BASE + 0x20 * 1    )
#define CFG_SW_DMA_DEDICATE2_OTHER          (CFG_SW_DMA_OTHER_BASE + 0x20 * 2    )
#define CFG_SW_DMA_DEDICATE3_OTHER          (CFG_SW_DMA_OTHER_BASE + 0x20 * 3    )
#define CFG_SW_DMA_DEDICATE4_OTHER          (CFG_SW_DMA_OTHER_BASE + 0x20 * 4    )
#define CFG_SW_DMA_DEDICATE5_OTHER          (CFG_SW_DMA_OTHER_BASE + 0x20 * 5    )
#define CFG_SW_DMA_DEDICATE6_OTHER          (CFG_SW_DMA_OTHER_BASE + 0x20 * 6    )
#define CFG_SW_DMA_DEDICATE7_OTHER          (CFG_SW_DMA_OTHER_BASE + 0x20 * 7    )

struct sw_dma
{
    volatile unsigned int config;           /* DMA���ò���              */
    volatile unsigned int src_addr;         /* DMA����Դ��ַ            */
    volatile unsigned int dst_addr;         /* DMA����Ŀ�ĵ�ַ          */
    volatile unsigned int bytes;            /* DMA�����ֽ���            */
};

typedef volatile struct sw_dma *sw_dma_t;

struct sw_dma_other
{
    volatile unsigned int page_size;        /* DMA����PAGE SIZE         */
    volatile unsigned int page_step;        /* DMA����PAGE STEP         */
    volatile unsigned int comity_counter;   /* DMA����comity counter    */
};

typedef volatile struct sw_dma_other *sw_dma_other_t;

typedef struct sw_dma_channal_set
{
    unsigned int            used;           /* DMA�Ƿ�ʹ��            */
      signed int            channalNo;      /* DMAͨ�����              */
    sw_dma_t                channal;        /* DMAͨ��                  */
    sw_dma_other_t          other;          /* DMA��������              */
}
sw_dma_channal_set_t;


typedef struct __ndma_config_set
{
    unsigned int      src_drq_type     : 5;            //Դ��ַ�洢���ͣ���DRAM, SPI,NAND�ȣ��μ�  __ndma_drq_type_t
    unsigned int      src_addr_type    : 1;            //ԭ��ַ���ͣ�����������߲���  0:����ģʽ  1:���ֲ���
    unsigned int      src_secure       : 1;            //source secure  0:secure  1:not secure
    unsigned int      src_burst_length : 2;            //����һ��burst��� 0:1   1:4   2:8
    unsigned int      src_data_width   : 2;            //���ݴ����ȣ�0:һ�δ���8bit��1:һ�δ���16bit��2:һ�δ���32bit��3:����
    unsigned int      reserved0        : 5;
    unsigned int      dst_drq_type     : 5;            //Ŀ�ĵ�ַ�洢���ͣ���DRAM, SPI,NAND��
    unsigned int      dst_addr_type    : 1;            //Ŀ�ĵ�ַ���ͣ�����������߲���  0:����ģʽ  1:���ֲ���
    unsigned int      dst_secure       : 1;            //dest secure  0:secure  1:not secure
    unsigned int      dst_burst_length : 2;            //����һ��burst��� ��0��Ӧ��1����1��Ӧ��4,
    unsigned int      dst_data_width   : 2;            //���ݴ����ȣ�0:һ�δ���8bit��1:һ�δ���16bit��2:һ�δ���32bit��3:����
    unsigned int      wait_state       : 3;            //�ȴ�ʱ�Ӹ��� ѡ��Χ��0-7
    unsigned int      continuous_mode  : 1;            //ѡ����������ģʽ 0:����һ�μ����� 1:�������䣬��һ��DMA������������¿�ʼ����
    unsigned int      reserved1        : 1;
}
__ndma_config_t;

typedef struct __ddma_config_set
{
    unsigned int      src_drq_type     : 5;            //Դ��ַ�洢���ͣ���DRAM, SPI,NAND�ȣ��μ�  __ddma_src_type_t
    unsigned int      src_addr_type    : 2;            //ԭ��ַ���ͣ�����������߲���  0:����ģʽ  1:���ֲ���  2:Hģʽ  3:Vģʽ
    unsigned int      src_burst_length : 2;            //����һ��burst��� ��0��Ӧ��1����1��Ӧ��4,
    unsigned int      src_data_width   : 2;            //���ݴ����ȣ�0:һ�δ���8bit��1:һ�δ���16bit��2:һ�δ���32bit��3:����
    unsigned int      reserved0        : 5;
    unsigned int      dst_drq_type     : 5;            //Ŀ�ĵ�ַ�洢���ͣ���DRAM, SPI,NAND��, �μ�  __ddma_dst_type_t
    unsigned int      dst_addr_type    : 2;            //Ŀ�ĵ�ַ���ͣ�����������߲��� 0:����ģʽ  1:���ֲ���  2:Hģʽ  3:Vģʽ
    unsigned int      dst_burst_length : 2;            //����һ��burst��� ��0��Ӧ��1����1��Ӧ��4,
    unsigned int      dst_data_width   : 2;            //���ݴ����ȣ�0:һ�δ���8bit��1:һ�δ���16bit��2:һ�δ���32bit��3:����
    unsigned int      reserved1        : 3;
    unsigned int      continuous_mode  : 1;            //ѡ����������ģʽ 0:����һ�μ����� 1:�������䣬��һ��DMA������������¿�ʼ����
    unsigned int      reserved2        : 1;
}
__ddma_config_t;

#endif	/* _EGON2_DMAC_I_H_ */

