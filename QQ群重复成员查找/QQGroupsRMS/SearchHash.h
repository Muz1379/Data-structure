#pragma once
#pragma execution_character_set("utf-8")

#define OK 1
#define ERR -1
#define NULL 0
#define HASHLENGTH 500
//��ϣ���ң�arg[1]Ϊ��ϣ��arg[2]ΪҪ���ҵ�Ԫ�أ����ҵ��򷵻ر���������Ҳ������򷵻�0

int searchhash( struct BINTREE * item, struct BINTREE * hashB[], struct RESNODE * resList )
{
	char qqF4char[5];		//QQ��ǰ�ĸ�����
	int qqNumF4;	 		//��Ϊint���ֽڣ����ֵΪ65535������ȫ��ʾ��λ����
	int i = 0;

	strncpy( qqF4char, item->member->qqNum, 4 );
	qqF4char[4] = '\0';
	qqNumF4 = atoi( qqF4char );

	i = qqNumF4%HASHLENGTH;

	if(hashB[i]->member != NULL)		//��ϣɢ�еõ���λ�ô���Ԫ�أ����������������һ��
	{
		//���Ҹö�����
		//����������ң�����hashB[i]�У�����item�����ڽ��׷�Ӹ�����resList
		DLRsearchbintree( hashB[i], item, resList );
	}
	else
	{
		return OK;
	}

	return OK;
}