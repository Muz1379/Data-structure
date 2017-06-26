#pragma once
#pragma execution_character_set("utf-8")
/*
读入文件，并把文件流赋值给cont，返回字符数组指针
*/
struct NODE * fileRead( void )
{
	struct NODE * res = { 0 };
	char url[50] = { 0 };
	puts( "请输入文件数据路径" );
	printf( "\n" );
	scanf( "%s", url );

	puts( "正在读入...请稍后..." );
	printf( "\n" );
	FILE *fp = fopen( url, "r" );
	if(fp == 0)
	{
		puts( "文件打开失败" );
		printf( "\n" );
		return 0;
	}
	fseek( fp, 0, SEEK_END );
	long fpLength = ftell( fp );
	char * cont = (char *)malloc( sizeof( char )* (fpLength+1) );
	
	fseek( fp, 0, SEEK_SET );
	fread( cont, fpLength, sizeof( char ), fp );
	
	fclose( fp );
	free( fp );
	*(cont + fpLength) = '\0';
	
	res = contExec( cont );
	free( cont );
	return res;
}