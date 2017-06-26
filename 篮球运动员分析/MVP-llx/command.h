#pragma once
#pragma execution_character_set("utf-8")
#include "diyOp.h"
static short isFileReaded = 0;

int command(void)
{
	struct NODE * playerList = {0};
	struct NODE * resList = { 0 };
	struct NODE * analy = { 0 };
	int cmd;
	do
	{
		printf ( "\n\n\t" );
		puts   ( "== == == == == == == == == == ==" );
		printf( "\n" );
		printf( "\t" );
		puts( "0-退出      1-帮助      2-读入数据" ); printf( "\n\t" );
		puts( "3-查看链表  4-选择排序  5-统计分析" ); 
		printf ( "\n\t" );
		puts ( "== == == == == == == == == == ==" );
		printf( "\n\n" );
		puts ( "请输入指令" );
		printf( "\n" );
		scanf ( "%d", &cmd );

		switch ( cmd )
		{
			case 1:
				help ();
				break;
			case 2:
				playerList=fileRead ();
				if(playerList != 0)
				{
					puts( "数据已读入成功，并生成了单向链表【playerList】" );
					printf( "\n" );
				}
				break;
			case 3:
				lookList(playerList);//查看链表
				break;
			case 4:
				if(isFileReaded)
					resList=selectSort (playerList);
				else
				{
					printf( "\n" );
					puts( "您尚未输入数据，请输入后再执行该操作" );
					printf( "\n" );
					break;
				}
			case 5:
				analy=analysis( playerList );//查看链表
				break;
			default:
				break;
		}
	} while ( cmd );
	return cmd;
}