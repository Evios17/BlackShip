//Préprocessus principaux
#include <stdio.h>

//Préprocessus pour socket
#include <string.h>

//Préprocessus annexe
#include "couleur.h"



void entete() {
  puts("");
  puts("╦══════════════════════════════════════════════════════════════╦");
  puts("╬                          " VERT "BlackShip" RESET "                           ╬");
  puts("╬══════════════════════════════════════════════════════════════╬");
  puts("╬ " NNOIR "Description :" RESET "                                                ╬");
  puts("╬                                                              ╬");
  puts("╬ " NNOIR " - Bienvenu dans BlackShip, un bataille navale solo ou " RESET "      ╬\n╬ " NNOIR "   multi joueurs jouable dans un terminal en ligne" RESET "           ╬");
  puts("╬ " NNOIR "   de commande." RESET "                                              ╬");
  puts("╬ " NNOIR " - Ce jeu a été réalisé en C dans le cadre d'un projet" RESET "       ╬\n╬ " NNOIR "   d'apprentissage universitaire." RESET "                            ╬");
  puts("╩══════════════════════════════════════════════════════════════╩");
}

int modeDeJeux(){
  puts("");
  puts("Veuillez choisir votre mode de jeux :");
  puts(NNOIR "[" VERT "1" NNOIR "] Lancer une partie en solo");
  puts("[" VERT "2" NNOIR "] Lancer une partie en multi-joueurs" RESET);
}

int modeDeSelection(){
  puts(""RESET);
  puts("Veuillez choisir votre une option :");
  puts(NNOIR"[" VERT "1" NNOIR "] Héberger la partie");
  puts("[" VERT "2" NNOIR "] Rejoindre une partie" RESET);
}


int main(void){
  

  menu();

  return 0;
}