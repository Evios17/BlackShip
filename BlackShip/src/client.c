//Préprocessus principaux
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include <stdbool.h>
//#include <time.h>
//#include <unistd.h>

//Préprocessus pour socket


//Préprocessus annexe
//#include "color.h"
#include "game.h"
#include "network.h"
//#include <ncurses.h>


int main(void){
  int tableau1[9][9], tableau2[9][9], bateau[9][9], axeX, axeY;
  int dimension, manche, partie, win, tir = 0;  
  int condition1, condition2;
  
  
  system("clear");

  entete();
  condition1 = modeDeJeux();

  if(condition1 == 1){
    dimension = modeDeSelectionMap();
    manche =  modeDeSelectionManche();

    for(partie = 0; partie < manche; partie++){
      initialisationTableau1(dimension, tableau1);
      initialisationBateau(dimension, bateau);
      afficheur(dimension, manche, partie, tir, tableau1, bateau);
      commande(&axeX, &axeY);
      tir++;
    }

    afficheur(dimension, manche, partie, tir, tableau1, bateau);
  }else{
    condition2 = modeDeSelectionReseau();

    if(condition2 == 1){
      printf("Enter a valid IP to connect to : ");
      // scanf pour l'adresse IP
    } else {
      ipaddress();
    }
  }
  

  return 0;
}