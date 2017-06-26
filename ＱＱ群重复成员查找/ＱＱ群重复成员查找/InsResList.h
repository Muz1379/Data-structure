#pragma once

#include "resNode.h"

int insreslist( struct RESNODE * list, struct RESNODE * p )
{
	while(list->next != NULL)
	{
		list = list->next;
	}
	list->next = p;
	return OK;
}