#pragma once

#include <string.h>


int insbintree( struct BINTREE * bintree, struct BINTREE * item )
{
	if(strcmp( bintree->member->qqNum, item->member->qqNum ) > 0)
	{
		//左子结点不是叶子结点
		if(bintree->left != NULL)
		{
			insbintree( bintree->left, item );
		}
		else
		{
			bintree->left = item;
			return OK;
		}
	}
	//QQ号唯一，不会出现两qq号相同的情况，因此，不考虑字符串想等的情况。
	else
	{
		//左子结点不是叶子结点
		if(bintree->right != NULL)
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