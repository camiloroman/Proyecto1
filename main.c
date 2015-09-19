#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "mostrar.h"
#include "banderas.h"
#include "Alu.h"
#include <curses.h>
#include <colors.h>


int main()
{
	unsigned i;
	uint32_t flags[4]={0,0,0,0};//Se declara el arreglo flags y se inicializan sus valores en 0
	uint32_t registros[12];

	
	initscr();		/* Inicia modo curses */
	curs_set(0);	/* Cursor Invisible */
	raw();			/* Activa modo raw */
	keypad(stdscr, TRUE);	/* Obtener F1, F2, etc */
	noecho();		/* No imprimir los caracteres leidos */
	
	start_color();	/* Permite manejar colores */
	
	init_pair(1, COLOR_GREEN, COLOR_BLACK);	/* Pair 1 -> Texto ver fondo Negro */	
	
	
	border( ACS_VLINE, ACS_VLINE, 
			ACS_HLINE, ACS_HLINE, 
			ACS_ULCORNER, ACS_URCORNER,
			ACS_LLCORNER, ACS_LRCORNER);
	
	attron(COLOR_PAIR(1));	/* Activa el color verde para el 
							   texto y negro para el fondo Pair 1*/
	
	move(2, 34);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("Emulador ARM-Cortex-M0");	
	refresh();	/* Imprime en la pantalla
					Sin esto el printw no es mostrado */
	
	for(i=0;i<=3;i++)
	{
	move(i+3, 5);
	printw("R[%d]=%d \n",i+1,R[i]);
	refresh();
	}
	for(i=0;i<=11;i++)
	{
	move(i+9, 5);
	printw("Registro[%d]=%d \n",i+1,resgistros[i]);
	refresh();
	}
	
	attroff(COLOR_PAIR(1));	/* DEshabilita los colores Pair 1 */
	
	getch();	/* Espera entrada del usuario */
	endwin();	/* Finaliza el modo curses */

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
	printf("12- Para (REV16) Cambia el orden de los Bytes en cada halfword de 16 bits");
	printf("13- Para (ROR) Rotacion a la derecha");
	printf("14- Para (RSB) Obtiene el complemento a dos de un numero");
	printf("15- Para (SUB) Resta");
	

	scanf("%d",&operacion);
	system("cls");
	switch(operacion);
	{
		case 0:
			mostrardatos(*registros);
			mostrarbanderas(*flags);
			break;
		
		case 1:
			registros[0]=ADD(registros,registros[1],registros[2]);  //Se envian registros a operar y se recibe un retorno
			flags[0]=banderas(*registros,registros[1],registros[2]);  //Se envian los registros operados a banderas y se retornan las banderas activas
			mostrardatos(*registros);  //Se accede a la funcion para mostrar los valores de los registros
			mostrarbanderas(*flags);  //Se accede a la funcion para mostrar los valores de las banderas
			break;
		case 2:
			registros[0]=AND(*registros,registros[1],registros[2]);  //Se envian registros a operar y se recibe un retorno
			flags[0]=banderas(*registros,registros[1],registros[2]);  //Se envian los registros operados a banderas y se retornan las banderas activas
			mostrardatos(*registros);  //Se accede a la funcion para mostrar los valores de los registros
			mostrarbanderas(*flags);  //Se accede a la funcion para mostrar los valores de las banderas
			break;

		case 3:
			registros[0]=BIC(registros,registros[1]);  //Se envian registros a operar y se recibe un retorno
			flags[0]=banderas(*registros,registros[0],registros[1]);  //Se envian los registros operados a banderas y se retornan las banderas activas
			mostrardatos(*registros);  //Se accede a la funcion para mostrar los valores de los registros
			mostrarbanderas(*flags);  //Se accede a la funcion para mostrar los valores de las banderas
			break;

		case 4:
			registros[0]=EOR(registros,registros[1],registros[2]);  //Se envian registros a operar y se recibe un retorno
			flags[0]=banderas(*registros,registros[1],registros[2]);  //Se envian los registros operados a banderas y se retornan las banderas activas
			mostrardatos(*registros);  //Se accede a la funcion para mostrar los valores de los registros
			mostrarbanderas(*flags);  //Se accede a la funcion para mostrar los valores de las banderas
			break;

		case 5:
			registros[0]=LSL(registros,registros[1],registros[2]);  //Se envian registros a operar y se recibe un retorno
			flags[0]=banderas(*registros,registros[1],registros[2]);  //Se envian los registros operados a banderas y se retornan las banderas activas
			mostrardatos(*registros);  //Se accede a la funcion para mostrar los valores de los registros
			mostrarbanderas(*flags);  //Se accede a la funcion para mostrar los valores de las banderas
			break;

		case 6:
			registros[0]=LSR(registros,registros[1],registros[2]);  //Se envian registros a operar y se recibe un retorno
			flags[0]=banderas(*registros,registros[1],registros[2]);  //Se envian los registros operados a banderas y se retornan las banderas activas
			mostrardatos(*registros);  //Se accede a la funcion para mostrar los valores de los registros
			mostrarbanderas(*flags);  //Se accede a la funcion para mostrar los valores de las banderas
			break;

		case 7:
			registros[0]=MOV(registros,registros[1]);  //Se envian registros a operar y se recibe un retorno
			flags[0]=banderas(*registros,registros[0],registros[1]);  //Se envian los registros operados a banderas y se retornan las banderas activas
			mostrardatos(*registros);  //Se accede a la funcion para mostrar los valores de los registros
			mostrarbanderas(*flags);  //Se accede a la funcion para mostrar los valores de las banderas
			break;

		case 8:
			registros[0]=MVN(registros,registros[1]);  //Se envian registros a operar y se recibe un retorno
			flags[0]=banderas(*registros,registros[1],registros[2]);  //Se envian los registros operados a banderas y se retornan las banderas activas
			mostrardatos(*registros);  //Se accede a la funcion para mostrar los valores de los registros
			mostrarbanderas(*flags);  //Se accede a la funcion para mostrar los valores de las banderas
			break;

		case 9:
			registros[0]=NOP(registros,registros[1]);  //Se envian registros a operar y se recibe un retorno
			flags[0]=banderas(*registros,registros[1],registros[2]);  //Se envian los registros operados a banderas y se retornan las banderas activas
			mostrardatos(*registros);  //Se accede a la funcion para mostrar los valores de los registros
			mostrarbanderas(*flags);  //Se accede a la funcion para mostrar los valores de las banderas
			break;

		case 10:
			registros[0]=ORR(registros,registros[1],registros[2]);  //Se envian registros a operar y se recibe un retorno
			flags[0]=banderas(*registros,registros[1],registros[2]);  //Se envian los registros operados a banderas y se retornan las banderas activas
			mostrardatos(*registros);  //Se accede a la funcion para mostrar los valores de los registros
			mostrarbanderas(*flags);  //Se accede a la funcion para mostrar los valores de las banderas
			break;

		case 11:
			registros[0]=REV(registros,registros[1]);  //Se envian registros a operar y se recibe un retorno
			flags[0]=banderas(*registros,registros[1],registros[2]);  //Se envian los registros operados a banderas y se retornan las banderas activas
			mostrardatos(*registros);  //Se accede a la funcion para mostrar los valores de los registros
			mostrarbanderas(*flags);  //Se accede a la funcion para mostrar los valores de las banderas
			break;

		case 12:
			registros[0]=REV16(registros,registros[1]);  //Se envian registros a operar y se recibe un retorno
			flags[0]=banderas(*registros,registros[1],registros[2]);  //Se envian los registros operados a banderas y se retornan las banderas activas
			mostrardatos(*registros);  //Se accede a la funcion para mostrar los valores de los registros
			mostrarbanderas(*flags);  //Se accede a la funcion para mostrar los valores de las banderas
			break;
		
		case 13:
			registros[0]=ROR(registros,registros[1],registros[2]);  //Se envian registros a operar y se recibe un retorno
			flags[0]=banderas(*registros,registros[1],registros[2]);  //Se envian los registros operados a banderas y se retornan las banderas activas
			mostrardatos(*registros);  //Se accede a la funcion para mostrar los valores de los registros
			mostrarbanderas(*flags);  //Se accede a la funcion para mostrar los valores de las banderas
			break;

		case 14:
			registros[0]=RSB(registros,registros[1]);  //Se envian registros a operar y se recibe un retorno
			flags[0]=banderas(*registros,registros[1],registros[2]);  //Se envian los registros operados a banderas y se retornan las banderas activas
			mostrardatos(*registros);  //Se accede a la funcion para mostrar los valores de los registros
			mostrarbanderas(*flags);  //Se accede a la funcion para mostrar los valores de las banderas
			break;

		case 15:
			registros[0]=SUB(registros,registros[1],registros[2]);  //Se envian registros a operar y se recibe un retorno
			flags[0]=banderas(*registros,registros[1],registros[2]);  //Se envian los registros operados a banderas y se retornan las banderas activas
			mostrardatos(*registros);  //Se accede a la funcion para mostrar los valores de los registros
			mostrarbanderas(*flags);  //Se accede a la funcion para mostrar los valores de las banderas
			break;

		default:
			printf("Error");
			break;
	}

	int continuar;
	
	printf("1 - Para continuar");
	printf("otro - Para salir");
	scanf("%d",&continuar);

}while(continuar==1)

	
	return 0;
}