#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#define M 5

void crea(char matrice[M][M]){ // Funzione cha crea la matrice iniziale

    // Creazione della matrice
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            if (j % 2 == 0 && i % 2 == 0) {
                matrice[i][j] = ' ';
            } else {
                if (j % 2 == 1) {
                    matrice[i][j] = '|';
                }
                if (i % 2 == 1) {
                    matrice[i][j] = '-';
                }
            }
        }
    }
}
void stampa(char matrice[M][M]) { // Funzione che ogni volta stampera la mia matrice aggiornandola con le X o i Oe

    system("cls"); 
    // Qui ci sarà il campo di gioco che si aggiornerà ogni volta
    printf("  TRIS\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            printf("%c ", matrice[i][j]);
        }
        printf("\n");
    }
}
void gioco( char matrice[M][M]){ // Funzione che è alla base del mio gioco( posizionamento dei simboli, e richiamo alla funzione che ogni volta stampa la matrice) 

    static char p;
    static int cnt = 0;
    static int r =0,c =0;
    int i=0, j=0;
    // Dopo 5 mosse ci potrebbe essere un vincitore :)
    // Dunque andiamo a controllare se c'e :O......;
    
    if(cnt >=5 ){
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
        printf(" Dimmi le Righe (0,2,4): ");
        scanf("%d", &r);  
        printf(" Dimmi le Colonne(0,2,4): ");
        scanf("%d", &c);  
        printf("\n");
    } while(c % 2 != 0 || r % 2 != 0); 

    printf("Hai scelto la riga %d e la colonna %d\n", r, c);
    
    for(i=0;i<M;i++){
        for(j=0;j<M;j++){
            if(i == r && j == c && matrice[i][j]  == ' '){
                matrice[i][j] = p;
                cnt ++;
            }
        }
    }

    stampa(matrice);
    gioco(matrice);

}
 
void checkWin(char matrice[M][M]) {
    //ORRIZZONATLI
    for (int i = 0; i < M; i++) {
        if (matrice[i][0] == matrice[i][2] && matrice[i][2] == matrice[i][4]) {
            if (matrice[i][0] == 'X') {
                printf("Giocatore 2 ha vinto!!!\n");
                exit(0);  
            } 
            else if (matrice[i][0] == 'O') {
                printf("Giocatore 1 ha vinto!!!!\n"); 
                exit(0); 
            }
        }
    }
    //VERTICALI
    for (int i = 0; i < M; i++) {
        if (matrice[0][i] == matrice[2][i] && matrice[2][i] == matrice[4][i]) {
            if (matrice[0][i] == 'X') {
                printf("Giocatore 2 ha vinto!!!\n");
                exit(0);  
            } else if (matrice[0][i] == 'O') {
                printf("Giocatore 1 ha vinto!!!!\n");
                exit(0); 
            }
        }
    }
    // DIAGONALE
    if (matrice[0][0] == matrice[2][2] && matrice[2][2] == matrice[4][4]) {
        if (matrice[0][0] == 'X') {
            printf("Giocatore 2 ha vinto!!!\n");
            exit(0);   
        } else if (matrice[0][0] == 'O') {
            printf("Giocatore 1 ha vinto!!!!\n");
            exit(0);   
        }
    }
    //DIAGONALE
    if (matrice[0][4] == matrice[2][2] && matrice[2][2] == matrice[4][0]) {
        if (matrice[0][4] == 'X') {
            printf("Giocatore 2 ha vinto!!!\n");
            exit(0);
        } else if (matrice[0][4] == 'O') {
            printf("Giocatore 1 ha vinto!!!!\n");
            exit(0); 
        }
    }
    printf("Nessuno dei due giocatori ha vinto\n");
}
int main() {

    char matrice[M][M];

    crea(matrice);
    stampa(matrice);
    //printf("Il primo a giocare avra gli O mente il secondo le X , capito?\n\n\");
    gioco(matrice);

}
