#pragma once

//������������ͻ����ڵ㣬�����ṹΪ���������
typedef struct BINTREE
{
	struct MEMBERNODE * member;//QQ��Ա��Ϣ�ṹ��
	struct BINTREE * left;	   //Сֵ����
	struct BINTREE * right;	   //��ֵ����
}binTreeNODE;