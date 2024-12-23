#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#define N 6
#define M 13

//void checkWin();

void gioco( char matrice[N][M]){

    static int cnt =0;
    static char p;
    int c, r;

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
        printf(" Dimmi le Righe (0,1,2,3,4,5,6): ");
        scanf("%d", &r);  
        printf(" Dimmi le Colonne(0,2,4): ");
        scanf("%d", &c);  
        printf("\n");
    } while(c % 2 != 0 || r % 2 != 0); 

    printf("Hai scelto la riga %d e la colonna %d\n", r, c);
    
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            if(i == r && j == c && matrice[i][j]  == ' '){
                matrice[i][j] = p;
                cnt ++;
            }
        }
    }

    stampa(matrice);
    gioco(matrice);
}
void crea(char matrice[N][M]) {

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i == N - 1) {
                if(( j == 0) || (j == M-1)){
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

void stampa(char matrice[M][M]) { // Funzione che ogni volta stampera la mia matrice aggiornandola con le X o i Oe

    //system("cls"); 
    printf("         FORZA 4\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%c ", matrice[i][j]);
        }
        printf("\n");
    }
}
int main(){

    char matrice[N][M];
    crea(matrice);
    matrice[0][1] = 'c';
    stampa(matrice);
    //gioco(matrice);

}