#pragma once
/*#pragma execution_character_set("ANSI") */                   
//内置系统头文件
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

#define OK 1
#define ERR -1
#define NULL 0
#define HASHLENGTH 500

//数据结构
#include "BINNode.h"
#include "MemberNode.h"
#include "resNode.h"
#include "STACKNODE.h"
//函数声明
#include "Function.h"
//函数定义
#include "FileRead.h"
#include "ContExec.h"
#include "isChinese.h"
#include "KMP.h"
#include "insHash.h"
#include "SearchHash.h"
#include "InsResList.h"
#include "insBinTree.h"
#include "LRDVisitBinTree.h"
#include "HashCmp.h"
#include "DLRSearchBinTree.h"
#include "FileWrite.h"
#include "QuickSort.h"
#include "PopStack.h"
#include "PushStack.h"
#include "isEmptyStack.h"

int main( void )
{
	int flag = 0;
	//TODO:测试用
	char fileNameA[100] = "testA.txt";	                //文件名A
	char fileNameB[100] = "testC.txt";	                //文件名B

	char * contA = NULL;			                //内容字符串A
	char * contB = NULL;			                //内容字符串B
	struct BINTREE * hashA[HASHLENGTH] = { NULL };	//设定哈希表长500，由于目前qq群最大人数为2000，哈希冲突使用拉链法解决。
	struct BINTREE * hashB[HASHLENGTH] = { NULL };
	struct BINTREE * tempA = { NULL };
	struct BINTREE * tempB = { NULL };
	struct RESNODE * resList = { NULL };
	struct RESNODE * resListEnd;
	struct RESNODE * resTemp;

	//初始化结果链表头
	struct MEMBERNODE memberA = {
		"A群名","A群名片","QQ号"
	};
	struct MEMBERNODE memberB = {
		"B群名","B群名片","QQ号"
	};
	resList = (struct RESNODE *)malloc( sizeof( struct RESNODE ) );
	resList->A = &memberA;
	resList->B = &memberB;
	resList->next = NULL;


	int i = 0;
	int j = 0;

	/*system( "chcp 65001" );*/
	system( "cls" );
	printf( "= = = = = = = = = = = = = = = = =\n" );
	printf( "\n该程序用于查找两qq群重复成员\n" );
	printf( "\n" );
	printf( "= = = = = = = = = = = = = = = = =\n" );
	printf( "\n" );

	//TODO:此处打开文件生成字符串，应添加异常处理模块
	//TODO:测试注释
	/*
	printf( "请输入QQ群【A】成员名单文件名：" );
	scanf( "%s", fileNameA );
	contA = fileread( fileNameA );
	printf( "请输入QQ群【B】成员名单文件名：" );
	scanf( "%s", fileNameB );
	contB = fileread( fileNameB );
	*/
	fileread( fileNameA, hashA );
	fileread( fileNameB, hashB );

	//查找哈希表，生成结果链表
	hashcmp( hashA, hashB, resList );
	FileWrite( resList );//写入结果文件
	printf( "查找完毕，结果存储在resList单链表和文件result.txt中\n" );
	
	resTemp = resList;
	if(resTemp->next != NULL)
	{
		while(resTemp != NULL)
		{
			printf( "\n" );
			printf( "  %-20s\t%-35s\t%-30s\t%-35s\t%-30s\t", resTemp->A->qqNum, resTemp->A->qqGroup, resTemp->A->personCard, resTemp->B->qqGroup, resTemp->B->personCard );
			resTemp = resTemp->next;
		}
	}
	else
	{
		printf( "两群内无重复人员" );
	}
	printf( "\n\n" );
	printf( "是否进行排序——快速排序：是 1      否 0\n" );
	//TODO:测试设定
	//scanf( "%d", &flag );
	flag = 1;
	if(flag == 1)
	{
		resListEnd = resList;
		while(resListEnd->next != NULL)
		{
			resListEnd = resListEnd->next;
		}
		QuickSort( resList->next ,resListEnd);
	}

	printf( "\n" );

	resTemp = resList;
	if(resTemp->next != NULL)
	{
		while(resTemp != NULL)
		{
			printf( "\n" );
			printf( "  %-20s\t%-35s\t%-30s\t%-35s\t%-30s\t", resTemp->A->qqNum, resTemp->A->qqGroup, resTemp->A->personCard, resTemp->B->qqGroup, resTemp->B->personCard );
			resTemp = resTemp->next;
		}
	}
	else
	{
		printf( "两群内无重复人员" );
	}



	printf( "\n" );
	system( "pause" );
	return 0;
}