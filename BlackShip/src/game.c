//Préprocessus principaux
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
//#include <ncurses.h>

//Préprocessus pour socket


//Préprocessus annexe
#include "color.h"
#include "game.h"
#include "network.h"




//Partie affichage

void entete(void){
  puts("");
  puts("╔══════════════════════════════════════════════════════════════╗");
  puts("║ V1.1                     " NVERT "BlackShip" RESET "                           ║");
  puts("╠══════════════════════════════════════════════════════════════╣");
  puts("║ " GRIS "Description :" RESET "                                                ║");
  puts("║                                                              ║");
  puts("║ " GRIS " - Welcome to BlackShip, a solo naval battle where     " RESET "      ║\n║ " GRIS "   multiplayer playable in an online terminal" RESET "                ║");
  puts("║ " GRIS "   de commande." RESET "                                              ║");
  puts("║ " GRIS " - This game was made in C as part of a academic " RESET "            ║\n║ " GRIS "   learning project" RESET "                                          ║");
  puts("╚══════════════════════════════════════════════════════════════╝");
  puts("");
}

void afficheur(int dimension, int manche, int partie, int tir, int tableau[9][9], int bateau[9][9]){
  
  int axeX, axeY, bascule = false;

  /*memset(&bateau,0,sizeof(bateau));

  srand(time(NULL));

  pourcentage = (dimension * dimension) * 0.17;

  for(int i = 1; i <= dimension; i++){
    axeX = rand() % dimension + 1;
    axeY = rand() % dimension + 1;
    
    bateau[axeX][axeY] =  4;
  }*/

  system("clear");

  if(partie == manche){
    puts(MAGENTA "╔══════════════════════════════════════════════════════════════╗");
    puts("║                                                              ║");
    printf("║ " BLANC "The playerX win the game ! Score = x/x | Time = Xmn          " MAGENTA "║\n", manche, manche);
    puts("║                                                              ║");
    puts("╚══════════════════════════════════════════════════════════════╝" RESET);
    puts("");
  }
  

  puts("╔═════════╦════════════════╦════════════════╦══════════════════╗");
  printf("║  Score  ║ " JAUNE "Player 1" RESET " [" VERT "1" RESET "/" VERT "%d" RESET "] ║ " BLEU "Player 2" RESET " [" VERT "0" RESET "/" VERT "%d" RESET "] ║                  ║\n", manche, manche);
  puts("╚═════════╩════════════════╩════════════════╩══════════════════╝");
  puts("");

  for (axeX = 0; axeX <= dimension; axeX++){
      printf(NJAUNE "%d  " RESET, axeX);
  }
  puts("");

  for (axeY = 0; axeY < dimension; axeY++){
    printf(NJAUNE  "%d  " RESET, axeY + 1);
    
    for (axeX = 0; axeX < dimension; axeX++){
      switch(bateau[axeX][axeY]){
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
  puts("");


  for (axeX = 0; axeX <= dimension; axeX++){
      printf(NBLEU "%d  " RESET, axeX);
  }
  puts("");

  for (axeY = 0; axeY < dimension; axeY++){
    printf(NBLEU  "%d  " RESET, axeY + 1);
    
    for (axeX = 0; axeX < dimension; axeX++){
      switch(tableau[axeX][axeY]){
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
  puts("");

  puts("╔══════════════╦════════════════════════════════════╦══════════╗");
printf("║ Sleeve [" VERT "%d" RESET "/" VERT "%d" RESET "] ║                                    ║ Shot [" VERT "%d" RESET "] ║\n", partie, manche, tir);
  puts("╚══════════════╩════════════════════════════════════╩══════════╝");
  puts("");
}



//Partie entré et sortie

int modeDeJeux(void){

  int condition, bascule;

  do{
    puts("Select your gamemode :");
    puts(GRIS "[" NVERT "1" RESET GRIS "] Launch a singleplayer game" RESET);
    puts(GRIS "[" NVERT "2" RESET GRIS "] Launch a multiplayer game" RESET);

    puts("");
    printf("➤  " JAUNE);
    scanf("%d", &condition);
    puts("" RESET);

    if(condition == 1){
      bascule = true;
    }else if(condition == 2){
      bascule = true;
    }else{
      puts(NROUGE "[Error] Wrong Input, please respond by 1 or 2" RESET);

      bascule = false;
    }
  }while(bascule != true);


  return condition;
}


int modeDeSelectionReseau(void){

  int condition, bascule;

  do{
    puts("Select a option :");
    puts(GRIS "[" NVERT "1" RESET GRIS "] Join a server" RESET);
    puts(GRIS "[" NVERT "2" RESET GRIS "] Host a server" RESET);

    puts("");
    printf("➤  " JAUNE);
    scanf("%d", &condition);
    puts("" RESET);

    if(condition == 1){
      bascule = true;
    }else if(condition == 2){
      bascule = true;
    }else{
      puts(ROUGE "[Error] Wrong Input, please respond by 1 or 2" RESET);

      bascule = false;
    }
  }while(bascule != true);


  return condition;
}

/*int modeDeSelectionReseau(void){
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
          printf("Voici l'adresse IP à partager avec le client : " VERT);
          ip();
          puts("" RESET);
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
*/

int modeDeSelectionMap(void){

  int condition, bascule;

  do{
    puts("Choose the map size (min 5, max 9) :");

    puts("");
    printf("➤  " JAUNE);
    scanf("%d", &condition);
    puts("" RESET);

    if (condition >= 5 && condition <= 9){
      bascule = true;
    }else{
      puts(ROUGE "[Error] Wront Input, please choose a number between 5 and 9" RESET);
      puts("");

      bascule = false;
    }
  }while(bascule == false);


  return condition++;
}

int modeDeSelectionManche(void){

  int condition, bascule;

  do{
    puts("Choose the number of round (min 1, max 6) :");

    puts("");
    printf("➤  " JAUNE);
    scanf("%d", &condition);
    puts("" RESET);

    if (condition >= 1 && condition <= 6){
      bascule = true;
    }else{
      puts(ROUGE "[Error] Wront Input, please choose a number between 1 and 6" RESET);
      puts("");

      bascule = false;
    }
  }while(bascule == false);


  return condition;
}

void commande(int *axeX, int *axeY){

  puts("Enter the line of fire : ");
  puts("");
  printf("➤  " JAUNE);
  scanf("%d", axeX);
  (*axeX)--;
  puts("" RESET);

  puts("Enter the column of fire : ");
  puts("");
  printf("➤  " JAUNE);
  scanf("%d", axeY);
  (*axeY)--;
  puts("" RESET);
}



//Partie logique

void initialisationTableau1(int dimension, int tableau[9][9]){

  memset(tableau, 0, sizeof(int) * dimension * dimension);
  

  tableau[8 - 1][8 - 1] = 2;
  tableau[4 - 1][2 - 1] = 1;
  tableau[2 - 1][7 - 1] = 3;
  tableau[4 - 1][5 - 1] = 4;
  tableau[4 - 1][6 - 1] = 4;
}

/*void initialisationTableau2(int dimension){
  int tableau[dimension][dimension];

  memset(&tableau,0,sizeof(tableau));

  tableau[8][8] = 2;
  tableau[4][2] = 1;
  tableau[2][7] = 3;
  tableau[4][5] = 4;
  tableau[4][6] = 4;
}*/

void initialisationBateau(int dimension, int bateau[9][9]){
 
  int axeX, axeY;
  int pourcentage = (dimension * dimension) * 0.17;

  memset(bateau, 0, sizeof(int) * dimension * dimension);

  srand(time(NULL));

  for(int i = 1; i <= pourcentage; i++){
    do{
      axeX = rand() % dimension;
      axeY = rand() % dimension;
    }while(bateau[axeX][axeY] ==  4);

    bateau[axeX][axeY] =  4;
  }
}



int calcul(int axeX, int axeY, int tir){

  int tableau1[axeX][axeY], bateau[axeX][axeY];

  if(tableau1[axeX][axeY] == bateau[axeX][axeY]){
    tableau1[axeX][axeY] = 2;
    
  }else{
    tableau1[axeX][axeY] = 1;
  }
  
  tir++;
}