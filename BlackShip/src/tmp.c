#include <stdio.h>
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <netdb.h>
#include <sys/types.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define SERVEURNAME "127.0.0.1"
#define PORT 30000
#define BUFFERSIZE 512

// COULEURS
#define RESET              "\x1b[0m"
#define BLACK              "\x1b[30m"
#define RED                "\x1b[31m"
#define GREEN              "\x1b[32m"
#define YELLOW             "\x1b[33m"
#define BLUE               "\x1b[34m"
#define MAGENTA            "\x1b[35m"
#define CYAN               "\x1b[36m"
#define WHITE              "\x1b[37m"

int main ( void )
{
char buffer[BUFFERSIZE];
int to_server_socket = -1;
long hostAddr;

struct sockaddr_in serverSockAddr;
struct hostent *serverHostEnt;

bzero(&serverSockAddr,sizeof(serverSockAddr));
hostAddr = inet_addr(SERVEURNAME);
if ( (long)hostAddr != (long)-1)
  bcopy(&hostAddr,&serverSockAddr.sin_addr,sizeof(hostAddr));
else
{
  serverHostEnt = gethostbyname(SERVEURNAME);
  if (serverHostEnt == NULL)
  {
    printf("ca chie gethost\n");
    exit(0);
  }
  bcopy(serverHostEnt->h_addr,&serverSockAddr.sin_addr,serverHostEnt->h_length);
}
serverSockAddr.sin_port = htons(PORT);
serverSockAddr.sin_family = AF_INET;

/* creation de la socket */
if ( (to_server_socket = socket(AF_INET,SOCK_STREAM,0)) < 0)
{
  printf("ca chie creation socket client\n");
  exit(0);
}
/* requete de connexion */
if(connect( to_server_socket,
            (struct sockaddr *)&serverSockAddr,
            sizeof(serverSockAddr)) < 0 )
{
  printf("ca chie demande de connection\n");
  exit(0);
}

/* envoie de donne et reception */
while (1) {
    write(to_server_socket,"Voilà un code très secret qui transite [biloute]",BUFFERSIZE);
    // Je lis la réponse du serveur après une seconde
    sleep(1);
    read(to_server_socket,buffer,BUFFERSIZE);
    printf("... le client a reçu:" MAGENTA " %s" RESET "\n",buffer);
}
/* fermeture de la connection */
shutdown(to_server_socket,2);
close(to_server_socket);

return EXIT_SUCCESS;
}