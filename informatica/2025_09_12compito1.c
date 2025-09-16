/*Data una matrice di valori casuali scambiare gli elementi della diagonale 
principale con la diagonale secondaria.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RIGHE 3
#define COLONNE 3

void riempiMatriceCasuale(int mat[][COLONNE], int righe, int colonne){
    for(int i=0; i<righe; i++){
        for(int j=0; j<colonne; j++){
            mat[i][j] = rand()%100+1;
        }
    }
}

void stampaMatrice(int mat[][COLONNE], int righe, int colonne){
    for(int i=0; i<righe; i++){
        for(int j=0; j<colonne; j++){
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

void scambiaElementi(int *num1, int *num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void scambiaDiagonali(int mat[][COLONNE], int  righe, int colonne){
    for(int i=0; i<righe; i++){
        for(int j=0; j<colonne; j++){
            if(i==j){
                scambiaElementi(&mat[i][j], &mat[i][colonne-j-1]);
            }
        }
    }
}

int main(){
    int matrice[RIGHE][COLONNE];
    srand(time(NULL));
    riempiMatriceCasuale(matrice, RIGHE, COLONNE);
    stampaMatrice(matrice, RIGHE, COLONNE);
    printf("Matrice con le diagonali invertite:\n");
    scambiaDiagonali(matrice, RIGHE, COLONNE);
    stampaMatrice(matrice, RIGHE, COLONNE);
    return 0;
}