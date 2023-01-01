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




}

void ip () {
    char ip[20];
    FILE *ipcmd = popen("echo $(hostname -I | awk '{print $1}')", "r");
    
    fscanf(ipcmd, "%s", ip);
    pclose(ipcmd);

    printf("%s",ip);
 }