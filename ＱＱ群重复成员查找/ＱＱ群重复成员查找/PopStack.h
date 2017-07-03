#pragma once
//出栈，栈顶元素与二号元素交换值，将交换后的二号元素作为栈顶元素弹出
struct STACKNODE * PopStack( STACK * stack)
{
	STACK * RES;

	RES = stack->next;
	stack->next = RES->next;
	
	RES->next = NULL;

	return RES;
}