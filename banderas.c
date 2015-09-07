 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>
 #include "banderas.h"
void banderas(uint32_t *R,uint32_t R0,uint32_t R1)
{
uint32_t RR
RR=R0+R1;
if(RR>=pow(2,31))
	{
		R[0]=1;
	}
else
	{
		R[0]=0;
	}

if (RR==0)
	{
		R[1]=1;
	}
else
	{
		R[1]=0;
	}

if(((R1>=pow(2,31))&&(R0>=pow(2,31)))||((R0>=pow(2,31))&&(R1<pow(2,31))&&(RR<pow(2,31)))||((R1>=pow(2,31))&&(R0<pow(2,31))&&(RR<pow(2,31))))
	{
		R[2]=1;
	}
else
	{
		R[2]=0;
	}

if(((R1>=pow(2,31))&&(R0>=pow(2,31))&&(RR<pow(2,31)))||((R0<pow(2,31))&&(R1<pow(2,31))&&(RR>=pow(2,31))))
	{
		if(((Rn>=pow(2,31))&&(Rm>=pow(2,31))&&(R<pow(2,31)))||((Rn<pow(2,31))&&(Rm<pow(2,31))&&(R>=pow(2,31))))
    		R[3]=1;
	}
else
	{
		R[3]=0;
	}
}

void LSL(uint32_t *R,uint32_t R0,uint32_t R1) 
{
	*R=R0<<R1; 
}

void LSR(uint32_t *R,uint32_t R0,uint32_t R1)
{
	*R=R0>>R1;
}

void BIC(uint32_t *R,uint32_t R0)
{
	*R&=~R0;
}

void MVN(uint32_t *R,uint32_t R0)
{
	*R&=R0;
}

void RSB(uint32_t *R,uint32_t R0)
{
	*R=0-R0;
}

void NOP(uint32_t *R,uint32_t R0)
{
	
}

void ROR(uint32_t *R,uint32_t R0,uint32_t R1)
{
	if(R1==32)
	{
		*R=R0;
	}
	else
	{
		uint32_t aux;
		aux=R0>>(32-R1);
		*R=R0<<R1;
		*R=*R|aux;
	}

}


void REV(uint32_t *R,uint32_t R0)
{
	uint32_t aux,aux1,aux2;
	aux=R0<<24;
	aux1=R0>>24;
	aux2=((R0<<16)>>24)<<16;
	aux3=((R0<<8)>>24)<<8;
	*R=((aux|aux1)|aux2)|aux3;
	
}

void REVIG(uint32_t *R,uint32_t R0)
{
	uint32_t aux,aux1,aux2;
	aux=(R0>>24)<<16;
	aux1=(R0>>16)<<24;
	aux2=((R0<<16)>>24);
	aux3=((R0<<24)>>16);
	*R=((aux|aux1)|aux2)|aux3;
}
