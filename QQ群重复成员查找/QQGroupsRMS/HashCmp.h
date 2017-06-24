#pragma once
#pragma execution_character_set("utf-8")

#define OK 1
#define ERR -1
#define NULL 0
#define HASHLENGTH 500

//将哈希表看作按照一定规则组织起来的二叉查找树森林。哈希函数求得二叉查找树的树根

int hashcmp( struct BINTREE * hashA[], struct BINTREE *hashB[], struct RESNODE * resList)
{
	int i = 0;

	for(i = 0; i < HASHLENGTH; i++)//遍历hashA，
	{
		if(hashA[i] != NULL)
		{
			LRDvisitbintree( hashA[i], hashB, resList );
		}
	}

	return OK;
}