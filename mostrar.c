#include <stdio.h>
#include <stdlib.h>
#include "mostrar.h"

void mostrardatos(uint32_t registros[])
{
	int i;
	for(i=0;i<12;i++)//ciclo for para mostrar los registros en las 12 posiciones
	{
		printf("\n%d",&registros[i]);
	}
}