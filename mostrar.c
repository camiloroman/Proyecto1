#include <stdio.h>
#include <stdlib.h>
#include "mostrar.h"

void mostrardatos(unsigned long int registros[])
{
	int i;
	for(i=0;i<12;i++)
	{
		printf("\n%d",&registros[i]);
	}
}