#pragma once
//函数声明头文件
void Init();//初始化控制台界面
int fileread( char * filename, binTreeNODE * hash[]);	//读入文件,处理后，生成哈希表
int contexec( char * str, binTreeNODE * hashT[] );	//处理内容字符串，并将提取到到数据散列
int isChinese( char * );//判断UTF-8字符是否为汉字
long kmp( char * master, char * pattern, long pos);//kmp模式匹配算法，参数一是主串，参数二是模式串，参数三是主串开始位置。返回找到的模式串在主串中开始的位置。找不到返回-1
int searchhash( binTreeNODE * bintree, binTreeNODE * hashB[], resNODE * resList );//哈希二叉树查找。
int insreslist( resNODE * list, resNODE * p );//结果链表中插入结点
int insbintree( binTreeNODE *, binTreeNODE * );//二叉查找树中插入结点
int hashcmp( binTreeNODE * hashA[], binTreeNODE *hashB[], resNODE * resList );//哈希比对。将比对结果存入resList
int LRDvisitbintree( binTreeNODE * bintree, binTreeNODE *hashB[], resNODE * resList );//后序遍历二叉树
int DLRsearchbintree( binTreeNODE * bintree, binTreeNODE * item, resNODE * resList );
int FileWrite( resNODE * list, char * filename );//将结果写入文件，filename为文件路径，
int QuickSort( resNODE * list, resNODE * end );
int PushStack( STACK * stack, STACK * item );//入栈
STACK * PopStack( STACK * stack );//出栈
void ShowResult( resNODE * list );//控制台显示结果
int ClearResList( resNODE * list );//销毁结果链表
int ClearHash( binTreeNODE * hash[] );//销毁哈希
int LRDClearBinTree( binTreeNODE * bintree );
int inshash( binTreeNODE * hashT[], binTreeNODE * item );//哈希插入