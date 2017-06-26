#pragma once
#pragma execution_character_set("utf-8")
#include "listNode.h"
void listAdd( struct NODE *l, struct NODE *p )
{
	while(l->next != 0)
		l = l->next;
	l->next = p;
}