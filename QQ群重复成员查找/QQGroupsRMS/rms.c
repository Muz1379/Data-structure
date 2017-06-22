#pragma once
#pragma execution_character_set("utf-8")
                                            //内置系统头文件
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
                                            //数据结构

#include "BINNode.h"
#include "MemberNode.h"
#include "resNode.h"
                                            //函数声明
#include "Function.h"
                                            //函数定义
#include "FileRead.h"
#include "ContExec.h"
#include "isChinese.h"
#include "KMP.h"
#include "SearchHash.h"
#include "InsertList.h"

#define OK 1
#define ERR -1
#define NULL 0

int main( void )
{
	char fileNameA[100];	                //文件名A
	char fileNameB[100];	                //文件名B
	char * contA;			                //内容字符串A
	char * contB;			                //内容字符串B
	struct BINTREE * hashA[500] = { NULL };	//设定哈希表长500，由于目前qq群最大人数为2000，哈希冲突使用拉链法解决。
	struct BINTREE * hashB[500] = { NULL };
	struct BINTREE * tempA = { NULL };
	struct BINTREE * tempB = { NULL };
	struct RESNODE * resList = { NULL };
	struct RESNODE * resTemp;
	int i = 0;
	int j = 0;

	system( "chcp 65001" );                 //设定cmd界面编码格式UTF-8：codepage=65001
	system( "cls" );
	printf("============================\n");
	printf("\n该程序用于查找两qq群重复成员\n");
	printf("\n");
	printf("============================\n");
	printf( "\n" );

	                                        //TODO:此处打开文件生成字符串，应添加异常处理模块
	printf( "请输入QQ群【A】成员名单文件名：" );
	scanf( "%s", fileNameA );
	contA = fileread( fileNameA );
	printf( "请输入QQ群【B】成员名单文件名：" );
	scanf( "%s", fileNameB );
	contB = fileread( fileNameB );

	contexec( contA ,hashA);
	contexec( contB ,hashB);


	hashcmp( hashA, hashB, resList );
	//查找哈希表，生成结果链表

	printf( "查找完毕，结果存储在resList单链表中" );
	

	if(resList != NULL)
	{
		printf( "%20s\t%50s\t%50s\t%50s\t%50s\t","QQ号", "A群名称", "A群内名片", "B群名称", "B群内名片" );
		while(resList != NULL)
		{
			printf( "\n" );
			printf( "%20s\t%50s\t%50s\t%50s\t%50s\t", resList->A->qqNum, resList->A->qqGroup, resList->A->personCard, resList->B->qqGroup, resList->B->personCard );
			resList = resList->next;
		}
	}
	else
	{
		printf( "两群内无重复人员" );
	}

	system( "pause" );
	return 0;
}