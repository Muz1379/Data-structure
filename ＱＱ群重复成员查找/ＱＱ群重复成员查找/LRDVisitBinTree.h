#pragma once

int LRDvisitbintree( binTreeNODE * bintree, binTreeNODE * hashB[], resNODE * resList )
{
	if(bintree->left != NULL)//����������
	{
		LRDvisitbintree( bintree->left, hashB, resList );
	}
	if(bintree->right != NULL)//����������
	{
		LRDvisitbintree( bintree->right, hashB, resList );
	}
	searchhash( bintree, hashB, resList );
	return OK;
}