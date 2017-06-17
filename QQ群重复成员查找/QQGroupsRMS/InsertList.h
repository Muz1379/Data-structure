#pragma once
#pragma execution_character_set("utf-8")

int insertlist( struct RESNODE * list, struct RESNODE * p)
{
	while(list->next != 0)
	{
		list = list->next;
	}
	list->next = p;
}