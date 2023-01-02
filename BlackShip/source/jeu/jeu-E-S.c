//Préprocessus principaux
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include <stdbool.h>
//#include <unistd.h>
//#include <time.h>


//Préprocessus annexe
#include "jeu.h"
#include "couleur.h"



int modeDeJeux() {

  int condition, bascule;

  do{
    puts("Sélectionnez votre mode de jeu :");
    puts(GRIS "[" NVERT "1" RESET GRIS "] Lancez une partie solo" RESET);
    puts(GRIS "[" NVERT "2" RESET GRIS "] Lancez une partie multijoueurs" RESET);

    puts("");
    printf("➤  " JAUNE);
    scanf("%d", &condition);
    puts(RESET);

/*    REMETTRE QUAND IL Y A PLUS LE DEBUG
    if(condition == 1){
      bascule = true;
    }else if(condition == 2){
      bascule = true;
    }else{
      puts(NROUGE "[Erreur] Entrée invalide, veuillez répondre par 1 ou 2" RESET);

      bascule = false;
    }
*/
    if(condition == 1){
      bascule = true;
    }else if(condition == 2){
      bascule = true;
    }else if(condition == 3){
      bascule = true;
    }else{
      puts(NROUGE "[Erreur] Entrée invalide, veuillez répondre par 1, 2 ou 3" RESET);

      bascule = false;
    }
  }while(bascule != true);


  return condition;
}


int modeDeSelectionReseau() {

  int condition, bascule;

  do{
    puts("Sélectionnez une option :");
    puts(GRIS "[" NVERT "1" RESET GRIS "] Rejoindre une partie" RESET);
    puts(GRIS "[" NVERT "2" RESET GRIS "] Héberger une partie" RESET);

    puts("");
    printf("➤  " JAUNE);
    scanf("%d", &condition);
    puts(RESET);

    if(condition == 1){
      condition = true;
      bascule = true;

    }else if(condition == 2){
      condition = false;
      bascule = true;

    }else{
      puts(ROUGE "[Erreur] Entrée invalide, veuillez répondre par 1 ou 2" RESET);

      bascule = false;
    }
  }while(bascule != true);


  return condition;
}

int modeDeSelectionMap() {

  int condition, bascule;

  do{
    puts("Choisissez la taille de votre plateau (min 5, max 9) :");

    puts("");
    printf("➤  " JAUNE);
    scanf("%d", &condition);
    puts(RESET);

    if (condition >= 5 && condition <= 9){
      bascule = true;

    }else{
      puts(ROUGE "[Erreur] Entrée invalide, veuillez répondre par un nombre entre 5 et 9" RESET);
      puts("");

      bascule = false;
    }
  }while(bascule == false);


  return condition++;
}

int modeDeSelectionManche() {

  int condition, bascule;

  do{
    puts("Choisissez un nombre de manches (min 1, max 6) :");

    puts("");
    printf("➤  " JAUNE);
    scanf("%d", &condition);
    puts(RESET);

    if (condition >= 1 && condition <= 6){
      bascule = true;
      
    }else{
      puts(ROUGE "[Erreur] Entrée invalide, veuillez entrer un nombre entre 1 et 6" RESET);
      puts("");

      bascule = false;
    }
  }while(bascule == false);


  return condition;
}

void commande(struct jeu *jeu) {

  puts("Entrez la ligne de tir : ");
  puts("");
  printf("➤  "JAUNE);
  scanf("%d", &jeu->axeX);
  puts(RESET);

  puts("Entrez la colonne de tir : ");
  puts("");
  printf("➤  "JAUNE);
  scanf("%d", &jeu->axeY);
  puts(RESET);

  jeu->axeX--;
  jeu->axeY--;
}