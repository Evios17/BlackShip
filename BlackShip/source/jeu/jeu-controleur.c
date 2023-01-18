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
  memset(&(jeu->tableauTmp), 0, sizeof(jeu->tableauTmp));

  srand(time(NULL));

  for (int i = 1; i <= pourcentage; i++) {
    do {
      axeX = rand() % parametre.dimension;
      axeY = rand() % parametre.dimension;
    } while (jeu->tableauTmp[axeX][axeY] == 3);

    jeu->tableauTmp[axeX][axeY] =  3;

    jeu->bateauCpt++;
  }
}



void calculateur(int modeDeJeux, struct jeu *jeu) {

  if (modeDeJeux == true) {
    if (jeu->gagner != true) {
      if (jeu->tableauTmp[jeu->axeY][jeu->axeX] == 0) {
        jeu->tableauTmp[jeu->axeY][jeu->axeX] = 1;

        jeu->toucheMsg = 2;

        jeu->essaiCpt++;

      } else if (jeu->tableauTmp[jeu->axeY][jeu->axeX] == 1 || jeu->tableauTmp[jeu->axeY][jeu->axeX] == 2) {
        jeu->toucheMsg = 3;

      } else if (jeu->tableauTmp[jeu->axeY][jeu->axeX] == 3) {
        jeu->tableauTmp[jeu->axeY][jeu->axeX] = 2;

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
      if (jeu->tableauTmp[jeu->axeY][jeu->axeX] == 0) { // Tir effectué, pas de bateau
        jeu->tableauTmp[jeu->axeY][jeu->axeX] = 1;

        jeu->toucheMsg = 2;

        jeu->essaiCpt++;

        jeu->send = true;
        //jeu->tourTog = false;
        
        if (jeu->tour == true) {
            jeu->tour = false;
        } else {
            jeu->tour = true;
        }

      } else if (jeu->tableauTmp[jeu->axeY][jeu->axeX] == 1 || jeu->tableauTmp[jeu->axeY][jeu->axeX] == 2) { // Tir sur une case qui a déjà été touché
        jeu->toucheMsg = 3;

        jeu->send = false;
        //jeu->tourTog = true;

      } else if (jeu->tableauTmp[jeu->axeY][jeu->axeX] == 3) { // Tir effectué, bateau touché
        jeu->tableauTmp[jeu->axeY][jeu->axeX] = 2;

        jeu->toucheMsg = 1;

        jeu->toucheCpt++;
        jeu->essaiCpt++;

        jeu->send = true;
        //jeu->tourTog = false;
      }
      
      
      if (jeu->toucheCpt == jeu->bateauCpt) {
        jeu->gagner = true;

      }
    } else {
      jeu->gagner = false;
    }
  }
}