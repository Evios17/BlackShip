//Préprocessus principaux
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <stdbool.h>

//Préprocessus annexe
#include "jeu.h"
#include "couleur.h"


void client () {
    /*int dimension, manche;                                                                                // Initialisation des variables de paramètre
    int tableau1[9][9], tableau2[9][9], bateau[9][9], tir[9][9], axeX, axeY;                                // Initialisation des variables de tableau
    int partie, win, essai, touche, toucheMsg, bateauNombre;*/                                              // Initialisation des variables d'information statistique
    int condition1, condition2, check = 0, check1 = 0, checkno = 0, no;
    char SERVERIP[16], r;
    int socketClient;
    //system("clear");
    
    int mode = 2;                                                                                        // Nettoyage du terminal


  /* DEMANDE D'ADRESSE IP DU SERVEUR */

    while (check == 0) {                                                                                      // Demande de saisie de l'IP du serveur
        if (checkno == 1) {check1 = 0;}

        system("clear");
        entete();

        puts("Entrez l'adresse du serveur :");
        puts("");
        printf("➤  "JAUNE);
        scanf("%16s",SERVERIP);
        puts(RESET);

        if (r != '\n') {                                                                                    // Permet de "manger" les caractères en trop pour éviter la répétion du switch case
        while ((no = getchar()) != '\n');
        }

            while (check1 == 0) {                                                                             // Switch case de confirmation de syntaxe
                system("clear");
                entete();

                puts("Vous avez bien tapé l'adresse ? (Y/n) ");
                puts("");
                printf("➤  "JAUNE);
                scanf("%c",&r);
                puts(RESET);
                
                if (r != '\n') {
                while ((no = getchar()) != '\n');
                }
                
                    printf("\n");

                    switch (r) {
                        case '\n' :
                        case 'Y' :
                        case 'y' :
                            check = 1;
                            check1 = 1;
                        break;
                        case 'N' :
                        case 'n' :
                            check1 = 1;
                            checkno = 1;
                        break;
                        default :
                            puts(ROUGE "[Erreur] Merci de rentrer une réponse valide (y ou n)" RESET);
                            puts("");
                        break;
                    }
            }
        }

    system("clear");
    entete();

    puts("Tentative de connexion au serveur en cours...");
    puts("");


    /* INITIALISATION DES SOCKETS (CLIENT) */


    memset(&socketClient,0,sizeof(socketClient));                                                           // Mise à zéro du socket du client
    socketClient = socket(AF_INET, SOCK_STREAM, 0);                                                         // Création du socket IPV4, TCP, ?
    struct sockaddr_in addrClient;                                                                          // Structure de l'ip du serveur pour le socket
    addrClient.sin_addr.s_addr = inet_addr(SERVERIP);                                                       // IP du serveur
    addrClient.sin_family = AF_INET;                                                                        // IPV4
    addrClient.sin_port = htons(30000);                                                                     // Port du serveur
    if (connect(socketClient, (const struct sockaddr *)&addrClient, sizeof(addrClient)) == -1 ) {           // Connexion au socket du serveur
        puts(ROUGE"Impossible de se connecter au socket distant."RESET);                                    // "If" pour savoir si la connexion s'est effectué
        exit(EXIT_FAILURE);
    }
    printf(VERT"Connexion avec le serveur effectuée.\n"RESET);



    struct parametre parametre;
    struct jeu jeu;

    char TAMPON[20];

    recv(socketClient, TAMPON, sizeof(TAMPON), 0);
    sscanf(TAMPON, "%d %d", &parametre.dimension, &parametre.manche);

    

    jeu.mancheCpt = 0;

    int joueur1;
    int joueur2;

    int toucheCpt1;
    int essaiCpt1;

    int toucheCpt2;
    //int essaiCpt2;
    //int bateauCpt2;

    int tableau1[9][9];
    int tableau2[9][9];

    do{
        jeu.toucheCpt = 0;
        jeu.essaiCpt = 0;
        jeu.gagner = 0;
        jeu.toucheMsg = 0;

        recv(socketClient, &jeu.bateauCpt, sizeof(jeu.bateauCpt), 0);
        recv(socketClient, tableau2, sizeof(tableau2), 0);
        recv(socketClient, tableau1, sizeof(tableau1), 0);

        do{
            
            //recv(socketClient, tour, sizeof(tour), 0);

            if (jeu.tour == true) {
                memcpy(jeu.tableau1, tableau1, sizeof(jeu.tableau1));
                memcpy(jeu.tableau2, tableau2, sizeof(jeu.tableau2));

                toucheMs(jeu);
                afficheur(mode, parametre, jeu);
                commande(&jeu);
                
                afficheur(mode, parametre, jeu);
            } else {
                memcpy(jeu.tableau1, tableau1, sizeof(jeu.tableau1));
                memcpy(jeu.tableau2, tableau2, sizeof(jeu.tableau2));

                toucheMs(jeu);
                afficheur(mode, parametre, jeu);
                commande(&jeu);
                
                afficheur(mode, parametre, jeu);
            }
            

        }while(jeu.gagner != true);
        
        jeu.mancheCpt++;

        afficheur(mode, parametre, jeu);
        sleep(2);

    }while(jeu.mancheCpt != parametre.manche);
    jeu.gagner = false;
    afficheur(mode, parametre, jeu);




    /*char msg[50];

    recv(socketClient, msg, sizeof(msg), 0);

    printf("%s\n",msg);

    int number[5][5];
    number[5][2] = 9;
    char BUFFER[50];

    int a, b;

    recv(socketClient, BUFFER, sizeof(BUFFER), 0);
    sscanf(BUFFER,"%d %d",&a,&b);

    printf("%d\n",number[a][b]);*/






    puts("Fin de la communication.");
}