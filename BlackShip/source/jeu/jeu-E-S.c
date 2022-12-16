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
#include "network.h"




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
    puts("Select an option :");
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
      puts(ROUGE "[Error] Wrong Input, please choose a number between 5 and 9" RESET);
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

  puts("Enter the column of the fire : ");
  puts("");
  printf("➤  " JAUNE);
  scanf("%d", axeY);
  (*axeY)--;
  puts("" RESET);
}