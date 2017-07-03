#pragma once


#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "BINNode.h"
#include "MemberNode.h"
#include "insBinTree.h"

int inshash( binTreeNODE * hashT[], binTreeNODE* item )
{
	char qqF4char[6];		//QQ��ǰ�ĸ�����
	int qqNumF4;	 		//��Ϊint���ֽڣ����ֵΪ65535������ȫ��ʾ��λ����
	int hashP;		 		//��ϣ���±�

	strncpy( qqF4char,item->member->qqNum, 5 );
	qqF4char[4] = '\0';
	qqNumF4 = atoi( qqF4char );

	hashP = qqNumF4 % HASHLENGTH;

	if(hashT[hashP] == NULL)//��λ����item�������ڸ�λ�ã��������������
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