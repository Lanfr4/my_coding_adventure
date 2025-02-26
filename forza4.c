#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#define N 6
#define M 21

//void checkWin();

void gioco( char matrice[N][M]){

    static int cnt =0;
    static char p;
    int c, r, i=0;
/*
    if(cnt>= 10){
        checkWin(matrice);
    }*/

    if(cnt%2 == 0){
        p = 'O';
    }
    else{
        p = 'X';
    }

    printf("Giocatore dove vuoi inserire la pedina ?\n");

    do { 
        printf(" Dimmi la Colonne dove vuoi inserire il gettone(1,3,5,7,9,11): ");
        scanf("%d", &c);  
    }  while (c % 2 == 0 || c > 11 || c < 1);
  
    
    

    //stampa(matrice);
    //gioco(matrice);
}
void crea(char matrice[N][M]) {

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i == N - 1) {
                if(j %2 == 0){
                    matrice[i][j] = '|';
                }
                else{
                   matrice[i][j] = '_';  
                }
            }
             
            else if (j % 2 == 0) {
                matrice[i][j] = '|';  
            } 

            else {
                matrice[i][j] = ' '; 
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