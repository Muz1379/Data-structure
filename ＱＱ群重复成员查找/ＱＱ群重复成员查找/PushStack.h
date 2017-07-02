#pragma once
//压入栈，将新结点插入头结点后的位置，完成压入栈
int PushStack( struct STACKNODE * stack,struct STACKNODE * item)
{
	item->next = stack->next;
	stack->next = item;
	struct RESNODE * resTemp = NULL;

	return OK;
}