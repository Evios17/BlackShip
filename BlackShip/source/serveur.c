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


















    char TAMPON[20];
    int inutile; // pour  les send et recv après les getchar
    



    /* ENVOIE DES PARAMÈTRES DU JEU AU CLIENT */
    sprintf(TAMPON, "%d %d", parametre.dimension, parametre.manche);
    send(socketClient, TAMPON, sizeof(TAMPON), 0);                                                  // send 1 : Envoie du tampon contenant les paramètres du jeu
    
    
    
    jeu.mancheCpt = 0;

    int essaiCpt1;
    int toucheCpt1;
    
    int essaiCpt2;
    int toucheCpt2;

    do {
        jeu.tour = true;

        jeu.toucheCpt = 0;
        jeu.essaiCpt = 0;
        jeu.gagner = 0;
        jeu.toucheMsg = 0;

        essaiCpt1 = 0;
        toucheCpt1 = 0;

        essaiCpt2 = 0;
        toucheCpt2 = 0;

        initialisationTableau(parametre, &jeu);                                                     // Initialisation du premier tableau
        memcpy(jeu.tableau1, jeu.tableauTmp, sizeof(jeu.tableau1));                                 // Copie du tableau généré dans le tableau 1 (serveur)
        sleep(2);                                                                                   // Attente de 2 secondes pour laisse le srand() changer de valeur
        initialisationTableau(parametre, &jeu);                                                     // Initialisation du deuxième tableau
        memcpy(jeu.tableau2, jeu.tableauTmp, sizeof(jeu.tableau2));                                 // Copie du tableau généré dans le tableau 2 (client)

        /* ENVOIE DES PARAMÈTRES DU JEU AU CLIENT */
        send(socketClient, &jeu.bateauCpt, sizeof(jeu.bateauCpt), 0);                               // send 2 : Envoie du nombre de bateaux 
        send(socketClient, jeu.tableau1, sizeof(jeu.tableau1), 0);                                  // send 3 : Envoie du tableau du serveur
        send(socketClient, jeu.tableau2, sizeof(jeu.tableau2), 0);                                  // send 4 : Envoie du tableau du client
        
        do {
            
            sprintf(TAMPON, "%d", jeu.tour);
            send(socketClient, TAMPON, sizeof(TAMPON), 0);                                          // send 5 : Envoie du tampon contenant la variable de tour
            
            //send(socketClient, &jeu.tour, sizeof(&jeu.tour), 0);
            
            if (jeu.tour == true) {                                                                 // Test pour savoir c'est le tour à qui
                /* TOUR DU SERVEUR */

                jeu.touchePrf = true;                                                               // Définie le profil de message affiché (ici "serveur")

                jeu.essaiCpt = essaiCpt1;
                jeu.toucheCpt = toucheCpt1;

                memcpy(jeu.tableauTmp, jeu.tableau1, sizeof(jeu.tableauTmp));

                afficheur(multi, parametre, jeu);                                                   // Affiche les tableaux

                commande(&jeu);                                                                     // Entrée des coordonnées d'attaque
                
                calculateur(multi, &jeu);                                                           // Comparaison des coordonées reçues et changements de variable

                memcpy(jeu.tableau1, jeu.tableauTmp, sizeof(jeu.tableau1));                         // Copie du tableau du serveur dans le tableau tampon

                essaiCpt1 = jeu.essaiCpt;
                toucheCpt1 = jeu.toucheCpt;

                if (jeu.send == true) {                                                             // Test pour savoir si le serveur a touché un bateau
                    int tmp = jeu.tableau1[jeu.axeY][jeu.axeX];
                    
                    sprintf(TAMPON, "%d %d %d %d",jeu.axeX, jeu.axeY, tmp, jeu.toucheMsg);       // X=axeX Y=axeY V=tableau[axeY][axeX] ; Insertion des coordonnées et du message de touche dans le tampon
                    send(socketClient, TAMPON, sizeof(TAMPON), 0);                                  // send 6 : Envoie du tempon contenant les coordonées et du message de touche
                }
                
                afficheur(multi, parametre, jeu);                                                   // Affiche les tableaux
                toucheMs(jeu);                                                                      // Message qui affiche le résultat du tir
                getchar();                                                                          // Mange le précédent retour chariot
                getchar();                                                                          // Attente de la pression d'une touche
                send(socketClient, &inutile, sizeof(&inutile), 0);                                  // send 7 : Accusé reception pour mettre en pause le code du côté serveur et client
                recv(socketClient, &inutile, sizeof(&inutile), 0);                                  // recv 8 : Accusé reception pour mettre en pause le code du côté serveur et client
                //printf("\nINUTILE RECV = %d\n", inutile);                               // DEBUG
                //printf("Je dois reçevoir \"69\"\n");                                    // DEBUG

            } else {
                /* TOUR DU CLIENT */

                jeu.touchePrf = false;                                                              // Définie le profil de message affiché (ici "client")

                jeu.essaiCpt = essaiCpt1;
                jeu.toucheCpt = toucheCpt1;

                memcpy(jeu.tableauTmp, jeu.tableau2, sizeof(jeu.tableauTmp));

                afficheur(multi, parametre, jeu);                                                   // Affiche les tableaux

                jeu.essaiCpt = essaiCpt2;
                jeu.toucheCpt = toucheCpt2;

                recv(socketClient, TAMPON, sizeof(TAMPON), 0);                                      // Reçeption des coordonées de la part du client
                sscanf(TAMPON, "%d %d", &jeu.axeX, &jeu.axeY);                                      // Extraction des coordonées du tampon

                calculateur(multi, &jeu);
                
                memcpy(jeu.tableau2, jeu.tableauTmp, sizeof(jeu.tableau2));                         // Copie du tableau temporaire vers le tableau du client

                essaiCpt2 = jeu.essaiCpt;
                toucheCpt2 = jeu.toucheCpt;
                
                jeu.essaiCpt = essaiCpt1;
                jeu.toucheCpt = toucheCpt1;

                int tmp = jeu.tableauTmp[jeu.axeY][jeu.axeX];

                sprintf(TAMPON, "%d %d", tmp, jeu.toucheMsg);         // X=axeX Y=axeY V=tableau[axeY][axeX]
                send(socketClient, TAMPON, sizeof(TAMPON), 0);                                      // send 10 : Envoie du tampon contenu le résultat de l'attaque

                afficheur(multi, parametre, jeu);                                                   // Affiche les tableaux
                
                if (jeu.toucheMsg == 1 || jeu.toucheMsg == 2) {                                     // Test de condition
                    toucheMs(jeu);
                    recv(socketClient, &inutile, sizeof(inutile), 0);                               // recv 11 : Accusé reception pour mettre en pause le code du côté serveur et client
                    send(socketClient, &inutile, sizeof(inutile), 0);                               // send 12 : Accusé reception pour mettre en pause le code du côté serveur et client

                }
            }

        } while (jeu.gagner != true);
        
        jeu.mancheCpt++;                                                                            // Incrémente la manche

        afficheur(multi, parametre, jeu);
        sleep(2);

    }while(jeu.mancheCpt != parametre.manche);

    jeu.gagner = false;

    afficheur(multi, parametre, jeu);

}

void ip () {
    char ip[20];
    FILE *ipcmd = popen("echo $(hostname -I | awk '{print $1}')", "r");
    
    fscanf(ipcmd, "%s", ip);
    pclose(ipcmd);

    printf("%s",ip);
 }