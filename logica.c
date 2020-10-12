#include "logica.h"

/****************************************
 * 
 * @ Proposit: 	Peocessar totes les accions realitzades per l'usuari i crear canvis a pertir d'aquestes
 * @ Autors: Carlos Fernandez Lajara, Albert Espanyol Castillo
 * @ Data Creacio: 16/04/2018
 * @ Data ultima modificacio: 14/05/2018
 * 
****************************************/

void LOGICA_giraTotal (Tauler *board){
	int x, y; //Posicions que recorren les files i les columnes del tauler
	//Primer bucle que augmenta la posicio en columnes i que s'acaba quan arriba al final del tauler
	for (x = 0; x < (board -> n_col); x++) {
		//Segon bucle que augmenta la posicio en files i que s'acaba quan arriba al final del tauler
		for (y = 0; y < (board -> n_fil); y++) {
			//Es va girant tot el tauler casella a casella
			((board -> caselles[y][x]).girada) = 1;
		}
	}
}

void LOGICA_Temps (float *t0, int *segs) {
	float t1; //Guarda el temps actual en el programa
	//Es guarda el temps acutal
	t1 = (float) clock();
	
	//Calculem la diferència de temps i transformem a segons
	if ((t1 - (*t0)) / (float)CLOCKS_PER_SEC >= 0.5) {
		(*segs)++;
		(*t0) = (float) clock();
	}
}

void LOGICA_mouCursor (Tauler board, int *x, int *y) {
		//Depenent de la tecla que premi l'usuari(les quatre fletxes) s'augmentaran o disminuiran les posicions.
		if(LS_allegro_key_pressed(ALLEGRO_KEY_UP) && (*y) != 0){
			(*y)--;
		}
		
		if(LS_allegro_key_pressed(ALLEGRO_KEY_DOWN) && (*y) != board.n_fil - 1){
			(*y)++;
		}
	
		if(LS_allegro_key_pressed(ALLEGRO_KEY_RIGHT) && (*x) != board.n_col - 1){
			(*x)++;
		}
	
		if(LS_allegro_key_pressed(ALLEGRO_KEY_LEFT) && (*x) != 0){
			(*x)--;
		}
		//Es dibuixa el cursor en la posicio marcada
		al_draw_rectangle(3 + 83*(*x),83 + 83*(*y),83 + 83*(*x),163 + 83*(*y),LS_allegro_get_color(YELLOW),4);
}

void LOGICA_bandera(Tauler board, LlistaB *b, int x1, int y1) {
	int repetida = 0;		//Boolea que comprova que una bandera no estigui repetida 
	int x2 = -1, y2 = -1;	//Es guarda temporalment la posicio d'una bandera 
	
	//Es mou el PDI al principi
	LLISTAB_vesInici (b);
	//Bucle que comprova fins el final de la llista si existeix una bandera amb les mateixes coordenades que les passades.
	while (!LLISTAB_fi(*b) && !repetida) {
		//Consulta les coordenades d'un node
		LLISTAB_consulta(*b, &x2, &y2);
		//Es comprova si son iguals
		if (x1 == x2 && y1 == y2) {
			//Si ho son s'activa el boolea i s'esborra aquesta bandera
			repetida = 1;
			LLISTAB_esborra(b);
		}
		//Si no s'ha trobat s'avanca el pdi
		if (!repetida) {
			LLISTAB_avanca(b);
		}
	}
	//Si en tota la llista no s'ha trobat s'insereix una bandera a la llista amb les coordenades passades
	if (!repetida) {
		LLISTAB_insereix (b, x1, y1);
	}
}

void LOGICA_sortida(Tauler board, Ranking rank, LlistaB banderes, int nSortir, int victoria, int mina, int segs) {
	//Independentment de si ha guanyat o perdut, no s'acaba el joc fins que es premi ESC
	while(!nSortir) {	
		//Es divuixa tot el necessari en la pantalla de sortida
		al_draw_textf(LS_allegro_get_font(LARGE),LS_allegro_get_color(WHITE),10,10,0,"%s","NOM:");
		al_draw_textf(LS_allegro_get_font(LARGE),LS_allegro_get_color(WHITE),200,10,0,"%s","TEMPS:");
		al_draw_textf(LS_allegro_get_font(EXTRA_LARGE),LS_allegro_get_color(WHITE),40,40,0,"%s", rank.user.nom_jug);
		al_draw_textf(LS_allegro_get_font(EXTRA_LARGE),LS_allegro_get_color(WHITE),300,10,0,"%d", segs);
		
		LS_allegro_clear_and_paint(BLACK);
		GRAFICA_creaQuadricula (board, banderes);
		GRAFICA_mostraResultat (board, victoria, mina);
		
		//Si es prem ESC s'activa le boolea de sortida, es detrueix la llista de banderes i si ha guanyat s'afegeix al ranquing.
		if(LS_allegro_key_pressed(ALLEGRO_KEY_ESCAPE)) {
			nSortir = 1;
			LLISTAB_destrueix(&banderes);
			if (victoria) {
				RANQUING_afegeixUsuari (&rank, segs, board.n_min);
			} 
		}
	}
	//Si no s'ha guanyat ni perdut sino que s'ha forcat la sortida es mostra unm
	if (!mina && !victoria) {
		printf ("Partida finalitzada pel jugador\n\n");
	}
	//Tanquem la finestra gràfica
	LS_allegro_exit();
}