#pragma once

//先序遍历。bintree为待查找树，item为待查找项，resList为结果链表
int DLRsearchbintree( binTreeNODE * bintree, binTreeNODE * item, resNODE* resList )
{
	if(bintree == NULL)//结点不存在，直接返回。
		return OK;

	int flag = 0;
	flag = strcmp( item->member->qqNum, bintree->member->qqNum );//item<bintree小于零,item==bintree等于零，item>bintree大于零

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
	if(flag > 0)//大值在右
	{
		DLRsearchbintree( bintree->right, item, resList );
	}
	else
	{
		DLRsearchbintree( bintree->left, item, resList );
	}

	return OK;
}