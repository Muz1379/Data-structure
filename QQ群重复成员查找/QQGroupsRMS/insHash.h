#pragma once
#pragma execution_character_set("utf-8")

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "BINNode.h"
#include "MemberNode.h"
#include "insBinTree.h"

#define OK 1
#define ERR -1
#define NULL 0
#define HASHLENGTH 500

int inshash( struct BINTREE * hashT[], struct BINTREE * item)
{
	char qqF4char[5];		//QQ��ǰ�ĸ�����
	int qqNumF4;	 		//��Ϊint���ֽڣ����ֵΪ65535������ȫ��ʾ��λ����
	int hashP;		 		//��ϣ���±�

	strncpy(qqF4char,item->member->qqNum,4);
	qqF4char[4] = '\0';
	qqNumF4 = atoi( qqF4char );

	hashP = qqNumF4 % HASHLENGTH;

	if(hashT[hashP] == NULL)//��λ����item,�򴴽����������
	{
		hashT[hashP] = item;
	}
	else					//�״ι�ϣʧ�ܣ����˻�Ϊ��������
	{
							//���������룬Сֵ���󣬴�ֵ����
		if(insbintree( hashT[hashP], item ) != OK)
		{
			printf( "����������ʧ��" );
			return ERR;
		}
	}
	return OK;
}