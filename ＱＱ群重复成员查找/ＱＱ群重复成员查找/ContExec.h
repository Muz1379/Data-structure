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
	char temp[5] = { NULL };
	int count = 0;
	char qqG[100];													//Ⱥ��
	char NL[] = { 0x0d,0x0a };			   			   				//���з�\n\r��
	int j = 0;
	long i = 0;
	long strP = 0;						   			   				//�ַ���ָ��
	long strEnd = 0;
	char * strA;
	struct MEMBERNODE * memberT = { NULL };					   		//���ɴ�ų�Ա�ڴ�ָ��
	struct BINTREE * listT = { NULL };				   				//��ϣԪ��ָ��

	unsigned char youqinglianjie[9] = "��������";
	unsigned char fankui[5] = "����";
	unsigned char zuihoufanyan[] = "�����";

	strEnd = kmp( str, youqinglianjie, 0 );							//��������---12399
	strP = kmp( str, fankui, 0 );									//����---169

	strA = (char *)malloc( sizeof( char )*(strEnd + 1) );

	strncpy( strA, str, strEnd );

	free( str );
	str = NULL;

	strP = strP + sizeof( "����" );		   	//�ҵ�����������β��λ�á��������������з�֮��ΪȺ����

	if(strP >= strEnd)
	{
		printf( "��ʼλ�ü������" );
		return NULL;
	}

	for(j=0; j == 0; strP++)					//��������������Ⱥ��֮��Ļ��з����Ϳո�
	{
		j = 1;
		if(*(strA + strP) == '\n')
			j = 0;
		if(*(strA + strP) == '\r')
			j = 0;
		if(*(strA + strP) == ' ')
			j = 0;
	}
	strP--;
	j = 0;
	do
	{
		qqG[j] = *(strA + strP);
		j++;
		strP++;
	} while(*(strA + strP - 1) != (char)0x29);		   	   				 
	qqG[j] = '\0';														 //Ⱥ��Ƭ��ȡ����
	
	for(j = 0; j < 3;)
	{
		i = -1;
		i = kmp( strA, zuihoufanyan, strP );
		if(i != -1)
		{
			j++;
			strP = strP + i;
		}
	}

	for(; strP < strEnd; strP++)
	{
		memberT = (struct MEMBERNODE *)malloc( sizeof( struct MEMBERNODE ) );
		strcpy( memberT->qqGroup, qqG );								//����Ⱥ����
		/*
		QQ��Ϣ��һ��Ⱥ�ڱ�š�QQ�ǳƣ�Ⱥ��Ƭ��QQ�ţ�������У����ɡ�
		��ź�֮ǰ��Ԫ��֮����ܼ��һ�����з����������з����������ո�
		��ź��ǳ�֮�����������з����������ո�
		�ǳ���Ⱥ��Ƭ֮����һ�����з����������ո�
		Ⱥ��Ƭ��QQ��֮����һ�����з����������ո�QQ�Ž����󣬽�����һ���ո�
		֮��Ϊ���ǲ���Ҫ�����ڵ���Ϣ��		
		*/
		j = 0;
		for(; j < 2 && strP < strEnd; strP++)						   		 //����һ�����з�
		{
			if(*(strA + strP) == NL[j % 2])
			{
				j++;
			}
			else
			{
				j = 0;
			}
		}

		for(; *(strA + strP) < '0' || *(strA + strP) > '9'; strP++);//�ҵ����
		for(; *(strA + strP) >= '0' && *(strA + strP) <= '9'; strP++);//���˱��

		for(j = 0; j == 0; strP++)				//������ź��ǳ�֮��Ļ��з����Ϳո�������Ϊ�ǳƾ���Ϊ�ո�
		{
			j = 1;
			if(*(strA + strP) == '\n')
				j = 0;
			if(*(strA + strP) == '\r')
				j = 0;
			if(*(strA + strP) == ' ')
				j = 0;
		}
		//�˴��������ǳ�
		for(j=0; j < 2 && strP<strEnd; strP++)			//����һ�����з�
		{
			if(*(strA + strP) == NL[j % 2])
			{
				j++;
			}
			else
			{
				j = 0;
			}
		}
		for(; (*(strA + strP) == (char)0x20) && strP < strEnd; strP++);	   //ȥ��ǰ���ո�
		j = 0;
		while((*(strA + strP) != (char)0x0d) && strP < strEnd)		   	   	 //��QQȺ��Ƭ
		{
			*((memberT->personCard) + j) = *(strA + strP);
			strP++;
			j++;
		}
		*((memberT->personCard) + j) = '\0';

		j = 0;
		for(; j < 2 && strP < strEnd; strP++)						   		  //����һ�����з�
		{
			if(*(strA + strP) == NL[j % 2])
			{
				j++;
			}
		}

		for(; (*(strA + strP) == (char)0x20) && strP < strEnd; strP++);	   //ȥ��ǰ���ո�

		j = 0;																//��ȡqq�š���֪qq�ź����һ�ո�
		for(; (*(strA + strP) != (char)0x20) && strP < strEnd; j++, strP++)
		{
			*((memberT->qqNum) + j) = *(strA + strP);
		}
		*((memberT->qqNum) + j) = '\0';

		if(*(memberT->qqNum) == '\0')//���������һ�������������strP�������������һ�ξ��룬���Իᴴ��һ����������������ж��Ƿ�Ϊ�գ����գ��򷵻أ������룬��������ɡ�
		{
			return OK;
		}

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