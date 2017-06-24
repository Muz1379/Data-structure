#pragma once


#include "BINNode.h"

#define OK 1
#define ERR -1
#define NULL 0
/*
找到符合MEMBERNODE格式的数据，生成MNODE,并插入哈希表。返回0
*/

int contexec( char * str, struct BINTREE * hashT[] )
{
	char * qqG[50] = { 0 };		//群名
	char NL[] = { 0x0d,0x0a };			   			   					   //utf-8中换行符\n\r。
	int j = 0;
	long i = 0;
	long strP = 0;						   			   					   //字符串指针
	long strEnd = 0;
	int intTemp = 1;								   					   //分析发现，每个成员结构前，有一个数字表示是第几个成员
	struct MEMBERNODE * memberT = { NULL };					   					   //过渡存放成员内存指针
	struct BINTREE * listT = { NULL };				   					   //哈希元素指针


	strEnd = kmp( str, "友情链接", 0 );
	strP = kmp( str, "反馈", 0 );
	strP = strP + sizeof( "反馈" );		   			   					   //找到“反馈”的尾部位置。向后过掉几个换行符之后，为群名。


	for(; !isChinese( str+ strP ); strP++);			   					   //过掉“反馈”和群名之间的换行符。
	strP--;
	j = 0;
	do
	{
		qqG[j] = *(str + strP);
		j++;
		strP++;
	} while(*(str + strP-1) != (char)0x29);		   	   					   //TODO:此处字符转换问题
										   			   					   //群名片读取结束

	for(i = 0; i !=-1;)
	{
		i = kmp( str, "最后发言 \n\r\n\r  最后发言", strP );
		if(i > 0)						   					   //找到“最后发言”，字符串游标后移
		{
			strP = strP + i + sizeof( "最后发言" );
		}					   			   					   //找不到“最后发言”，跳出循环，结束查找。
	}
	for(; *(str + strP) != '1'; strP++);			   					   //成员列表第一个序号 1
													   					   //进入成员列表区块。开始处理
	for(; strP < strEnd; strP++) 
	{
		memberT = (struct MEMBERNODE *)malloc( sizeof( struct MEMBERNODE ) );
		strcpy( memberT->qqGroup, qqG );//赋给群名称

		j = 0;
		for(; j < 4 && strP<strEnd;strP++)							   	   //过滤两连续换行符
		{
			if(*(str + strP) == NL[j%2])
			{
				j++;
			}
			if(*(str + strP) != NL[j%2])
			{
				j = 0;
			}
		}
		j = 0;
		for(; j < 2 && strP<strEnd; strP++)						   		   //过滤一个换行符
		{
			if(*(str + strP) == NL[j % 2])
			{
				j++;
			}
			if(*(str + strP) != NL[j % 2])
			{
				j = 0;
			}
		}
		
		for(; (*(str + strP) == (char)0x20 ) && strP<strEnd; strP++);	   //去除前部空格
		strP--;
												   	   					   //提取群名片
		j = 0;
		while((*(str + strP) != (char)0x0d ) && strP<strEnd)		   	   //0x0d 为 \n
		{
			*((memberT->personCard) + j) = *(str + strP + j);
			strP++;
			j++;
		}
		*((memberT->personCard) + j) = '\0';

		j = 0;
		for(; j < 2 && strP<strEnd; strP++)						   		   //过滤一个换行符
		{
			if(*(str + strP) == NL[j % 2])
			{
				j++;
			}
		}
		
		for(; (*(str + strP) == (char)0x20) && strP<strEnd; strP++);	   //去除前部空格
		strP--;
													   					   //提取qq号。已知qq号后紧跟一空格
		for(j = 0;(*(str+strP)!=(char)0x20) && strP<strEnd; j++,strP++)
		{
			*((memberT->qqNum) + j) = *(str + strP);
		}
		*((memberT->qqNum) + j) = '\0';

		listT = (struct BINTREE *)malloc( sizeof( struct BINTREE ) );
		listT->member = memberT;
		listT->left = NULL;
		listT->right = NULL;

		if(inshash( hashT, listT ) != OK)
		{
			printf( "哈希失败\n" );
			printf( "QQ群：%s\tQQ名片：%s\tQQ号%s", listT->member->qqGroup, listT->member->personCard, listT->member->qqNum );
			return ERR;
		}
	}
	return OK;
}