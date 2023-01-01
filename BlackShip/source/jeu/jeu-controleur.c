//Préprocessus principaux
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>


//Préprocessus annexe
#include "jeu.h"




void initialisationTableau(struct jeu *jeu) {
  //memset(&(jeu->tableau[0]), 0, sizeof(int) * parametre.dimension * parametre.dimension);
  //printf("%x %x", &(jeu->tableau), &(jeu->tableau[0]));

  //printf("%d %d", sizeof(jeu->tableau), sizeof(int) * parametre.dimension * parametre.dimension);

  memset(&(jeu->tableau), 0, sizeof(jeu->tableau));
  //memset(jeu->tableau, 0, sizeof(*(jeu->tableau)) * parametre.dimension * parametre.dimension);
  //memset(jeu->tableau, 0, sizeof(jeu->tableau));

  /*for (int i = 0; i < 5 ; i++) {
    for (int j = 0; j < 5 ; j++) {
      jeu->tableau[i][j] = 0;
    }
  }*/

  //for (int i = 0; i < 9*9; i++) { ((int*)&jeu->tableau[0])[i] = i; }
  
}

int initialisationBateau(struct parametre parametre, struct jeu *jeu) {
 
  int axeX, axeY;
  int pourcentage = (parametre.dimension * parametre.dimension) * 0.17;
  int bateauCpt = 0;

  //memset(jeu.tableau, 0, sizeof(int) * parametre.dimension * parametre.dimension);

  srand(time(NULL));

  for (int i = 1; i <= pourcentage; i++) {
    do {
      axeX = rand() % parametre.dimension;
      axeY = rand() % parametre.dimension;
    } while (jeu->tableau[axeX][axeY] == 3);

    jeu->tableau[axeX][axeY] =  3;

    bateauCpt++;
  }

  return bateauCpt;
}



void calculateur(struct jeu *jeu) {

  // pointés : mancheCpt, gagné, toucheCpt, toucheMessage, essai
  // pas pointés : axe x, axe y, tableau, bateauCpt, manche

  int tableau[9][9];

  for (int i = 0; i < 9 ; i++) {
    for (int j = 0; j < 9 ; j++) {
      tableau[i][j] = jeu->tableau[i][j];
    }
  }
  
  int axeX = jeu->axeX;
  int axeY = jeu->axeY;
  int bateauCpt = jeu->bateauCpt;

  if (jeu->gagner != true) {
    if (tableau[axeX][axeY] == 0) {
      tableau[axeX][axeY] = 1;
      jeu->toucheMsg = 2;
      jeu->essaiCpt++;

    } else if (tableau[axeX][axeY] == 1) {
      jeu->toucheMsg = 3;

    } else if(tableau[axeX][axeY] == 2) {
      jeu->toucheMsg = 3;

    } else if (tableau[axeX][axeY] == 3) {
      tableau[axeX][axeY] = 2;
      jeu->toucheMsg = 1;
      jeu->toucheCpt++;
      jeu->essaiCpt++;
    }
    
    if (jeu->toucheCpt == bateauCpt) {
      jeu->gagner = true;

    }
  } else {
    jeu->gagner = false;
  }
}