#pragma once
#pragma execution_character_set("utf-8")
//�������ڵ㶨��
typedef struct RESNODE
{
	struct MEMBERNODE * A;
	struct MEMBERNODE * B;
	struct RESNODE * next;
};