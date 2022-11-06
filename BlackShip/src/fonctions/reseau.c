#include <reseau.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void ip () {
    FILE *file;
    int c;

    system("echo $(hostname -I | awk '{print $1}') > ip.tmp");
    file = fopen("ip.tmp", "r");

    while ((c = fgetc(file)) != EOF)
    {
        printf("%c", c);
    }
    fclose(file);
    remove("ip.tmp");    
}

int chk_w () {
    FILE *chk;
    chk = fopen ("check", "w");
    remove("check");
    if (chk == NULL) {
        return false;
    } else {
        return true;
    }
}