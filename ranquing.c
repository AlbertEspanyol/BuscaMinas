#include "ranquing.h"

/****************************************
 * 
 * @ Proposit: S'encarrega de processar la informacio de l'usuari(nom, punts, tipus de tauler) per a despres poder mostrar-los per pantalla.
 * @ Autors: Carlos Fernandez Lajara, Albert Espanyol Castillo
 * @ Data Creacio: 09/04/2018
 * @ Data ultima modificacio: 12/05/2018
 * 
****************************************/
void RANQUING_afegeixUsuari (Ranking *rank, int segs, int mines){
	//S'obre el fitxer on guardar la informacio del ranking del ususari
	rank -> r = fopen ("ranquing.txt", "a");
	
	//Depenent del nivell del tauler s'obtindra una puntuacio diferent
	switch (mines) {
		case 10: 
			rank -> user.punts = segs;
			break;
		case 40:
			rank -> user.punts = segs * 2;
			break;
		case 99:
			rank -> user.punts = segs * 3;
			break;
	}
	//S'escriu la informacio de l'usuari en el fitxer de text
	fprintf(rank -> r,"%s#%s#%d\n", rank -> user.nom_jug, rank -> user.nom_fitxer, rank -> user.punts);
	//Es mostra per pantalla al acabar la partida el nom de l'usuari i la seva puntucacio
	printf ("El jugador: %s\nPuntuacio: %d\n", rank -> user.nom_jug, rank -> user.punts);
	//Es tanca el fitxer
	fclose(rank -> r);
}
int RANQUING_compteUsuaris(FILE *r) {
	int usuaris = 0;	//On es guarda el nombre d'usuaris introduits al sistema
	char extra[150];	//On es gurda la cadena amb la informacio de cada usuari
	
	//S'obra el fitxer en mode de lectura i es comprova que existeixi
	r = fopen("ranquing.txt", "r");
	if (r == NULL){
		printf("Error! No hi ha memoria\n");
	} else {
		//Es fa la prelectura del primer usuari i es comença un bulce que va avançant per fitxer
		//incrementant el nombre d'usuaris per cada cedna llegida fins arribar al final de fitxer.
		fgets(extra, 150, r);
		while (!feof(r)) {
			usuaris++;
			fgets(extra, 150, r);
		}
		//Es tanca el fitxer i es retorna le nombre d'usuaris
		fclose(r);
	}
	return usuaris;
}

void RANQUING_llegeixUsuaris(Usuari *aux, int usuaris, FILE *r) {
	int j = 0, index_u = 0;	//j = index de la cadena extreta del fitxer, index_u = index de l'array d'usuaris
	int suma = 0;			//On es guarda la suma al fer l'AtoI dels punts de la cadena
	char extra[150];		//On es guarda la cadena extreta del fitxer
	
	//Es comprova que hi hagin usuaris al sistema
	if (usuaris > 0) {
		//Si n'hi han, sobre el fitxer i es comprova que existeixi
		r = fopen ("ranquing.txt", "r");
		if (r == NULL){
			printf("Error! No hi ha memoria\n");
		} else {
			//Es fa una prelectura de la primer cadena del fitxer
			fscanf(r, "%s", extra);
			extra[strlen(extra)] = '\0';
			//S'inicia el bucle que extreura la informacio de cada cadena correctament fins arribar a l'ultima del fitxer
			while (!feof(r) && index_u < usuaris) {
				//S'extreu el nom del usuari
				RANQUING_copiaCadena(aux[index_u].nom_jug, extra, &j, 0);
				//S'extreu el nom del fitxer introduit per l'usuari
				RANQUING_copiaCadena(aux[index_u].nom_fitxer, extra, &j, 1);
				//Es fa un AtoI dels punts
				while (extra[j] != '\0') {
					suma = suma * 10;
					suma = suma + (extra[j] - '0');
					j++;
				}
				aux[index_u].punts = suma;
				//S'incrementa l'index d'usuaris indicant qu ela informacio seguent es d'un altre usuari
				index_u++;
				//Es fa la lectura de la informacio del seguent usuari
				fscanf(r, "%s", extra);
				extra[strlen(extra)] = '\0';
				j = 0;
				suma = 0;
			}
		}
		fclose(r);
	}
}

