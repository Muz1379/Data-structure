#pragma once
//TODO:此处暴力匹配成功。
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
//TODO:此处kmp算法实现不成功
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
			if(t[i] != t[j])   //只有前后两个字符不相同时才会按前面的算法来计算next， 即next[i] = j
				next[i] = j;
			else
				next[i] = next[j];        //当前后两个字符相同时，进行向前找，能够减少比较的次数
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
		if(j == -1 || master[i] == pattern[j])//第一个字符都不匹配或者字符相等的情况
		{
			i++;
			j++;
		}
		else   //i指针不回溯,j指针
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