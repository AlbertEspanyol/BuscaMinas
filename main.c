#include <stdlib.h>
#include "grafica.h"
#include "ranquing.h"
/****************************************
 * 
 * @ Proposit: S'encarrega de donar i demanar tota la informacio necessaria al ususari i,a partir d'aixo, cridar les funcions 
				dels diferents moduls per a que el joc i les diferents opcions que aporta el programa es realitzin satisfactoriament.
 * @ Autors: Carlos Fernandez Lajara, Albert Espanyol Castillo
 * @ Data Creacio: 
 * @ Data ultima modificacio: 12/05/2018
 * 
****************************************/
/*******************************************************************************
@Objective:

@Author: Arnau Sanz Froiz and Marta Casanovas Clos
@Creation date: 08/01/2019
@Last modification date 10/01/2019
********************************************************************************/

//Libraries

#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
#include <math.h>

//Constants

#define STRING_SIZE 252 //
#define NAME_SIZE 22    //
#define TRUE 1
#define FALSE 0

//Structs + User data types

typedef struct {
  char day[STRING_SIZE];
  char month[STRING_SIZE];
  char year[STRING_SIZE];
} FoundationDate;

typedef struct {
    char humanTower[STRING_SIZE];
} stringArray;

typedef struct {
  char team_name[STRING_SIZE];
  FoundationDate foundation_date;
  int num_members;
  int num_humanTowers_achieved;
  stringArray humanTowers_achieved[10];
} TeamData;

//Variables



// Procedures and Functions

int processString (char source[STRING_SIZE], int position, char threshold, char output[STRING_SIZE]) {
  int i = 0;

  while (source[position] != threshold && source[position] != '\0') {
      output[i] = source[position];
      i++;	
      position++;
  }

  output[i] = '\0';
  position++;
  return position;
} //processString end

int atoi (char input[STRING_SIZE]) {
  //printf("\n*\t*\tstart of  atoi()\t*\t*\n");                                   // DEBUG LINE

  int length = strlen(input);
  int i, flag = 0;
  int number = 0;

  if (!flag) {
    //printf("\n*\t*\tstart of  if !flag  in atoi()\t*\t*\n");                    // DEBUG LINE

    for (i = 0; i < length; i++) {
      number = number + ((input[length - (i + 1)] - '0') * pow(10, i));
      //printf("$ %d $ ", number);                                                // DEBUG LINE
    }
  }

  return number;
} //atoi end

int abs (int source) {
  int output;

  if (source < 0) {
    output = source * (-1);
  }

  return output;
}

int main () {

  char input[STRING_SIZE], menu_input[STRING_SIZE], teams_num_string[STRING_SIZE];
  char aux1[STRING_SIZE], aux2[STRING_SIZE];
  int exit, flag_input = 1, flag_menu = 1;
  int string_position = 0, teams_num_int = 0;
  int j, k;
  TeamData team[10];

  for (j = 0; j < strlen(input); j++) {
    input[j] = ' ';
  }

  printf("\nWelcome to LSHumanTowerMaker\n");

  do { //while flag_input

    printf("\nInput:\n");

    fgets(input, STRING_SIZE, stdin);
    input[strlen(input) - 1] = '\0';
    /*
    for (j = 0; j < strlen(input); j++) {
      printf("*%c*", input[j]);
      //if(0 == strcmp(input[j], "\n")) printf("INTROintroINTRO");
    }
    j=0;
    */
    exit = abs(strcmp("exit", input));
    exit = !exit;

    if (exit == FALSE) {
      printf("\nIN exit == FALSE");
      //CODIGO - extraer datos - MENU

      string_position = processString(input, string_position, '$', teams_num_string);
      printf("\nsPos %d sPos\n", string_position);

      teams_num_int = atoi(teams_num_string);
      printf("\n%d\n", teams_num_int);

      if (teams_num_int <= 0 || teams_num_int > 11) {
        printf("Error! You can only put 10 teams");
        flag_input = 1;
      }
      else {
        for(j = 0; j < teams_num_int; j++){
          string_position = processString(input, string_position, '-', team[j].team_name);
          printf("\nnom %s nom\n", team[j].team_name);
          printf("\nsPos %d sPos\n", string_position);
/*
          string_position = processString(input, string_position, '/', team[j].foundation_date.day);
          printf("\ndia %s dia\n", team[j].foundation_date.day);
          printf("\nsPos %d sPos\n", string_position);

          string_position = processString(input, string_position, '/', team[j].foundation_date.month);
          printf("\nmes %s mes\n", team[j].foundation_date.month);
          printf("\nsPos %d sPos\n", string_position);

          string_position = processString(input, string_position, '-', team[j].foundation_date.year);
          printf("\nany %s any\n", team[j].foundation_date.year);

          string_position = processString(input, string_position, '-', aux1);
          team[j].num_members = atoi(aux1);
          printf("\nmembers %s members\n", aux1);

          string_position = processString(input, string_position, '-', aux2);
          team[j].num_humanTowers_achieved = atoi(aux2);
          printf("\nnumAchieved %s numAchieved\n", aux2);

          for(k = 0; k < (team[j].num_humanTowers_achieved); k++){
              string_position = processString(input, string_position, ',', team[j].humanTowers_achieved[k].humanTower);
              printf("\nhumanT %s humanT\n", team[j].humanTowers_achieved[k].humanTower);
          }
*/        k=0;
          string_position = processString(input, string_position, '$', team[j].humanTowers_achieved[k].humanTower);
          printf("\nhumanT %s humanT\n", team[j].humanTowers_achieved[k].humanTower);
        }
      }


      //menu while
      do { //while flag_menu

        printf("\nWhat statistics do you want to show:\n");
        printf("\ta- Number of human towersde by each team\n");
        printf("\tb- Most common human tower\n");
        printf("\tc- Team with the most members\n");
        printf("\td- Newest team\n");
        printf("\te- Show all the teams\n");
        printf("\tf- Exit\n");

        //ask for menu input and show MENU
        fgets(menu_input, STRING_SIZE, stdin);
        menu_input[strlen(menu_input) - 1] = '\0';

        if (0 == strcmp("a", menu_input)) {
          flag_menu = 1;
          printf("\nestás en A");
        }
        else{
          if (0 == strcmp("b", menu_input)) {
            flag_menu = 1;
            printf("\nestás en B");
          }
          else{
            if (0 == strcmp("c", menu_input)) {
              flag_menu = 1;
              printf("\nestás en C");
            }
            else{
              if (0 == strcmp("d", menu_input)) {
                flag_menu = 1;
                printf("\nestás en D");
              }
              else{
                if (0 == strcmp("e", menu_input)) {
                  flag_menu = 1;
                  printf("\nestás en E");
                }
                else{
                  if (0 == strcmp("f", menu_input)) {
                    flag_menu = 0;
                    printf("\nestás en F");
                  }
                  else{
                    // if here input is not valid
                    printf("\nError! This option doesn't exist");
                    flag_menu = 1;
                  }
                }
              }
            }
          }
        }



        //when menu option is 'f' get out
      } while (flag_menu);

    }
    else {
      printf("Thank you for using our program!\n");
      flag_input = 0;
    }

  } while (flag_input);

  return 0;
}

