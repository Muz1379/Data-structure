#pragma once

//����ϣ��������һ��������֯�����Ķ��������ɭ�֡���ϣ������ö��������������

int hashcmp( binTreeNODE * hashA[], binTreeNODE * hashB[], resNODE* resList )
{
	int i = 0;

	//����hashA��
	for(i = 0; i < HASHLENGTH; i++)
	{
		if(hashA[i] != NULL)
		{
			LRDvisitbintree( hashA[i], hashB, resList );
		}
	}

	return OK;
}