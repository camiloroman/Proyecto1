#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "mostrar.h"
#include "banderas.h"
#include "Alu.h"

int main()
{
	uint32_t flags,instrucciones[23];
	uint32_t registros[12];
	flags=banderas(registros,registros(1),registros(2));
	instrucciones[0]=LSL(registros,registros(1),registros(2));
	instrucciones[1]=LSR(registros,registros(1),registros(2));
	instrucciones[2]=BIC(registros,registros(1));
	instrucciones[3]=MVN(registros,registros(1));
	instrucciones[4]=RSB(registros,registros(1));
	instrucciones[5]=NOP(registros,registros(1));
	mostrardatos(registros);
}