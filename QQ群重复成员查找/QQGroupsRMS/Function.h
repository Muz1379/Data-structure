#pragma once
#pragma execution_character_set("utf-8")
//��������ͷ�ļ�

char * fileread( char * );	//�����ļ������������ַ���ָ��
int contexec( char * str, struct BINTREE * hashT[] );	//���������ַ�����������ȡ��������ɢ��
int isChinese( char * );//�ж�UTF-8�ַ��Ƿ�Ϊ����
int kmp( char *, char *, long );//kmpģʽƥ���㷨������һ����������������ģʽ������������������ʼλ�á������ҵ���ģʽ���������п�ʼ��λ�á��Ҳ�������-1
struct BINTREE * searchHash( struct BINTREE * hash[], char * v );//��ϣ���������ҡ�
int insreslist( struct RESNODE * list, struct RESNODE * p );//��������в�����
int insbintree( struct BINTREE * , struct BINTREE * );//����������в�����