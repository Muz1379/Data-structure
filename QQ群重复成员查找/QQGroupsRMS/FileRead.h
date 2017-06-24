﻿#pragma once

#include <stdio.h>

#include "ContExec.h"
/*
读入文件，并把文件流赋值给cont，返回字符数组指针
*/

int fileread( char * url , struct BINTREE * hash)
{
	
	long fpLength = 0;

	FILE * fp = fopen( url, "rb+" );
	if(fp == 0)
	{
		puts( "文件打开失败" );
		printf( "\n" );
		return -1;
	}
	fseek( fp, 0, SEEK_END );
	
	fpLength = ftell( fp );

	char * cont = (char *)malloc( sizeof( char )* (fpLength+1) );

	//fseek( fp, 0, SEEK_SET );
	rewind( fp );
	fread( cont, sizeof( char ), fpLength, fp );

	*(cont + fpLength) = '\0';

	contexec( cont, hash );
	fclose(fp);
	free(fp);

	free( cont );
	
	return OK;
}