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
  int dimension, manche;                                                                                        // Initialisation des variables de paramètre
  int tableau1[9][9], tableau2[9][9], bateau[9][9], tir[9][9], axeX, axeY;                                      // Initialisation des variables de tableau
  int partie = 0, win, essai = 0, touche, toucheMsg, bateauNombre;                                                                                   // Initialisation des variables d'information statistique
  int condition1, condition2;                                                                                   // Initialisation des variables tampons
  
  
  system("clear");                                                                                              // Nettoyage du terminal

  entete();                                                                                                     // Affichage de l'entete
  condition1 = modeDeJeux();                                                                                    // Selection du mode de jeux (solo/multi)

  if(condition1 == 1){                                                                                          // Condition en fonction du mode de jeux
    dimension = modeDeSelectionMap();                                                                           // Selection de la dimention de la map
    manche =  modeDeSelectionManche();                                                                          // Selection du nombre de manche

    do{                                                                                                         // Début du jeux
      initialisationTableau1(dimension, tableau1);                                                              // Iniialisation du plateau de jeux
      bateauNombre = initialisationBateau(dimension, bateau, bateauNombre);                                                                  // Initilisation du placement des bateaux
      do{
        toucheMs(toucheMsg);
        afficheur(dimension, tableau1, bateau, essai, manche, partie, bateauNombre);                                            // Affichage du jeux
        commande(&axeX, &axeY);                                                                                   // Saisie des coordonnées
        toucheMsg = calculateur(axeX, axeY, tableau1, bateau, bateauNombre, manche, partie, win, essai, touche, toucheMsg);
        afficheur(dimension, tableau1, bateau, essai, manche, partie, bateauNombre);
        essai++;
      }while(win != true);

      afficheur(dimension, tableau1, bateau, essai, manche, partie, bateauNombre);
    }while(partie != manche);
  }else{
    condition2 = modeDeSelectionReseau();

    if(condition2 == 1){
      printf("Enter a valid IP to connect to : \n");
      // scanf pour l'adresse IP
    } else {
      ip();
    }
  }
  

  return 0;
}