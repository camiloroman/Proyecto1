#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "mostrar.h"
#include "banderas.h"
#include "Alu.h"
#include <curses.h>


int main()
{
	unsigned i;
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

	return 0;
}