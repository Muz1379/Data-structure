#pragma once
//�ж��Ƿ�Ϊ��ջ������ջ��Ԫ�ظ���
int isEmptyStack( struct STACKNODE * stack )
{
	int count = 0;
	struct STACKNODE * p = stack;
	while(p->res != NULL)
	{
		count++;
		p = p->next;
	}
	return count;
}