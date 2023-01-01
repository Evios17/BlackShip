//Préprocessus principaux
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>


//Préprocessus annexe
#include "couleur.h"
#include "jeu.h"



void entete () {
  puts("");
  puts("╔══════════════════════════════════════════════════════════════╗");
  puts("║ V1.1                     " NVERT "BlackShip" RESET "                           ║");
  puts("╠══════════════════════════════════════════════════════════════╣");
  puts("║ " GRIS "Description :" RESET "                                                ║");
  puts("║                                                              ║");
  puts("║ " GRIS " - Welcome to BlackShip, a solo or multiplayer battleship" RESET "    ║\n║ " GRIS "   playable on a prompt command" RESET "                              ║");
  puts("║ " GRIS "                " RESET "                                             ║");
  puts("║ " GRIS " - This game was made in C as part of an academic " RESET "           ║\n║ " GRIS "   learning project" RESET "                                          ║");
  puts("╚══════════════════════════════════════════════════════════════╝");
  puts("");
}

void afficheur(struct parametre parametre, struct jeu jeu){
  
  int axeX, axeY;

  system("clear");

  if (jeu.mancheCpt == parametre.manche) {
    puts(MAGENTA "╔══════════════════════════════════════════════════════════════╗");
    puts("║                                                              ║");
    printf("║ " BLANC "The playerX win the game ! Score = x/x | Time = Xmn          " MAGENTA "║\n");
    puts("║                                                              ║");
    puts("╚══════════════════════════════════════════════════════════════╝" RESET);
    puts("");
  }

  if (jeu.gagner == true) {
    puts(MAGENTA "╔══════════════════════════════════════════════════════════════╗");
    puts("║                                                              ║");
    printf("║ " BLANC "The playerX win the round ! Score = x/x | Time = Xmn          " MAGENTA "║\n");
    puts("║                                                              ║");
    puts("╚══════════════════════════════════════════════════════════════╝" RESET);
    puts("");
  }
  

  puts("╔═════════╦════════════════╦════════════════╦══════════════════╗");
  printf("║  Score  ║ " JAUNE "Joueur 1" RESET " [" VERT "1" RESET "/" VERT "%d" RESET "] ║ " BLEU "Joueur 2" RESET " [" VERT "0" RESET "/" VERT "%d" RESET "] ║                  ║\n", parametre.manche, parametre.manche);
  puts("╚═════════╩════════════════╩════════════════╩══════════════════╝");
  puts("");

  for (axeX = 0; axeX <= parametre.dimension; axeX++){
      printf(NJAUNE "%d  " RESET, axeX);
  }
  puts("");

  for (axeY = 0; axeY < parametre.dimension; axeY++){
    printf(NJAUNE  "%d  " RESET, axeY + 1);
    
    for (axeX = 0; axeX < parametre.dimension; axeX++){
      switch(jeu.tableau[axeX][axeY]){
        case 0 :
            printf("~  ");
            break;
        case 1 :
            printf( "   " );
            break;
        case 2 :
            printf(NROUGE "×  " RESET);
            break;
        case 3 :
            printf(NCYAN "•  " RESET);
            break;
        default:
            printf("~  ");
            break;
      }
    }
    puts("");
  }
  puts("");


  for (axeX = 0; axeX <= parametre.dimension; axeX++){
      printf(NBLEU "%d  " RESET, axeX);
  }
  puts("");

  for (axeY = 0; axeY < parametre.dimension; axeY++){
    printf(NBLEU  "%d  " RESET, axeY + 1);
    
    for (axeX = 0; axeX < parametre.dimension; axeX++){
      switch(jeu.tableau[axeX][axeY]){
        case 0 :
            printf("~  ");
            break;
        case 1 :
            printf( "   " );
            break;
        case 2 :
            printf(NVERT "×  " RESET);
            break;
        case 3 :
            printf("~  ");
            break;
        default:
            printf("~  ");
            break;
      }
    }
    puts("");
  }
  puts("");

  puts("╔══════════════╦════════════╦═══════════════════════╦══════════╗");
printf("║ Manche [" VERT "%d" RESET "/" VERT "%d" RESET "] ║ Bateau [" VERT "%d" RESET "/" VERT "%d" RESET "] ║                       ║ Tir [" VERT "%d" RESET "] ║\n", jeu.mancheCpt, parametre.manche, jeu.toucheCpt, jeu.bateauCpt, jeu.essaiCpt);
  puts("╚══════════════╩════════════╩═══════════════════════╩══════════╝");
  puts("");
}



void toucheMs(struct jeu jeu){
  switch(jeu.toucheMsg){
    case 1:
      puts(VERT "╔══════════════════════════════════════════════════════════════╗");
      puts("║ " BLANC "Touché ! Vous avez atteint votre cible. " VERT "                     ║");
      puts("╚══════════════════════════════════════════════════════════════╝" RESET);
      puts("");

      sleep(1);

      system("clear");

      jeu.toucheMsg = 0;
      break;
    case 2:
      puts(ROUGE "╔══════════════════════════════════════════════════════════════╗");
      puts("║ " BLANC "Raté ! Vous n'avez pas atteint votre cible. " ROUGE "                 ║");
      puts("╚══════════════════════════════════════════════════════════════╝" RESET);
      puts("");

      sleep(1);

      system("clear");

      jeu.toucheMsg = 0;
      break;
    case 3:
        puts(ROUGE "╔══════════════════════════════════════════════════════════════╗");
        puts("║ " BLANC "Erreur, vous ne pouvez pas tirer au même coordonnées " ROUGE "                 ║");
        puts("╚══════════════════════════════════════════════════════════════╝" RESET);
        puts("");

        sleep(1);

        system("clear");

        jeu.toucheMsg = 0;
        break;
    default:
      break;
  }
}