#pragma once
#pragma execution_character_set("utf-8")
                                            //内置系统头文件
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
                                            //数据结构

#include "ListNode.h"
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

int main( void )
{
	char fileNameA[100];	                //文件名A
	char fileNameB[100];	                //文件名B
	char * contA;			                //内容字符串A
	char * contB;			                //内容字符串B
	struct LISTNODE * hashA[500] = { 0 };	//设定哈希表长500，由于目前qq群最大人数为2000，哈希冲突使用拉链法解决。
	struct LISTNODE * hashB[500] = { 0 };
	struct LISTNODE * tempA = { 0 };
	struct LISTNODE * tempB = { 0 };
	struct RESNODE * resList = { 0 };
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

	//查找哈希表，生成结果链表
	for(i = 0; i < 50; i++)
	{
		tempA = hashA[i];
		if(tempA->member == 0)//该哈希位置空，不用查找，直接进行下一项
		{
			continue;
		}
		else
		{
			while(tempA != 0)
			{
				tempB = searchHash( hashB, tempA->member->qqNum );
				if(tempB == 0)//查找失败,即无重复。可进行下一项查找
				{
					continue;
				}
				else//查找成功，将成员节点赋值给结果链表
				{
					resTemp = (struct RESNODE *)malloc( sizeof( struct RESNODE * ) );
					resTemp->A = tempA;
					resTemp->B = tempB;
					resTemp->next = 0;
					insertlist( resList, resTemp );
				}
				tempA = tempA->next;
			}
		}
	}
	printf( "查找完毕，结果存储在resList单链表中" );
	//TODO:完善后续功能。








	system( "pause" );
	return 0;
}