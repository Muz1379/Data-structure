#pragma once
#pragma execution_character_set("utf-8")

#include <string.h>

#define OK 1
#define ERR -1
#define NULL 0

int insbintree( struct BINTREE * bintree, struct BINTREE * item )
{
	if(strcmp( bintree->member->qqNum, item->member->qqNum ) > 0)
	{
		if(bintree->left != NULL)//���ӽ�㲻��Ҷ�ӽ��
		{
			insbintree( bintree->left, item );
		}
		else
		{
			bintree->left = item;
			return OK;
		}
	}
	else//QQ��Ψһ�����������qq����ͬ���������ˣ��������ַ�����ȵ������
	{
		if(bintree->right != NULL)//���ӽ�㲻��Ҷ�ӽ��
		{
			insbintree( bintree->right, item );
		}
		else
		{
			bintree->right = item;
			return OK;
		}
	}

	return OK;
}