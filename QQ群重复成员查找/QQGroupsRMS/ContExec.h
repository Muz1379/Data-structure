#pragma once


#include "BINNode.h"

#define OK 1
#define ERR -1
#define NULL 0
/*
�ҵ�����MEMBERNODE��ʽ�����ݣ�����MNODE,�������ϣ������0
*/

int contexec( char * str, struct BINTREE * hashT[] )
{
	char * qqG[50] = { 0 };		//Ⱥ��
	char NL[] = { 0x0d,0x0a };			   			   					   //utf-8�л��з�\n\r��
	int j = 0;
	long i = 0;
	long strP = 0;						   			   					   //�ַ���ָ��
	long strEnd = 0;
	int intTemp = 1;								   					   //�������֣�ÿ����Ա�ṹǰ����һ�����ֱ�ʾ�ǵڼ�����Ա
	struct MEMBERNODE * memberT = { NULL };					   					   //���ɴ�ų�Ա�ڴ�ָ��
	struct BINTREE * listT = { NULL };				   					   //��ϣԪ��ָ��


	strEnd = kmp( str, "��������", 0 );
	strP = kmp( str, "����", 0 );
	strP = strP + sizeof( "����" );		   			   					   //�ҵ�����������β��λ�á��������������з�֮��ΪȺ����


	for(; !isChinese( str+ strP ); strP++);			   					   //��������������Ⱥ��֮��Ļ��з���
	strP--;
	j = 0;
	do
	{
		qqG[j] = *(str + strP);
		j++;
		strP++;
	} while(*(str + strP-1) != (char)0x29);		   	   					   //TODO:�˴��ַ�ת������
										   			   					   //Ⱥ��Ƭ��ȡ����

	for(i = 0; i !=-1;)
	{
		i = kmp( str, "����� \n\r\n\r  �����", strP );
		if(i > 0)						   					   //�ҵ�������ԡ����ַ����α����
		{
			strP = strP + i + sizeof( "�����" );
		}					   			   					   //�Ҳ���������ԡ�������ѭ�����������ҡ�
	}
	for(; *(str + strP) != '1'; strP++);			   					   //��Ա�б��һ����� 1
													   					   //�����Ա�б����顣��ʼ����
	for(; strP < strEnd; strP++) 
	{
		memberT = (struct MEMBERNODE *)malloc( sizeof( struct MEMBERNODE ) );
		strcpy( memberT->qqGroup, qqG );//����Ⱥ����

		j = 0;
		for(; j < 4 && strP<strEnd;strP++)							   	   //�������������з�
		{
			if(*(str + strP) == NL[j%2])
			{
				j++;
			}
			if(*(str + strP) != NL[j%2])
			{
				j = 0;
			}
		}
		j = 0;
		for(; j < 2 && strP<strEnd; strP++)						   		   //����һ�����з�
		{
			if(*(str + strP) == NL[j % 2])
			{
				j++;
			}
			if(*(str + strP) != NL[j % 2])
			{
				j = 0;
			}
		}
		
		for(; (*(str + strP) == (char)0x20 ) && strP<strEnd; strP++);	   //ȥ��ǰ���ո�
		strP--;
												   	   					   //��ȡȺ��Ƭ
		j = 0;
		while((*(str + strP) != (char)0x0d ) && strP<strEnd)		   	   //0x0d Ϊ \n
		{
			*((memberT->personCard) + j) = *(str + strP + j);
			strP++;
			j++;
		}
		*((memberT->personCard) + j) = '\0';

		j = 0;
		for(; j < 2 && strP<strEnd; strP++)						   		   //����һ�����з�
		{
			if(*(str + strP) == NL[j % 2])
			{
				j++;
			}
		}
		
		for(; (*(str + strP) == (char)0x20) && strP<strEnd; strP++);	   //ȥ��ǰ���ո�
		strP--;
													   					   //��ȡqq�š���֪qq�ź����һ�ո�
		for(j = 0;(*(str+strP)!=(char)0x20) && strP<strEnd; j++,strP++)
		{
			*((memberT->qqNum) + j) = *(str + strP);
		}
		*((memberT->qqNum) + j) = '\0';

		listT = (struct BINTREE *)malloc( sizeof( struct BINTREE ) );
		listT->member = memberT;
		listT->left = NULL;
		listT->right = NULL;

		if(inshash( hashT, listT ) != OK)
		{
			printf( "��ϣʧ��\n" );
			printf( "QQȺ��%s\tQQ��Ƭ��%s\tQQ��%s", listT->member->qqGroup, listT->member->personCard, listT->member->qqNum );
			return ERR;
		}
	}
	return OK;
}