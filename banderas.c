 #include <stdio.h>
 #include <stdlib.h>
 #include <stdint.h>
 #include "banderas.h"

//R, R0 y R1 son los registros que se van a operar

void banderas(uint32_t *R,uint32_t R0,uint32_t R1)
{
	uint32_t RR;//Se crea la variable auxiliar RR
	int flags[4];//Se crea el arreglo "flags" para almacenar los valores de las banderas
	RR=R0+R1;
	if(*R>=(1<<31))
		{
			flags[0]=1; //Si se cumple la condicion anterior se activa la bandera de signo
		}
	else
		{
			flags[0]=0;
		}


	if (*R==0)
		{
			flags[1]=1; //Si RR=0 se activa la bandera de cero
		}
	else
		{
			flags[1]=0;
		}


	if(((R1>=(1<<31))&&(R0>=(1<<31)))||((R0>=(1<<31))&&(R1<(1<<31))&&(RR<(1<<31)))||((R1>=(1<<31))&&(R0<(1<<31))&&(RR<(1<<31))))
		{
			flags[2]=1; //Si se cumple la anterior condicion se activa la bandera de carry
		}
	else
		{
			flags[2]=0;
		}


	if(((R1>=(1<<31))&&(R0>=(1<<31))&&(RR<(1<<31)))||((R0<(1<<31))&&(R1<(1<<31))&&(RR>=(1<<31))))
		{
    			flags[3]=1; //Si se cumple la anterior condicion se activa la bandera de sobreflujo
		}
	else
		{
			flags[3]=0;
		}

	return *flags;
}

void LSL(uint32_t *R,uint32_t R0,uint32_t R1) 
	{
		*R=R0<<R1; //R0 se desplaza R1 posiciones a la izquierda y se almacena en *R
		return *R; //retorna el valor de la operacion realizada
	}


void LSR(uint32_t *R,uint32_t R0,uint32_t R1)
	{
		*R=R0>>R1; //R0 se desplaza R1 posiciones a la derecha y se almacena en *R
		return *R; //retorna el valor de la operacion realizada
	}


void BIC(uint32_t *R,uint32_t R0)
	{
		*R&=~R0; //Se realiza la AND entre el registro *R y el complemento de R0 y se almacena en *R
		return *R; //retorna el valor de la operacion realizada
	}

void MVN(uint32_t *R,uint32_t R0)
	{
		*R&=R0; //Se realiza la AND entre el registro *R, R0 y se almacena en *R
		return *R; //retorna el valor de la operacion realizada
	}


void RSB(uint32_t *R,uint32_t R0)
	{
		*R=0-R0;
		return *R; //retorna el valor de la operacion realizada
	}


void NOP(uint32_t *R,uint32_t R0)
	{
		//Esta funcion no hace nada
		return *R; //retorna el valor que tenia *R 
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
		return *R; //retorna el valor de la operacion realizada
	}



void REV(uint32_t *R,uint32_t R0)
	{
		uint32_t aux,aux1,aux2,aux3; //Se crean tres variables auxiliares
		aux=R0<<24; //En aux se almacena R0 desplazado 24 posiciones a la izquierda
		aux1=R0>>24; //En aux1 se almacena R0 desplazado 24 posiciones a la derecha
		aux2=((R0<<16)>>24)<<16; //En aux2 se almacena el resultado de R0 desplazado 
		aux3=((R0<<8)>>24)<<8; //En aux3 se almacena el resultado de R0 desplazado
		*R=((aux|aux1)|aux2)|aux3; //En *R se almacena la suma bit a bit de las tres variables auxiliares
		return *R; //retorna el valor de la operacion realizada
	}


void REVIG(uint32_t *R,uint32_t R0)
	{
		uint32_t aux,aux1,aux2,aux3; //Se crean tres variables auxiliares
		aux=(R0>>24)<<16;
		aux1=(R0>>16)<<24;
		aux2=((R0<<16)>>24);	//Se hacen varios desplazamientos de R0 y se almacenan el las tres variables auxiliares
		aux3=((R0<<24)>>16);
		*R=((aux|aux1)|aux2)|aux3; //En *R se almacena la suma bit a bit de las tres variables auxiliares
		return *R; //retorna el valor de la operacion realizada
	}
