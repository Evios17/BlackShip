//Préprocessus principaux
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Préprocessus pour socket


//Préprocessus annexe
#include <color.h>
#include <game.h>
//#include <ncurses.h>


int main(void) {
  int condition1, condition2, dimension, axeX, axeY;

  entete();
  condition1 = modeDeJeux();

  if(condition1 == 1){
    dimension = modeDeSelectionMap();
    initialisationTableau1(dimension);
    //initialisationBateau(y);
    afficheur(dimension);
    commande(&axeX, &axeY);
    printf("%d %d", axeX, axeY);
  }else{
    condition2 = modeDeSelectionReseau();
    if (condition2 == 1) {
      printf("Entrez une adresse IP valide sur laquelle vous connecter : ");
      // scanf pour l'adresse IP
    } else {
          ipaddress();
        }
    }
  

    return 0;
}