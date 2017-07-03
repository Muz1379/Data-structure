#pragma once

#include <stdio.h>
#include "ContExec.h"
/*
读入文件，并把文件流赋值给cont，返回字符数组指针
*/

int fileread( char * url, binTreeNODE * hash[] )
{
	long fpLength = 0;
	FILE * fp;
	fp = (fopen( url, "rb+" ));
	if(fp == NULL)
	{
		puts( "文件打开失败" );
		printf( "\n" );
		return -1;
	}
	fseek( fp, 0, SEEK_END );

	fpLength = ftell( fp );

	char * cont = (char *)malloc( sizeof( char )* (fpLength + 2) );

	//fseek( fp, 0, SEEK_SET );
	rewind( fp );

	int i = -1;
	i = ftell( fp );

	fread( cont, sizeof( char ), fpLength, fp );

	fclose( fp );
	fp = NULL;

	*(cont + fpLength) = '\0';

	return contexec( cont, hash );;
}