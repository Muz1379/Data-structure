#pragma once


#define OK 1
#define ERR -1
#define NULL 0

#include "BINNode.h"
#include "SearchHash.h"

int LRDvisitbintree( struct BINTREE * bintree, struct BINTREE *hashB[], struct RESNODE * resList )
{
	if(bintree->left != NULL)//遍历左子树
	{
		LRDvisitbintree( bintree->left, hashB, resList );
	}
	if(bintree->right != NULL)//遍历右子树
	{
		LRDvisitbintree( bintree->right, hashB, resList );
	}
	searchhash( bintree, hashB, resList );
	return OK;
}