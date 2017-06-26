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
//TODO:此处kmp算法实现不成功
//void getnext( char p[], int next[] )
//{
//	int k = -1;
//	int j = 0;
//
//	next[j] = k;
//
//	while(j < strlen( p ))
//	{
//		if((k == -1) || (p[j] == p[k])) //注意等号是==，而不是=  
//		{
//			++k; // 注意是先加后使用  
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
//		/* j = -1 表示next[0], 说明失配处在模式串T的第0个字符。所以这里特殊处理，然后令i+1和j+1。*/
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