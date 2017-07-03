#pragma once 
#include <malloc.h>

void get_next( char * str, int next[],int strLength)
{
	int i = 1;
	int j = 0;
	next[i-1] = 0;
	while(i < strLength)
	{
		if(j == 0 || str[i] == str[j])
		{
			i++;
			j++;
			if(str[i-1] != str[j-1])
				next[i-1] = j;
			else
				next[i-1] = next[j-1];
		}
		else
			j = next[j-1];
	}
}

//master主串，pattern模式串，pos主串开始匹配位置，返回从开始位置到模式串匹配到到开始位置
long kmp( char * master, char * pattern, long pos )
{
	int patternLength = strlen( pattern );

	int size = patternLength * sizeof( char );

	int * next = (int *) malloc(size);
	long j = 0;
	get_next( pattern, next ,patternLength);

	long masterLength = strlen( master );
	long res = 0;

	while((pos + res) < masterLength && j < patternLength)
	{
		if(*(master + pos + res) == *(pattern + j))
		{
			j++;
		}
		else
		{
			j = next[j];
		}
		res++;
	}

	return pos + res - patternLength;
}