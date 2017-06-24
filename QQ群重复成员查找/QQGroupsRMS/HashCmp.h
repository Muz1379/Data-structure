#pragma once
#pragma execution_character_set("utf-8")

#define OK 1
#define ERR -1
#define NULL 0
#define HASHLENGTH 500

//����ϣ��������һ��������֯�����Ķ��������ɭ�֡���ϣ������ö��������������

int hashcmp( struct BINTREE * hashA[], struct BINTREE *hashB[], struct RESNODE * resList)
{
	int i = 0;

	for(i = 0; i < HASHLENGTH; i++)//����hashA��
	{
		if(hashA[i] != NULL)
		{
			LRDvisitbintree( hashA[i], hashB, resList );
		}
	}

	return OK;
}