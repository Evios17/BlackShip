//Préprocessus principaux
#include <stdio.h>
#include <stdbool.h>
#include <ncurses.h>

//Préprocessus pour socket
#include <string.h>

//Préprocessus annexe
#include <couleur.h>
#include <reseau.h>



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
  puts("");
}

int modeDeJeux(void){
  int x, y;

  do{
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
  int x, y, z;

  do{
    puts("Sélectionnez une option :");
    puts(NNOIR "[" VERT "1" NNOIR "] Rejoindre un serveur");
    puts("[" VERT "2" NNOIR "] Héberger un serveur" RESET);

    puts("");
    printf("=> " JAUNE);
    scanf("%d", &x);
    puts("" RESET);

    if(x == 1){
      do{
        puts("Saisissez l'adresse IP du serveur (true / false) : ");

        puts("");
        printf("=> " JAUNE);
        scanf("%d", &y);
        puts("" RESET);

        if(y == true){
          z = true;
        }else{
          puts(ROUGE "Erreur => L'adresse erroné, veuillez recommencer" RESET);
          puts("");
          z = false;
        }
      }while(z != true);

      z = true;
    }else if(x == 2){
        if (chk_w() == false) {
          puts("Impossible d'afficher votre IP");
        } else {
          printf("Voici l'adresse IP à partager avec le client : "); ip();
        }

      z = true;
    }else{
      puts(ROUGE "Erreur => Saisie incorrecte, veuillez répondre par 1 ou 2" RESET);
      puts("");
      z = false;
    }
  }while(z != true);
  


  return x;
}


int modeDeSelectionMap(void){
  int x, y;

  do{
    puts("Indiquez la taille de la map (min 5, max 9) :");

    puts("");
    printf("=> " JAUNE);
    scanf("%d", &x);
    puts("" RESET);

    if (x >= 5 && x <= 9){
      y = true;
    }else{
      puts(ROUGE "Erreur => Saisie incorrecte, veuillez saisir une valeur entre 5 et 9" RESET);
      puts("");
      y = false;
    }
  }while(y == false);


  return x++;
}

int initialisation(int taille){
  int x[0][0], y[0][0];

  x[0][0] = x[0][taille];
  y[0][0] = y[0][taille];
  
}

int afficheur(int k){
  int x, y, z = false, e = false;

  int t[k][k];
  
  memset(&t,0,sizeof(t));
  t[8][8] = 2;
  t[4][2] = 1;
  t[2][7] = 3;
  t[4][5] = 4;
  t[4][6] = 4;

  puts("╦══════════════════════════════════════════════════════════════╦");
  puts("╬ Partie => " VERT "3" RESET "/4                           Nombre d'essais => " VERT "5" RESET " ╬");
  puts("╩══════════════════════════════════════════════════════════════╩");
  puts("");

  for (y = 0; y <= k; y++){
    printf(NBLEU  "%d  " RESET, y);
    if(z == false){
        for (x = 1; x <= k; x++){
            printf(NBLEU "%d  " RESET, x);
        }
        puts("");
        z = true;
    }else{
        for (x = 1; x <= k; x++){
          switch(t[x][y]){
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
                printf(NROUGE "×  " RESET);
                break;
            case 4 :
                printf(NCYAN "•  " RESET);
                break;
            default:
                printf("~  ");
                break;
          }
        }
        puts("");
    }
  }
  puts("");

  puts("╦══════════════════════════════════════════════════════════════╦");
  puts("╬ Score => Player 1 : " VERT "3" RESET "/4 | Player 2 : " VERT "2" RESET "/4                     ╬");
  puts("╩══════════════════════════════════════════════════════════════╩");
  puts("");
}


int main(void){
  int x, y;

  entete();
  x = modeDeJeux();

  if(x == true){
    y = modeDeSelectionMap();
    //initialisation();
    afficheur(y);

  }else{
    modeDeSelectionReseau();
  }  

    return 0;
}