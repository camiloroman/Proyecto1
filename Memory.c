#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "Memory.h"

void PUSH(uint32_t *registros, uint32_t *sp, uint32_t *memoria)
{
	int i;
	int BitCount=0;
	for(i=0; i<15; i++)
		{
			if(registros[i]==1)
			BitCount++;
		}

	uint32_t address;
	address=sp-4*BitCount;

	for(i=0; i<8; i++)
		{
			if(registros[i]==1)
			{
				for(j=0;j<4;j++)
                    		{
                        		memoria[address+j]=(uint8_t)(registros[i]>>(8*j));
                    		}
                		address+=4;
			}

		}
	if(registros[14]==1)
		{
			for(j=0;j<4;j++)
                    		{
                        		memoria[address+j]=(uint8_t)(registros[14]>>(8*j));
                    		}
		}
	sp=sp-4*BitCount;

}

void POP(uint32_t *registros, uint32_t *sp, uint32_t *memoria)
{
	int i;
	int BitCount=0;
	for(i=0; i<15; i++)
		{
			if(registros[i]==1)
			BitCount++;
		}

	uint32_t address;
	address=sp;
	for(i=0;i<8;i++)
	{
		if(registros[i]==1)
		{
			registros[i]=((uint32_t)(memoria[address+3]<<24))|((uint32_t)(memoria[address+2]<<16))|((uint32_t)(memoria[address+1]<<8))|((uint32_t)(memoria[address]));
			address+=4;
		}
		if(registros[15]==1)
		{
			registros[15]=(uint32_t)(memoria[address+3]<<24)|(uint32_t)(memoria[address+2]<<16)|(uint32_t)(memoria[address+1]<<8)|(uint32_t)(memoria[address]);
		}
	sp=sp+4*BitCount;

	}

}

