//Préprocessus principaux
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>


//Préprocessus annexe
#include "jeu.h"




void initialisationTableau(struct parametre parametre, struct jeu *jeu) {
 
  int axeX, axeY;
  int pourcentage = (parametre.dimension * parametre.dimension) * 0.17;
  jeu->bateauCpt = 0;

  //memset(jeu.tableau, 0, sizeof(int) * parametre.dimension * parametre.dimension);
  memset(&(jeu->tableau1), 0, sizeof(jeu->tableau1));

  srand(time(NULL));

  for (int i = 1; i <= pourcentage; i++) {
    do {
      axeX = rand() % parametre.dimension;
      axeY = rand() % parametre.dimension;
    } while (jeu->tableau1[axeX][axeY] == 3);

    jeu->tableau1[axeX][axeY] =  3;

    jeu->bateauCpt++;
  }
}



void calculateur(int modeDeJeux, struct jeu *jeu) {

  // pointés : mancheCpt, gagné, toucheCpt, toucheMessage, essai
  // pas pointés : axe x, axe y, tableau, bateauCpt, manche

  /*int tableau[9][9];

  for (int i = 0; i < 9 ; i++) {
    for (int j = 0; j < 9 ; j++) {
      tableau[i][j] = jeu->tableau[i][j];
    }
  }
  
  int axeX = jeu->axeX;
  int axeY = jeu->axeY;
  int bateauCpt = jeu->bateauCpt;*/
  if (modeDeJeux == 1) {
    if (jeu->gagner != true) {
      if (jeu->tableau1[jeu->axeY][jeu->axeX] == 0) {
        jeu->tableau1[jeu->axeY][jeu->axeX] = 1;
        jeu->toucheMsg = 2;
        jeu->essaiCpt++;

      } else if (jeu->tableau1[jeu->axeY][jeu->axeX] == 1) {
        jeu->toucheMsg = 3;

      } else if(jeu->tableau1[jeu->axeY][jeu->axeX] == 2) {
        jeu->toucheMsg = 3;

      } else if (jeu->tableau1[jeu->axeY][jeu->axeX] == 3) {
        jeu->tableau1[jeu->axeY][jeu->axeX] = 2;
        jeu->toucheMsg = 1;
        jeu->toucheCpt++;
        jeu->essaiCpt++;
      }
      
      if (jeu->toucheCpt == jeu->bateauCpt) {
        jeu->gagner = true;

      }
    } else {
      jeu->gagner = false;
    }
  } else {
    if (jeu->gagner != true) {
      if (jeu->tableau1[jeu->axeY][jeu->axeX] == 0) {
        jeu->tableau1[jeu->axeY][jeu->axeX] = 1;
        jeu->toucheMsg = 2;
        jeu->essaiCpt++;

        jeu->send = true;

        if (jeu->tour == true) {
          jeu->tour == false;
        } else {
          jeu->tour == true;
        }

      } else if (jeu->tableau1[jeu->axeY][jeu->axeX] == 1) {
        jeu->toucheMsg = 3;

        jeu->send = false;

        if (jeu->tour == true) {
          jeu->tour == true;
        } else {
          jeu->tour == false;
        }

      } else if(jeu->tableau1[jeu->axeY][jeu->axeX] == 2) {
        jeu->toucheMsg = 3;

        jeu->send = false;

        if (jeu->tour == true) {
          jeu->tour == true;
        } else {
          jeu->tour == false;
        }

      } else if (jeu->tableau1[jeu->axeY][jeu->axeX] == 3) {
        jeu->tableau1[jeu->axeY][jeu->axeX] = 2;
        jeu->toucheMsg = 1;
        jeu->toucheCpt++;
        jeu->essaiCpt++;

        jeu->send = true;

        if (jeu->tour == true) {
          jeu->tour == false;
        } else {
          jeu->tour == true;
        }
      }
      
      
      if (jeu->toucheCpt == jeu->bateauCpt) {
        jeu->gagner = true;

      }
    } else {
      jeu->gagner = false;
    }
  }
}