#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "Alu.h"

void ADD(uint32_t *R0,uint32_t R1,uint32_t R2)
	{
	    	R0=R1+R2;//Se suman los valores R1, R2 y se almacenan en *R0
		return *R0; //se retorna el valor del puntero *R0
	}

void AND(uint32_t *R0,uint32_t R1,uint32_t R2)
	{
	    	R0=R1&R2;//se realiza la AND entre R1, R2 y se almacena en *R0
		return *R0; //se retorna el valor del puntero *R0
	}

void EOR(uint32_t *R0,uint32_t R1,uint32_t R2)
	{
    		R0=R1^R2;//se realiza la XOR entre R1, R2 y se almacena en *R0
		return *R0; //se retorna el valor del puntero *R0
	}

void MOV(uint32_t *R0,uint32_t R1)
	{
 	   	R0=R1;//Se almacena el valor de R1 en R0
		return *R0; //se retorna el valor del puntero *R0
	}

void ORR(uint32_t *R0,uint32_t R1,uint32_t R2)
	{
 	   	R0=R1|R2;//Se realiza la or binaria de R1, R2 y se almacena en *R0
		return *R0; //se retorna el valor del puntero *R0
	}

void SUB(uint32_t *R0,uint32_t R1,uint32_t R2)
	{
    		R0=R1-R2;//Se restan los valores R1, R2 y se almacenan en *R0
		return *R0; //se retorna el valor del puntero *R0
	}
