#pragma once

//结果链表节点定义
typedef struct RESNODE
{
	MNODE * A;
	MNODE * B;
	struct RESNODE * next;
}resNODE;