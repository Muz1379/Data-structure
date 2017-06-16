#pragma once
#pragma execution_character_set("utf-8")
#include "listNode.h"
#include "player.h"
struct NODE * analysis( struct NODE * list )
{
	int count = 0;
	struct NODE * ava;
	struct PLAYERS * p = 0;
	p = (struct PLAYERS *)malloc( sizeof( struct PLAYERS ) );
	ava = (LIST *)malloc( sizeof( LIST ) );
	strcpy(p->name ,"平均") ;
	p->show=0;
	p->first=0;
	p->time=0;
	p->shot=0;
	p->three=0;
	p->penalty=0;
	p->front=0;
	p->back=0;
	p->board=0;
	p->assist=0;
	p->steal=0;
	p->block=0;
	p->mistake=0;
	p->foul = 0;
	p->score = 0;

	while(list->next != 0)
	{			   	
		count++;
		p->show		= p->show		+list->player->show		;
		p->first		= p->first	+list->player->first	;
		p->time		= p->time		+list->player->time		;
		p->shot		= p->shot		+list->player->shot		;
		p->three		= p->three	+list->player->three	;
		p->penalty	= p->penalty	+list->player->penalty	;
		p->front		= p->front	+list->player->front	;
		p->back		= p->back		+list->player->back		;
		p->board		= p->board	+list->player->board	;
		p->assist		= p->assist	+list->player->assist	;
		p->steal		= p->steal	+list->player->steal	;
		p->block		= p->block	+list->player->block	;
		p->mistake	= p->mistake	+list->player->mistake	;
		p->foul		= p->foul		+list->player->foul		;
		p->score		= p->score	+list->player->score	;
		list = list->next;
	}
	p->show	  =p->show		   /count;
	p->first	  =p->first		   /count;
	p->time	  =p->time		   /count;
	p->shot	  =p->shot		   /count;
	p->three	  =p->three		   /count;
	p->penalty  =p->penalty		   /count;
	p->front	  =p->front		   /count;
	p->back	  =p->back		   /count;
	p->board	  =p->board		   /count;
	p->assist	  =p->assist		   /count;
	p->steal	  =p->steal		   /count;
	p->block	  =p->block		   /count;
	p->mistake  =p->mistake		   /count;
	p->foul	  =p->foul		   /count;
	p->score	  =p->score		   /count;

	ava->player = p;
	ava->next = 0;
	printf( "%-20s", "姓名\t\t"	 );
	printf( "%10s", "出场\t"	 );
	printf( "%10s", "首发\t"	 );
	printf( "%10s", "上场时间\t" );
	printf( "%10s", "投篮\t"	 );
	printf( "%10s", "三分\t"	 );
	printf( "%10s", "罚球\t"	 );
	printf( "%10s", "前篮板\t"	 );
	printf( "%10s", "后篮板\t"	 );
	printf( "%10s", "总篮板\t"	 );
	printf( "%10s", "助攻\t"	 );
	printf( "%10s", "抢断\t"	 );
	printf( "%10s", "盖帽\t"	 );
	printf( "%10s", "失误\t"	 );
	printf( "%10s", "犯规\t"	 );
	printf( "%10s", "得分\t"	);
	printf( "\n" );
	printf( "%-20s\t", p->name );
	printf( "%8d\t", p->show );
	printf( "%8d\t", p->first );
	printf( "%7.1f\t", p->time );
	printf( "%7.1f%%\t", p->shot );
	printf( "%7.1f%%\t", p->three );
	printf( "%7.1f%%\t", p->penalty );
	printf( "%7.1f\t", p->front );
	printf( "%7.1f\t", p->back );
	printf( "%7.1f\t", p->board );
	printf( "%7.1f\t", p->assist );
	printf( "%7.1f\t", p->steal );
	printf( "%7.1f\t", p->block );
	printf( "%7.1f\t", p->mistake );
	printf( "%7.1f\t", p->foul );
	printf( "%7.1f\t", p->score );

	return ava;
}