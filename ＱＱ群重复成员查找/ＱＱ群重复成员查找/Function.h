#pragma once
//��������ͷ�ļ�
void Init();//��ʼ������̨����
int fileread( char * filename, binTreeNODE * hash[]);	//�����ļ�,��������ɹ�ϣ��
int contexec( char * str, binTreeNODE * hashT[] );	//���������ַ�����������ȡ��������ɢ��
int isChinese( char * );//�ж�UTF-8�ַ��Ƿ�Ϊ����
long kmp( char * master, char * pattern, long pos);//kmpģʽƥ���㷨������һ����������������ģʽ������������������ʼλ�á������ҵ���ģʽ���������п�ʼ��λ�á��Ҳ�������-1
int searchhash( binTreeNODE * bintree, binTreeNODE * hashB[], resNODE * resList );//��ϣ���������ҡ�
int insreslist( resNODE * list, resNODE * p );//��������в�����
int insbintree( binTreeNODE *, binTreeNODE * );//����������в�����
int hashcmp( binTreeNODE * hashA[], binTreeNODE *hashB[], resNODE * resList );//��ϣ�ȶԡ����ȶԽ������resList
int LRDvisitbintree( binTreeNODE * bintree, binTreeNODE *hashB[], resNODE * resList );//�������������
int DLRsearchbintree( binTreeNODE * bintree, binTreeNODE * item, resNODE * resList );
int FileWrite( resNODE * list, char * filename );//�����д���ļ���filenameΪ�ļ�·����
int QuickSort( resNODE * list, resNODE * end );
int PushStack( STACK * stack, STACK * item );//��ջ
STACK * PopStack( STACK * stack );//��ջ
void ShowResult( resNODE * list );//����̨��ʾ���
int ClearResList( resNODE * list );//���ٽ������
int ClearHash( binTreeNODE * hash[] );//���ٹ�ϣ
int LRDClearBinTree( binTreeNODE * bintree );
int inshash( binTreeNODE * hashT[], binTreeNODE * item );//��ϣ����