//Préprocessus principaux
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

//Préprocessus pour socket
// kiss daddy

//Préprocessus annexe
#include "jeu.h"
#include "couleur.h"

void solo () {
  struct parametre parametre;
  struct jeu jeu;
  

  parametre.dimension = modeDeSelectionMap();
  parametre.manche =  modeDeSelectionManche();

  jeu.mancheCpt = 0;

  do{
    jeu.toucheCpt = 0;
    jeu.essaiCpt = 0;
    jeu.gagner = 0;
    jeu.toucheMsg = 0;

    initialisationTableau(&jeu);
    jeu.bateauCpt = initialisationBateau(parametre, &jeu);

    //printf("je suis passe par la");

    do{
      toucheMs(jeu);
      afficheur(parametre, jeu);
      commande(&jeu);
      calculateur(&jeu);
      afficheur(parametre, jeu);

    }while(jeu.gagner != true);

    afficheur(parametre, jeu);
    jeu.mancheCpt++;
    sleep(2);

  }while(jeu.mancheCpt != parametre.manche);
  
  afficheur(parametre, jeu);

}