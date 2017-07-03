#pragma once
#include <stdio.h>

int FileWrite( resNODE * list,char * filename)
{
	resNODE * resTemp;
	resTemp = list;

	FILE * fp;
	fp = fopen( filename, "w+" );

	if(resTemp->next != NULL)
	{
		while(resTemp != NULL)
		{
			fprintf(fp, "\n" );
			fprintf(fp, "  %-20s\t%-35s\t%-30s\t%-35s\t%-30s\t", resTemp->A->qqNum, resTemp->A->qqGroup, resTemp->A->personCard, resTemp->B->qqGroup, resTemp->B->personCard );
			resTemp = resTemp->next;
		}
	}
	else
	{
		fprintf(fp, "两群内无重复人员" );
	}

	fclose( fp );
	fp = NULL;
	return OK;
}