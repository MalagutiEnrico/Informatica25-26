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
#define DIMiniziale 5

void stampaMenu(int *scelta){
    system("CLS");
    printf("*****Gestione di un insieme di numeri utilizzando un array dinamico*****\n");
    printf("1.Aggiungi un numero al vettore\n2.Visualizza tutti i numeri\n3.Cerca un numero\n");
    printf("4.Ordina i numeri in ordine crescente\n5.Elimina un numero\n6.Esci dal programma.\n");
    printf("Effettua una scelta:\n");
    scanf("%d", &*scelta);
}

void aggiungiElemento(int vett[], int *dim){
    (*dim)++;
    int *temp = (int *)realloc(vett, (*dim)*sizeof(int));
    if(temp != NULL)    
        *vett = *temp;
    else 
        (*dim)--;
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
    int *temp = (int *)realloc(vett, (*dim)*sizeof(int));
    if(temp != NULL)
        *vett = *temp;
    else
        (*dim)++;
}

int main(){
    int *vettore, n=1, dim=DIMiniziale, num, scelta, pos, numdaeliminare;
    vettore = (int *)malloc(dim*sizeof(int));
    riempiVettoreCasuale(vettore, dim, 0, 100);
    do{
        stampaMenu(&scelta);
        switch(scelta){
            case 1:
                aggiungiElemento(vettore, &dim);
                printf("Inserisci l'elemento da aggiungere: ");
                scanf("%d", &vettore[dim-1]);
                break;
            case 2:
                printf("Il vettore stampato: ");
                stampaVettore(vettore, dim, ' ');
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
                scanf("%d", &numdaeliminare);
                eliminaElemento(vettore, &dim, numdaeliminare);
                break;
            case 6:
                printf("Il programma è terminato.\n");
                break;
        }
        system("PAUSE");
    }while(scelta!=6);
    free(vettore);
    return 0;
}