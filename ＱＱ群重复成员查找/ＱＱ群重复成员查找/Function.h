#pragma once
//��������ͷ�ļ�

int fileread( char[], struct BINTREE * );	//�����ļ�,��������ɹ�ϣ��
int contexec( char * str, struct BINTREE * hashT[] );	//���������ַ�����������ȡ��������ɢ��
int isChinese( char * );//�ж�UTF-8�ַ��Ƿ�Ϊ����
int kmp( char *, char *, long );//kmpģʽƥ���㷨������һ����������������ģʽ������������������ʼλ�á������ҵ���ģʽ���������п�ʼ��λ�á��Ҳ�������-1
int searchhash( struct BINTREE * bintree, struct BINTREE * hashB[], struct RESNODE * resList );//��ϣ���������ҡ�
int insreslist( struct RESNODE * list, struct RESNODE * p );//��������в�����
int insbintree( struct BINTREE *, struct BINTREE * );//����������в�����
int hashcmp( struct BINTREE * hashA[], struct BINTREE *hashB[], struct RESNODE * resList );//��ϣ�ȶԡ����ȶԽ������resList
int LRDvisitbintree( struct BINTREE * bintree, struct BINTREE *hashB[], struct RESNODE * resList );//�������������
int DLRsearchbintree( struct BINTREE * bintree, struct BINTREE * item, struct RESNODE * resList );
int FileWrite( struct RESNODE * list );