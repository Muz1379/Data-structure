#pragma once
#pragma execution_character_set("utf-8")
//������������ͻ����ڵ�
typedef struct LISTNODE
{
	struct MEMBERNODE * member;
	struct LIST * next;
}LNODE;