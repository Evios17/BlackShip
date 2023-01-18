// Préprocessus principaux
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

// Préprocessus annexe
#include "jeu.h"
#include "couleur.h"


int main (int argc, char const *argv[]) {
    
    #ifdef _WIN32
        printf(ROUGE"Ce programme n'est pas compatible avec les systèmes Windows\n");
        return EXIT_FAILURE;
    #endif

    int opt, arg;

    if ( argc > 2 ) {                                                                                           // Teste les options reçu dans le main
        puts(ROUGE"Syntaxe incorrecte"RESET);
        puts("Utilisation :");
        puts("-s\t -- Active le mode serveur");
        puts("-c\t -- Active le mode client");
        exit(EXIT_FAILURE);
    }
    else {
        while ((opt = getopt (argc, argv, ":oschv")) != -1) {
            switch (opt) {
                case 'o' :                                                                                            // -s : active le mode "serveur"
                    solo();
                    arg = true;
                    break;
                case 's' :                                                                                            // -s : active le mode "serveur"
                    serveur();
                    arg = true;
                    break;
                case 'c' :                                                                                            // -c : active le mode "client"
                    client();
                    arg = true;
                    break;
                case 'h' :                                                                                            // -h : affiche l'aide
                    puts("Utilisation :");
                    puts("-o\t -- Active le mode solo");
                    puts("-s\t -- Active le mode serveur");
                    puts("-c\t -- Active le mode client");
                    puts("-v\t -- Affiche la version du programme");
                    exit(EXIT_SUCCESS);
                    break;
                case 'v':                                                                                            // -v : affiche la version
                    puts("Blackship v1.0, SAE105 | Fait par Antoine, Lukas et Cylian");
                    exit(EXIT_SUCCESS);
                    break;
                default :                                                                                            // Affiche l'aide quand l'utilisateur entre un argument non-existant
                    puts(ROUGE"Syntaxe incorrecte"RESET);
                    puts("Utilisation :");
                    puts("-o\t -- Active le mode solo");
                    puts("-s\t -- Active le mode serveur");
                    puts("-c\t -- Active le mode client");
                    puts("-v\t -- Affiche la version du programme");
                    exit(EXIT_FAILURE);
            }
        }
    }


    if ( arg == true ) {
        return(EXIT_SUCCESS);
    }


    int condition1, condition2;                                                                 // Déclaration de variable


    system("clear");                                                                            // Nettoyage du terminal
    
    entete();                                                                                   // Affichage de l'entête

    condition1 = modeDeJeux(); 

    if (condition1 == 1) {                                                                   // Mode solo
        solo();

    } else if (condition1 == 2) {                                                            // Mode multi
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