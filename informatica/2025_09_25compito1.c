/*Scrivere un programma che:
1. Allochi direttamente un array iniziale di n numeri
2. Inserimento dei valori
3. Stampa il vettore
4. Calcoli la somma degli elementi multipli di 3
5. Creiamo un nuovo array contenente solo valori dispari*/
#include <stdio.h>
#include <stdlib.h>

int* creaVettore(int dim){
    int *vett = (int *)malloc(dim*sizeof(int));
    if(vett==NULL){
        printf("Errore nell'allocazione della memoria.\n");
        return NULL;
    }
    return vett;
}

int* riempiVettore(int *vett, int dim){
    for(int i=0; i<dim; i++){
        printf("Inserisci l'elemento %d: ", i+1);
        scanf("%d", &vett[i]);
    }
    return vett;
}

void stampaVettore(int *vett, int dim){
    for(int i=0; i<dim; i++){
        printf("%d ", vett[i]);
    }
}

int sommaMultipliTre(int *vett, int dim){
    int somma=0;
    for(int i=0; i<dim; i++){
        if(vett[i]%3==0)    somma+=vett[i];
    }
    return somma;
}

/*int contaDispari(int *vett, int dim){
    int cnt=0;
    for(int i=0; i<dim; i++){
        if(vett[i]%2==1)    cnt++;
    }
    return cnt;
}

void riempiVettoreDispari(int *vett_partenza, int *vett_destinazione, int dim_vett1, int dim_vett2){
    int cnt=0;
    while(cnt < dim_vett2){
        for(int i=0; i<dim_vett1; i++){
            if(vett_partenza[i]%2==1){
               vett_destinazione[cnt] = vett_partenza[i];
               cnt++;
            }
        }
    }
}*/

int* estraiDispari(int *vettore, int dim, int *dimDispari){
    int *dispari=NULL;
    *dimDispari=0;
    for(int i=0; i<dim; i++){
        if(vettore[i]%2==0){
            (*dimDispari)++;
            int *tmp = (int *)realloc(dispari, (*dimDispari)*sizeof(int));
        }
    }
}

int main(){
    int *vettore=NULL;
    int *dispari=NULL;
    int scelta, dimensione, somma, numDispari, dimDispari=0;

    printf("Inserisci la dimensione del vettore: ");
    scanf("%d", &dimensione);
    vettore = creaVettore(dimensione);
    vettore = riempiVettore(vettore, dimensione);
    stampaVettore(vettore, dimensione);
    somma = sommaMultipliTre(vettore, dimensione);
    printf("\nLa somma degli elementi multipli di 3 è: %d\n", somma);
    //dimDispari = contaDispari(vettore, dimensione);
    //dispari = creaVettore(dimDispari);
    //riempiVettoreDispari(vettore, dispari, dimensione, dimDispari);
    dispari = estraiDispari(vettore, dimensione, &dimDispari);
    printf("Il vettore con i numeri dispari: ");
    stampaVettore(dispari, dimDispari);
    return 0; 
}