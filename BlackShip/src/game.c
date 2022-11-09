//Préprocessus principaux
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
//#include <ncurses.h>

//Préprocessus pour socket
#include <string.h>

//Préprocessus annexe
#include <color.h>
#include <game.h>
#include <network.h>




//Partie affichage

void entete(void){
  puts("");
  puts("╔══════════════════════════════════════════════════════════════╗");
  puts("║ V1.1                     " NVERT "BlackShip" RESET "                           ║");
  puts("╠══════════════════════════════════════════════════════════════╣");
  puts("║ " GRIS "Description :" RESET "                                                ║");
  puts("║                                                              ║");
  puts("║ " GRIS " - Bienvenu dans BlackShip, un bataille navale solo ou " RESET "      ║\n║ " GRIS "   multi joueurs jouable dans un terminal en ligne" RESET "           ║");
  puts("║ " GRIS "   de commande." RESET "                                              ║");
  puts("║ " GRIS " - Ce jeu a été réalisé en C dans le cadre d'un projet" RESET "       ║\n║ " GRIS "   d'apprentissage universitaire." RESET "                            ║");
  puts("╚══════════════════════════════════════════════════════════════╝");
  puts("");
}

void afficheur(int dimension){
  int axeX, axeY, bascule = false, pourcentage;
  int tableau[dimension][dimension];
  int bateau[dimension][dimension];

  memset(&tableau,0,sizeof(tableau));

  tableau[8][8] = 2;
  tableau[4][2] = 1;
  tableau[2][7] = 3;
  tableau[4][5] = 4;
  tableau[4][6] = 4;

  memset(&bateau,0,sizeof(bateau));

  srand(time(NULL));

  pourcentage = (dimension * dimension) * 0.17;

  for(int i = 1; i <= dimension; i++){
    axeX = rand() % dimension + 1;
    axeY = rand() % dimension + 1;
    
    bateau[axeX][axeY] =  4;
  }

  system("clear");

  puts("╔══════════════════════════════════════════════════════════════╗");
  puts("║ Score [" NJAUNE "Player 1" RESET " : " NVERT "1" RESET "/" NVERT "3" RESET " | " NBLEU "Player 2" RESET " : " NVERT "0" RESET "/" NVERT "3" RESET "]                      ║");
  puts("╚══════════════════════════════════════════════════════════════╝");
  puts("");

  for (axeY = 0; axeY <= dimension; axeY++){
    printf(NJAUNE  "%d  " RESET, axeY);
    if(bascule == false){
        for (axeX = 1; axeX <= dimension; axeX++){
            printf(NJAUNE "%d  " RESET, axeX);
        }
        puts("");
        bascule = true;
    }else{
        for (axeX = 1; axeX <= dimension; axeX++){
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
  }
  puts("");

  bascule = false;
  
  for (axeY = 0; axeY <= dimension; axeY++){
    printf(NBLEU  "%d  " RESET, axeY);
    if(bascule == false){
        for (axeX = 1; axeX <= dimension; axeX++){
            printf(NBLEU "%d  " RESET, axeX);
        }
        puts("");
        bascule = true;
    }else{
        for (axeX = 1; axeX <= dimension; axeX++){
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
  }
  puts("");

  puts("╔══════════════════════════════════════════════════════════════╗");
  puts("║ Manche [" NVERT "1" RESET "/" NVERT "3" RESET "]                               Tire effectué [" NVERT "6" RESET "] ║");
  puts("╚══════════════════════════════════════════════════════════════╝");
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

void commande(int *axeX, int *axeY){
  puts("Enter the line of fire : ");
  puts("");
  printf("➤  " JAUNE);
  scanf("%d", axeX);
  puts("" RESET);

  puts("Enter the column of fire : ");
  puts("");
  printf("➤  " JAUNE);
  scanf("%d", axeY);
  puts("" RESET);
}



//Partie logique

void initialisationTableau1(int dimension){
  int tableau[dimension][dimension];

  memset(&tableau,0,sizeof(tableau));

  tableau[8][8] = 2;
  tableau[4][2] = 1;
  tableau[2][7] = 3;
  tableau[4][5] = 4;
  tableau[4][6] = 4;
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

void initialisationBateau(int dimension){
  int axeX, axeY, pourcentage;
  int bateau[axeX][axeY];

  memset(&bateau,0,sizeof(bateau));

  srand(time(NULL));

  pourcentage = (dimension * dimension) * 0.17;

  for(int i = 1; i <= dimension; i++){
    axeX = rand() % dimension + 1;
    axeY = rand() % dimension + 1;
    
    bateau[axeX][axeY] =  4;
  }
}



/*int calcul(){
  int x, y, t;

  int bateau = 0;

  if(bateau == true){
    t[x][y] = 2;
  }else{
    t[x][y] = 1;
  }
}

int information(){
  printf("coco");
}*/