#pragma once

void ShowResult( resNODE * list )
{
	resNODE * resTemp;
	resTemp = list;
	if(resTemp->next != NULL)
	{
		while(resTemp != NULL)
		{
			printf( "\n" );
			printf( "  %-20s\t%-35s\t%-30s\t%-35s\t%-30s\t", resTemp->A->qqNum, resTemp->A->qqGroup, resTemp->A->personCard, resTemp->B->qqGroup, resTemp->B->personCard );
			resTemp = resTemp->next;
		}
	}
	else
	{
		printf( "两群内无重复人员" );
	}
}