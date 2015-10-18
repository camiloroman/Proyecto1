#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "mostrar.h"
#include "banderas.h"
#include "Alu.h"
#include "Memory.h"
#include "LDR y STR.h"
#include "branch.h"
#include <curses.h>

int main()
{
	unsigned i;
	uint32_t flags[4]={0,0,0,0};//Se declara el arreglo flags y se inicializan sus valores en 0
	uint32_t registros[15]={1,2,3,4,0,0,0,0,0,0,0,0,0,0,0};
initscr();		/* Inicia modo curses */
	curs_set(0);	/* Cursor Invisible */
	raw();			/* Activa modo raw */
	keypad(stdscr, TRUE);	/* Obtener F1, F2, etc */
	noecho();		/* No imprimir los caracteres leidos */

	start_color();	/* Permite manejar colores */

	init_pair(1, COLOR_GREEN, COLOR_BLACK);	/* Pair 1 -> Texto verde
						fondo Negro */


	border( ACS_VLINE, ACS_VLINE,
			ACS_HLINE, ACS_HLINE,
			ACS_ULCORNER, ACS_URCORNER,
			ACS_LLCORNER, ACS_LRCORNER	);

	attron(COLOR_PAIR(1));	/* Activa el color verde para el
							   texto y negro para el fondo Pair 1*/

	move(2, 34);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("Emulador ARM-Cortex-M0");
	refresh();	/* Imprime en la pantalla
					Sin esto el printw no es mostrado */

	for(i=0;i<=3;i++)
	{
	move(i+3, 5);
	printw("bandera[%d]=%d \n",i+1,flags[i]);
	refresh();
	}
	for(i=0;i<=11;i++)
	{
	move(i+9, 5);
	printw("Registro[%d]=%d \n",i+1,registros[i]);
	refresh();
	}




int continuar;

do
{
system("cls");
int operacion;  //Se declara variable entera "operacion"
	printf("INGRESE:\n");
	printf("0 - Para Imprimir registros y banderas\n");
	printf("1 - Para (ADD) suma\n");
	printf("2 - Para (AND) AND bit a bit\n");
	printf("3 - Para (BIC) AND entre un registro y el complemento de otro\n");
	printf("4 - Para (EOR) OR exclusiva bit a bit\n");
	printf("5 - Para (LSL) Desplazamiento logico a la izquierda\n");
	printf("6 - Para (LSR) Desplazamiento logico a la derecha\n");
	printf("7 - Para (MOV) Escribe un valor en un registro\n");
	printf("8 - Para (MVN) Guarda el complemento de un registro\n");
	printf("9 - Para (NOP) No hace nada\n");
	printf("10- Para (ORR) OR lògica bit a bit\n");
	printf("11- Para (REV) Cambia el orden de los Bytes\n");
	printf("12- Para (REVIG) Cambia el orden de los Bytes en cada halfword de 16 bits\n");
	printf("13- Para (ROR) Rotacion a la derecha\n");
	printf("14- Para (RSB) Obtiene el complemento a dos de un numero\n");
	printf("15- Para (SUB) Resta\n");


	scanf("%d",&operacion);
	system("cls");
	switch(operacion)
	{
		case 0:
			mostrardatos(registros);
			mostrarbanderas(flags);
			break;

		case 1:
			ADD(registros,registros[1],registros[2]);  //Se envian registros a operar y se recibe un retorno
			banderas(registros,registros[1],registros[2]);  //Se envian los registros operados a banderas y se retornan las banderas activas
			mostrardatos(registros);  //Se accede a la funcion para mostrar los valores de los registros
			mostrarbanderas(flags);  //Se accede a la funcion para mostrar los valores de las banderas
			break;
		case 2:
			AND(registros,registros[1],registros[2]);  //Se envian registros a operar y se recibe un retorno
			banderas(registros,registros[1],registros[2]);  //Se envian los registros operados a banderas y se retornan las banderas activas
			mostrardatos(registros);  //Se accede a la funcion para mostrar los valores de los registros
			mostrarbanderas(flags);  //Se accede a la funcion para mostrar los valores de las banderas
			break;

		case 3:
			BIC(registros,registros[1]);  //Se envian registros a operar y se recibe un retorno
			banderas(registros,registros[0],registros[1]);  //Se envian los registros operados a banderas y se retornan las banderas activas
			mostrardatos(registros);  //Se accede a la funcion para mostrar los valores de los registros
			mostrarbanderas(flags);  //Se accede a la funcion para mostrar los valores de las banderas
			break;

		case 4:
			EOR(registros,registros[1],registros[2]);  //Se envian registros a operar y se recibe un retorno
			banderas(registros,registros[1],registros[2]);  //Se envian los registros operados a banderas y se retornan las banderas activas
			mostrardatos(registros);  //Se accede a la funcion para mostrar los valores de los registros
			mostrarbanderas(flags);  //Se accede a la funcion para mostrar los valores de las banderas
			break;

		case 5:
			LSL(registros,registros[1],registros[2]);  //Se envian registros a operar y se recibe un retorno
			banderas(registros,registros[1],registros[2]);  //Se envian los registros operados a banderas y se retornan las banderas activas
			mostrardatos(registros);  //Se accede a la funcion para mostrar los valores de los registros
			mostrarbanderas(flags);  //Se accede a la funcion para mostrar los valores de las banderas
			break;

		case 6:
			LSR(registros,registros[1],registros[2]);  //Se envian registros a operar y se recibe un retorno
			banderas(registros,registros[1],registros[2]);  //Se envian los registros operados a banderas y se retornan las banderas activas
			mostrardatos(registros);  //Se accede a la funcion para mostrar los valores de los registros
			mostrarbanderas(flags);  //Se accede a la funcion para mostrar los valores de las banderas
			break;

		case 7:
			MOV(registros,registros[1]);  //Se envian registros a operar y se recibe un retorno
			banderas(registros,registros[0],registros[1]);  //Se envian los registros operados a banderas y se retornan las banderas activas
			mostrardatos(registros);  //Se accede a la funcion para mostrar los valores de los registros
			mostrarbanderas(flags);  //Se accede a la funcion para mostrar los valores de las banderas
			break;

		case 8:
			MVN(registros,registros[1]);  //Se envian registros a operar y se recibe un retorno
			banderas(registros,registros[1],registros[2]);  //Se envian los registros operados a banderas y se retornan las banderas activas
			mostrardatos(registros);  //Se accede a la funcion para mostrar los valores de los registros
			mostrarbanderas(flags);  //Se accede a la funcion para mostrar los valores de las banderas
			break;

		case 9:
			NOP(registros,registros[1]);  //Se envian registros a operar y se recibe un retorno
			banderas(registros,registros[1],registros[2]);  //Se envian los registros operados a banderas y se retornan las banderas activas
			mostrardatos(registros);  //Se accede a la funcion para mostrar los valores de los registros
			mostrarbanderas(flags);  //Se accede a la funcion para mostrar los valores de las banderas
			break;

		case 10:
			ORR(registros,registros[1],registros[2]);  //Se envian registros a operar y se recibe un retorno
			banderas(registros,registros[1],registros[2]);  //Se envian los registros operados a banderas y se retornan las banderas activas
			mostrardatos(registros);  //Se accede a la funcion para mostrar los valores de los registros
			mostrarbanderas(flags);  //Se accede a la funcion para mostrar los valores de las banderas
			break;

		case 11:
			REV(registros,registros[1]);  //Se envian registros a operar y se recibe un retorno
			banderas(registros,registros[1],registros[2]);  //Se envian los registros operados a banderas y se retornan las banderas activas
			mostrardatos(registros);  //Se accede a la funcion para mostrar los valores de los registros
			mostrarbanderas(flags);  //Se accede a la funcion para mostrar los valores de las banderas
			break;

		case 12:
			REVIG(registros,registros[1]);  //Se envian registros a operar y se recibe un retorno
			banderas(registros,registros[1],registros[2]);  //Se envian los registros operados a banderas y se retornan las banderas activas
			mostrardatos(registros);  //Se accede a la funcion para mostrar los valores de los registros
			mostrarbanderas(flags);  //Se accede a la funcion para mostrar los valores de las banderas
			break;

		case 13:
			ROR(registros,registros[1],registros[2]);  //Se envian registros a operar y se recibe un retorno
			banderas(registros,registros[1],registros[2]);  //Se envian los registros operados a banderas y se retornan las banderas activas
			mostrardatos(registros);  //Se accede a la funcion para mostrar los valores de los registros
			mostrarbanderas(flags);  //Se accede a la funcion para mostrar los valores de las banderas
			break;

		case 14:
			RSB(registros,registros[1]);  //Se envian registros a operar y se recibe un retorno
			banderas(registros,registros[1],registros[2]);  //Se envian los registros operados a banderas y se retornan las banderas activas
			mostrardatos(registros);  //Se accede a la funcion para mostrar los valores de los registros
			mostrarbanderas(flags);  //Se accede a la funcion para mostrar los valores de las banderas
			break;

		case 15:
			SUB(registros,registros[1],registros[2]);  //Se envian registros a operar y se recibe un retorno
			banderas(registros,registros[1],registros[2]);  //Se envian los registros operados a banderas y se retornan las banderas activas
			mostrardatos(registros);  //Se accede a la funcion para mostrar los valores de los registros
			mostrarbanderas(flags);  //Se accede a la funcion para mostrar los valores de las banderas
			break;

		default:
			printf("Error");
			break;
	}


	printf("\n1 - Para continuar");
	printf("\totro - Para salir\n");
	scanf("%d", &continuar);

}while(continuar==1);
attroff(COLOR_PAIR(1));	/* DEshabilita los colores Pair 1 */

	getch();	/* Espera entrada del usuario */
	endwin();	/* Finaliza el modo curses */

	return 0;
}