/*Esercizio 2 del file esercizi.md*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum{false, true} Bool;

typedef struct Auto {
    char targa[9];
    char marca[20];
    char modello[20];
    float prezzo_giorno;
    struct Auto* next;
} Auto;

typedef struct Lista{
    Auto* testa;
    int lunghezza;
}Lista;

Bool controllo_targa(Lista* list, char* targa){     //ritorna a true se un'altra auto ha la stessa targa
    Auto* tmp = list->testa;
    while(tmp!=NULL){
        if(strcmp(tmp->targa, targa) == 0)
            return true;
        tmp = tmp->next;
    }
    return false;
}

void inserisci_targa(Auto* nuova_auto, Lista* list){
    Bool trovato;
    do{
        printf("Inserisci targa: ");
        fgets(nuova_auto->targa, 9, stdin);
        trovato = controllo_targa(list, nuova_auto->targa);
        if(trovato)
            printf("Targa già appartenente ad un veicolo. Inserimento non valido.\n");
    }while(trovato);
}

void set_auto(Auto* nuova_auto, Lista* list){
    printf(" === Inserimento nuova auto ===\n");
    inserisci_targa(nuova_auto, list);
    printf("Inserisci marca: ");
    fgets(nuova_auto->marca, 20, stdin);
    printf("Inserisci modello: ");
    fgets(nuova_auto->modello, 20, stdin);
    printf("Inserisci prezzo giornaliero: ");
    scanf("%f", &nuova_auto->prezzo_giorno);
    char c;
    while((c = getchar()) != '\n') {}

}

void inserisciAuto(Lista* lista) {
    Auto* nuova=(Auto*)malloc(sizeof(Auto));
    if(nuova == NULL) {
        printf("Errore di allocazione");
        exit(1);
    }
    nuova->next=NULL;

    set_auto(nuova, lista);
    if(lista->testa==NULL){
        lista->testa=nuova;
        lista->lunghezza++;

    }else {
        Auto* temp=lista->testa;
        while(temp->next!=NULL){
            temp=temp->next;

        }
        temp->next=nuova;
        lista->lunghezza++;
    }
}

void stampaAuto(Lista* parco_auto){
    Auto* temp=parco_auto->testa;
    int i=0;
    while(temp!=NULL){
        printf("\n=== AUTO %d ===\n", i+1);
        printf("%s%s%s%.2f€/giorno\n", temp->targa, temp->marca, temp->modello, temp->prezzo_giorno);
        i++;
        temp=temp->next;
    }
}

Auto* cercaAuto(char* targa, Lista* list){
    Auto* tmp = list->testa;
    while(tmp->next != NULL){
        if(strcmp(tmp->targa, targa)==0)
            return tmp;
        tmp = tmp->next;
    }
    return NULL;
}

void eliminaAuto(char* targa, Lista* list){
    Auto* tmpprima = list->testa;
    Auto* tmp = cercaAuto(targa, list);
    if(tmp == NULL){
        printf("La targa non corrisponde a nessun veicolo inserito.\n");
    }
    else{
        if(tmp == list->testa){                 //l'auto da eliminare è al primo posto nella lista
            list->testa = tmp->next;
        }
        else{
            while(tmpprima->next != tmp)
                tmpprima = tmpprima->next;
            tmpprima->next = tmp->next;
        }
        list->lunghezza--;
        free(tmp);
    } 
}

Lista* crea_lista(){
    Lista *parco_auto=(Lista*)malloc(sizeof(Lista));
    parco_auto->lunghezza=0;
    parco_auto->testa=NULL;
    return parco_auto;
}

int main(){
    Lista *parco_auto=crea_lista();
    int scelta;
    char c, targa[20];
    do {
        printf("\n===== AUTONOLEGGIO 2000 =====\n");
        printf("1. Inserisci nuova auto\n");
        printf("2. Visualizza auto\n");
        printf("3. Cancella auto\n");
        printf("0. Esci\n");
        printf("Scelta: ");
        scanf("%d", &scelta);
        while((c = getchar()) != '\n') {}

        switch (scelta) {
            case 1:
                inserisciAuto(parco_auto);
                break;
            case 2:
                stampaAuto(parco_auto);
                break;
            case 3:
                printf("Inserisci la targa dell'auto da cancellare: ");
                fgets(targa, 9, stdin);
                eliminaAuto(targa, parco_auto);
                break;
            case 0:
                printf("Uscita dal programma.\n");
                break;
            default:
                printf("Scelta non valida!\n");
        } 
    } while (scelta != 0);

    return 0;
}