#pragma once
//��ջ��ջ��Ԫ�������Ԫ�ؽ���ֵ����������Ķ���Ԫ����Ϊջ��Ԫ�ص���
struct STACKNODE * PopStack( STACK * stack)
{
	STACK * RES;

	RES = stack->next;
	stack->next = RES->next;
	
	RES->next = NULL;

	return RES;
}