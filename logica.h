#ifndef _LOGICA_H_
#define _LOGICA_H_
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "tauler.h"
#include "LS_allegro.h"
#include "llistab.h"
#include "ranquing.h"
#include "grafica.h"

/***********************************************
 * 
 * @ Finalitat: Girar totes les caselles del tauler de cop independentment de les accions de l'ususari
 * @ Parametres: 	in/out: *board = tipus on es modifica la informacio del tauler i de cada casella passat per referencia 
 * @ Retorn: --------
 * 
***********************************************/
void LOGICA_giraTotal(Tauler *board);

/***********************************************
 * 
 * @ Finalitat: Crear un rellotge que vagi augmentant cada segon
 * @ Parametres: 	in/out: *t0 = temps inicial declarat fora del bucle del joc al inicialitzar la partida
					in/out: *segs = s'augmenta en 1 cada segon
 * @ Retorn: --------
 * 
***********************************************/
void LOGICA_Temps (float *t0, int *segs);

/***********************************************
 * 
 * @ Finalitat: Permetre al usuari controlar un cursor que selecciona les diferentes caselles del tauler
 * @ Parametres: 	in: board = tipus on es troba la informacio del tauler i de cada casella
					in/out: *x = posicio del cursor en columnes que es retorna modificada si l'usuari prem certa tecla
					in/out: *y = posicio del cursor en files que es retorna modificda si l'usuari prem la tecla corresponent
 * @ Retorn: --------
 * 
***********************************************/
void LOGICA_mouCursor (Tauler board, int *x, int *y);

/***********************************************
 * 
 * @ Finalitat: Permetre a l'usuari tenir l'habilitat de colocar i treure banderes en les caselles
 * @ Parametres: 	in: board = tipus on es troba la informacio del tauler i de cada casella 
					in/out: *l = llista on es s'insereix o es borra un node bandera
					in: x = posicio en columnes de la bandera a introduir o esborrar
					in: y = posicio en files de la bandera a introduir o esborrar
 * @ Retorn: --------
 * 
***********************************************/
void LOGICA_bandera (Tauler board, LlistaB *l, int x, int y);

/***********************************************
 * 
 * @ Finalitat: Crear un protocol de sortida del joc depenent del resultat
 * @ Parametres: 	in: board = tipus on es troba la informacio del tauler i de cada casella 
					in: banderes = llista on es s'insereix o es borra un node bandera
					in: rank = tipus on es troba tota la informacio sobre el ranking del usuari
					in: nSortir = determina si es vol sortir del joc
					in: victoria = determina la victoria
					in: mina = determina la derrota
					in: segs = el temps actual
 * @ Retorn: --------
 * 
***********************************************/
void LOGICA_sortida(Tauler board, Ranking rank, LlistaB banderes, int nSortir, int victoria, int mina, int segs);


#endif 