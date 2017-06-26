#pragma once
#pragma execution_character_set("utf-8")
typedef struct PLAYERS
{
	char	name[70];	//姓名
	int		show	;		//出场次数
	int		first	;		//首发
	float	time	;		//上场时间
	float	shot	;		//投篮
	float	three	;		//三分
	float	penalty	;	//罚球
	float	front	;		//前篮板
	float	back	;		//后篮板
	float	board	;		//总篮板
	float	assist	;		//助攻
	float	steal	;		//抢断
	float	block	;		//盖帽
	float	mistake	;	//失误
	float	foul	;		//犯规
	float	score	;		//得分
};