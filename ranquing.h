#ifndef _RANQUING_H_
#define _RANQUING_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Tipus usuari que guarda la informacio que l'usuari entre al principi del programa, el seu nom i el nom del fitxer
//juntament amb el nombre de punta que obte una vegada s'acabi la partida
typedef struct {
	char nom_jug[100], nom_fitxer[50];
	int punts;
} Usuari;

//Tipus ranking que guarda l'usuari juntament amb el fitxer on esta guardada la informacio de tots els usuaris
typedef struct {
	Usuari user;
	FILE *r;
} Ranking;

/***********************************************
 * 
 * @ Finalitat: Llegir le fitxer del ranking amb tots els usuaris i mostrar la seva informacio per pantalla de forma ordenada
 * @ Parametres: 	in: rank = el tipus on es troba tota la informacio necessaria per a fer el ranking
 * @ Retorn: --------
 * 
***********************************************/
void RANQUING_mostraRanquing (Ranking rank);

/***********************************************
 * 
 * @ Finalitat: Omple el tipus ranking amb tota la informacio que s'obte despres d'una partida
 * @ Parametres: 	in/out: rank = el tipus on es guarda la informacio obtinguda
					in: segs = els segons que ha trigat l'usuari a completar el joc per a fer el calcul de punts
					in: mines = defineix el tipus de nivell en que l'usuari ha decidit jugar i en funcio d'aixo varia el multiplicdor dels punts. 
 * @ Retorn: --------
 * 
***********************************************/
void RANQUING_afegeixUsuari (Ranking *rank, int segs, int mines);

/***********************************************
 * 
 * @ Finalitat: Omple l'array dinamic d'usuaris previament creat amb informacio dels ranquings de cada ususari trobada en un fitxer
 * @ Parametres: 	in/out: *aux = array dinamic de tipus Usuari on es guarda la informacio de cada usuari trobat en el sistema  
					in: usuaris = el nombre d'usuaris guardats en el sistema 
					in/out: *r = fitxer d'on s'ectreuen les dades 
 * @ Retorn: --------
 * 
***********************************************/
void RANQUING_llegeixUsuaris(Usuari *aux, int usuaris, FILE *r);

/***********************************************
 * 
 * @ Finalitat: Compta els usuaris actuals que estan guardats en el sistema
 * @ Parametres: in/out: *r = fitxer d'on s'ectreuen les dades 
 * @ Retorn: El nombre d'usuaris que han introduit un ranquing
 * 
***********************************************/
int RANQUING_compteUsuaris(FILE *r);

/***********************************************
 * 
 * @ Finalitat: Ordena de major a menor cada usuari en l'array dinamic en funcio de la seva puntuacio  
 * @ Parametres: 	in/out: *aux = array dinamic de tipus Usuari on s'ordenen els usuaris  
					in: usuaris = el nombre d'usuaris guardats en el sistema 
 * @ Retorn: --------
 * 
***********************************************/
void RANQUING_ordena(Usuari *aux, int usuaris);

/***********************************************
 * 
 * @ Finalitat: Copia una part d'una cadena a una altra caracter a caracter  
 * @ Parametres: 	in/out: *cadena1 = cadena on es copia  
					in/out: *cadena2 = cadena d'on es copia  
					in/out: *posicio = posicio del index de la cadena d'on es copia
					in: mode = indica de quina posicio ha de començar a copiar
 * @ Retorn: --------
 * 
***********************************************/
void RANQUING_copiaCadena(char *cadena1, char *cadena2, int *posicio, int mode);

#endif