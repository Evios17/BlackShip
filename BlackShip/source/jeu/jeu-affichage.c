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
  puts("║ " GRIS " - Bienvenue dans Blackship, une bataille navale solo et" RESET "     ║\n║    " GRIS "multijoueur jouable en ligne de commande" RESET "                  ║");
  puts("║ " GRIS "                " RESET "                                             ║");
  puts("║ " GRIS " - Ce jeu a été crée en C, dans le cadre d'un projet   " RESET "      ║\n║ " GRIS "   d'étude universitaire" RESET "                                     ║");
  puts("╚══════════════════════════════════════════════════════════════╝");
  puts("");
}

void afficheur(int modeDeJeux, struct parametre parametre, struct jeu jeu){
  
  int axeX, axeY;

  system("clear");

  if (modeDeJeux == true) {
    
    /*
    puts("╔══════════════════════════════════════════════════════════════╗");
    puts("║                          " NVERT "BlackShip" RESET "                           ║");
    puts("╚══════════════════════════════════════════════════════════════╝");
    puts("");
    */

    if ( jeu.bateauCpt >= 10 ) {
      puts("╔══════════════════════════════════════════════════════════════════╗");
    } else {
      puts("╔════════════════════════════════════════════════════════════════╗");
    }
    
    printf("║                            " NVERT "BlackShip" RESET "                         "); 
    
    
    if ( jeu.bateauCpt >= 10 ) {
      printf("    ║\n");
      puts("╚══════════════════════════════════════════════════════════════════╝");
    } else {
      printf("  ║\n");
      puts("╚════════════════════════════════════════════════════════════════╝");
    }
    
    puts("");

    for (axeX = 0; axeX <= parametre.dimension; axeX++){
        printf(NBLEU "%d  " RESET, axeX);
    }
    puts("");

    for (axeY = 0; axeY < parametre.dimension; axeY++){
      printf(NBLEU  "%d  " RESET, axeY + 1);
      
      for (axeX = 0; axeX < parametre.dimension; axeX++){
        switch(jeu.tableauTmp[axeX][axeY]){
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

    /*
    puts("╔═══════════════╦══════════════╦═════════════════════╦══════════╗");
    printf("║ Manches [" VERT "%d" RESET "/" VERT "%d" RESET "] ║ Bateaux [" VERT "%d" RESET "/" VERT "%d" RESET "] ║                     ║ Tir [" VERT "%d" RESET "]  ║\n", jeu.mancheCpt, parametre.manche, jeu.toucheCpt, jeu.bateauCpt, jeu.essaiCpt);
    puts("╚═══════════════╩══════════════╩═════════════════════╩══════════╝");
    puts("");
    */

    if ( jeu.bateauCpt >= 10 ) {
      puts("╔═══════════════╦═════════════════╦═════════════════════╦══════════╗");
    } else {
      puts("╔═══════════════╦═══════════════╦═════════════════════╦══════════╗");
    }

    printf("║ Manches [" VERT "%d" RESET "/" VERT "%d" RESET "] ║ Bateaux [" VERT,jeu.mancheCpt, parametre.manche);
    if ( jeu.bateauCpt >= 10 ) {
      if ( jeu.toucheCpt < 10 ) {
        printf("0%d" RESET "/" VERT "%d" RESET "] ║", jeu.toucheCpt, jeu.bateauCpt);
      } else {
        printf("%d" RESET "/" VERT "%d" RESET "] ║", jeu.toucheCpt, jeu.bateauCpt);
      }
    } else {
      printf("%d" RESET "/" VERT "%d" RESET "] ║", jeu.toucheCpt, jeu.bateauCpt);
    }


    
    printf("                     ║ Tir [" VERT);
    if ( jeu.essaiCpt < 10) {
      printf("0%d", jeu.essaiCpt);
    } else {
      printf("%d", jeu.essaiCpt);
    }
    printf(RESET "] ║\n");
    
    if ( jeu.bateauCpt >= 10 ) {
      puts("╚═══════════════╩═════════════════╩═════════════════════╩══════════╝");
    } else {
      puts("╚═══════════════╩═══════════════╩═════════════════════╩══════════╝");
    }
    puts("");
        

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

  } else {
    
    /*
    puts("╔═════════╦════════════════╦════════════════╦══════════════════╗");
    printf("║  Score  ║ " JAUNE "Joueur 1" RESET " [" VERT "1" RESET "/" VERT "%d" RESET "] ║ " BLEU "Joueur 2" RESET " [" VERT "0" RESET "/" VERT "%d" RESET "] ║                  ║\n", parametre.manche, parametre.manche,jeu.tour);
    puts("╚═════════╩════════════════╩════════════════╩══════════════════╝");
    puts("");
    */

    if ( jeu.bateauCpt >= 10 ) {
      puts("╔═════════╦════════════════╦════════════════╦═══════════════════════╗");
      
    } else {
      puts("╔═════════╦════════════════╦════════════════╦═════════════════════╗");
    }
    
    if (jeu.touchePrf == true) {
      printf("║  Score  ║ " BLEU "Joueur 1" RESET " [" VERT "%d" RESET "/" VERT "%d" RESET "] ║ " JAUNE "Joueur 2" RESET " [" VERT "%d" RESET "/" VERT "%d" RESET "] ║                  ", jeu.joueurScr1, parametre.manche, jeu.joueurScr2, parametre.manche,jeu.tour);
    } else {
      printf("║  Score  ║ " JAUNE "Joueur 1" RESET " [" VERT "%d" RESET "/" VERT "%d" RESET "] ║ " BLEU "Joueur 2" RESET " [" VERT "%d" RESET "/" VERT "%d" RESET "] ║                  ", jeu.joueurScr1, parametre.manche, jeu.joueurScr2, parametre.manche,jeu.tour);
    }

    if ( jeu.bateauCpt >= 10 ) {
      printf("     ║\n");
      puts("╚═════════╩════════════════╩════════════════╩═══════════════════════╝");
    } else {
      printf("   ║\n");
      puts("╚═════════╩════════════════╩════════════════╩═════════════════════╝");
    }
    puts("");

    for (axeX = 0; axeX <= parametre.dimension; axeX++){
        printf(NJAUNE "%d  " RESET, axeX);
    }
    puts("");

    for (axeY = 0; axeY < parametre.dimension; axeY++){
      printf(NJAUNE  "%d  " RESET, axeY + 1);
      
      for (axeX = 0; axeX < parametre.dimension; axeX++){
        switch(jeu.tableau2[axeX][axeY]){
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
        switch(jeu.tableau1[axeX][axeY]){
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
              printf("0  ");
              break;
          default:
              printf("~  ");
              break;
        }
      }
      puts("");
    }
    puts("");


    /*
    puts("╔══════════════╦════════════╦═══════════════════════╦══════════╗");
    printf("║ Manches [" VERT "%d" RESET "/" VERT "%d" RESET "] ║ Bateaux [" VERT "%d" RESET "/" VERT "%d" RESET "] ║                       ║ Tir [" VERT "%d" RESET "] ║\n", jeu.mancheCpt, parametre.manche, jeu.toucheCpt, jeu.bateauCpt, jeu.essaiCpt);
    puts("╚══════════════╩════════════╩═══════════════════════╩══════════╝");
    puts("");
    */

    if ( jeu.bateauCpt >= 10 ) {
      puts("╔═══════════════╦═════════════════╦═════════════════════╦══════════╗");
    } else {
      puts("╔═══════════════╦═══════════════╦═════════════════════╦══════════╗");
    }

    printf("║ Manches [" VERT "%d" RESET "/" VERT "%d" RESET "] ║ Bateaux [" VERT,jeu.mancheCpt, parametre.manche);
    if ( jeu.bateauCpt >= 10 ) {
      if ( jeu.toucheCpt < 10 ) {
        printf("0%d" RESET "/" VERT "%d" RESET "] ║", jeu.toucheCpt, jeu.bateauCpt);
      } else {
        printf("%d" RESET "/" VERT "%d" RESET "] ║", jeu.toucheCpt, jeu.bateauCpt);
      }
    } else {
      printf("%d" RESET "/" VERT "%d" RESET "] ║", jeu.toucheCpt, jeu.bateauCpt);
    }


    
    printf("                     ║ Tir [" VERT);
    if ( jeu.essaiCpt < 10) {
      printf("0%d", jeu.essaiCpt);
    } else {
      printf("%d", jeu.essaiCpt);
    }
    printf(RESET "] ║\n");
    
    if ( jeu.bateauCpt >= 10 ) {
      puts("╚═══════════════╩═════════════════╩═════════════════════╩══════════╝");
    } else {
      puts("╚═══════════════╩═══════════════╩═════════════════════╩══════════╝");
    }
    puts("");


    if (jeu.gagner == true) {
      puts("╔══════════════════════════════════════════════════════════════╗");
      puts("║                                                              ║");
      
      if (jeu.gagnant == true) {
    printf("║          Joueur1 a gagné la manche ! Score = %d/%d             ║\n", jeu.joueurScr1, parametre.manche);
      } else {
    printf("║          Joueur2 a gagné la manche ! Score = %d/%d             ║\n", jeu.joueurScr2, parametre.manche);
      }
      
      puts("║                                                              ║");
      puts("╚══════════════════════════════════════════════════════════════╝" RESET);
      puts("");
    }
  }
}



void fin(struct jeu jeu, struct parametre parametre) {
  if (jeu.mancheCpt == parametre.manche) {
    puts("╔══════════════════════════════════════════════════════════════╗");
    puts("║                                                              ║");
    
    if (jeu.joueurScr1 > jeu.joueurScr2) {
      printf("║ Joueur1 a ramporté le jeu ! Score = %d/%d                      ║\n", jeu.joueurScr1, parametre.manche);
    
    } else if (jeu.joueurScr1 < jeu.joueurScr2) {
      printf("║ Joueur2 a ramporté le jeu ! Score = %d/%d                      ║\n", jeu.joueurScr2, parametre.manche);
    
    } else{
      printf("║ Les joueurs joueur1 et joueur2 sont ex aequo.                ║\n");
    }

    puts("║                                                              ║");
    puts("╚══════════════════════════════════════════════════════════════╝" RESET);
    puts("");
  }

  if (jeu.mancheCpt == parametre.manche) {
    puts(CYAN "╔══════════════════════════════════════════════════════════════╗");
    puts("║                                                              ║");
    puts("║"BLANC"                Merci d'avoir joué à BlackShip                " CYAN "║");
    puts("║                                                              ║");
    puts("╚══════════════════════════════════════════════════════════════╝" RESET);
    puts("");
  }
}



void tourMs(struct jeu jeu){
  if (jeu.tour == true) {
    puts("C'est votre tour, à vous de jouer.");
    puts("");
  } else {
    puts("C'est le tour de votre adversaire, veuillez patienter.");
    puts("");
  }
}



void toucheMs(int modeDeJeux, struct jeu jeu){
  switch (jeu.toucheMsg) {
      case 1:
        if (modeDeJeux == true) {
          puts( VERT "╔══════════════════════════════════════════════════════════════╗");
          puts("║           Touché ! Vous avez atteint votre cible.            ║");
          puts("╚══════════════════════════════════════════════════════════════╝" RESET);
          puts("");

          puts("Appuyez sur une touche pour continuer .. ");
          puts("");

        } else {
          if (jeu.touchePrf == true) {
            puts( VERT "╔══════════════════════════════════════════════════════════════╗");
            puts("║           Touché ! Vous avez atteint votre cible.            ║");
            puts("╚══════════════════════════════════════════════════════════════╝" RESET);
            puts("");

            puts("Appuyez sur une touche pour continuer .. ");
            puts("");

          } else {
            puts( ROUGE "╔══════════════════════════════════════════════════════════════╗");
            puts("║   Attention ! Votre adversaire a touché un de vos bateaux.   ║");
            puts("╚══════════════════════════════════════════════════════════════╝" RESET);
            puts("");

            puts("En attente de votre adversaire pour continuer .. ");
            puts("");

          }
        }
        
        

        jeu.toucheMsg = 0;
        break;
      case 2:
        if (modeDeJeux == true) {
          puts( ROUGE "╔══════════════════════════════════════════════════════════════╗");
          puts("║         Raté ! Vous n'avez pas atteint votre cible.          ║");
          puts("╚══════════════════════════════════════════════════════════════╝" RESET);
          puts("");

          puts("Appuyez sur une touche pour continuer .. ");
          puts("");

        } else {
          if (jeu.touchePrf == true) {
            puts( ROUGE "╔══════════════════════════════════════════════════════════════╗");
            puts("║         Raté ! Vous n'avez pas atteint votre cible.          ║");
            puts("╚══════════════════════════════════════════════════════════════╝" RESET);
            puts("");

            puts("Appuyez sur une touche pour continuer .. ");
            puts("");

          } else {
            puts( VERT "╔══════════════════════════════════════════════════════════════╗");
            puts("║ Échappée Belle ! Votre adversaire n'a pas atteint sa cible.  ║");
            puts("╚══════════════════════════════════════════════════════════════╝" RESET);
            puts("");

            puts("En attente de votre adversaire pour continuer .. ");
            puts("");

          }
        }
        

        jeu.toucheMsg = 0;
        break;
      case 3:
        puts( ROUGE "╔══════════════════════════════════════════════════════════════╗");
        puts("║    Erreur, vous ne pouvez pas tirer aux mêmes coordonnées    ║");
        puts("╚══════════════════════════════════════════════════════════════╝" RESET);
        puts("");

        printf("Appuyez sur une touche pour continuer .. ");

        jeu.toucheMsg = 0;
        break;
      default:
        break;
    }
}