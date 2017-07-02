#pragma once
//判断是否为空栈，返回栈内元素个数
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