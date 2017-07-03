#pragma once

#include "resNode.h"

int insreslist( resNODE * list, resNODE * p )
{
	while(list->next != NULL)
	{
		list = list->next;
	}
	list->next = p;
	return OK;
}