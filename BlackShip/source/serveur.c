// Préprocessus
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

#include "jeu.h"
#include "couleur.h"

void serveur () {

    char TAMPON[20];
    struct parametre parametre;
    struct jeu jeu;


    system("clear");
    entete();

    parametre.dimension = modeDeSelectionMap();
    parametre.manche =  modeDeSelectionManche();

    system("clear");
    entete();

    printf("Voici l'adresse IP de votre serveur : " JAUNE);
    ip();
    puts("" RESET);


    puts("En attente d'une connection entrente...");
    puts("");


    /* INITIALISATION DES SOCKETS (SERVEUR)*/


    int socketClient, socketServer;
    memset(&socketServer,0,sizeof(socketServer));                                                           // Mise à zéro du socket Server
    memset(&socketClient,0,sizeof(socketClient));                                                           // Mise à zéro du socket Client

    socketServer = socket(AF_INET, SOCK_STREAM, 0);                                                         // Création du socket du serveur IPV4, TCP
    struct sockaddr_in addrServer;                                                                          // Structure de l'IP du serveur pour le socket
    addrServer.sin_addr.s_addr = htonl(INADDR_ANY);                                                         // Définition de de l'ip d'écoute: "htonl(INADDR_ANY)" pour ne pas définir d'ip spécifique au socket
    addrServer.sin_family = AF_INET;                                                                        // IPV4
    addrServer.sin_port = htons(30000);                                                                     // Définition du port
    bind(socketServer, (const struct sockaddr *)&addrServer, sizeof(addrServer));                           // Assignation du socket
    listen(socketServer, 1);                                                                                // Écoute sur le socket

    struct sockaddr_in addrClient;                                                                          // Structure pour le socket du client
    socklen_t csize = sizeof(addrClient);                                                                   // Définition de la taille des paramètres pour le socket du client
    socketClient = accept(socketServer, (struct sockaddr *)&addrClient, &csize);                            // Attente de connexion auprès du client

    puts(VERT "Client connecté, génération des bateaux..." RESET);


    /* ENVOIE DES PARAMÈTRES DU JEU AU CLIENT */
    sprintf(TAMPON, "%d %d", parametre.dimension, parametre.manche);
    send(socketClient, TAMPON, sizeof(TAMPON), 0);
    
    
    int inutile; // pour  les send et recv après les getchar
    
    jeu.mancheCpt = 0;

    int joueur1;
    int joueur2;

    int essaiCpt;
    
    int toucheCpt;

    int tableau1[9][9];
    int tableau2[9][9];

    do {
        jeu.tour = true;
        jeu.toucheCpt = 0;
        jeu.essaiCpt = 0;
        jeu.gagner = 0;
        jeu.toucheMsg = 0;

        essaiCpt = 0;
        
        toucheCpt = 0;

        initialisationTableau(parametre, &jeu);
        memcpy(tableau1, jeu.tableau1, sizeof(tableau1));
        sleep(2);
        initialisationTableau(parametre, &jeu);
        memcpy(tableau2, jeu.tableau1, sizeof(tableau2));

        /* ENVOIE DES PARAMÈTRES DU JEU AU CLIENT */
        send(socketClient, &jeu.bateauCpt, sizeof(jeu.bateauCpt), 0);
        send(socketClient, tableau1, sizeof(tableau1), 0);
        send(socketClient, tableau2, sizeof(tableau2), 0);
        
        do {
            send(socketClient, &jeu.tour, sizeof(jeu.tour), 0);
            
            if (jeu.tour == true) {
                jeu.toucheCpt = toucheCpt;
                jeu.essaiCpt = essaiCpt;

                memcpy(jeu.tableau1, tableau1, sizeof(jeu.tableau1));
                memcpy(jeu.tableau2, tableau2, sizeof(jeu.tableau2));
                

                jeu.touchePrf = true;
                //toucheMs(jeu);
                afficheur(multi, parametre, jeu);
                commande(&jeu);
                
                calculateur(multi, &jeu);

                essaiCpt = jeu.essaiCpt;
                toucheCpt = jeu.toucheCpt;

                memcpy(tableau1, jeu.tableau1, sizeof(tableau1));

                if (jeu.send == true) {
                    sprintf(TAMPON, "%d %d %d %d",jeu.axeX,jeu.axeY,tableau1[jeu.axeX][jeu.axeY], jeu.toucheMsg);
                    send(socketClient, TAMPON, sizeof(TAMPON), 0);
                    // X=axeX Y=axeY V=tableau[axeY][axeX]
                }
                
                afficheur(multi, parametre, jeu);
                toucheMs(jeu);
                getchar();
                getchar();
                send(socketClient, &inutile, sizeof(&inutile), 0);
                recv(socketClient, &inutile, sizeof(&inutile), 0);

                if (jeu.send == true) {
                    if (jeu.tour == true) {
                        jeu.tour = false;
                    } else {
                        jeu.tour = true;
                    }
                }
            } else {
                memcpy(jeu.tableau1, tableau1, sizeof(jeu.tableau1));
                memcpy(jeu.tableau2, tableau2, sizeof(jeu.tableau2));
                
                
                jeu.touchePrf = false;
                //toucheMs(jeu);
                afficheur(multi, parametre, jeu);

                recv(socketClient, TAMPON, sizeof(TAMPON), 0);
                sscanf(TAMPON, "%d %d %d %d", &jeu.axeX, &jeu.axeY, &jeu.toucheCpt, &jeu.essaiCpt);

                memcpy(jeu.tableau1, tableau2, sizeof(jeu.tableau1));
                
                calculateur(multi, &jeu);
                
                sprintf(TAMPON, "%d %d %d %d %d %d",jeu.axeX,jeu.axeY,tableau1[jeu.axeX][jeu.axeY], jeu.toucheCpt, jeu.toucheMsg, jeu.essaiCpt);
                send(socketClient, TAMPON, sizeof(TAMPON), 0);
                // X=axeX Y=axeY V=tableau[axeY][axeX]

                memcpy(tableau2, jeu.tableau1, sizeof(tableau2));
                memcpy(jeu.tableau2, jeu.tableau1, sizeof(jeu.tableau2));
                memcpy(jeu.tableau1, tableau1, sizeof(jeu.tableau1));

                afficheur(multi, parametre, jeu);
                if (jeu.toucheMsg == 1 || jeu.toucheMsg == 2) {
                    toucheMs(jeu);
                    recv(socketClient, &inutile, sizeof(inutile), 0);
                    send(socketClient, &inutile, sizeof(inutile), 0);
                }
                

                if (jeu.tourTog == true) {
                    if (jeu.tour == true) {
                        jeu.tour = false;
                    } else {
                        jeu.tour = true;
                    }
                }
            }

        } while (jeu.gagner != true);
        
        jeu.mancheCpt++;

        afficheur(multi, parametre, jeu);
        sleep(2);

    }while(jeu.mancheCpt != parametre.manche);

    jeu.gagner = false;

    afficheur(multi, parametre, jeu);

    /*char msg[50] = "j'aime les chenilles";

    send(socketClient, msg, sizeof(msg), 0);

    puts("Message envoyé.");

    int number[5][5];

    int a = 5, b = 2;
    char BUFFER[50];

    sprintf(BUFFER,"%d %d",a,b);
    send(socketClient, BUFFER, sizeof(BUFFER), 0);*/



}

void ip () {
    char ip[20];
    FILE *ipcmd = popen("echo $(hostname -I | awk '{print $1}')", "r");
    
    fscanf(ipcmd, "%s", ip);
    pclose(ipcmd);

    printf("%s",ip);
 }