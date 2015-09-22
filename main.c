#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "mostrar.h"
#include "banderas.h"
#include "Alu.h"
#include "branch.h"

int main()
{
	unsigned i;
	uint32_t flags[4]={0,0,0,0};//Se declara el arreglo flags y se inicializan sus valores en 0
	uint32_t registros[12];



int continuar;

do
{
system("cls");
int operacion;  //Se declara variable entera "operacion"
	printf("INGRESE:");
	printf("0 - Para Imprimir registros y banderas");
	printf("1 - Para (ADD) suma");
	printf("2 - Para (AND) AND bit a bit");
	printf("3 - Para (BIC) AND entre un registro y el complemento de otro");
	printf("4 - Para (EOR) OR exclusiva bit a bit");
	printf("5 - Para (LSL) Desplazamiento logico a la izquierda");
	printf("6 - Para (LSR) Desplazamiento logico a la derecha");
	printf("7 - Para (MOV) Escribe un valor en un registro");
	printf("8 - Para (MVN) Guarda el complemento de un registro");
	printf("9 - Para (NOP) No hace nada");
	printf("10- Para (ORR) OR lògica bit a bit");
	printf("11- Para (REV) Cambia el orden de los Bytes");
	printf("12- Para (REVIG) Cambia el orden de los Bytes en cada halfword de 16 bits");
	printf("13- Para (ROR) Rotacion a la derecha");
	printf("14- Para (RSB) Obtiene el complemento a dos de un numero");
	printf("15- Para (SUB) Resta");


	scanf("%d",&operacion);
	system("cls");
	switch(operacion)
	{
		case 0:
			mostrardatos(*registros);
			mostrarbanderas(*flags);
			break;

		case 1:
			ADD(*registros,registros[1],registros[2]);  //Se envian registros a operar y se recibe un retorno
			banderas(*registros,registros[1],registros[2]);  //Se envian los registros operados a banderas y se retornan las banderas activas
			mostrardatos(*registros);  //Se accede a la funcion para mostrar los valores de los registros
			mostrarbanderas(*flags);  //Se accede a la funcion para mostrar los valores de las banderas
			break;
		case 2:
			AND(*registros,registros[1],registros[2]);  //Se envian registros a operar y se recibe un retorno
			banderas(*registros,registros[1],registros[2]);  //Se envian los registros operados a banderas y se retornan las banderas activas
			mostrardatos(*registros);  //Se accede a la funcion para mostrar los valores de los registros
			mostrarbanderas(*flags);  //Se accede a la funcion para mostrar los valores de las banderas
			break;

		case 3:
			BIC(registros,registros[1]);  //Se envian registros a operar y se recibe un retorno
			banderas(*registros,registros[0],registros[1]);  //Se envian los registros operados a banderas y se retornan las banderas activas
			mostrardatos(*registros);  //Se accede a la funcion para mostrar los valores de los registros
			mostrarbanderas(*flags);  //Se accede a la funcion para mostrar los valores de las banderas
			break;

		case 4:
			EOR(registros,registros[1],registros[2]);  //Se envian registros a operar y se recibe un retorno
			banderas(*registros,registros[1],registros[2]);  //Se envian los registros operados a banderas y se retornan las banderas activas
			mostrardatos(*registros);  //Se accede a la funcion para mostrar los valores de los registros
			mostrarbanderas(*flags);  //Se accede a la funcion para mostrar los valores de las banderas
			break;

		case 5:
			LSL(registros,registros[1],registros[2]);  //Se envian registros a operar y se recibe un retorno
			banderas(*registros,registros[1],registros[2]);  //Se envian los registros operados a banderas y se retornan las banderas activas
			mostrardatos(*registros);  //Se accede a la funcion para mostrar los valores de los registros
			mostrarbanderas(*flags);  //Se accede a la funcion para mostrar los valores de las banderas
			break;

		case 6:
			LSR(registros,registros[1],registros[2]);  //Se envian registros a operar y se recibe un retorno
			banderas(*registros,registros[1],registros[2]);  //Se envian los registros operados a banderas y se retornan las banderas activas
			mostrardatos(*registros);  //Se accede a la funcion para mostrar los valores de los registros
			mostrarbanderas(*flags);  //Se accede a la funcion para mostrar los valores de las banderas
			break;

		case 7:
			MOV(registros,registros[1]);  //Se envian registros a operar y se recibe un retorno
			banderas(*registros,registros[0],registros[1]);  //Se envian los registros operados a banderas y se retornan las banderas activas
			mostrardatos(*registros);  //Se accede a la funcion para mostrar los valores de los registros
			mostrarbanderas(*flags);  //Se accede a la funcion para mostrar los valores de las banderas
			break;

		case 8:
			MVN(registros,registros[1]);  //Se envian registros a operar y se recibe un retorno
			banderas(*registros,registros[1],registros[2]);  //Se envian los registros operados a banderas y se retornan las banderas activas
			mostrardatos(*registros);  //Se accede a la funcion para mostrar los valores de los registros
			mostrarbanderas(*flags);  //Se accede a la funcion para mostrar los valores de las banderas
			break;

		case 9:
			NOP(registros,registros[1]);  //Se envian registros a operar y se recibe un retorno
			banderas(*registros,registros[1],registros[2]);  //Se envian los registros operados a banderas y se retornan las banderas activas
			mostrardatos(*registros);  //Se accede a la funcion para mostrar los valores de los registros
			mostrarbanderas(*flags);  //Se accede a la funcion para mostrar los valores de las banderas
			break;

		case 10:
			ORR(registros,registros[1],registros[2]);  //Se envian registros a operar y se recibe un retorno
			banderas(*registros,registros[1],registros[2]);  //Se envian los registros operados a banderas y se retornan las banderas activas
			mostrardatos(*registros);  //Se accede a la funcion para mostrar los valores de los registros
			mostrarbanderas(*flags);  //Se accede a la funcion para mostrar los valores de las banderas
			break;

		case 11:
			REV(registros,registros[1]);  //Se envian registros a operar y se recibe un retorno
			banderas(*registros,registros[1],registros[2]);  //Se envian los registros operados a banderas y se retornan las banderas activas
			mostrardatos(*registros);  //Se accede a la funcion para mostrar los valores de los registros
			mostrarbanderas(*flags);  //Se accede a la funcion para mostrar los valores de las banderas
			break;

		case 12:
			REVIG(registros,registros[1]);  //Se envian registros a operar y se recibe un retorno
			banderas(*registros,registros[1],registros[2]);  //Se envian los registros operados a banderas y se retornan las banderas activas
			mostrardatos(*registros);  //Se accede a la funcion para mostrar los valores de los registros
			mostrarbanderas(*flags);  //Se accede a la funcion para mostrar los valores de las banderas
			break;

		case 13:
			ROR(registros,registros[1],registros[2]);  //Se envian registros a operar y se recibe un retorno
			banderas(*registros,registros[1],registros[2]);  //Se envian los registros operados a banderas y se retornan las banderas activas
			mostrardatos(*registros);  //Se accede a la funcion para mostrar los valores de los registros
			mostrarbanderas(*flags);  //Se accede a la funcion para mostrar los valores de las banderas
			break;

		case 14:
			RSB(registros,registros[1]);  //Se envian registros a operar y se recibe un retorno
			banderas(*registros,registros[1],registros[2]);  //Se envian los registros operados a banderas y se retornan las banderas activas
			mostrardatos(*registros);  //Se accede a la funcion para mostrar los valores de los registros
			mostrarbanderas(*flags);  //Se accede a la funcion para mostrar los valores de las banderas
			break;

		case 15:
			SUB(registros,registros[1],registros[2]);  //Se envian registros a operar y se recibe un retorno
			banderas(*registros,registros[1],registros[2]);  //Se envian los registros operados a banderas y se retornan las banderas activas
			mostrardatos(*registros);  //Se accede a la funcion para mostrar los valores de los registros
			mostrarbanderas(*flags);  //Se accede a la funcion para mostrar los valores de las banderas
			break;

		default:
			printf("Error");
			break;
	}


	printf("1 - Para continuar");
	printf("otro - Para salir");
	scanf("%d", &continuar);

}while(continuar==1);


	return 0;
}
