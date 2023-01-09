#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <couleur.h>

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
        if(z == true){
            for (x = 1; x <= k; x++){
                switch(t[x][y]){
                    case 0 :
                        printf("~  ");
                        break;
                    case 1 :
                        printf( "   " );
                        break;
                    case 2 :
                        printf(NVERT "×  " RESET);
                        break;
                    case 3 :
                        printf(NROUGE "×  " RESET);
                        break;
                    case 4 :
                        printf(NCYAN "•  " RESET);
                        break;
                    default:
                        printf("~  ");
                        break;
                }
            }
            puts("");
        }else{
            for (x = 1; x <= k; x++){
                printf(NBLEU "%d  " RESET, x);
            }
            puts("");
            z = true;
        }
    }

    return 0;
}