#pragma once
//ѹ��ջ�����½�����ͷ�����λ�ã����ѹ��ջ
int PushStack( STACK * stack, STACK * item)
{
	item->next = stack->next;
	stack->next = item;
	STACK * resTemp = NULL;

	return OK;
}