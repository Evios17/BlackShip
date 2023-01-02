// Preprocessus principaux
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <signal.h>

// Préprocessus annexes
#include "jeu.h"
#include "couleur.h"

void debug () {
    struct parametre parametre;
    struct jeu jeu;

    parametre.dimension = modeDeSelectionMap();
    parametre.manche =  modeDeSelectionManche();
    int axeX, axeY;
    initialisationTableau(&jeu);
    initialisationBateau(parametre, &jeu);


    //printf("je suis passe par la");


    for (axeX = 0; axeX <= parametre.dimension; axeX++){
      printf(NJAUNE "%d  " RESET, axeX);
    }
    puts("");

    for (axeY = 0; axeY < parametre.dimension; axeY++){
        printf(NJAUNE  "%d  " RESET, axeY + 1);
        
        for (axeX = 0; axeX < parametre.dimension; axeX++){
            printf("%d  ", jeu.tableau[axeX][axeY]);
        }
        puts("");
    }
    puts("");

    commande(&jeu);
    
    //printf("Fin de la fonction debug()\n");
}