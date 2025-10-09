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
    printf("1. Aggiungere un numero\n2. Visualizzare tutti i numeri\n3. Cercare un numero specifico\n");
    printf("4. Ordinare i numeri in ordine crescente\n5. Eliminare un numero scelto\n6. Uscire\n");
    printf("Effettua la scelta: ");
    scanf("%d", &*scelta);
}

int* creaVettore(int *vett, int dim){
    int *tmp = realloc(vett, dim*sizeof(int));
    if(tmp==NULL){
        printf("Errore nell'allocazione della memoria.\n");
        exit(1);
    }
    return tmp;
}

void riempiVettore(int *vett, int dim1, int dim2){
    for(int i=dim1-dim2; i<dim1; i++){
        printf("Inserisci l'elemento: ");
        scanf("%d", &vett[i]);
    }
}

void stampaVettore(int *vett, int dim){
    for(int i=0; i<dim; i++){
        printf("%d ", vett[i]);
    }
}

int cercaNumero(int *vett, int dim, int num){
    for(int i=0; i<dim; i++){
        if(vett[i]==num)    return i;
    }
    return -1;
}

void bubbleSort(int vett[], int dim){
    int temp, flag=0, i=0;
    while(flag==0){
        flag=1;
        for(int j=0; j<dim-1-i; j++){
            if(vett[j]>vett[j+1]){
                flag=0;
                temp=vett[j];
                vett[j]=vett[j+1];
                vett[j+1]=temp;
            }
        }
        i++;
    }
}

void slittaDestra(int *vett, int *dim, int pos){
    for(int i=pos; i<(*dim)-1; i++){
        vett[i] = vett[i+1];
    }
}

void eliminaNumero(int *vett, int *dim, int num){
    int pos = cercaNumero(vett, *dim, num);
    if(pos == -1){
        printf("Numero non presente nel vettore.\n");
    }
    else{
        slittaDestra(vett, dim, pos);
        int *tmp = realloc(vett, ((*dim)-1)*sizeof(int));
        if(tmp==NULL){
            printf("Errore nell'allocazione della memoria.\n");
            exit(1);
        }
        (*dim)--;
        vett=tmp;
    }
}

int main(){
    int *vettore=NULL;
    int scelta, dimensione=0, dimensione2, numero, posizione;
    do{
        stampaMenu(&scelta);
        switch(scelta){
            case 1:
                printf("Quanti numeri vuoi aggiungere: ");
                scanf("%d", &dimensione2);
                dimensione += dimensione2;
                vettore = creaVettore(vettore, dimensione);
                riempiVettore(vettore, dimensione, dimensione2);
                break;
            case 2:
                stampaVettore(vettore, dimensione);
                break;
            case 3:
                printf("Inserisci il numero da cercare: ");
                scanf("%d", &numero);
                posizione = cercaNumero(vettore, dimensione, numero);
                if(posizione == -1)     printf("Il numero non è presente all'interno del vettore.\n");
                else                    printf("Il numero %d si trova in posizione %d.\n", numero, posizione);
                break;
            case 4:
                bubbleSort(vettore, dimensione);
                printf("Vettore ordinato con successo.\n");
                break;
            case 5:
                printf("Inserisci il numero da eliminare: ");
                scanf("%d", &numero);
                eliminaNumero(vettore, &dimensione, numero);
                break;
            case 6:
                printf("Programma terminato.\n");
                break;
            default:
                printf("Tasto inserito non valido.\n");
        }
    }while(scelta!=6);
    free(vettore);
    return 0;
}