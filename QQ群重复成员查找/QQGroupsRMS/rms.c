#pragma once
#pragma execution_character_set("utf-8")
                                            //����ϵͳͷ�ļ�
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
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
#include "SearchHash.h"
#include "InsertList.h"

#define OK 1
#define ERR -1
#define NULL 0

int main( void )
{
	char fileNameA[100];	                //�ļ���A
	char fileNameB[100];	                //�ļ���B
	char * contA;			                //�����ַ���A
	char * contB;			                //�����ַ���B
	struct BINTREE * hashA[500] = { NULL };	//�趨��ϣ��500������ĿǰqqȺ�������Ϊ2000����ϣ��ͻʹ�������������
	struct BINTREE * hashB[500] = { NULL };
	struct BINTREE * tempA = { NULL };
	struct BINTREE * tempB = { NULL };
	struct RESNODE * resList = { NULL };
	struct RESNODE * resTemp;
	int i = 0;
	int j = 0;

	system( "chcp 65001" );                 //�趨cmd��������ʽUTF-8��codepage=65001
	system( "cls" );
	printf("============================\n");
	printf("\n�ó������ڲ�����qqȺ�ظ���Ա\n");
	printf("\n");
	printf("============================\n");
	printf( "\n" );

	                                        //TODO:�˴����ļ������ַ�����Ӧ����쳣����ģ��
	printf( "������QQȺ��A����Ա�����ļ�����" );
	scanf( "%s", fileNameA );
	contA = fileread( fileNameA );
	printf( "������QQȺ��B����Ա�����ļ�����" );
	scanf( "%s", fileNameB );
	contB = fileread( fileNameB );

	contexec( contA ,hashA);
	contexec( contB ,hashB);


	hashcmp( hashA, hashB, resList );
	//���ҹ�ϣ�����ɽ������

	printf( "������ϣ�����洢��resList��������" );
	

	if(resList != NULL)
	{
		printf( "%20s\t%50s\t%50s\t%50s\t%50s\t","QQ��", "AȺ����", "AȺ����Ƭ", "BȺ����", "BȺ����Ƭ" );
		while(resList != NULL)
		{
			printf( "\n" );
			printf( "%20s\t%50s\t%50s\t%50s\t%50s\t", resList->A->qqNum, resList->A->qqGroup, resList->A->personCard, resList->B->qqGroup, resList->B->personCard );
			resList = resList->next;
		}
	}
	else
	{
		printf( "��Ⱥ�����ظ���Ա" );
	}

	system( "pause" );
	return 0;
}