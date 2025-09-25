/*Scrivere un programma in C che gestisca un insieme di numeri interi usando un array dinamico.
Il programma deve permettere, tramite menù:
    1. Aggiungere un numero (espandendo l’array con realloc)
    2. Visualizzare tutti i numeri
    3. Cercare un numero specifico
    4. Ordinare i numeri in ordine crescente
    5. Eliminare un numero scelto
    6. Uscire
*/
#include <stdio.h>
#include <stdlib.h>
#include "Arraylib.h"
#include "Arraylib.c"

void stampaMenu(int *scelta){
    system("clear");
    printf("*****Gestione di un insieme di numeri utilizzando un array dinamico*****\n");
    printf("1.Aggiungi un numero al vettore\n2.Visualizza tutti i numeri\n3.Cerca un numero\n");
    printf("4.Ordina i numeri in ordine crescente\n5.Elimina un numero\n6.Esci dal programma.\n");
    printf("Effettua una scelta:");
    scanf("%d", &*scelta);
}

void aggiungiElemento(int vett[], int *dim){
    (*dim)++;
    vett = (int *)realloc(vett, (*dim)*sizeof(int));
    if(vett == NULL){
        printf("Errore nell'allocazione della memoria\n");
        (*dim)--;
    }
}

int trovaNumero(int vett[], int dim, int num){
    for(int i=0; i<dim; i++){
        if(vett[i]==num)    return i;
    }
    return -1;
}

void eliminaElemento(int vett[], int *dim, int num){
    int posizione = ricercaSequenziale(vett, *dim, num);
    for(int i=posizione; i<*dim-1; i++){
        vett[i] = vett[i+1];
    }
    (*dim)--;
    vett = (int *)realloc(vett, (*dim)*sizeof(int));
    if(vett == NULL){
        printf("Errore nell'allocazione della memoria.\n");
        (*dim)++;
    }
}

int main(){
    int *vettore = NULL;    //array dinamico
    int n=1, dim=0, num, scelta, pos;
    vettore = (int *)malloc(dim*sizeof(int));
    do{
        stampaMenu(&scelta);
        switch(scelta){
            case 1:
                aggiungiElemento(vettore, &dim);
                printf("Inserisci l'elemento da aggiungere: ");
                scanf("%d", &vettore[dim-1]);
                break;
            case 2:
                if(dim==0){
                    printf("La dimensione del vettore è 0. Non ci sono elementi da stampare.\n");
                }
                else{
                    printf("Il vettore stampato: ");
                    stampaVettore(vettore, dim, ' ');
                    printf("\n");
                }
                break;
            case 3:
                printf("Inserisci l'elemento da cercare: ");
                scanf("%d", &num);
                pos = trovaNumero(vettore, dim, num);
                if(pos == -1){
                    printf("L'elemento non è stato trovato all'interno del vettore.\n");
                }
                else{
                    printf("L'elemento ricercato è in posizione %d\n", pos);
                }
                break;
            case 4:
                quickSort(vettore, dim, 0, dim-1);
                break;
            case 5:
                printf("Inserisci il numero da eliminare: ");
                scanf("%d", &num);
                eliminaElemento(vettore, &dim, num);
                break;
            case 6:
                printf("Il programma è terminato.\n");
                break;
        }
        pausa();
    }while(scelta!=6);
    free(vettore);
    return 0;
}