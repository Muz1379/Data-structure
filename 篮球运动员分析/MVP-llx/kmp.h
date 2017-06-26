#pragma once
#pragma execution_character_set("utf-8")

int next[20];

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

int kmp( char *master, char *pattern )
{
	get_next( pattern, next );
	long i = 0;
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
		return i - len2;
	else
		return -1;
}