//La quantitat de caracter de les cadenes por variar i per tant les hem de declarar amb punters
void RANQUING_copiaCadena(char *cadena1, char *cadena2, int *posicio, int mode) {
	//Si mode val 1 voldra dir que volem extreure el nom del fitxer per tant s'anaça fins el cuixinet
	if(mode) {
		while (*cadena2 != '#') {
			cadena2++;
		}
		//Es salta el cuixinet
		cadena2++;
	}
	//Comença el bucle on es copia el contingut de la segona cadena a la primera caracter a caracter fins al cuixinet o fins que s'acabi la segona.
	while (*cadena2 != '#' && *cadena2 != '\0'){
		*cadena1 = *cadena2;
		//Es va augmentant posicio per poder tenir una referencia d'on es troba l'index de la segona cadena al sortir
		(*posicio)++;
		cadena1++;
		cadena2++;
	}
	*cadena1 = '\0';
	(*posicio)++;
}

void RANQUING_ordena(Usuari *aux, int usuaris) {
	Usuari temporal;	//Es declara un usuari on es guarda la informacio a intercanviar temporalment
	int i = 1;			//i = index que compta el nombre de canvis fets
	int j; 				//j = index d'usuaris que recor tota la cadena buscant algun qe sigui valid per intercanviar
	int canvi = 1;		//Boolea que marca si s'ha trobat un canvi
	
	//Bucle que tria el usuari a intercanviar i que s'acaba quan ha reccoregut tota la cadena o si no s'ha trobat ningun canvi
	while (i <= usuaris && canvi){
		canvi = 0;
		//Bucle que recor tota la cadena en busca d'algun usuari amb el que intercanviar 
		for(j = usuaris - 1; j >= i; j--) {
			//Si en comparar usuaris en troba un amb menys punts, fa l'intercanvi ficant el que en te mes a dalt.
			if(aux[j - 1].punts < aux[j].punts) {
				temporal = aux[j - 1];
				aux[j - 1] = aux[j];
				aux[j] = temporal;
				canvi = 1;
			}
		}
		i++;
	}
}

void RANQUING_mostraRanquing(Ranking rank) {
	int i = 0, usuaris = 0;	//i = index de la cadena, usuaris = nombre d'usuaris en el sistema.
	Usuari *aux;			//Array dinamic d'usuaris on es guarda l'informacio de cada un
	
	//Es troba el nombre d'usuaris que hi ha actualment en el sistema
	usuaris=RANQUING_compteUsuaris(rank.r);
	//A partir del nombre trobat es crea l'array
	aux = (Usuari *)malloc(sizeof(Usuari) * usuaris);
	//Es llegeix el fitxer i es guarda l'informacio de cada usuari al array
	RANQUING_llegeixUsuaris(aux, usuaris, rank.r);
	
	//Es mostra per pantalla el tauler 
	printf ("\n####################################\n# NOM - TAULELL - PUNTS #\n####################################\n");
	//Si no hi han usuaris es mostren linies indicant-ho
	if (!usuaris) {
		printf ("______ ______ ____\n\n");
	} else {
		//Si hi ha mes d'un usuari, s'ordena l'array
		if (usuaris > 1) {
			RANQUING_ordena(aux, usuaris);
		}
		//Es mostren els usuaris per pantalla de forma ordenada en funcio del punts
		do {
			printf("%s - %s - %d\n", aux[i].nom_jug, aux[i].nom_fitxer, aux[i].punts);
			i++;
		} while (i < usuaris);
		printf("\n");
	}
	//S'allibera l'array dinamic
	free(aux);
}
