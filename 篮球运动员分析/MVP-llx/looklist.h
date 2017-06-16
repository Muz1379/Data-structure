#pragma once
#pragma execution_character_set("utf-8")
//查看单向链表
void lookList( struct NODE * list )
{
	printf( "%-20s","姓名\t\t" );
	printf( "%10s","出场\t" );
	printf( "%10s","首发\t");
	printf( "%10s","上场时间\t" );
	printf( "%10s","投篮\t" );
	printf( "%10s","三分\t" );
	printf( "%10s","罚球\t" );
	printf( "%10s","前篮板\t" );
	printf( "%10s","后篮板\t" );
	printf( "%10s","总篮板\t" );
	printf( "%10s","助攻\t" );
	printf( "%10s","抢断\t" );
	printf( "%10s","盖帽\t" );
	printf( "%10s","失误\t" );
	printf( "%10s","犯规\t" );
	printf( "%10s","得分\t" );
	while(list->next != 0)
	{
		printf( "\n" );
		printf( "%-20s\t",list->player->name );
		printf( "%8d\t",list->player->show );
		printf( "%8d\t",list->player->first);
		printf( "%7.1f\t",list->player->time);
		printf( "%7.1f%%\t", list->player->shot);
		printf( "%7.1f%%\t", list->player->three);
		printf( "%7.1f%%\t", list->player-> penalty);
		printf( "%7.1f\t",list->player->front);
		printf( "%7.1f\t",list->player->back);
		printf( "%7.1f\t",list->player->board);
		printf( "%7.1f\t",list->player->assist);
		printf( "%7.1f\t",list->player->steal);
		printf( "%7.1f\t",list->player->block);
		printf( "%7.1f\t",list->player->mistake);
		printf( "%7.1f\t",list->player->foul);
		printf( "%7.1f\t",list->player->score);
		list = list->next;
	}
}