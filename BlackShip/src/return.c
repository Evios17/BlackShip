#include <stdio.h>
#include <stdbool.h>

//Palette de couleur
#define RESET               "\x1b[0m"
#define NOIR                "\x1b[30m"
#define NNOIR               "\x1b[1;30m"
#define ROUGE               "\x1b[31m"
#define NROUGE              "\x1b[1;31m"
#define VERT                "\x1b[32m"
#define NVERT               "\x1b[1;32m"
#define JAUNE               "\x1b[33m"
#define NJAUNE              "\x1b[1;33m"
#define BLEU                "\x1b[34m"
#define NBLEU               "\x1b[1;34m"
#define MAGENTA             "\x1b[35m"
#define NMAGENTA            "\x1b[1;35m"
#define CYAN                "\x1b[36m"
#define NCYAN               "\x1b[1;36m"
#define BLANC               "\x1b[37m"
#define NBLANC              "\x1b[1;37m"

//Palette d'arrière plan
#define SROUGE               "\x1b[41m"
#define SVERT                "\x1b[42m"
#define SJAUNE               "\x1b[43m"
#define SBLEU                "\x1b[44m"
#define SMAGENTA             "\x1b[45m"
#define SCYAN                "\x1b[46m"
#define SBLANC               "\x1b[47m"

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