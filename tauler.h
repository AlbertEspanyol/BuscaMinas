#ifndef _TAULER_H_
#define _TAULER_H_

#include <stdio.h>
#include <stdlib.h>
#include "ranquing.h"

//Tipus Casella que conte el contigut de cada casella 
//i un boolea comprovant si esta girada o no
typedef struct {
	char contingut;
	int girada;
} Casella;

//Tipus Tauler on s'hi troba el nombre de files, columnes i 
//mines del tauler, juntament amb l'array dinamic de caselles
typedef struct{
	int n_col;
	int n_fil;
	int n_min;
	Casella **caselles;
} Tauler;

/***********************************************
 * 
 * @ Finalitat: Llegir el nombre de files, columnes o mines del fitxer de text.
 * @ Parametres: 	in/out: f = el fitxer on s'hi troba tota la informacio a extreure 
 * @ Retorn: el nombre que es vol extreure
 * 
***********************************************/
int TAULER_extreuNombre (FILE *f);

/***********************************************
 * 
 * @ Finalitat: Extreure la infromacio del fitxer corresponent a cada casella i guardar-la en l'array dinamic.
 * @ Parametres: 	in/out: f = fixter on es troba tota la informacio a extreure
					in/out: *board = es guarda la infromacio de cada casella
 * @ Retorn: --------
 * 
***********************************************/
void TAULER_extreuCaselles (FILE *f, Tauler *board);

/***********************************************
 * 
 * @ Finalitat: Es el pas inicial per a comencar el joc. Inicialitza el tipus tauler i l'omple amb la informacio necessaria per a 
				poder comencar el joc. A partir d'aquesta funcio s'empeça el proces grafic i de ranking.
 * @ Parametres: 	in/out *t = fitxer on es troba la informacio del tauler
					in: rank = tipus on es troba tota la informacio relacionada amb el ranking dels usuaris
 * @ Retorn: --------
 * 
***********************************************/
void TAULER_inicialitzaTauler (FILE *t, Ranking rank);

/***********************************************
 * 
 * @ Finalitat: Alliberar el array dinamic que conte la informacio de cada casella al acabar la partida
 * @ Parametres: 	in/out: *board = s'esborra l'array dinamic 
 * @ Retorn: --------
 * 
***********************************************/
void TAULER_destrueix(Tauler *board);
#endif