#pragma once
#pragma execution_character_set("utf-8")
//拉链法——冲突链表节点
typedef struct LISTNODE
{
	struct MEMBERNODE * member;
	struct LIST * next;
}LNODE;