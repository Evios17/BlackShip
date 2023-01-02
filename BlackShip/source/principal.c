// Préprocessus principaux
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include <unistd.h>

// Préprocessus annexe
#include "jeu.h"
#include "couleur.h"


int main (int argc, char const *argv[]) {
    
    #ifdef _WIN32
        printf(ROUGE"Ce programme n'est pas compatible avec les systèmes Windows\n");
        return EXIT_FAILURE;
    #endif

    int condition1, condition2;                                                                 // Déclaration de variable



    system("clear");                                                                            // Nettoyage du terminal
    
    entete();                                                                                   // Affichage de l'entete

    condition1 = modeDeJeux(); 

    if (condition1 == 1) {                                                                   // Mode solo
        solo();

    } else if (condition1 == 2) {                                                                                    // Mode multi
       condition2 = modeDeSelectionReseau();

       if(condition2 == true){
            client();
        } else {
            serveur();
        }
    } else { /*DEBUG MENU*/
        debug();
    }


    return EXIT_SUCCESS;
}