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
#include "InitGUI.h"
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
#include "ShowResult.h"
#include "ClearResList.h"
#include "ClearHash.h"
#include "LRDClearBinTree.h"


//TODO:该程序目前存在严重的指针越界或内存泄露问题。
//BUG:可能会导致程序无法运行，由于每次报错位置不同，暂时难以定位错误进行修复。

//如果调试失败，关机重启，或许就好了，#^_^#

int main( void )
{
	int flag = OK;
	char fileNameA[100] = { NULL };	   //文件名A
	char fileNameB[100] = { NULL };	   //文件名B

	//设定哈希表长500，由于目前qq群最大人数为2000，哈希冲突使用拉链法解决。
	binTreeNODE * hashA[HASHLENGTH] = { NULL };	
	binTreeNODE * hashB[HASHLENGTH] = { NULL };

	//定义结果链表
	resNODE * resList =  NULL ;
	resNODE * resListEnd = NULL;

	//初始化结果链表头数据
	MNODE memberA = {"A群名","A群名片","QQ号"};
	MNODE memberB = {"B群名","B群名片","QQ号"};

	//初始化界面
	Init();

	do
	{
		//置空存器储
		ClearHash( hashA );
		ClearHash( hashB );
		ClearResList( resList );

		resList = (resNODE *)malloc( sizeof( resNODE ) );
		resList->A = &memberA;
		resList->B = &memberB;
		resList->next = NULL;

		printf( "  请输入QQ群【A】成员名单文件名：" );
		scanf_s( "%s", fileNameA ,95);
		printf( "  请输入QQ群【B】成员名单文件名：" );
		scanf_s( "%s", fileNameB ,95);


		flag = fileread( fileNameA, hashA );
		if(flag == ERR)
		{
			printf( "\n\n  群成员名单 A 处理失败，未生成哈希表\n\n" );
			system( "pause" );
		}
		else
		{
			flag = fileread( fileNameB, hashB );
			if(flag == ERR)
			{
				printf( "\n\n  群成员名单 B 处理失败，未生成哈希表\n\n" );
				system( "pause" );
			}
			else
			{
				//查找哈希表，生成结果链表
				hashcmp( hashA, hashB, resList );
				//写入结果文件
				FileWrite( resList, "result.txt" );
				printf( "\n\n  查找完毕，结果存储在resList单链表和文件result.txt中\n\n" );
				ShowResult( resList );

				printf( "\n\n" );
				printf( "  是否进行排序——快速排序：是 1      否 0\n" );
				scanf_s( "%d", &flag );
				if(flag == 1)
				{
					resListEnd = resList;
					while(resListEnd->next != NULL)
					{
						resListEnd = resListEnd->next;
					}
					QuickSort( resList->next, resListEnd );
					printf( "\n" );
					printf( "\n" );
					ShowResult( resList );
					FileWrite( resList, "resultQuickSort.txt" );
					printf( "\n\n  快排结束，结果存储在resList单链表和文件resultQuickSort.txt中\n\n" );
				}
			}
		}

		printf( "\n\n" );
		printf( "  是否继续测试——是 1      否 0\n" );
		scanf_s( "%d", &flag );
	} while(flag == 1);
	
	printf( "\n" );
	printf( "\n" );
	system( "pause" );
	return 0;
}