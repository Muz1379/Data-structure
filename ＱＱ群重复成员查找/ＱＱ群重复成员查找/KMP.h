#pragma once
//TODO:�˴�����ƥ��ɹ���
//long kmp( unsigned char * master, unsigned char * pattern, long start )
//{
//	int j = 0;
//	long i = start;
//	int t = strlen( pattern );
//	long L = strlen( master );
//
//	for(; i < L&&j < t; i++)
//	{
//		if(*(master + i) == *(pattern + j))
//		{
//			j++;
//		}
//		else
//		{
//			j = 0;
//		}
//	}
//	return i-start;
//}
//TODO:�˴�kmp�㷨ʵ�ֲ��ɹ�
int next[60];

void get_next( char* t, int next[] )
{
	int i = 1;
	int j = 0;
	next[0] = -1;
	while(i<strlen( t ))
	{
		if(j == -1 || t[i] == t[j])
		{
			i++;
			j++;
			if(t[i] != t[j])   //ֻ��ǰ�������ַ�����ͬʱ�Żᰴǰ����㷨������next�� ��next[i] = j
				next[i] = j;
			else
				next[i] = next[j];        //��ǰ�������ַ���ͬʱ��������ǰ�ң��ܹ����ٱȽϵĴ���
		}
		else
		{
			j = next[j];
		}
	}
}

int kmp( char *master, char *pattern ,long start)
{
	get_next( pattern, next );
	long i = start;
	int j = 0;
	int len1 = strlen( master );
	int len2 = strlen( pattern );
	while(i < len1&&j < len2)
	{
		if(j == -1 || master[i] == pattern[j])//��һ���ַ�����ƥ������ַ���ȵ����
		{
			i++;
			j++;
		}
		else   //iָ�벻����,jָ��
		{
			//i=i-j+1;
			j = next[j];
		}
	}
	if(j >= len2)
		return i - start;
	else
		return -1;
}