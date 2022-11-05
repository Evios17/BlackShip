#include <stdio.h>
#include <stdbool.h>
#include "couleur.h"

int main() {
    int x, y, z = false, e = false;
    int t[10][10] = {{0},{0},{0},{0},{0},{0},{0},{0},{0}};
    
    t[8][8] = 2;
    t[4][2] = 1;

    for (y = 0; y <= 9; y++){
        printf(NBLEU  "%d  " RESET, y);
        if(z == false){
            for (x = 1; x <= 9; x++){
                printf(NBLEU "%d  " RESET, x);
            }
            puts("");
            z = true;
        }else{
            for (x = 1; x <= 9; x++){
                if(t[x][y] == 0){
                    printf("•  ");
                }else if(t[x][y] == 1){
                    printf(NCYAN "๑  " RESET);
                }else if(t[x][y] == 2){
                    printf(NROUGE "×  " RESET);
                }else{
                    e = true;
                }
            }
            puts("");
        }
    }

    return 0;
}