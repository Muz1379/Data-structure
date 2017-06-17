#pragma once
#pragma execution_character_set("utf-8")
                                            //����ϵͳͷ�ļ�
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
                                            //���ݽṹ

#include "ListNode.h"
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

int main( void )
{
	char fileNameA[100];	                //�ļ���A
	char fileNameB[100];	                //�ļ���B
	char * contA;			                //�����ַ���A
	char * contB;			                //�����ַ���B
	struct LISTNODE * hashA[500] = { 0 };	//�趨��ϣ��500������ĿǰqqȺ�������Ϊ2000����ϣ��ͻʹ�������������
	struct LISTNODE * hashB[500] = { 0 };
	struct LISTNODE * tempA = { 0 };
	struct LISTNODE * tempB = { 0 };
	struct RESNODE * resList = { 0 };
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

	//���ҹ�ϣ�����ɽ������
	for(i = 0; i < 50; i++)
	{
		tempA = hashA[i];
		if(tempA->member == 0)//�ù�ϣλ�ÿգ����ò��ң�ֱ�ӽ�����һ��
		{
			continue;
		}
		else
		{
			while(tempA != 0)
			{
				tempB = searchHash( hashB, tempA->member->qqNum );
				if(tempB == 0)//����ʧ��,�����ظ����ɽ�����һ�����
				{
					continue;
				}
				else//���ҳɹ�������Ա�ڵ㸳ֵ���������
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
	printf( "������ϣ�����洢��resList��������" );
	//TODO:���ƺ������ܡ�








	system( "pause" );
	return 0;
}