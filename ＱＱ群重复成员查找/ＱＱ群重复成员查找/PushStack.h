#pragma once
//压入栈，将新结点插入头结点后的位置，完成压入栈
int PushStack( STACK * stack, STACK * item)
{
	item->next = stack->next;
	stack->next = item;
	STACK * resTemp = NULL;

	return OK;
}