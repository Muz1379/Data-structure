#pragma once

int ClearResList( resNODE * list )
{
	if(list == NULL)
		return OK;
	else
		list = NULL;
	/*struct RESNODE * p = list->next;
	if(p == NULL)
		return OK;
	if(p->next != NULL)
		ClearResList( p );
	free( p );
	p = NULL;*/
	return OK;
}