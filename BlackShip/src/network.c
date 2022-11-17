#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <network.h>

void ip () {
    char ip[20];
    FILE *ipcmd = popen("echo $(hostname -I | awk '{print $1}')", "r");
    
    fscanf(ipcmd, "%s", ip);
    pclose(ipcmd);

    printf("%s",ip);
 }