//Préprocessus principaux
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include <stdbool.h>
//#include <time.h>
#include <unistd.h>

//Préprocessus pour socket


//Préprocessus annexe
//#include "color.h"
#include "game.h"
#include "network.h"
//#include <ncurses.h>


int main(void){
  int dimension, manche;                                                                                        // Initialisation des variables de paramètre
  int tableau1[9][9], tableau2[9][9], bateau[9][9], tir[9][9], axeX, axeY;                                      // Initialisation des variables de tableau
  int partie, win, essai, touche, toucheMsg, bateauNombre;                                                                                   // Initialisation des variables d'information statistique
  int condition1, condition2;
  
  system("clear");                                                                                              // Nettoyage du terminal

  entete();                                                                                                     // Affichage de l'entete
  condition1 = modeDeJeux();                                                                                    // Selection du mode de jeux (solo/multi)

  if(condition1 == 1){                                                                                          // Condition en fonction du mode de jeux
    dimension = modeDeSelectionMap();                                                                           // Selection de la dimention de la map
    manche =  modeDeSelectionManche();                                                                          // Selection du nombre de manche

    partie = 0;

    do{                                                                                                         // Début du jeux
      touche = 0;
      essai = 0;
      win = 0;
      toucheMsg = 0;

      initialisationTableau1(dimension, tableau1);                                                              // Iniialisation du plateau de jeux
      bateauNombre = initialisationBateau(dimension, bateau, bateauNombre);                                                                  // Initilisation du placement des bateaux
      do{
        toucheMs(toucheMsg);
        afficheur(dimension, tableau1, bateau, essai, manche, partie, bateauNombre, win, touche);                                            // Affichage du jeux
        commande(&axeX, &axeY);                                                                                   // Saisie des coordonnées
        calculateur(axeX, axeY, tableau1, bateau, bateauNombre, manche, &partie, &win, &touche, &toucheMsg, &essai);
        afficheur(dimension, tableau1, bateau, essai, manche, partie, bateauNombre, win, touche);
      }while(win != true);

      afficheur(dimension, tableau1, bateau, essai, manche, partie, bateauNombre, win, touche);
      partie++;
      sleep(2);
    }while(partie != manche);
    
    afficheur(dimension, tableau1, bateau, essai, manche, partie, bateauNombre, win, touche);
  }else{
    condition2 = modeDeSelectionReseau();

    if(condition2 == 1){
      printf("Enter a valid IP to connect to : \n");
      // scanf pour l'adresse IP
    } else {
      printf("Votre ip :"); ip(); printf("\n");
    }
  }
  

  return 0;
}