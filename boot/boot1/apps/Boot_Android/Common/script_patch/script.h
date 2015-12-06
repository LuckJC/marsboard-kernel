#ifndef _SCRIPT_H_
#define _SCRIPT_H_

#define   MAX_PATH                   256
#define   ITEM_MAIN_NAME_MAX          32

#define   DATA_COUNT_MAX         (4)
#define   DATA_TYPE_SINGLE_WORD  (1)
#define   DATA_TYPE_STRING       (2)
#define   DATA_TYPE_MULTI_WORD   (3)
#define   DATA_TYPE_GPIO         (4)

typedef struct _script_item
{
	char  item_name[ITEM_MAIN_NAME_MAX];           //��������
	int   item_length;                             //������Ա�ĸ���
	int   item_offset;							   //������Ա��ʼ��ƫ����
}
script_item_t;

typedef struct _script_head
{
	int   item_num;
	int   version[3];
}
script_head_t;

extern int script_patch(char *script_name, void *script_buf, int boot_script_type);

#endif   //_SCRIPT_H_

