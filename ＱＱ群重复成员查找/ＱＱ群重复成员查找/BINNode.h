#pragma once

//拉链法——冲突链表节点，拉链结构为二叉查找树
typedef struct BINTREE
{
	struct MEMBERNODE * member;//QQ成员信息结构体
	struct BINTREE * left;	   //小值在左
	struct BINTREE * right;	   //大值在右
}binTreeNODE;