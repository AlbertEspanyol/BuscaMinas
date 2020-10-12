#include "tauler.h"
#include "grafica.h"
#include <stdlib.h>

/****************************************
 * 
 * @ Proposit: S'encarrega de crear i modificar la informacio relacionada amb el tauler per a despres poder-ho representar graficament
 * @ Autors: Carlos Fernandez Lajara, Albert Espanyol Castillo
 * @ Data Creacio: 09/04/2018
 * @ Data ultima modificacio: 14/05/2018
 * 
****************************************/
void TAULER_extreuCaselles(FILE *f, Tauler *board){
	char aux[31];	//Cadena auxiliar on es guarda temporalent la informacio del fitxer de text
	int i, j;		//Defineixen les posicions de cada caracter en el fitxer que es determinat com el tipus d'una casella
	
	//Es fa la prelectura de la primera cadena de caselles en el fitxer
	fscanf(f, "%s", aux);
	//Es creen dos bucles, un per files i l'altre per columnes, que van omplenant les caselles del tipus board amb la informacio del fitxer
	for (i = 0; i < board -> n_fil; i++)
	{
		for (j = 0; j < board -> n_col; j++)
		{
			//La posicio j en la cadena correspondra amb la posicio de la casella en el taules
			board -> caselles[i][j].contingut = aux[j];
			//Es declaren inicialment totes com a no girades.
			board -> caselles[i][j].girada = 0;
		}
		//Es segueix fent lectures
		fscanf(f, "%s", aux);
	}
}

int TAULER_extreuNombre (FILE *f) {
	char aux[10]; 		//On es guarda la cadena que conté el nombre
	int num = 0, i = 0;	//El nombre final i l'index de la cadena
	
	//Es llegeix la cadena del fitxer amb el nombre i es fa un AtoI.
	fgets(aux, 10, f);
	for (i = 2; aux[i] != '\n'; i++) {
			num = num * 10 + (aux[i] - '0');
	}
	return num;
}

void TAULER_inicialitzaTauler(FILE *t, Ranking rank) {
	int i;			//Index de files
	Tauler board;	//Es declara el tauler
	
	//S'omplen el nombre de files, columnes i mines a partir de la informacio del fitxer
	board.n_col = TAULER_extreuNombre (t);
	board.n_fil = TAULER_extreuNombre (t);
	board.n_min = TAULER_extreuNombre (t);
	
	//Es crea un array dinamic de caselles on hi han n_col columnes per cada fila.
	board.caselles = (Casella **)malloc(sizeof(Casella*) * board.n_fil);
	for(i = 0; i < board.n_fil; i++) 
	{
		board.caselles[i] = (Casella *)malloc(sizeof(Casella) * board.n_col);
	}
	
	//S'extreu tota la informacio de cada casella del fitxer i es guarda al array
	TAULER_extreuCaselles(t, &board);
	//Es comenca el joc creant tots els aspeces grafics a partir de la informacio que hi ha al tauler
	GRAFICA_mostraPantalla(board, rank);
	//Una vegada acabat el joc s'allibera el tauler de la memoria
	TAULER_destrueix(&board);
}

void TAULER_destrueix(Tauler *board) {
	int i;	//Index de files
	//S'allibera l'array fila a fila
	for (i = 0; i < board -> n_fil; i++){
		free(board -> caselles[i]);
	}
}