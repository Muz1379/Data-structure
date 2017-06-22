#pragma once
#pragma execution_character_set("utf-8")
							   //拉链法——冲突链表节点，拉链结构为二叉查找树
typedef struct BINTREE
{
	struct MEMBERNODE * member;//QQ成员信息结构体
	struct BINTREE * left;	   //QQ号小值
	struct BINTREE * right;	   //QQ号大值
}binNODE;