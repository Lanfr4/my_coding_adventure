#include <stdio.h>
#include<stdlib.h>
#include <time.h>

#define N 6
#define M 21


void checkWin(char matrice[N][M]) {
    
    char winner =' ';
    // la variabile serve per vedere se effettivamente 
    //c'e un vincitore che verra verificato in un if-else alla fine di tutto

    // ORRIZZONTALE
    for(int i=0; i<N ;  i++){
        for( int j=0; j <M-4 ; j++){
            if(matrice[i][j] != ' ' && 
                matrice[i][j] == matrice[i][j+1] && 
                matrice[i][j] == matrice[i][j+2] &&
                matrice[i][j] == matrice[i][j+3] ){
                winner = matrice[i][j];
            }

        }
    }

    // VERTICALE
    for(int j=0; j<M;j++){
        for(int i=0;i< N-4;i++){
            if(matrice[i][j] != ' ' && 
                matrice[i][j] == matrice[i+1][j] && 
                matrice[i][j] == matrice[i+2][j] &&
                matrice[i][j] == matrice[i+3][j] ){
                winner = matrice[i][j];
            }
        }
    }

    // DIAGONALE NORMALE
    for(int i=0; i<N;  i++){
        for( int j=0; j <M-4 ; j++){
            if(matrice[i][j] != ' ' && 
                matrice[i][j] == matrice[i+1][j+1] && 
                matrice[i][j] == matrice[i+2][j+2] &&
                matrice[i][j] == matrice[i+3][j+3] ){
                winner = matrice[i][j];
            }

        }
    }
    // DIAGONALE AL CONTRARIO 
    for(int i= N; i< 4 ;  i--){
        for( int j=M; j > 4 ; j--){
            if(matrice[i][j] != ' ' && 
                matrice[i][j] == matrice[i-1][j-1] && 
                matrice[i][j] == matrice[i-2][j-2] &&
                matrice[i][j] == matrice[i-3][j-3] ){
                winner = matrice[i][j];
            }

        }
    }

   if(winner == 'X'){
    printf("Giocatore 1 hai vinto!!!");
   }
   else{
    printf("Giocatore 2 hai vinto!!!");
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