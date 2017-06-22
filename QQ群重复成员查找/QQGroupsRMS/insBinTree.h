#pragma once
#pragma execution_character_set("utf-8")

#include <string.h>

#define OK 1
#define ERR -1
#define NULL 0

int insbintree( struct BINTREE * bintree, struct BINTREE * item )
{
	if(strcmp( bintree->member->qqNum, item->member->qqNum ) > 0)
	{
		if(bintree->left != NULL)//左子结点不是叶子结点
		{
			insbintree( bintree->left, item );
		}
		else
		{
			bintree->left = item;
			return OK;
		}
	}
	else//QQ号唯一，不会出现两qq号相同的情况，因此，不考虑字符串想等的情况。
	{
		if(bintree->right != NULL)//左子结点不是叶子结点
		{
			insbintree( bintree->right, item );
		}
		else
		{
			bintree->right = item;
			return OK;
		}
	}

	return OK;
}