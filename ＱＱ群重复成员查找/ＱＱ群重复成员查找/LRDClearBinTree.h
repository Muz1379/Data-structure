#pragma once
#include <malloc.h>
#include "BINNode.h"

int LRDClearBinTree( binTreeNODE * bintree )
{
	if(bintree == NULL)
		return OK;
	if(bintree->left != NULL)//遍历左子树
	{
		LRDClearBinTree( bintree->left);
	}
	if(bintree->right != NULL)//遍历右子树
	{
		LRDClearBinTree( bintree->right );
	}
	
	free( bintree );
	bintree = NULL;
	return OK;
}