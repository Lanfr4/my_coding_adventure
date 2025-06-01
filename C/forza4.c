
#include <stdio.h>
#include<stdlib.h>
#include <time.h>

#define N 6
#define M 21


void checkWin(char matrice[N][M]) {
    
    char winner = ' ';

    // ORIZZONTALE
    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j < M - 6; j++) {
            if (matrice[i][j] != ' ' && matrice[i][j] == matrice[i][j + 2] &&
                matrice[i][j] == matrice[i][j + 4] && matrice[i][j] == matrice[i][j + 6]) {
                winner = matrice[i][j];
            }
        }
    }

    // VERTICALE
    for (int i = N - 1; i >= 6; i--) {
        for (int j = 0; j < M; j++) {
            if (matrice[i][j] != ' ' && matrice[i][j] == matrice[i - 2][j] &&
                matrice[i][j] == matrice[i - 4][j] && matrice[i][j] == matrice[i - 6][j]) {
                winner = matrice[i][j];
            }
        }
    }

    // DIAGONALE NORMALE (↘)
    for (int i = N - 1; i >= 6; i--) {
        for (int j = 0; j < M - 6; j++) {
            if (matrice[i][j] != ' ' && matrice[i][j] == matrice[i - 2][j + 2] &&
                matrice[i][j] == matrice[i - 4][j + 4] && matrice[i][j] == matrice[i - 6][j + 6]) {
                winner = matrice[i][j];
            }
        }
    }

    // DIAGONALE AL CONTRARIO (↙)
    for (int i = N - 1; i >= 6; i--) {
        for (int j = 6; j < M; j++) {
            if (matrice[i][j] != ' ' && matrice[i][j] == matrice[i - 2][j - 2] &&
                matrice[i][j] == matrice[i - 4][j - 4] && matrice[i][j] == matrice[i - 6][j - 6]) {
                winner = matrice[i][j];
            }
        }
    }

    if (winner != ' ') {
        printf("Il vincitore è: %c\n", winner);
        exit(0); // Termina il gioco se c'è un vincitore
    }
}

void gioco( char matrice[N][M]){

    static int cnt =0;
    static char p;
    int c, r, i=0;

    if(cnt>= 10){
        checkWin(matrice);
    }

    if(cnt%2 == 0){
        p = 'O';
    }
    else{
        p = 'X';
    }

    printf("Giocatore dove vuoi inserire la pedina ?\n");

    do { 
        printf(" Dimmi la Colonne dove vuoi inserire il gettone(1,3,5,7,9,11,13,15,17,19): ");
        scanf("%d", &c);  
    }  while (c % 2 == 0 || c > 20|| c < 0);

    for(int i = N; i > 0; i--) {
        if (matrice[i][c] == ' ') {  
                matrice[i][c] = p;       
                break;                   
        }
        if (i == 1) {  
            printf("Non puoi più inserire gettoni qui, devi cambiare colonna\n");
        }
    }
    
    cnt ++;
  
    stampa(matrice);
    gioco(matrice);
}

void crea(char matrice[N][M]) {

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i == N - 1) {
                if (j % 2 == 0) {
                    matrice[i][j] = '|';
                } else {
                    matrice[i][j] = ' ';
                }
            } else {
                if (j % 2 == 0) {
                    matrice[i][j] = '|';
                } else {
                    matrice[i][j] = ' ';
                }
            }
        }
    }
}



void stampa(char matrice[M][M]) { 

    system("cls"); 
    printf("         FORZA 4\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%c", matrice[i][j]);
        }
        printf("\n");
    }
}
int main(){

    char matrice[N][M];

    crea(matrice);
    stampa(matrice);
    gioco(matrice);

}