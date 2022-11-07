//Préprocessus principaux
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include <ncurses.h>

//Préprocessus pour socket
#include <string.h>

//Préprocessus annexe
#include <color.h>
#include <game.h>



int main(void) {
  int x, y, z;

  entete();
  x = modeDeJeux();

  if(x == 1){
    y = modeDeSelectionMap();
      afficheur(y);

  } else {
    z = modeDeSelectionReseau();
      if (z == 1) {
        printf("Entrez une adresse IP valide sur laquelle vous connecter : ");
        // scanf pour l'adresse IP
      } else {
            printf(ipaddress());
          }
      }
  

    return EXIT_SUCCESS;
}