#pragma once
#pragma execution_character_set("utf-8")
//函数声明头文件

char * fileread( char * );	//读入文件，返回内容字符串指针
int contexec( char * str, struct BINTREE * hashT[] );	//处理内容字符串，并将提取到到数据散列
int isChinese( char * );//判断UTF-8字符是否为汉字
int kmp( char *, char *, long );//kmp模式匹配算法，参数一是主串，参数二是模式串，参数三是主串开始位置。返回找到的模式串在主串中开始的位置。找不到返回-1
struct BINTREE * searchHash( struct BINTREE * hash[], char * v );//哈希二叉树查找。
int insreslist( struct RESNODE * list, struct RESNODE * p );//结果链表中插入结点
int insbintree( struct BINTREE * , struct BINTREE * );//二叉查找树中插入结点