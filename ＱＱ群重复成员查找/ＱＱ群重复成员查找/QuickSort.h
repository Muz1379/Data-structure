#pragma once

int QuickSort( resNODE * list, resNODE * end)
{
	if(list == NULL || list == end)
	{
		return OK;
	}

	resNODE * key = list;//keyΪ���ĵ�
	resNODE * preP = key;
	resNODE * p = key->next;//�洢�㣬�����ָ�뽻���ĵ�
	resNODE * preQ = key;
	resNODE * q = key->next;//��ָ�룬
	resNODE temp = { NULL };//��Ϊ����ֵʱʹ�õ���ʱ����

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