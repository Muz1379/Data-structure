#pragma once


#include <string.h>
#include <stdlib.h>

#define OK 1
#define ERR -1
#define NULL 0
#define HASHLENGTH 500

#include "BINNode.h"
#include "MemberNode.h"
#include "resNode.h"

#include "InsResList.h"
//���������bintreeΪ����������itemΪ�������resListΪ�������

int DLRsearchbintree( struct BINTREE * bintree, struct BINTREE * item, struct RESNODE * resList )
{
	if(bintree == NULL)//��㲻���ڣ�ֱ�ӷ��ء�
		return OK;

	int flag = 0;
	flag = strcmp( item->member->qqNum, bintree->member->qqNum );//item<bintreeС����,item==bintree�����㣬item>bintree������

	if(flag == 0)
	{
		struct RESNODE * res = { NULL };
		res = (struct RESNODE *)malloc( sizeof( struct RESNODE ) );
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