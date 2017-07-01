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
//��������
#include "Function.h"
//��������
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

int main( void )
{
	//TODO:������
	char fileNameA[100] = "testA.txt";	                //�ļ���A
	char fileNameB[100] = "testB.txt";	                //�ļ���B

	char * contA = NULL;			                //�����ַ���A
	char * contB = NULL;			                //�����ַ���B
	struct BINTREE * hashA[HASHLENGTH] = { NULL };	//�趨��ϣ��500������ĿǰqqȺ�������Ϊ2000����ϣ��ͻʹ�������������
	struct BINTREE * hashB[HASHLENGTH] = { NULL };
	struct BINTREE * tempA = { NULL };
	struct BINTREE * tempB = { NULL };
	struct RESNODE * resList = { NULL };
	struct RESNODE * resTemp;

	//��ʼ���������ͷ
	struct MEMBERNODE memberA = {
		"AȺ��","AȺ��Ƭ","QQ��"
	};
	struct MEMBERNODE memberB = {
		"BȺ��","BȺ��Ƭ","QQ��"
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
	printf( "\n�ó������ڲ�����qqȺ�ظ���Ա\n" );
	printf( "\n" );
	printf( "= = = = = = = = = = = = = = = = =\n" );
	printf( "\n" );

	//TODO:�˴����ļ������ַ�����Ӧ����쳣����ģ��
	//TODO:����ע��
	/*
	printf( "������QQȺ��A����Ա�����ļ�����" );
	scanf( "%s", fileNameA );
	contA = fileread( fileNameA );
	printf( "������QQȺ��B����Ա�����ļ�����" );
	scanf( "%s", fileNameB );
	contB = fileread( fileNameB );
	*/
	fileread( fileNameA, hashA );
	fileread( fileNameB, hashB );

	//���ҹ�ϣ�����ɽ������
	hashcmp( hashA, hashB, resList );

	printf( "������ϣ�����洢��resList��������\n" );
	FileWrite( resList );//д�����ļ�

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
		printf( "��Ⱥ�����ظ���Ա" );
	}

	printf( "\n" );
	system( "pause" );
	return 0;
}