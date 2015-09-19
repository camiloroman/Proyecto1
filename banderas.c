 #include <stdio.h>
 #include <stdlib.h>
 #include <stdint.h>
 #include "banderas.h"

void banderas(uint32_t *R,uint32_t R0,uint32_t R1)
{
	uint32_t RR;//Se crea la variable auxiliar RR
	RR=R0+R1;
	if(RR>=(1<<31))
		{
			R[0]=1; //Si se cumple la condicion anterior se activa la bandera de signo
		}
	else
		{
			R[0]=0;
		}


	if (RR==0)
		{
			R[1]=1; //Si RR=0 se activa la bandera de cero
		}
	else
		{
			R[1]=0;
		}


	if(((R1>=(1<<31))&&(R0>=(1<<31)))||((R0>=(1<<31))&&(R1<(1<<31))&&(RR<(1<<31)))||((R1>=(1<<31))&&(R0<(1<<31))&&(RR<(1<<31))))
		{
			R[2]=1; //Si se cumple la anterior condicion se activa la bandera de carry
		}
	else
		{
			R[2]=0;
		}


	if(((R1>=(1<<31))&&(R0>=(1<<31))&&(RR<(1<<31)))||((R0<(1<<31))&&(R1<(1<<31))&&(RR>=(1<<31))))
		{
    			R[3]=1; //Si se cumple la anterior condicion se activa la bandera de sobreflujo
		}
	else
		{
			R[3]=0;
		}
}

void LSL(uint32_t *R,uint32_t R0,uint32_t R1) 
	{
		*R=R0<<R1; //R0 se desplaza R1 posiciones a la izquierda y se almacena en *R
	}


void LSR(uint32_t *R,uint32_t R0,uint32_t R1)
	{
		*R=R0>>R1; //R0 se desplaza R1 posiciones a la derecha y se almacena en *R
	}


void BIC(uint32_t *R,uint32_t R0)
	{
		*R&=~R0; //Se realiza la AND entre el registro *R y el complemento de R0 y se almacena en *R
	}

void MVN(uint32_t *R,uint32_t R0)
	{
		*R&=R0; //Se realiza la AND entre el registro *R, R0 y se almacena en *R
	}


void RSB(uint32_t *R,uint32_t R0)
	{
		*R=0-R0;
	}


void NOP(uint32_t *R,uint32_t R0)
	{
		//Esta funcion no hace nada
	}


void ROR(uint32_t *R,uint32_t R0,uint32_t R1)
	{
		if(R1==32)
			{
				*R=R0;
			}
		else
			{
				uint32_t aux; //Se crea una variable auxiliar
				aux=R0>>(32-R1); //R0 se desplaza 32-R1 posiciones a la derecha
				*R=R0<<R1; //R0 se desplaza R1 posiciones a la izquierda y se almacena en *R
				*R=*R|aux; //Se realiza la suma bit a bit entre *R, aux y se almacena en *R
			}
	}



void REV(uint32_t *R,uint32_t R0)
	{
		uint32_t aux,aux1,aux2,aux3; //Se crean tres variables auxiliares
		aux=R0<<24; //En aux se almacena R0 desplazado 24 posiciones a la izquierda
		aux1=R0>>24; //En aux1 se almacena R0 desplazado 24 posiciones a la derecha
		aux2=((R0<<16)>>24)<<16; //En aux2 se almacena el resultado de R0 desplazado 
		aux3=((R0<<8)>>24)<<8; //En aux3 se almacena el resultado de R0 desplazado
		*R=((aux|aux1)|aux2)|aux3; //En *R se almacena la suma bit a bit de las tres variables auxiliares
	}


void REVIG(uint32_t *R,uint32_t R0)
	{
		uint32_t aux,aux1,aux2,aux3; //Se crean tres variables auxiliares
		aux=(R0>>24)<<16;
		aux1=(R0>>16)<<24;
		aux2=((R0<<16)>>24);	//Se hacen varios desplazamientos de R0 y se almacenan el las tres variables auxiliares
		aux3=((R0<<24)>>16);
		*R=((aux|aux1)|aux2)|aux3; //En *R se almacena la suma bit a bit de las tres variables auxiliares
	}
