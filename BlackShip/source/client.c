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

/* DEBUG SEND ET RECV */
#define snd 1
#define rcv 0


void client () {
    /*int dimension, manche;                                                                                // Initialisation des variables de paramètre
    int tableau1[9][9], tableau2[9][9], bateau[9][9], tir[9][9], axeX, axeY;                                // Initialisation des variables de tableau
    int partie, win, essai, touche, toucheMsg, bateauNombre;*/                                              // Initialisation des variables d'information statistique
    int condition1, condition2, check = 0, check1 = 0, checkno = 0, no;
    char SERVERIP[16], r;
    int socketClient;
    //system("clear");                                                                                        // Nettoyage du terminal


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
        puts(ROUGE"Impossible de se connecter au serveur distant."RESET);                                      // "If" pour savoir si la connexion s'est effectué
        close(socketClient);

        sleep(5);

        for ( int recon = 1 ; recon <= 5 ; recon ++ ) {
            socketClient = socket(AF_INET, SOCK_STREAM, 0);
            if (connect(socketClient, (const struct sockaddr *)&addrClient, sizeof(addrClient)) == -1 ) {
                printf(ROUGE"Tentative de connexion n°%d/5 échouée...\n", recon);
                close(socketClient);

                sleep(5);
            } else {
                recon = 6;
            }
        }
    }
    printf(VERT"Connexion avec le serveur effectuée, génération des bateaux...\n"RESET);

    
    
    
    









    
    

    struct parametre parametre;
    struct jeu jeu;

    char TAMPON[20];
    int inutile; // pour les send et recv après les getchar
    int tmp;



    /* RECEPTION DES PARAMÈTRES DU JEU AU CLIENT */
    recv(socketClient, TAMPON, sizeof(TAMPON), 0);      // recv 1
    sscanf(TAMPON, "%d %d", &parametre.dimension, &parametre.manche);

    

    jeu.mancheCpt = 0;

    do{
        jeu.tour = 56;

        jeu.toucheCpt = 0;
        jeu.essaiCpt = 0;
        jeu.gagner = 0;
        jeu.toucheMsg = 0;

        jeu.essaiCpt = 0;
        jeu.toucheCpt = 0;

        recv(socketClient, &jeu.bateauCpt, sizeof(jeu.bateauCpt), 0);       // recv2
        recv(socketClient, jeu.tableau2, sizeof(jeu.tableau2), 0);                  // recv3
        recv(socketClient, jeu.tableau1, sizeof(jeu.tableau1), 0);                  // recv4

        int deb = 0;                                                    // DEBUG
        
        do{

            //  DEBUG PRE-ENVOI TOUR :
            
            /*
            if (deb == 0) {                                             // DEBUG
                deb = 1;                                                // DEBUG
                printf("\nJe passe deb à 1\n");                         // DEBUG
            } else {                                                    // DEBUG
                recv(socketClient, &inutile, sizeof(&inutile), 0);      // DEBUG
                printf("\nJe reçois inutile = %d\n",inutile);           // DEBUG
            }
            

            printf("\n------\n");                                       // DEBUG

            recv(socketClient, &inutile, sizeof(&inutile), 0);          // DEBUG
            printf("\nINUTILE 10=%d\n",inutile);                        // DEBUG
            recv(socketClient, &inutile, sizeof(&inutile), 0);          // DEBUG
            printf("\nINUTILE 20=%d\n",inutile);                        // DEBUG
            recv(socketClient, &inutile, sizeof(&inutile), 0);          // DEBUG
            printf("\nINUTILE 30=%d\n",inutile);                        // DEBUG
            
            */

            //netdeb(rcv, 5);      // DEBUG
            recv(socketClient, &jeu.tour, sizeof(&jeu.tour), 0);
            //printf("\nTOUR=%d\n",jeu.tour);                             // DEBUG

            //sleep(5);                                                   // DEBUG
            
            inutile = 0;
            
            // Inversion de la variable jeu.tour
            if (jeu.tour == true) {
                jeu.tour = false;
            } else if (jeu.tour == false) {
                jeu.tour = true;
            }


            if (jeu.tour == false) { 
                /* TOUR DU SERVEUR */

                jeu.touchePrf = false;
                
                
                afficheur(multi, parametre, jeu);
                tourMs(jeu);

                //netdeb(rcv, 6);        // DEBUG
                recv(socketClient, TAMPON, sizeof(TAMPON), 0);      // recv 6
                sscanf(TAMPON, "%d %d %d %d %d", &jeu.axeX, &jeu.axeY, &tmp, &jeu.toucheMsg, &jeu.gagner);
                jeu.tableau2[jeu.axeY][jeu.axeX] = tmp;

                afficheur(multi, parametre, jeu);

                toucheMs(jeu);
                //netdeb(rcv, 7);        // DEBUG
                recv(socketClient, &inutile, sizeof(&inutile), 0);   // recv 7
                //netdeb(snd, 8);        // DEBUG
                send(socketClient, &inutile, sizeof(&inutile), 0);   // send 8

            } else {
                /* TOUR DU CLIENT */

                jeu.touchePrf = true;


                do{
                    afficheur(multi, parametre, jeu);
                    tourMs(jeu);

                    commande(&jeu);

                    sprintf(TAMPON, "%d %d", jeu.axeX, jeu.axeY);
                    //netdeb(snd, 9);        // DEBUG
                    send(socketClient, TAMPON, sizeof(TAMPON), 0);          //send9                  
                    
                    recv(socketClient, TAMPON, sizeof(TAMPON), 0);
                    sscanf(TAMPON, "%d %d", &jeu.send, &jeu.toucheMsg);

                    if (jeu.send != true) {
                        toucheMs(jeu);                                                                      // Message qui affiche le résultat du tir
                        getchar();                                                                          // Mange le précédent retour chariot
                        getchar();                                                                          // Attente de la pression d'une touche
                    }  

                } while (jeu.send != true);
                
                

                // Calculateur


                //netdeb(rcv, 10);        // DEBUG
                recv(socketClient, TAMPON, sizeof(TAMPON), 0);          //recv 10
                sscanf(TAMPON, "%d %d %d", &tmp, &jeu.toucheMsg, &jeu.gagner);
                jeu.tableau1[jeu.axeY][jeu.axeX] = tmp;
                
                afficheur(multi, parametre, jeu);
                
                toucheMs(jeu);
                getchar();
                getchar();

                //netdeb(snd, 11);        // DEBUG
                send(socketClient, &inutile, sizeof(&inutile), 0);      // send 11
                //netdeb(rcv, 12);        // DEBUG
                recv(socketClient, &inutile, sizeof(&inutile), 0);      // recv 12
            }

        }while(jeu.gagner != true);
        
        jeu.mancheCpt++;

        afficheur(multi, parametre, jeu);

    }while(jeu.mancheCpt != parametre.manche);

    jeu.gagner = false;
    
    afficheur(multi, parametre, jeu);
}