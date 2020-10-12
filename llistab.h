#ifndef _LLISTAB_H_
#define _LLISTAB_H_
#include <stdio.h>

//Node bandera que conte com a element les coordenades en el tauler d'aquesta 
//i un punter del mateix tipus per a poder enllaçar la llista
typedef struct n {
	int x, y;
	struct n *seg;
} Bandera;

//Tipus llista que conte un punter cap apuntant al fantasma, es a dir al principi 
//de la llista i un punter ant que representa la pdi.
typedef struct {
	Bandera *cap;
	Bandera *ant;
} LlistaB;

/***********************************************
 * 
 * @ Finalitat: Crear i preparar la llista per a que pugui ser modificada
 * @ Parametres: --------
 * @ Retorn: --------
 * 
***********************************************/
LlistaB LLISTAB_crea();

/***********************************************
 * 
 * @ Finalitat: Inserir un nou element dins de la llista a l'esquerra del pdi
 * @ Parametres: 	in/out: *b = la llista a modificar
					in: x = la coordenada en columnes de l'element a inserir
					in: y = la coordenada en files de l'element a inserir
 * @ Retorn: --------
 * 
***********************************************/
void LLISTAB_insereix (LlistaB *b, int x, int y);

/***********************************************
 * 
 * @ Finalitat: Extreure el contingut del element seleccionat pel pdi
 * @ Parametres: 	in: b = llista on es troba l'element a consultar
					in/out: *x = on es guarda la coordenada en columnes de l'element que es vol consultar
					in/out: *y = on es guarda la coordenada en files de l'element que es vol consultar
 * @ Retorn: --------
 * 
***********************************************/
void LLISTAB_consulta (LlistaB b, int *x, int *y);

/***********************************************
 * 
 * @ Finalitat: Eliminar de la llista l'element seleccionat per el pdi
 * @ Parametres: 	in/out: *b = la llista a modificar
 * @ Retorn: --------
 * 
***********************************************/
void LLISTAB_esborra (LlistaB *b);

/***********************************************
 * 
 * @ Finalitat: Avancar el pdi un element cap al final de la llista 
 * @ Parametres: 	in/out: *b = la llista a modificar
 * @ Retorn: --------
 * 
***********************************************/
void LLISTAB_avanca (LlistaB *b);

/***********************************************
 * 
 * @ Finalitat: Enviar el pdi al primer element de la llista
 * @ Parametres: 	in/out: *b = la llista a modificar
 * @ Retorn: --------
 * 
***********************************************/
void LLISTAB_vesInici (LlistaB *b);

/***********************************************
 * 
 * @ Finalitat: Comprovar si el pdi esta situat al final de la llista
 * @ Parametres: 	in: b = la llista d'on s'ha de comprovar
 * @ Retorn: un boolea que determina si esta al final o no
 * 
***********************************************/
int LLISTAB_fi (LlistaB b);

/***********************************************
 * 
 * @ Finalitat: Comprovar si no hi ha cap element dins de la llista
 * @ Parametres: 	in: b = la llista d'on s'ha de comprovar
 * @ Retorn: un boolea que determina si esta buida o no
 * 
***********************************************/
int LLISTAB_buida (LlistaB b);

/***********************************************
 * 
 * @ Finalitat: Esborrar completament tot el contingut de la llista incloent el fantasma
 * @ Parametres: 	in/out: *b = la llista a destruir
 * @ Retorn: --------
 * 
***********************************************/
void LLISTAB_destrueix (LlistaB *b);

/***********************************************
 * 
 * @ Finalitat: Buscar un element determinat dins la llista
 * @ Parametres: 	in: b = la llista on s'ha de buscar
					in: x = coordenada en columnes de l'lement a buscar
					in: y = coordenada en files de l'element a buscar
 * @ Retorn: un boolea que determina si ja existeix l'elemnt dins la llista o no
 * 
***********************************************/
int LLISTAB_troba (LlistaB b, int x, int y);

#endif