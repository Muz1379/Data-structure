#pragma once
#pragma execution_character_set("utf-8")
#include "isChinese.h"
/*
根据传入字符数组指针，提取球员数据，赋给变量，返回节点链表指针
*/
struct NODE * contExec( char * cont)
{
	char * tmp = cont;
	long start, end, length, i;
	int j = 0;
	int k = 0;
	int m = 1;	//使用m标识当前属性项
	char * contA = { 0 };
	char * contB = { 0 };
	char td[] = "<TD>";
	char num[6];
	struct PLAYERS * p = 0;
	struct NODE * listN;
	LIST *listHEAD;
	listHEAD = (LIST *)malloc( sizeof( LIST ) );
	listHEAD->player = 0;
	listHEAD->next = 0;

	
	//阅读保存的txt文件发现，“技术分析”部分位于id=“S_Cont_01”的div内，故从此处开始朴素匹配
	start = kmp( tmp, "S_Cont_01" );	
	contA = (char *)malloc( sizeof( char )*(strlen( tmp ) - start + 1) );
	substrR( contA, tmp, start, strlen( tmp ) );
	
	start = kmp( contA, "</TR>" );
	end = kmp( contA, "</TBODY>" );
	contB = (char *)malloc( sizeof( char )*(end - start + 1) );
	substrR( contB, contA, start, end );
	free( contA );
	start = kmp( contB, "TD" );
	end = strlen( contB );
	length = end - start + 1;
	i = 0;
	while(i < length)
	{
		listN = (LIST *)malloc( sizeof( LIST ) );
		listN->player = 0;
		listN->next = 0;
		j = 0;
		p = (struct PLAYERS *)malloc( sizeof( struct PLAYERS ) );
		//分析发现在该文件的表格部分，球员姓名均以汉字表示，在utf-8中，汉字以三个字节存储，且以0xe4开头
		for(; i < length; i++)
		{
			if(isChinese(contB + i))	//此处开始提取姓名
			{
				do {
					*((p->name) + j) = *(contB + i);
					j++;
					i++;
				} while(*(contB + i) != '<');
				*((p->name) + j) = '\0';//提取姓名结束
				m++;
				break;
			}
		}
		while(m <= 16)
		{
			j = 0;
			//定位数值
			for(; (i < length)&&(j<5);)
			{
				if(*(contB + i + j) == td[j])
				{
					j++;
				}
				else
				{
					i++;
					j = 0;
				}
				if(j == 4)
				{
					i = i + j;
					break;
				}
			}
			j = 0;
			//提取数值
			do {
				num[j] = *(contB + i);
				j++;
				i++;
			} while((*(contB + i) != '<') && (i < length));
			num[j] = '\0';
			j = 0;
			//数值由字符串转换为int或float，并赋值到目标
			while(num[j] != '\0')
			{
				if(num[j] == '.')
				{
					for(;; k++)
					{
						if(num[j + k] == '%')
							num[j + k] = '\0';
						break;
					}
				}
				j++;
			}
			//将num[]转换为对应int或float格式，并赋值到目标
			switch(m)
			{
				case 2:
					p->show = atoi( num );
					break;
				case 3:
					p->first = atoi( num );
					break;
				case 4:
					p->time = atof( num );
					break;
				case 5:
					p->shot = atof( num );
					break;
				case 6:
					p->three = atof( num );
					break;
				case 7:
					p->penalty = atof( num );
					break;
				case 8:
					p->front = atof( num );
					break;
				case 9:
					p->back = atof( num );
					break;
				case 10:
					p->board = atof( num );
					break;
				case 11:
					p->assist = atof( num );
					break;
				case 12:
					p->steal = atof( num );
					break;
				case 13:
					p->block = atof( num );
					break;
				case 14:
					p->mistake = atof( num );
					break;
				case 15:
					p->foul = atof( num );
					break;
				case 16:
					p->score = atof( num );
					break;
				default:
					break;
			}
			m++;
		}
		m = 1;
		listN->player = p;
		if(listHEAD->player == 0)
			listHEAD = listN;
		else 
		{
			listAdd( listHEAD, listN );
		}
		
	}
	return listHEAD;
}

void substrR( char * aim, char * src, long start, long end )
{
	long len = end - start + 1;
	long i = 0;
	for(; i < len; i++)
		*(aim + i) = *(src + start + i - 1);
}