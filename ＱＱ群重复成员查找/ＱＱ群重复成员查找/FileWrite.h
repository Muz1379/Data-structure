#pragma once

int FileWrite( struct RESNODE * list)
{
	struct RESNODE * resTemp;
	resTemp = list;

	FILE * fp = fopen( "result.txt", "w+" );

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

	return OK;
}