#pragma once

#include <stdio.h>

#include "ContExec.h"
/*
�����ļ��������ļ�����ֵ��cont�������ַ�����ָ��
*/

int fileread( char * url, struct BINTREE * hash[] )
{

	long fpLength = 0;

	FILE * fp = fopen( url, "rb+" );
	if(fp == NULL)
	{
		puts( "�ļ���ʧ��" );
		printf( "\n" );
		return -1;
	}
	fseek( fp, 0, SEEK_END );

	fpLength = ftell( fp );

	char * cont = (char *)malloc( sizeof( char )* (fpLength + 1) );

	//fseek( fp, 0, SEEK_SET );
	rewind( fp );

	int i = -1;
	i = ftell( fp );

	fread( cont, sizeof( char ), fpLength, fp );

	*(cont + fpLength) = '\0';

	contexec( cont, hash );

	fclose( fp );
	fp = NULL;

	return OK;
}