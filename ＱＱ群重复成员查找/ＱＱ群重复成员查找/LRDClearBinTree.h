#pragma once
#include <malloc.h>
#include "BINNode.h"

int LRDClearBinTree( binTreeNODE * bintree )
{
	if(bintree == NULL)
		return OK;
	if(bintree->left != NULL)//����������
	{
		LRDClearBinTree( bintree->left);
	}
	if(bintree->right != NULL)//����������
	{
		LRDClearBinTree( bintree->right );
	}
	
	free( bintree );
	bintree = NULL;
	return OK;
}