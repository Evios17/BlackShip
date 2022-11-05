#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "couleur.h"

int main() {
    int x, y, z = false, e = false, k;
    
    printf("Veuillez entré la taille du tableau : ");
    scanf("%d", &k);
    puts("");

    int t[k][k];
    
    memset(&t,0,sizeof(t));
    //t[8][8] = 2;
    //t[4][2] = 1;
    //t[2][7] = 3;
    //t[4][5] = 4;
    //t[4][6] = 4;

    for (y = 0; y <= k; y++){
        printf(NBLEU  "%d  " RESET, y);
        if(z == false){
            for (x = 1; x <= k; x++){
                printf(NBLEU "%d  " RESET, x);
            }
            puts("");
            z = true;
        }else{
            for (x = 1; x <= k; x++){
                if(t[x][y] == 0){
                    printf("~  ");
                }else if(t[x][y] == 1){
                    printf( "   " );
                }else if(t[x][y] == 2){
                    printf(NVERT "×  " RESET);
                }else if(t[x][y] == 3){
                    printf(NROUGE "×  " RESET);
                }else if(t[x][y] == 4){
                    printf(NCYAN "•  " RESET);
                }else{
                    e = true;
                }
            }
            puts("");
        }
    }

    return 0;
}