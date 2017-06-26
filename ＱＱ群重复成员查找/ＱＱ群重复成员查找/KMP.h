#pragma once

long kmp( unsigned char * master, unsigned char * pattern, long start )
{
	int j = 0;
	long i = start;
	int t = strlen( pattern );
	long L = strlen( master );

	for(; i < L&&j < t; i++)
	{
		if(*(master + i) == *(pattern + j))
		{
			j++;
		}
		else
		{
			j = 0;
		}
	}
	return i-start;
}
//TODO:�˴�kmp�㷨ʵ�ֲ��ɹ�
//void getnext( char p[], int next[] )
//{
//	int k = -1;
//	int j = 0;
//
//	next[j] = k;
//
//	while(j < strlen( p ))
//	{
//		if((k == -1) || (p[j] == p[k])) //ע��Ⱥ���==��������=  
//		{
//			++k; // ע�����ȼӺ�ʹ��  
//			++j;
//			next[j] = k;
//		}
//		else
//		{
//			k = next[k];
//		}
//	}
//
//}
//
//long kmp( char * master, char * pattern, long i )
//{
//	int j = 0;
//	int next[50] = { 0 };
//
//	getnext( pattern, next );
//	while((i < strlen( master )) && (j < strlen( pattern )))
//	{
//		/* j = -1 ��ʾnext[0], ˵��ʧ�䴦��ģʽ��T�ĵ�0���ַ��������������⴦��Ȼ����i+1��j+1��*/
//		if((j == -1) || master[i] == pattern[j])
//		{
//			i++;
//			j++;
//		}
//		else
//		{
//			j = next[j];
//		}
//	}
//
//	if(strlen( pattern ) == j)
//	{
//		return i - strlen( pattern );
//	}
//	else
//	{
//		return -1;
//	}
//
//}