//Préprocessus principaux
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>


//Préprocessus annexe
#include "jeu.h"




void initialisationTableau(struct parametre parametre, struct jeu jeu) {

  memset(jeu.tableau, 0, sizeof(int) * parametre.dimension * parametre.dimension);
}

int initialisationBateau(struct parametre parametre, struct jeu jeu) {
 
  int axeX, axeY;
  int pourcentage = (parametre.dimension * parametre.dimension) * 0.17;
  jeu.bateauCpt = 0;

  //memset(jeu.tableau, 0, sizeof(int) * parametre.dimension * parametre.dimension);

  srand(time(NULL));

  for (int i = 1; i <= pourcentage; i++) {
    do {
      axeX = rand() % parametre.dimension;
      axeY = rand() % parametre.dimension;
    } while (jeu.tableau[axeX][axeY] ==  3);

    jeu.tableau[axeX][axeY] =  3;

    jeu.bateauCpt++;
  }

  return jeu.bateauCpt;
}



void calculateur (struct parametre *parametre, struct jeu *jeu) {

  // pointés : mancheCpt, gagné, toucheCpt, toucheMessage, essai
  // pas pointés : axe x, axe y, tableau, bateauCpt, manche

  int manche = parametre->manche;

  int tableau[9][9] = jeu->tableau;
  int axeX = jeu->axeX;
  int axeY = jeu->axeY;
  int bateauCpt = jeu->bateauCpt;

  if (jeu->gagner != true) {
    if (tableau[axeX][axeY] == 0) {
      if (tableau[axeX][axeY] == 3) {
          tableau[axeX][axeY] = 1;

          jeu->toucheMsg = 2;
      } else {
          tableau[axeX][axeY] = 2;

          jeu->toucheMsg = 1;
          jeu->toucheCpt++;
      }
      jeu->gagner++;

    } else if (tableau[axeX][axeY] == 1) {
      jeu->toucheMsg = 3;

    } else if(tableau[axeX][axeY] == 2) {
      jeu->toucheMsg = 3;

    }
    
    if (jeu->toucheCpt == bateauCpt) {
      jeu->gagner = true;

    }
  } else {
    jeu->gagner = false;
  }
}