/*Scrivi un programma in c che gestista un array di interi usando un array dinamico.
Il programma, tramite menù, deve:
1. Aggiungere un numero
2. Visualizzare tutti i numeri
3. Cercare un numero specifico
4. Ordinare i numeri in ordine crescente
5. Eliminare un numero scelto
6. Uscire*/
#include <stdio.h>
#include <stdlib.h>

void stampaMenu(int *scelta){
    printf("\n\n\n\n******Gestione dell'array dinamico*****\n");
    printf("1. Aggiungere un numero\n2. Visualizzare tutti i numeri\n3. Cercare un numero specifico");
    printf("4. Ordinare i numeri in ordine crescente\n5. Eliminare un numero scelto\n6. Uscire");
    printf("Effettua la scelta: ");
    scanf("%d", &scelta);
}

void aggiungiNumeri(int *vett, int *dim){
    int numeri;
    printf("Quanti elementi vuoi aggiungere: ");
    scanf("%d", &numeri);
    (*dim) += numeri;
    int *tmp = realloc(vett, (*dim)*sizeof(int));
    if(tmp == NULL){
        printf("Errore nell'allocazione della memoria.\n");
        exit;
    }
    vett = tmp;
}

int main(){
    int *vett=NULL;
    int scelta;
    do{
        stampaMenu(&scelta);
        switch(scelta){
            case 1:
                
        }
    }while(scelta!=6);
}