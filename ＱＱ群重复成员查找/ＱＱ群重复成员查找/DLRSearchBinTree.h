#pragma once

//���������bintreeΪ����������itemΪ�������resListΪ�������
int DLRsearchbintree( binTreeNODE * bintree, binTreeNODE * item, resNODE* resList )
{
	if(bintree == NULL)//��㲻���ڣ�ֱ�ӷ��ء�
		return OK;

	int flag = 0;
	flag = strcmp( item->member->qqNum, bintree->member->qqNum );//item<bintreeС����,item==bintree�����㣬item>bintree������

	if(flag == 0)
	{
		resNODE * res = { NULL };
		res = (resNODE * )malloc( sizeof( resNODE ) );
		res->A = item->member;
		res->B = bintree->member;
		res->next = NULL;
		insreslist( resList, res );
		return OK;
	}
	if(flag > 0)//��ֵ����
	{
		DLRsearchbintree( bintree->right, item, resList );
	}
	else
	{
		DLRsearchbintree( bintree->left, item, resList );
	}

	return OK;
}