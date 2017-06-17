#pragma once
#pragma execution_character_set("utf-8")
/*
读入文件，并把文件流赋值给cont，返回字符数组指针
*/
char * fileread( char * url )
{
	FILE *fp = fopen( url, "r+" );
	if(fp == 0)
	{
		puts( "文件打开失败" );
		printf( "\n" );
		return -1;
	}
	fseek( fp, 0, SEEK_END );
	long fpLength = ftell( fp );
	char * cont = (char *)malloc( sizeof( char )* (fpLength+1) );
	
	fseek( fp, 0, SEEK_SET );
	fread( cont, fpLength, sizeof( char ), fp );
	
	fclose( fp );
	free( fp );
	*(cont + fpLength) = '\0';
	
	return cont;
}