#pragma once
/*#pragma execution_character_set("ANSI") */                   
//����ϵͳͷ�ļ�
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

//���ݽṹ
#include "BINNode.h"
#include "MemberNode.h"
#include "resNode.h"
#include "STACKNODE.h"
//��������
#include "Function.h"
//��������
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


//TODO:�ó���Ŀǰ�������ص�ָ��Խ����ڴ�й¶���⡣
//BUG:���ܻᵼ�³����޷����У�����ÿ�α���λ�ò�ͬ����ʱ���Զ�λ��������޸���

//�������ʧ�ܣ��ػ�����������ͺ��ˣ�#^_^#

int main( void )
{
	int flag = OK;
	char fileNameA[100] = { NULL };	   //�ļ���A
	char fileNameB[100] = { NULL };	   //�ļ���B

	//�趨��ϣ��500������ĿǰqqȺ�������Ϊ2000����ϣ��ͻʹ�������������
	binTreeNODE * hashA[HASHLENGTH] = { NULL };	
	binTreeNODE * hashB[HASHLENGTH] = { NULL };

	//����������
	resNODE * resList =  NULL ;
	resNODE * resListEnd = NULL;

	//��ʼ���������ͷ����
	MNODE memberA = {"AȺ��","AȺ��Ƭ","QQ��"};
	MNODE memberB = {"BȺ��","BȺ��Ƭ","QQ��"};

	//��ʼ������
	Init();

	do
	{
		//�ÿմ�����
		ClearHash( hashA );
		ClearHash( hashB );
		ClearResList( resList );

		resList = (resNODE *)malloc( sizeof( resNODE ) );
		resList->A = &memberA;
		resList->B = &memberB;
		resList->next = NULL;

		printf( "  ������QQȺ��A����Ա�����ļ�����" );
		scanf_s( "%s", fileNameA ,95);
		printf( "  ������QQȺ��B����Ա�����ļ�����" );
		scanf_s( "%s", fileNameB ,95);


		flag = fileread( fileNameA, hashA );
		if(flag == ERR)
		{
			printf( "\n\n  Ⱥ��Ա���� A ����ʧ�ܣ�δ���ɹ�ϣ��\n\n" );
			system( "pause" );
		}
		else
		{
			flag = fileread( fileNameB, hashB );
			if(flag == ERR)
			{
				printf( "\n\n  Ⱥ��Ա���� B ����ʧ�ܣ�δ���ɹ�ϣ��\n\n" );
				system( "pause" );
			}
			else
			{
				//���ҹ�ϣ�����ɽ������
				hashcmp( hashA, hashB, resList );
				//д�����ļ�
				FileWrite( resList, "result.txt" );
				printf( "\n\n  ������ϣ�����洢��resList��������ļ�result.txt��\n\n" );
				ShowResult( resList );

				printf( "\n\n" );
				printf( "  �Ƿ�������򡪡����������� 1      �� 0\n" );
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
					printf( "\n\n  ���Ž���������洢��resList��������ļ�resultQuickSort.txt��\n\n" );
				}
			}
		}

		printf( "\n\n" );
		printf( "  �Ƿ�������ԡ����� 1      �� 0\n" );
		scanf_s( "%d", &flag );
	} while(flag == 1);
	
	printf( "\n" );
	printf( "\n" );
	system( "pause" );
	return 0;
}