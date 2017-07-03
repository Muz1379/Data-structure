#pragma once

//将哈希表看作按照一定规则组织起来的二叉查找树森林。哈希函数求得二叉查找树的树根

int hashcmp( binTreeNODE * hashA[], binTreeNODE * hashB[], resNODE* resList )
{
	int i = 0;

	//遍历hashA，
	for(i = 0; i < HASHLENGTH; i++)
	{
		if(hashA[i] != NULL)
		{
			LRDvisitbintree( hashA[i], hashB, resList );
		}
	}

	return OK;
}