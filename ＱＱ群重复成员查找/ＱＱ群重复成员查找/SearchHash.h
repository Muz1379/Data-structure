#pragma once

//哈希查找，arg[1]为哈希表，arg[2]为要查找的元素，若找到则返回被查找项，若找不到，则返回0

int searchhash( binTreeNODE * item, binTreeNODE * hashB[], resNODE * resList )
{
	char qqF4char[6];		//QQ号前四个数字
	int qqNumF4;	 		//因为int两字节，最大值为65535，可完全表示四位数。
	int i = 0;

	strncpy( qqF4char, item->member->qqNum, 5 );
	qqF4char[4] = '\0';
	qqNumF4 = atoi( qqF4char );

	i = qqNumF4 % HASHLENGTH;

	if(hashB[i] != NULL)		//哈希散列得到的位置存在元素，即二叉查找树存在一棵
	{
		//查找该二叉树
		//先序遍历查找，从树hashB[i]中，查找item，存在结果追加给链表resList
		DLRsearchbintree( hashB[i], item, resList );
	}
	else
	{
		return OK;
	}

	return OK;
}