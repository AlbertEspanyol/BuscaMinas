#include "grafica.h"
/****************************************
 * 
 * @ Proposit: 	Mostrar per pantalla tota la informacio que l'usuari necessita per a poder 
 * 				jugar al joc, canviant el aspecte fisic depenent de les accions de l'usuari.
 * @ Autors: Carlos Fernandez Lajara, Albert Espanyol Castillo
 * @ Data Creacio: 09/04/2018
 * @ Data ultima modificacio: 14/05/2018
 * 
****************************************/

void GRAFICA_mostraResultat(Tauler board, int victoria, int mina) {
	int x, y; 	//Variables on es guarden els resultats de les operacions.
	//Es troba les coordenades correspoents al mig del tauler independentment de la seva mida.
	x = (board.n_col - 2) / 2; //Es resta la quantitat de quadres que ocupara el recuadre amb el missatge.
	y = (board.n_fil - 1) / 2;
	//Depenent de si ha guanyat o ha perdut canvia el missatge
	if (victoria) {
		//Les coordenades multipliquen per la mida d'una casella sumades a una constant per a quadra-ho a la perfeccio
		al_draw_filled_rectangle(3 + 83 * x, 83 + 83 * y, 249 + 83 * x, 163 + 83 * y,LS_allegro_get_color(GREEN));
		al_draw_textf(LS_allegro_get_font(LARGE),LS_allegro_get_color(BLACK),53 + 83 * x, 103 + 83 * y,0,"%s","VICTORIA");
	} else {
		if (mina) {
			al_draw_filled_rectangle(3 + 83 * x, 83 + 83 * y, 249 + 83 * x, 163 + 83 * y,LS_allegro_get_color(RED));
			al_draw_textf(LS_allegro_get_font(EXTRA_LARGE),LS_allegro_get_color(BLACK),43 + 83 * x, 103 + 83 * y,0,"%s","GAME OVER");
		}
	}
}

void GRAFICA_dibuixaMina (int x, int y) {
	//Es creen totes les formes a la posicio indicada per a formar el aspecte de la mina
	//Depen de les coordenades de la casella
	al_draw_filled_circle(43 + x*83,122 + y*83,27,LS_allegro_get_color(BLACK));
	al_draw_filled_circle(43 + x*83,92 + y*83,5,LS_allegro_get_color(BLACK));
	al_draw_filled_circle(43 + x*83,153 + y*83,5,LS_allegro_get_color(BLACK));
	al_draw_filled_circle(12 + x*83,123 + y*83,5,LS_allegro_get_color(BLACK));
	al_draw_filled_circle(74 + x*83,123 + y*83,5,LS_allegro_get_color(BLACK));
	al_draw_filled_circle(21 + x*83,101 + y*83,5,LS_allegro_get_color(BLACK));
	al_draw_filled_circle(64 + x*83,143 + y*83,5,LS_allegro_get_color(BLACK));
	al_draw_filled_circle(21 + x*83,143 + y*83,5,LS_allegro_get_color(BLACK));
	al_draw_filled_circle(64 + x*83,101 + y*83,5,LS_allegro_get_color(BLACK));
	al_draw_filled_circle(32 + x*83,110 + y*83,7,LS_allegro_get_color(WHITE));
}

void GRAFICA_creaQuadricula (Tauler board, LlistaB b) {
	int x = 0, y = 0; //x recor les columnes, y recor les files.
	//Bucle que recor totes les caselles i les mostra en la seva posicio amb diferents aspectes depenent de les accions de l'usuari i s'acaba quan s'han crecorregut totes les caselles
	do {
		//Segon bucle que augmenta el nombre de columnes i que s'acaba quan s'arribi al limit del tauler
		while ( x < board.n_col) {
			//Si la casella no s'ha girat ni s'ha colocat una bandera, es mostra la casella grisa tancada.
			if (!board.caselles[y][x].girada) {
				//Si s'ha declarat una bandera es dibuixa aqe¡uesta assobre de la casella
				if (LLISTAB_troba(b, x, y)) {
					al_draw_filled_rectangle(3 + x*83,83 + y*83,83 + x*83,163 + y*83,LS_allegro_get_color(GRAY));
					al_draw_filled_triangle(23 + x*83,102 + y*83,23 + x*83,142 + y*83,63 + x*83,122 + y*83,LS_allegro_get_color(RED));
					al_draw_filled_rectangle(18 + x*83,98 + y*83,22 + x*83,158 + y*83,LS_allegro_get_color(BLACK));
				} else {
					al_draw_filled_rectangle(3 + x*83,83 + y*83,83 + x*83,163 + y*83,LS_allegro_get_color(GRAY));
				}
			//Si s'ha girat es canvia el color de la casella a gris clar i es mostra el nombre de mines que te al voltant o si es una mina.
			} else {
				al_draw_filled_rectangle(3 + x*83,83 + y*83,83 + x*83,163 + y*83,LS_allegro_get_color(LIGHT_GRAY));
				//Cada nimbre te un codi de color diferent
				switch (board.caselles[y][x].contingut) {
					case '0':
						al_draw_textf(LS_allegro_get_font(EXTRA_LARGE), LS_allegro_get_color(LIGHT_BLUE),33 + x*83,103 + y*83, 0, "%c", board.caselles[y][x].contingut);
						break;
					case '1':
						al_draw_textf(LS_allegro_get_font(EXTRA_LARGE), LS_allegro_get_color(BLUE),33 + x*83,103 + y*83, 0, "%c", board.caselles[y][x].contingut);
						break;
					case '2':
						al_draw_textf(LS_allegro_get_font(EXTRA_LARGE), LS_allegro_get_color(LIGHT_GREEN),33 + x*83,103 + y*83, 0, "%c", board.caselles[y][x].contingut);
						break;
					case '3':
						al_draw_textf(LS_allegro_get_font(EXTRA_LARGE), LS_allegro_get_color(GREEN),33 + x*83,103 + y*83, 0, "%c", board.caselles[y][x].contingut);
						break;
					case '4':
						al_draw_textf(LS_allegro_get_font(EXTRA_LARGE), LS_allegro_get_color(YELLOW),33 + x*83,103 + y*83, 0, "%c", board.caselles[y][x].contingut);
						break;
					case '5':
						al_draw_textf(LS_allegro_get_font(EXTRA_LARGE), LS_allegro_get_color(ORANGE),33 + x*83,103 + y*83, 0, "%c", board.caselles[y][x].contingut);
						break;
					case '6':
						al_draw_textf(LS_allegro_get_font(EXTRA_LARGE), LS_allegro_get_color(RED),33 + x*83,103 + y*83, 0, "%c", board.caselles[y][x].contingut);
						break;
					case '7':
						al_draw_textf(LS_allegro_get_font(EXTRA_LARGE), LS_allegro_get_color(GARNET),33 + x*83,103 + y*83, 0, "%c", board.caselles[y][x].contingut);
						break;
					case '8':
						al_draw_textf(LS_allegro_get_font(EXTRA_LARGE), LS_allegro_get_color(BLACK),33 + x*83,103 + y*83, 0, "%c", board.caselles[y][x].contingut);
						break;
					case 'M':
						GRAFICA_dibuixaMina (x,y);
						break;
				}
			}
			//S'augmenta la posicio de les columnes
			x++;
		}
		//Es reinicialitza la posicio de les columnes i s'augmenta la de les files
		x = 0;
		y++;
	} while (x != board.n_col && y != board.n_fil);
}

