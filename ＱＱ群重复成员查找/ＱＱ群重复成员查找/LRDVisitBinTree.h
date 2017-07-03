#pragma once

int LRDvisitbintree( binTreeNODE * bintree, binTreeNODE * hashB[], resNODE * resList )
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