/*
int main (void) {
	char opcio;			//On es guarda el caracter introduit per l'usuari al demanar triar l'opcio del menu.
	int dada_ok = 0;	//Boolea que determina si els fitxers existeixen i que per tant no s'hand e tornar a demanar.
	FILE *t;			//El fitxer d'on s'agafara tota la informacio del tauler.
	Ranking rank;		//On s'emmagatzemen totes les dades relacionades amb el ranking.
	
	//Bucle que fa que el programa segueixi fins que l'usuari no seleccioni l'opcio de sortir.
	do {
		//Bucle on es mostra el menu, es demana i es comprova l'opcio i no s'acaba fins que aquesta sigui correcta.
		do {
			//Es deama l'opcio i es comprova
			printf ("Menu:\n 1- Nova partida\n 2- Mostrar ranquing\n 3- Sortir\n Opcio: ");
			scanf ("%c", &opcio);
			fflush(stdin);
			//Depenent del caràcter que s'ha introduit es mostra un error corresponent
			if(opcio < '1' || opcio > '3') {
				if (opcio < '0' || opcio > '9') {
					printf ("\nOpcio incorrecta! (L'opcio ha de ser un nombre)\n\n");
				} else {
					printf ("\nOpcio incorrecta!\n\n");
				}
			}
		} while (opcio < '1' || opcio > '3');
		
		//Segons l'opcio que s'hagi escollit el programa actua diferent
		switch (opcio) {
			//La primera opcio consisteix en la realitzacio del joc
			case '1':
				//Bucle on es demana el nom del jugador, es comprova que no superi els 30 caracters i no s'acaba fins que s'introdueixi un de correcte
				do {
					printf ("\nIntrodueix nom del jugador: ");
					gets (rank.user.nom_jug);
					fflush (stdin);
					if (strlen(rank.user.nom_jug) > 30) {
						printf ("\nError, el nom no pot superar els 30 caracters!\n");
					} else {
						dada_ok = 1;
					}
				} while (!dada_ok);
				//Es reinicialitza el boolea
				dada_ok = 0;
				//Bucle on es demana el nom del fitxer que conte les dades del tauler, es comprova que existeixi i no s'acaba fins que s'introdueixi un de correcte
				do {
					printf ("Introdueix nom del fitxer: ");
					gets (rank.user.nom_fitxer);
					fflush (stdin);
					t=fopen (rank.user.nom_fitxer, "r");
					if (t == NULL) {
						printf ("\nError, no es troba el fitxer!\n\n");
					} else {
						//Si el nom es correcte i el fitxer tambe s'inicialitza el joc.
						printf ("\nInformacio correcte\n\nProcessant informacio...\nPartida iniciada correctament\n\n");
						TAULER_inicialitzaTauler (t, rank); 
						dada_ok = 1;
					}
					//Una vegada acabat es tanca el fitxer.
					fclose(t);
				} while (!dada_ok);
				break;
			//En la segona opcio es mostra el ranking dels jugadors a partir de la informacio obtinguda anteriorment
			case '2':
				RANQUING_mostraRanquing(rank);
				break;
		}
	} while (opcio != '3');
	return 0;
}*/