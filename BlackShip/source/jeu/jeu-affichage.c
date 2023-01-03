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
  puts("║                          " NVERT "BlackShip" RESET "                           ║");
  puts("╠══════════════════════════════════════════════════════════════╣");
  puts("║ " GRIS "Description :" RESET "                                                ║");
  puts("║                                                              ║");
  puts("║ " GRIS " - Bienvenue dans Blackship, un bataille navale solo et" RESET "      ║\n║    " GRIS "multijoueur jouable en ligne de commande" RESET "                  ║");
  puts("║ " GRIS "                " RESET "                                             ║");
  puts("║ " GRIS " - Ce jeu a été crée en C, dans le cadre d'un projet   " RESET "      ║\n║ " GRIS "   d'étude universitaire" RESET "                                     ║");
  puts("╚══════════════════════════════════════════════════════════════╝");
  puts("");
}

void afficheur(int modeDeJeux, struct parametre parametre, struct jeu jeu){
  
  int axeX, axeY;

  system("clear");

  if (modeDeJeux == 1) {
    if (jeu.mancheCpt == parametre.manche) {
      puts(CYAN "╔══════════════════════════════════════════════════════════════╗");
      puts("║                                                              ║");
      puts("║" BLANC "                Vous avez remporté la partie !                " CYAN "║");
      puts("║                                                              ║");
      puts("╚══════════════════════════════════════════════════════════════╝" RESET);
      puts("");
    }

    if (jeu.gagner == true) {
      puts(MAGENTA "╔══════════════════════════════════════════════════════════════╗");
      puts("║                                                              ║");
      puts("║" BLANC "                Vous avez remporté la manche !                " MAGENTA "║");
      puts("║                                                              ║");
      puts("╚══════════════════════════════════════════════════════════════╝" RESET);
      puts("");
    }
    

    puts("╔══════════════════════════════════════════════════════════════╗");
    puts("║                     " CYAN "Partie en mode solo" RESET "                      ║");
    puts("╚══════════════════════════════════════════════════════════════╝");
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

    puts("╔══════════════╦══════════════╦═════════════════════╦══════════╗");
    printf("║ Manche [" VERT "%d" RESET "/" VERT "%d" RESET "] ║ Bateau [" VERT "%d" RESET "/" VERT "%d" RESET "] ║                     ║ Tir [" VERT "%d" RESET "]  ║\n", jeu.mancheCpt, parametre.manche, jeu.toucheCpt, jeu.bateauCpt, jeu.essaiCpt);
    puts("╚══════════════╩══════════════╩═════════════════════╩══════════╝");
    puts("");

    if (jeu.mancheCpt == parametre.manche) {
      puts(CYAN "╔══════════════════════════════════════════════════════════════╗");
      puts("║                                                              ║");
      puts("║"BLANC"                Merci d'avoir joué à BlackShip                " CYAN "║");
      puts("║                                                              ║");
      puts("╚══════════════════════════════════════════════════════════════╝" RESET);
      puts("");
    }

  } else {
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
      printf("║ " BLANC "The playerX win the round ! Score = x/x | Time = Xmn         " MAGENTA "║\n");
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

    if (jeu.mancheCpt == parametre.manche) {
      puts(MAGENTA "╔══════════════════════════════════════════════════════════════╗");
      puts("║                                                              ║");
      printf("║"BLANC"                Merci d'avoir joué à BlackShip                " MAGENTA "║\n");
      puts("║                                                              ║");
      puts("╚══════════════════════════════════════════════════════════════╝" RESET);
      puts("");
    }
  }
}



void toucheMs(struct jeu jeu){
  switch(jeu.toucheMsg){
    case 1:
      puts(VERT "╔══════════════════════════════════════════════════════════════╗");
      puts("║ " BLANC "Touché ! Vous avez atteint votre cible. " VERT "                     ║");
      puts("╚══════════════════════════════════════════════════════════════╝" RESET);
      puts("");

      printf("Appuyez sur une touche pour continuer .. ");
      getchar();
      getchar();

      system("clear");

      jeu.toucheMsg = 0;
      break;
    case 2:
      puts(ROUGE "╔══════════════════════════════════════════════════════════════╗");
      puts("║ " BLANC "Raté ! Vous n'avez pas atteint votre cible. " ROUGE "                 ║");
      puts("╚══════════════════════════════════════════════════════════════╝" RESET);
      puts("");

      printf("Appuyez sur une touche pour continuer .. ");
      getchar();
      getchar();

      system("clear");

      jeu.toucheMsg = 0;
      break;
    case 3:
      puts(ROUGE "╔══════════════════════════════════════════════════════════════╗");
      puts("║ " BLANC "Erreur, vous ne pouvez pas tirer au même coordonnées " ROUGE "                 ║");
      puts("╚══════════════════════════════════════════════════════════════╝" RESET);
      puts("");

      printf("Appuyez sur une touche pour continuer .. ");
      getchar();
      getchar();

      system("clear");

      jeu.toucheMsg = 0;
      break;
    default:
      break;
  }
}