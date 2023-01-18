//Préprocessus principaux
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

//Préprocessus pour socket

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

    initialisationTableau(parametre, &jeu);

    do{
      afficheur(seul, parametre, jeu);

      commande(&jeu);

      calculateur(seul, &jeu);

      afficheur(seul, parametre, jeu);

      toucheMs(seul, jeu);
      getchar();
      getchar();

    }while(jeu.gagner != true);
    
    jeu.mancheCpt++;

    afficheur(seul, parametre, jeu);
    sleep(2);

  }while(jeu.mancheCpt != parametre.manche);

  jeu.gagner = false;
  
  afficheur(seul, parametre, jeu);
}