#pragma once
#pragma execution_character_set("utf-8")
//结果链表节点定义
typedef struct RESNODE
{
	struct MEMBERNODE * A;
	struct MEMBERNODE * B;
	struct RESNODE * next;
};