#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>                     
#include <sys/socket.h>
#include <netinet/in.h>       
#include <arpa/inet.h>
#include <signal.h>

#define FFLUSH_MY_STDIN() {int _c_; while ((_c_ = getchar()) != '\n' && _c_ != EOF){}} 
#define BUFFERSIZE 512
#define PORT 30000

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

void deroute (int sig);

int main ( void )
{
char *reponse = "Merci j'ai bien reçu votre message [super biloute]";
char buffer[BUFFERSIZE];
unsigned int mon_address_longueur;
int client_socket, ma_socket;
int num=0; // Le numéro du client

struct sockaddr_in mon_address, client_address;
struct sigaction action;  

// Gestion de SIGINT (CTRL-C) et de SIGCHLD
/* Mise à zéro des champs de la structure "action" */
memset (&action, 0, sizeof(struct sigaction));  
action.sa_handler = deroute;                /* La fonction qui est appelée quand un signal arrive */
action.sa_flags = 0;
sigemptyset(&(action.sa_mask));
sigprocmask(SIG_SETMASK, &action.sa_mask, NULL); /* On applique le mask en beauté :) */
sigaction (SIGINT, &action, NULL);          /* Installation d'un gestionnaire pour "SIGINT" */
sigaction (SIGCHLD, &action, NULL);         /* Installation d'un gestionnaire pour "SIGCHLD" */

// Zone mémoire à zéro
memset(&mon_address,0,sizeof(mon_address));
mon_address.sin_port = htons(PORT);
mon_address.sin_family = AF_INET;
mon_address.sin_addr.s_addr = htonl(INADDR_ANY);

/* creation de socket */
if ((ma_socket = socket(AF_INET,SOCK_STREAM,0))== -1)
{
  printf("ca chie avec la creation\n");
  exit(0);
}
/* bind serveur - socket */
bind(ma_socket,(struct sockaddr *)&mon_address,sizeof(mon_address));

/* ecoute sur la socket */
listen(ma_socket,5);

/* accept la connexion */
mon_address_longueur = sizeof(client_address);

while(1)
{
    client_socket = accept(ma_socket,
                         (struct sockaddr *)&client_address,
                         &mon_address_longueur);
    num++;
    if (fork() == 0)
    {
        close(ma_socket);
        
        printf("\nConnexion [%d] avec le client (processus fils PID=%d et père PID=%d)\n",num,getpid(),getppid());

        while (1) {
            if (read(client_socket,buffer, BUFFERSIZE)<=0)
            {
                fprintf(stderr,"Unable to read \n");
                perror("read()");
                break;
            }
        
            printf("... le serveur a recu:" RED " %s" RESET "\n",buffer);

            // Je réponds après une seconde
            sleep(1);
            if (write(client_socket,reponse,BUFFERSIZE)<=0)
            {
                    fprintf(stderr,"Unable to write \n");
                    perror("write()");
                    break;
            }
        }
        shutdown(client_socket,2);
        close(client_socket);
        printf ("Terminaison connexion [%d] (processus fils PID=%d et père PID=%d)\n",num,getpid(),getppid());
        return EXIT_SUCCESS;
    }
}

shutdown(ma_socket,2);
close(ma_socket);

return EXIT_SUCCESS;
}


/*
 * Lorsque SIGINT arrive la fonction deroute() demande
 * si on veut réellement stopper le serveur !
 * Dès qu'un processus fils meure on le termine rééllement
 */
void deroute(int sig)                         
{    int c;    
     if (sig==SIGCHLD) {
        printf ("Terminaison du processus fils : %d\n",wait(NULL));
        exit(EXIT_SUCCESS); 
     }
     else if (sig==SIGINT) {
        printf (GREEN "\tLe signal %s=%d a été reçu !\n",sys_siglist[sig],sig);
        printf(RED "\tOUUPPPSS, vous avez tapé Ctrl-C?\n"
                "\tVoulez-vous réellement quitter ? [y/n]" RESET "\n");
        c = getchar();     
        FFLUSH_MY_STDIN(); /* vider le tampon clavier en utilisant notre macro */

        if (c == 'y' || c == 'Y') {            
            kill(-getppid(), SIGTERM); // Tue le père et tous les autres.
            exit(EXIT_SUCCESS);
        }
    }
}