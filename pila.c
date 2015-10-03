#include "pila.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void PUSH(uint32_t registros[16], uint32_t *regi, uint32_t *pila)
{
	int i;
	int acumulador=0;
	for(i=0; i<15; i++)
	{
        	if(registros[i]==0)
        	{
		acumulador=acumulador;
        	}
		else
		{
		acumulador+=1;
		}
	}

	uint32_t pos;

	pos=*(regi+13)-acumulador;

	for(i=0; i<15; i++)
	{
        	if(registros[i]==0)
        	{
		pos=pos;
        	}
		else
		{
		*(pila+pos)=*(regi+i);
		pos+=1;
		}
	}
		*(regi+13)-=acumulador;
}
