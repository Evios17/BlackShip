//Préprocessus principaux
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>


//Préprocessus annexe
#include "jeu.h"




void initialisationTableau1(int dimension, int tableau[9][9]){

  memset(tableau, 0, sizeof(int) * dimension * dimension);
  

  /*tableau[8 - 1][8 - 1] = 2;
  tableau[4 - 1][2 - 1] = 1;
  tableau[2 - 1][7 - 1] = 3;
  tableau[4 - 1][5 - 1] = 4;
  tableau[4 - 1][6 - 1] = 4;*/
}

/*void initialisationTableau2(int dimension){
  int tableau[dimension][dimension];

  memset(&tableau,0,sizeof(tableau));

  tableau[8][8] = 2;
  tableau[4][2] = 1;
  tableau[2][7] = 3;
  tableau[4][5] = 4;
  tableau[4][6] = 4;
}*/

int initialisationBateau(int dimension, int bateau[9][9], int bateauNombre){
 
  int axeX, axeY;
  int pourcentage = (dimension * dimension) * 0.17;
  bateauNombre = 0;

  memset(bateau, 0, sizeof(int) * dimension * dimension);

  srand(time(NULL));

  for(int i = 1; i <= pourcentage; i++){
    do{
      axeX = rand() % dimension;
      axeY = rand() % dimension;
    }while(bateau[axeX][axeY] ==  4);

    bateau[axeX][axeY] =  4;

    bateauNombre++;
  }

  return bateauNombre;
}



void calculateur(int axeX, int axeY, int tableau[9][9], int bateau[9][9], int bateauNombre, int manche, int *partie, int *win, int *touche, int *toucheMsg, int *essai){

  if((*win) != true){
    // Actualisation des valeurs du tableau d'affichage

    if(tableau[axeX][axeY] == 0){
        if(tableau[axeX][axeY] == bateau[axeX][axeY]){
            tableau[axeX][axeY] = 1;

            (*toucheMsg) = 2;
        }else{
            tableau[axeX][axeY] = 2;

            (*toucheMsg) = 1;
            (*touche)++;
        }
        (*essai)++;
    }else if(tableau[axeX][axeY] == 1){
        (*toucheMsg) = 3;
    }else if(tableau[axeX][axeY] == 2){
        (*toucheMsg) = 3;
    }

    if((*touche) == bateauNombre){
      (*win) = true;
    }

  }else{

    (*win) = false;
  }
}