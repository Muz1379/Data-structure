#pragma once

#include <string.h>


int insbintree( struct BINTREE * bintree, struct BINTREE * item )
{
	if(strcmp( bintree->member->qqNum, item->member->qqNum ) > 0)
	{
		//���ӽ�㲻��Ҷ�ӽ��
		if(bintree->left != NULL)
		{
			insbintree( bintree->left, item );
		}
		else
		{
			bintree->left = item;
			return OK;
		}
	}
	//QQ��Ψһ�����������qq����ͬ���������ˣ��������ַ�����ȵ������
	else
	{
		//���ӽ�㲻��Ҷ�ӽ��
		if(bintree->right != NULL)
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