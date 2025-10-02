/*Scrivi un programma in C che:
1. Chiede all'utente quanti numeri vuole inserire
2. Alloca dinamicamente un array di quella dimensione con malloc()
3. Permette all'utente di inserire i numeri
4. Chiede all'utente se vuole aumentare la dimensione dell'array:
    -se sì, richiede la dimensione e usa realloc per ridimensionarlo
    -Permette quindi di inserire i nuovi voti
5. Infine, stampa tutti gli elementi dell'array*/
#include <stdio.h>
#include <stdlib.h>

int* creaVettore(int dim){
    int *vettore = (int *)malloc(dim*sizeof(int));
    if(vettore==NULL){
        printf("Errore nell'allocazione della memoria.\n");
        exit;
    }
    return vettore;
}

void riempiVettore(int *vett, int dim){
    for(int i=0; i<dim; i++){
        printf("Inserisci l'elemento in posizione %d: ", i+1);
        scanf("%d", &vett[i]);
    }
}

void stampaVettore(int *vett, int dim){
    for(int i=0; i<dim; i++){
        printf("%d ", vett[i]);
    }
}

void stampaMenu(int *scelta){
    printf("\n\n\n\n");
    printf("1.Aumenta la dimensione dell'array\n2.Stampa gli elementi degli array\n0.Esci dal programma\n");
    printf("Effettua la scelta: ");
    scanf("%d", scelta);
}

void ridimensionaVettore(int *vett, int *dim){
    do{
        printf("Inserisci la nuova dimensione del vettore: ");
        scanf("%d", dim);
        if(dim<0)   printf("Dimensione del vettore non valida");
    }while(dim<0);
    int *tmp = realloc(vett, (*dim)*sizeof(int));
    if(tmp==NULL){
        printf("Errore nell'allocazione della memoria.\n");
        exit;
    }
    vett = tmp;
}

void riempiVettoreAggiornato(int *vett, int dim1, int dim2){
    for(int i=dim1; i<dim2; i++){
        printf("Inserisci il nuovo elemento che andrà in posizione %d: ", i+1);
        scanf("%d", &vett[i]);
    }
}

int main(){
    int *vettore=NULL;
    int dim1, dim2;
    int scelta;
    printf("Inserisci quanti numeri vuoi inserire: ");
    scanf("%d", &dim1);
    vettore = creaVettore(dim1);
    riempiVettore(vettore, dim1);
    do{
        stampaMenu(&scelta);
        switch(scelta){
            case 1:
                ridimensionaVettore(vettore, &dim2);
                if(dim2>dim1){
                    riempiVettoreAggiornato(vettore, dim1, dim2);
                }
                dim1 = dim2;
                break;
            case 2:
                stampaVettore(vettore, dim1);
                break;
                case 0:
                    printf("Programma terminato.\n");
                    break;
            default:
                printf("Scelta non valida.\n");
        }
    }while(scelta!=0);
    free(vettore);
    return 0;
}