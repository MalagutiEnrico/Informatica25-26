/*Creare un array dinamico chiedendo all'utente la sua dimensione. Il programma deve
prevedere le seguenti funzioni:
1. Creare l'array
2. Inserire gli elementi nell'array
3. Stampa dei valori
4. Esci*/
#include <stdio.h>
#include <stdlib.h>


int* creaVettore(int n){
    int *vettore = (int *)malloc(n*sizeof(int));
    if(vettore == NULL){
        printf("Errore nell'allocazione della memoria.\n");
        return 1;
    }
    return vettore;
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

int main(){
    int *vettore=NULL;  //creazione del puntatore
    int dim;
    do{
        printf("Inserisci la dimensione del vettore: ");
        scanf("%d", &dim);
        if(dim<=0)    printf("Dimensione del vettore non valida.\n");
    }while(dim<=0);
    vettore = creaVettore(dim);
    vettore = riempiVettore(vettore, dim);
    stampaVettore(vettore, dim);
    return 0;
}