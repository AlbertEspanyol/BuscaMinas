#ifndef _GRAFICA_H_
#define _GRAFICA_H_
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "logica.h"
#include "ranquing.h"

/***********************************************
 * 
 * @ Finalitat: Dibuixar una mina ben feta
 * @ Parametres: 	in: x = posicio en columnes del cursor
					in: y = posicio en files del cursor
 * @ Retorn: --------
 *  
***********************************************/
void GRAFICA_dibuixaMina (int x, int y);

/***********************************************
 * 
 * @ Finalitat: Dibuixar constantment el tauler de caselles del joc.
 * @ Parametres: 	in: board = tipus one es guarda la informacio del tauler i de cada casella
					in: b = llista on es troben les posicions de les banderes colocades
 * @ Retorn: --------
 * 
***********************************************/
void GRAFICA_creaQuadricula (Tauler board, LlistaB b);

/***********************************************
 * 
 * @ Finalitat: Mostrar per pantalla tota la informacio necessaria per a poder tenir una bona experiencia 
				de joc tenint en compte totes les accions del usuari
 * @ Parametres: 	in: board = tipus one es guarda la informacio del tauler i de cada casella
					in: rank = tipus on es guarda tota la informacio del ranking de cada usuari al acabar la partida
 * @ Retorn: --------
 * 
***********************************************/
void GRAFICA_mostraPantalla(Tauler board, Ranking rank);

/***********************************************
 * 
 * @ Finalitat: Mostrar per pantalla el resultat (guanyat o perdut). 
 * @ Parametres: 	in: board = tipus one es guarda la informacio del tauler i de cada casella
					in: victoria = definaix si s'ha guanyat o no
					in: mina = defineix si s'ha perdut o no
 * @ Retorn: --------
 * 
***********************************************/
void GRAFICA_mostraResultat (Tauler board, int victoria, int mina);

#endif