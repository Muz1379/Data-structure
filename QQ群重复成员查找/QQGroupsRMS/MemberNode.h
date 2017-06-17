#pragma  once
#pragma  execution_character_set("utf-8")
//成员节点

typedef  struct MEMBERNODE
{
	char qqGroup[50];   //qq群名
	char personCard[60];//群内名片
	char qqNum[12];     //qq号，目前最长为11位
}MNODE;