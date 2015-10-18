#include <stdio.h>
#include <stdlib.h>
#include "mostrar.h"
#include <stdint.h>

void mostrardatos(uint32_t *registros)
{
	int i;
	for(i=0;i<12;i++)//ciclo for para mostrar los registros en las 12 posiciones
	{
		printf("\n%d",registros[i]);
	}
	return;
}

void mostrarbanderas(uint32_t *flags)
{
	printf("BANDERAS ACTIVAS:\t(1 = bandera activa)\n");
	printf("n: %d",flags[0]);
	printf("z: %d",flags[1]);
	printf("c: %d",flags[2]);
	printf("v: %d",flags[3]);
	return;
}
