#pragma once
#pragma execution_character_set("utf-8")
void substrR( char * , char * , long , long  );
void help();
struct NODE * contExec( char *  );
struct NODE * fileRead( void );
struct NODE * selectSort( struct NODE * );
long kmp( char *, char * );
void get_next( char* , int [] );
void listAdd( struct NODE *, struct NODE *);
int diyop( char * );
void lookList( struct NODE *  );
int command( void );
int isChinese( char * );
struct NODE * analysis( struct NODE * );