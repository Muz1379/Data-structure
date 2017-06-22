#pragma once
#pragma execution_character_set("utf-8")

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "BINNode.h"
#include "MemberNode.h"
#include "insBinTree.h"

#define OK 1
#define ERR -1
#define NULL 0
#define HASHLENGTH 500

int inshash( struct BINTREE * hashT[], struct BINTREE * item)
{
	char qqF4char[5];		//QQ号前四个数字
	int qqNumF4;	 		//因为int两字节，最大值为65535，可完全表示四位数。
	int hashP;		 		//哈希表下标

	strncpy(qqF4char,item->member->qqNum,4);
	qqF4char[4] = '\0';
	qqNumF4 = atoi( qqF4char );

	hashP = qqNumF4 % HASHLENGTH;

	if(hashT[hashP] == NULL)//该位置无item,则创建二叉查找树
	{
		hashT[hashP] = item;
	}
	else					//首次哈希失败，则退化为二叉树。
	{
							//二叉树插入，小值在左，大值在右
		if(insbintree( hashT[hashP], item ) != OK)
		{
			printf( "二叉树插入失败" );
			return ERR;
		}
	}
	return OK;
}