#pragma once
//ѹ��ջ�����½�����ͷ�����λ�ã����ѹ��ջ
int PushStack( struct STACKNODE * stack,struct STACKNODE * item)
{
	item->next = stack->next;
	stack->next = item;
	struct RESNODE * resTemp = NULL;

	return OK;
}