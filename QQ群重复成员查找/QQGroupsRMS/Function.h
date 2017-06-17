#pragma once
#pragma execution_character_set("utf-8")
//函数声明头文件

char * fileread( char * );
int contexec( char * , struct LISTNODE * );
int isChinese( char * );
int kmp( char *, char *, long );
struct LISTNODE * searchHash( struct LISTNODE * hash[], char * v );
int insertlist( struct RESNODE * list, struct RESNODE * p )