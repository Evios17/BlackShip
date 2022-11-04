//Préprocessus principaux
#include <stdio.h>

//Préprocessus pour socket
#include <string.h>

//Préprocessus annexe
#include "couleur.h"



void menu() {
  puts(BLEU "╦═══════════════════════════════╦");
  puts("‖           BlackShip           ‖");
  puts("╩═══════════════════════════════╩" RESET);

  puts("Logs :");

  puts("");
  puts("Description :");
  puts("Bienvenu dans BlackShip, un bataille navale solo ou multi joueurs directement jouable dans un terminal.");
  puts("Ce jeux a été totalement réalisé en C dans le cadre d'un projet d'apprentissage universitaire.");

  puts("");
  puts("Veuillez choisir votre mode de jeux :");
  puts("Lancer une partie en solo");
  puts("Lancer une partie en multi-joueurs");

  puts("");
  puts("Héberger la partie");
  puts("Rejoindre une partie");
}


int main(void){
  printf("Hello World !");

  return 0;
}