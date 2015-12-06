#include "include.h"

static  volatile  unsigned  timerl = 0;

//ʹ��TIMER5��¼ʱ�䣬�����Ӳ�����г�ʼ������

//����һ����ʱ����ʱ
unsigned    timer_start(void)
{
    __u32 reg_val;
    __u32 i;

	*(unsigned int *)(0x01c20C00 + 0x6C) = 0;
	*(unsigned int *)(0x01c20C00 + 0x70) = 0;
	do
	{
		reg_val = ((*(unsigned int *)(0x01c20C00 + 0x60)) >> 4) & 0x01;
	}
	while(reg_val);
	for(i=0;i<50;i++);

	do
	{
		reg_val = ((*(unsigned int *)(0x01c20C00 + 0x60)) >> 5) & 0x01;
	}
	while(reg_val);

	timerl = *(unsigned int *)(0x01c20C00 + 0x6C);

    return 0;
}

//ʹ��AVS��¼ʱ�䣬����ȡ��start��ʼ��stop֮���ʱ�䣬��λms
unsigned   timer_stop(void)
{
    __u32 reg_val;

	do
	{
		reg_val = ((*(unsigned int *)(0x01c20C00 + 0x60)) >> 5) & 0x01;
	}
	while(reg_val);

	timerl = (*(unsigned int *)(0x01c20C00 + 0x6C)) - timerl;

	timerl/= 24000;

    return timerl;
}