void GRAFICA_mostraPantalla(Tauler board, Ranking rank) {
	int nSortir = 0, mina = 0, victoria = 0;	//Guarden la informacio de final de partida, si es vol sortir i si s'ha guanyat o perdut.
	int x = 0, y = 0;	//Marquen la posicio del punter
	int contador_c = 0;	//Contador que guarda el nombre de caselles girades
	int segs = 0;		//Guarda el temps en segons
	float t0;			//Guarda el temps quan s'inicialitza el programa
	LlistaB banderes;	//Es declara tot el tipus bandera
	
	//Es crea la llista de banderes
	banderes = LLISTAB_crea();
	//Es guarda el temps incial
	t0 = (float) clock();
	
	LS_allegro_init(83 * board.n_col + 3, board.n_fil * 83 + 83,"PGM1 - PRS 2");
	//Bucle infinit del joc que s'acaba quan es vulgui sortir o ja s'hagi perdut o guanyat
	//Aquest bucle fa que sempre s'estigui pendent de les accions de l'usuari
	while(!nSortir && !mina && !victoria){
		//Es comenca a calcular el temps
		LOGICA_Temps(&t0, &segs);
		//S'imprimeix per pantalla el nom de l'usuari i el temps
		al_draw_textf(LS_allegro_get_font(LARGE),LS_allegro_get_color(WHITE),10,10,0,"%s","NOM:");
		al_draw_textf(LS_allegro_get_font(LARGE),LS_allegro_get_color(WHITE),200,10,0,"%s","TEMPS:");
		al_draw_textf(LS_allegro_get_font(EXTRA_LARGE),LS_allegro_get_color(WHITE),40,40,0,"%s", rank.user.nom_jug);
		al_draw_textf(LS_allegro_get_font(EXTRA_LARGE),LS_allegro_get_color(WHITE),300,10,0,"%d", segs);
		//Pintem la pantalla de la finestra gràfica
		LS_allegro_clear_and_paint(BLACK);
		//Creem la quadricula
		GRAFICA_creaQuadricula (board, banderes);
		//Es mou el cursor si el usuari aixi ho ordena
		LOGICA_mouCursor (board, &x, &y);
		//S'implementa una bandera si l'usuari prem 'B' i si la casella encara no esta girada 
		if (LS_allegro_key_pressed(ALLEGRO_KEY_B) && !board.caselles[y][x].girada) {
			LOGICA_bandera (board, &banderes, x, y);
		}
		//Si l'usuari prem l'espai, la casella no esta ja girada o ja hi ha una bandera, es gira la casella
		if(LS_allegro_key_pressed(ALLEGRO_KEY_SPACE) && !board.caselles[y][x].girada && !LLISTAB_troba(banderes, x, y)) {
			//Si resulta ser una mina es gira tot el tauler i s'activa el boolea de derrota
			if (board.caselles[y][x].contingut == 'M') {
				LOGICA_giraTotal(&board);
				mina = 1;
			//Sino es gira la casella en la posicio del cursor i s'incrementa el comptador.
			} else {
				board.caselles[y][x].girada = 1;
				contador_c++;
			}
		}
		//Si el nombre de caselles totals del tauler menys les caselles girades es igual el nombre de mines, s'ha guanyat la partida
		if (((board.n_fil * board.n_col) - contador_c) == board.n_min) {
			victoria = 1;
		}
		//Si es prem ESC s'activa el boolea de sortida
		if(LS_allegro_key_pressed(ALLEGRO_KEY_ESCAPE)){
			nSortir = 1;
		}
	}
	//Una vegada sortit del bucle del joc s'activa el procediment de sortida
	LOGICA_sortida(board, rank, banderes, nSortir, victoria, mina, segs);
}