//Préprocessus principaux
#include <stdio.h>
#include <stdbool.h>

//Préprocessus pour socket
#include <string.h>

//Préprocessus annexe
#include "couleur.h"



void entete(void) {
  puts("");
  puts("╦══════════════════════════════════════════════════════════════╦");
  puts("╬ V1.1                     " VERT "BlackShip" RESET "                           ╬");
  puts("╬══════════════════════════════════════════════════════════════╬");
  puts("╬ " NNOIR "Description :" RESET "                                                ╬");
  puts("╬                                                              ╬");
  puts("╬ " NNOIR " - Bienvenu dans BlackShip, un bataille navale solo ou " RESET "      ╬\n╬ " NNOIR "   multi joueurs jouable dans un terminal en ligne" RESET "           ╬");
  puts("╬ " NNOIR "   de commande." RESET "                                              ╬");
  puts("╬ " NNOIR " - Ce jeu a été réalisé en C dans le cadre d'un projet" RESET "       ╬\n╬ " NNOIR "   d'apprentissage universitaire." RESET "                            ╬");
  puts("╩══════════════════════════════════════════════════════════════╩");
}

int modeDeJeux(void){
  int x, y;

  do{
    puts("");
    puts("Choisissez votre mode de jeux :");
    puts(NNOIR "[" VERT "1" NNOIR "] Lancer une partie en solo");
    puts("[" VERT "2" NNOIR "] Lancer une partie en multi-joueurs" RESET);

    puts("");
    printf("=> " JAUNE);
    scanf("%d", &x);
    puts("" RESET);

    if(x == 1){
      y = true;
    }else if(x == 2){
      y = true;
    }else{
      puts(ROUGE "Erreur => Saisie incorrecte, veuillez répondre par 1 ou 2" RESET);
      y = false;
    }
  }while(y != true);


  return x;
}

int modeDeSelectionReseau(void){
  int x, y;

  do{
    puts("");
    puts("Sélectionnez une option :");
    puts(NNOIR "[" VERT "1" NNOIR "] Rejoindre un serveur");
    puts("[" VERT "2" NNOIR "] Héberger un serveur" RESET);

    puts("");
    printf("=> " JAUNE);
    scanf("%d", &x);
    puts("" RESET);

    if(x == 1){
      y = true;
    }else if(x == 2){
      y = true;
    }else{
      puts(ROUGE "Erreur => Saisie incorrecte, veuillez répondre par 1 ou 2" RESET);
      y = false;
    }
  }while(y != true);


  return x;
}


int modeDeSelectionMap(void){
  int x, y;

  do{
    puts("");
    puts("Indiquez la taille de la map (min 5, max 20) :");

    puts("");
    printf("=> " JAUNE);
    scanf("%d", &x);
    puts("" RESET);

    if (x >= 5 && x <=20){
      y = true;
    }else{
      puts(ROUGE "Erreur => Saisie incorrecte, veuillez une valeur entre 5 et 20" RESET);
      y = false;
    }
  }while(y != true);


  return x;
}

int initialisation(int taille){
  int x[0][0], y[0][0];

  x[0][0] = x[0][taille];
  y[0][0] = y[0][taille];
  
}


int main(void){
  int x, y;

  entete();
  x = modeDeJeux();

  if(x == true){
    y = modeDeSelectionMap();
    initialisation(y);

    do{
      /* code */
    } while (/* condition */);
  }else{
    modeDeSelectionReseau();
  }
  

  return 0;
}