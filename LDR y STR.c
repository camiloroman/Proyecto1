#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "LDR y STR.h"

void LDR(uint32_t *registro,uint32_t *Rt,uint32_t R1,uint32_t R2)
{
	*Rt=R1+R2;
	registro[15]++;

}

void LDRB(uint32_t *registro,uint32_t *Rt,uint32_t R1,uint32_t R2)
{
	*Rt=(R1+R2);
	registro[15]++;
}

void LDRH(uint32_t *registro,uint32_t *Rt,uint32_t R1,uint32_t R2)
{
	*Rt=(R1+R2);
	registro[15]++;
}

void LDRSB(uint32_t *registro,uint32_t *Rt,uint32_t R1,uint32_t R2)
{
	*Rt=(uint32_t)(R1+R2);
	registro[15]++;
}

void LDRSH(uint32_t *registro,uint32_t *Rt,uint32_t R1,uint32_t R2)
{
	*Rt=(uint32_t)(R1+R2);
	registro[15]++;
}

void STR(uint8_t *memoria,uint32_t *registro,uint32_t *Rt,uint32_t R1,uint32_t R2)
{
	memoria[R1+R2]=(uint8_t)(*Rt);
	int i;
	for(i=1;i<=3;i++)
    {
        memoria[R1+R2+i]=(uint8_t)(*Rt>>i*8);

    }
	registro[15]++;
}

void STRB(uint8_t *memoria,uint32_t *registro,uint32_t *Rt,uint32_t R1,uint32_t R2)
{
	memoria[R1+R2]=(uint8_t)(*Rt);
	registro[15]++;
}

void STRH(uint8_t *memoria,uint32_t *registro,uint32_t *Rt,uint32_t R1,uint32_t R2){
	memoria[R1+R2]=(uint8_t)(*Rt);
    memoria[R1+R2+1]=(uint8_t)(*Rt>>8);
	registro[15]++;
}


