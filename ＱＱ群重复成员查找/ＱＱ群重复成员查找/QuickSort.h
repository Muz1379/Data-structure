#pragma once

int QuickSort( struct RESNODE * list, struct RESNODE * end)
{
	if(list == NULL || list == end)
	{
		return OK;
	}

	struct RESNODE * key = list;
	struct RESNODE * preP = key;
	struct RESNODE * p = key->next;
	struct RESNODE * preQ = key;
	struct RESNODE * q = key->next;

	struct RESNODE temp = { NULL };


	while(preQ != end)
	{
		if(strcmp( key->A->qqNum, q->A->qqNum ) > 0)
		{
			if(q != p)
			{
				temp.A = p->A;
				temp.B = p->B;
				p->A = q->A;
				p->B = q->B;
				q->A = temp.A;
				q->B = temp.B;
			}

			preP = p;
			p = p->next;
			preQ = q;
			q = q->next;
		}
		else
		{
			preQ = q;
			q = q->next;
		}
	}

	temp.A = preP->A;
	temp.B = preP->B;
	preP->A = key->A;
	preP->B = key->B;
	key->A = temp.A;
	key->B = temp.B;

	QuickSort( key, preP );
	QuickSort( preP->next, end );

	return OK;
}