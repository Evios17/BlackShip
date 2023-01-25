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
    printf("Vous n'êtes pas censé être ici...");
}