#pragma once

#include <malloc.h>

#include "BINNode.h"
#include "MemberNode.h"

#define OK 1
#define ERR -1

#include <malloc.h>
/*
找到符合MEMBERNODE格式的数据，生成MNODE,并插入哈希表。返回 OK
*/

int contexec( char * str, binTreeNODE * hashT[] )
{
	char qqG[100];													//群名
	char NL[] = { 0x0d,0x0a };			   			   				//换行符\n\r。
	int j = 0;
	long i = 0;
	long strP = 0;						   			   				//字符串指针
	long strEnd = 0;
	char * strA;
	MNODE * memberT = { NULL };					   		//过渡存放成员内存指针
	binTreeNODE * listT = { NULL };				   				//哈希元素指针

	unsigned char youqinglianjie[9] = "友情链接";
	unsigned char fankui[5] = "反馈";
	unsigned char zuihoufanyan[] = "最后发言";

	strEnd = kmp( str, youqinglianjie, 0 );							//友情链接
	strP = kmp( str, fankui, 0 );									//反馈

	int size = sizeof( char ) * (strEnd + 1);
	strA = (char *)malloc( size );

	strncpy( strA, str, strEnd );

	free( str );
	str = NULL;

	strP = strP + sizeof( fankui );		   	//找到“反馈”的尾部位置。向后过掉几个换行符之后，为群名。
	strP = strP + 5;
	if(strP >= strEnd)
	{
		printf( "\n\n  开始位置计算出错\n\n" );
		return ERR;
	}

	for(j = 0; j == 0; strP++)					//过掉“反馈”和群名之间的换行符。和空格
	{
		j = 1;
		if(*(strA + strP) == '\n')
			j = 0;
		if(*(strA + strP) == '\r')
			j = 0;
		if(*(strA + strP) == ' ')
			j = 0;
	}
	strP--;
	j = 0;
	do
	{
		qqG[j] = *(strA + strP);
		j++;
		strP++;
	} while(*(strA + strP - 1) != (char)0x29);
	qqG[j] = '\0';														 //群名片读取结束

	for(j = 0; j < 3;)
	{
		i = -1;
		i = kmp( strA, zuihoufanyan, strP );
		if(i != -1)
		{
			j++;
			strP = i + sizeof( zuihoufanyan );
		}
	}

	for(; strP < strEnd; strP++)
	{
		memberT = (MNODE *)malloc( sizeof( MNODE ) );
		strncpy( memberT->qqGroup, qqG, 100 );								//赋给群名称
		/*
		QQ信息由一个群内编号。QQ昵称，群名片，QQ号，四项（四行）构成。
		编号和之前的元素之间可能间隔一个换行符或两个换行符，并数个空格。
		编号和昵称之间有两个换行符，并数个空格。
		昵称与群名片之间有一个换行符，并数个空格。
		群名片与QQ号之间有一个换行符，并数个空格。QQ号结束后，紧跟有一个空格。
		之后为我们不需要的日期等信息。
		*/
		j = 0;
		for(; j < 2 && strP < strEnd; strP++)						   		 //过滤一个换行符
		{
			if(*(strA + strP) == NL[j % 2])
			{
				j++;
			}
			else
			{
				j = 0;
			}
		}

		for(; *(strA + strP) < '0' || *(strA + strP) > '9'; strP++);//找到编号
		for(; *(strA + strP) >= '0' && *(strA + strP) <= '9'; strP++);//过滤编号

		for(j = 0; j == 0; strP++)				//过掉编号和昵称之间的换行符。和空格。这里认为昵称均不为空格
		{
			j = 1;
			if(*(strA + strP) == '\n')
				j = 0;
			if(*(strA + strP) == '\r')
				j = 0;
			if(*(strA + strP) == ' ')
				j = 0;
		}
		//此处过掉了昵称
		for(j = 0; j < 2 && strP < strEnd; strP++)			//过滤一个换行符
		{
			if(*(strA + strP) == NL[j % 2])
			{
				j++;
			}
			else
			{
				j = 0;
			}
		}
		for(; (*(strA + strP) == (char)0x20) && strP < strEnd; strP++);	   //去除前部空格
		j = 0;
		while((*(strA + strP) != (char)0x0d) && strP < strEnd)		   	   	 //读QQ群名片
		{
			*((memberT->personCard) + j) = *(strA + strP);
			strP++;
			j++;
		}
		*((memberT->personCard) + j) = '\0';

		j = 0;
		for(; j < 2 && strP < strEnd; strP++)						   		  //过滤一个换行符
		{
			if(*(strA + strP) == NL[j % 2])
			{
				j++;
			}
		}

		for(; (*(strA + strP) == (char)0x20) && strP < strEnd; strP++);		//去除前部空格

		j = 0;																//提取qq号。已知qq号后紧跟一空格
		for(; (*(strA + strP) != (char)0x20) && strP < strEnd; j++, strP++)
		{
			*((memberT->qqNum) + j) = *(strA + strP);
		}
		*((memberT->qqNum) + j) = '\0';


		// 读入完最后一个数据项后，由于strP距离结束点仍有一段距离，所以会创建一个空项。
		//该条件用于判断是否为空，若空，则返回，不插入，表明已完成。
		if(*(memberT->qqNum) == '\0')
		{
			//free( strA );
			strA = NULL;
			return OK;
		}

		listT = (binTreeNODE *)malloc( sizeof( binTreeNODE ) );
		listT->member = memberT;
		listT->left = NULL;
		listT->right = NULL;

		if(inshash( hashT, listT ) != OK)
		{
			printf( "\n\n  哈希失败\n\n" );
			printf( "  QQ群：%s\tQQ名片：%s\tQQ号%s", listT->member->qqGroup, listT->member->personCard, listT->member->qqNum );
			free( strA );
			strA = NULL;

			return ERR;
		}
	}

	free( strA );
	strA = NULL;
	return OK;
}