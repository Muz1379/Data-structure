#pragma once

int ClearHash( binTreeNODE * hash[] )
{
	int i = 0;

	for(i = 0; i < HASHLENGTH; i++)//����hashA��
	{
		hash[i] = NULL;
		/*if(hash[i] != NULL)
		{
			LRDClearBinTree( hash[i]);
		}*/
	}
	return OK;
}