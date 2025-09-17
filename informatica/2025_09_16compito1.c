/*Data una matrice quadrata, riempirla a spirale*/
#include <stdio.h>
#define RIGHE 5
#define COLONNE 5

void stampaMatrice(int mat[][COLONNE], int righe, int colonne){
    for(int i=0; i<righe; i++){
        for(int j=0; j<colonne; j++){
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

void riempiMatriceSpirale(int mat[][COLONNE], int righe, int colonne){
    int num=1, i=0, j=0, destra=righe-1, alto=colonne-1, sinistra=0, basso=0;
    while(sinistra<=destra && basso<=alto){
        i=basso;
        j=sinistra;
        for(j=sinistra; j<destra; j++){
            mat[i][j] = num;
            num++;
        }
        for(i=basso; i<alto; i++){
            mat[i][j] = num;
            num++;
        }
        for(j=destra; j>sinistra; j--){
            mat[i][j] = num;
            num++;
        }
        for(i=alto; i>basso; i--){
            mat[i][j] = num;
            num++;
        }
        sinistra++;
        alto--;
        basso++;
        destra--;
    }
    mat[i][j]=num;
}

int main(){
    int matrice[RIGHE][COLONNE];
    riempiMatriceSpirale(matrice, RIGHE, COLONNE);
    stampaMatrice(matrice, RIGHE, COLONNE);
    return 0;
}