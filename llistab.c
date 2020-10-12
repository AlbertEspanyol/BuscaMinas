#include "llistab.h"
#include <stdlib.h>

/****************************************
 * 
 * @ Proposit: S'encarrega crear i gestionar una LlistaPDI on es guarden totes les posicions de les banderes
				que l'usuari col·loca en el tauler. Aquest fitxer comnpta amb totes les operacions necessaries per a que el sistema de banderes pugui funcionar.
 * @ Autors: Carlos Fernandez Lajara, Albert Espanyol Castillo
 * @ Data Creacio: 7/05/2018
 * @ Data ultima modificacio: 12/05/2018
 * 
****************************************/
LlistaB LLISTAB_crea() {
	LlistaB b;	//Es declara la llista a retornar
	
	//Es crea el fantasma de la llista i es comprova que hi hagi prouta memoria per fer-ho
	b.cap = (Bandera *)malloc(sizeof(Bandera));
	if (b.cap == NULL)
	{
		printf("Error! No hi ha memoria.\n");
	} else {
		//Si n'hi ha, es declara el punter seguent com a null i el pdi es coloca al inici
		b.cap -> seg = NULL;
		b.ant = b.cap;
	}
	return b;
}

void LLISTAB_insereix(LlistaB *b, int x, int y) {
	Bandera *aux;	//Es declara un node bandera auxiliar que sera el que s'insereixi
	
	//Es crea el node i es comprova que hi hagi memoria per fer-ho
	aux = (Bandera *)malloc(sizeof(Bandera));
	if (aux == NULL) {
		printf ("Error! No hi ha memoria.\n");
	} else {
		//Si hi ha menoria s'omple el node amb la informacio introduida
		aux -> x = x;
		aux -> y = y;
		//S'enllaça l'auxuliar amb el pdi
		aux -> seg = b -> ant -> seg;
		//S'enllaça el pdi amb l'auxiliar
		b -> ant -> seg = aux;
	}
}

void LLISTAB_consulta(LlistaB b, int *x, int *y){
	//Es comprova quer el pdi esta seleccionant algun element i s'extreu la informacio del pdi
	if (b.ant -> seg != NULL) {
		(*x) = b.ant -> seg -> x;
		(*y) = b.ant -> seg -> y;
	}
}

void LLISTAB_esborra(LlistaB *b) {
	Bandera *aux;	//Node auxiliar que ajuda a desenllaçar els nodes
	
	//Es comprova que el pdi seleccioni algun element
	if (b -> ant -> seg == NULL){
		printf ("Error! No hi ha cap element seleccionat.\n");
	} else {
		//Es declara aux com el pdi
		aux = b -> ant -> seg;
		//Es desenllaça de la resta de la llista
		b -> ant ->seg = aux -> seg;
		//S'allibera l'element seleccionat
		free(aux);
	}
}

void LLISTAB_avanca (LlistaB *b) {
	//Es comprova que no s'estigui al final de la llista 
	if (b -> ant -> seg == NULL) {
		printf ("Error! No es pot seguir endavant\n");
	} else {
		//S'avança
		b -> ant = b -> ant -> seg;
	}
}

void LLISTAB_vesInici (LlistaB *b) {
	//Es declara el pdi com al primer element de la llista
	b -> ant = b -> cap;
}

int LLISTAB_fi (LlistaB b) {
	//Retorna la comprovacio si no hi ha cap mes element despres del pdi
	return b.ant -> seg == NULL;
}

int LLISTAB_buida (LlistaB b) {
	//Retorna la comprovacio si no hi ha cap element despres del fantasma
	return b.cap -> seg == NULL;
}

void LLISTAB_destrueix (LlistaB *b) {
	Bandera *aux;	//Es declara un node auxiliar per a poder alliberar els diferents nodes 
	
	//Mentres no s'arribi al final de la llista es van esborrant els nodes
	while (b -> cap != NULL) {
		//Es declara aux com el fantasma
		aux = b -> cap;
		//Es mou cap cap al seguent element
		b -> cap = b -> cap -> seg;
		//S'allibera el primer element
		free(aux);
	}
	//cap es declarara a NULL sol dins del bucle per ant s'ha de fer manualment.
	b -> ant = NULL;
}

int LLISTAB_troba (LlistaB b, int x1, int y1) {
	int trobada = 0;	//Bolea que defineix si s'ha trobat l'element dins de la llista
	int x2 = 0, y2 = 0;	//On es guarden els elements de cada node a comprovar
	
	//Es comença enviant el pdi al principi
	LLISTAB_vesInici (&b);
	//Es consulten els elements un a un fins que s'arribi al final o es trobi una coincidencia
	while (!LLISTAB_fi(b) && !trobada) {
		LLISTAB_consulta (b, &x2, &y2);
		if (x1 == x2 && y1 == y2) {
			trobada = 1;
		} else {
			LLISTAB_avanca(&b);
		}
	}
	return trobada;
}