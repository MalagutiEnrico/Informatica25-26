#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ID = 0;

typedef struct Canzone{
    char titolo[50];
    char artista[50];
    int durata;
    int id;
    struct Canzone* next;
}Canzone;

typedef struct{
    Canzone* testa;
    int len;
}Lista;

void clear_buffer(){        //pulisci il buffer stdin
    char c;
    while((c = getchar()) != '\n'){}
}

int stampa_menu(){          //stampa il menu di scelta
    int scelta;
    printf("============SPOTIFY===========\n");
    printf("1.Inserisci una canzone\n2.Stampa canzoni lista\n3.Cerca canzoni per artista\n");
    printf("4.Aggiungi canzone alla playlist\n5.Stampa Playlist\n6.Cancella canzone dalla playlist.\n0.Esci\n");
    printf("Effettua una scelta: ");
    scanf("%d", &scelta);
    clear_buffer();
    return scelta;
}

void stampa_canzone(Canzone* song){     //stampa a video una singola canzone
    printf("Titolo: %s\nArtista: %s\nDurata: %d\nID: %d\n", song->titolo, song->artista, song->durata, song->id);
}

void set_canzone(Canzone* c){           //riempi i camèi di una singola canzone
    ID++;
    c->id = ID;
    printf("======Inserisci canzone======\n");
    printf("Inserisci il titolo della canzone: ");
    fgets(c->titolo, 50, stdin);
    printf("Inserisci l'artista della canzone: ");
    fgets(c->artista, 50, stdin);
    printf("Inserisci la durata della canzone: ");
    scanf("%d", &c->durata);
    clear_buffer();
}

Lista* crea_lista(){                    //crea una lista di canzoni
    Lista* tmp = malloc(sizeof(Lista));
    tmp->len = 0;
    tmp->testa = NULL;
    return tmp;
}

void stampa_lista(Lista* l){            //stampa a video tutti gli elementi di una lista
    Canzone *tmp = l->testa;
    int i=0;
    if(tmp == NULL){
        printf("Lista vuota.\n");
    }
    while(tmp != NULL){
        printf("Canzone: %d\nTitolo: %sArtista: %sDurata: %d\nID: %d\n", i+1, tmp->titolo, tmp->artista, tmp->durata, tmp->id);
        tmp = tmp->next;
        i++;
    }
}

void inserisci_canzone_lista(Lista *l){     //inserisci una canzone in testa alla lista
    Canzone *tmp = malloc(sizeof(Canzone));
    set_canzone(tmp);
    tmp->next = l->testa;
    l->testa = tmp;
    l->len++;
}

void ricerca_canzone_artista(Lista* l, char* artista){      //cerca e stampa a video le canzoni in base all'artista
    Canzone* tmp = l->testa;
    int flag=0;
    while(tmp != NULL){
        if(strcmp(tmp->artista, artista) == 0){
            printf("====================\n");
            stampa_canzone(tmp);
            flag = 1;
        }
        tmp = tmp->next;
    }
    if(flag = 0){
        printf("Non ci sono canzoni dell'artista selezionato all'interno della Lista.\n");
    }
}

void libera_memoria(Lista* l){                              //libera la memoria allocata
    Canzone* current = l->testa;
    while(current->next != NULL){
        Canzone* tmp = current;
        current = current->next;
        free(tmp);
    }
    free(l);
}

int cerca_canzone(Lista* l, int id){                        //cerca la canzone all'interno della lista e ne restituisce la posizione. ritorna a -1 se non la trova
    Canzone* tmp = l->testa;
    int i=0;
    while(tmp != NULL){
        if(tmp->id == id){
            return i;
        }
        i++;
        tmp = tmp->next;
    }
    return -1;
}

void inserisci_canzone_playlist(Lista* l, Lista* playlist){
    int id, pos;
    printf("Inserisci l'ID della canzone da inserire nella playlist: ");
    scanf("%d", &id);
    pos = cerca_canzone(l, id);
    if(pos == -1){
        printf("La canzone non è stata trovata all'interno dell'elenco\n");
    }
    else{
        Canzone *tmp = malloc(sizeof(Canzone));
        
    }
}

int main(){
    Lista* canzoni = crea_lista();
    Lista* playlist = crea_lista();
    int scelta;
    char artista[50];
    do{
        scelta = stampa_menu();
        switch(scelta){
            case 1:
                inserisci_canzone_lista(canzoni);
                break;
            case 2:
                printf("=========LISTA CANZONI=========\n");
                stampa_lista(canzoni);
                break;
            case 3:
                printf("Inserisci l'artista di cui cercare le canzoni: ");
                fgets(artista, 50, stdin);
                ricerca_canzone_artista(canzoni, artista);
                break;
            case 0:
                printf("Programma terminato.\n");
                break;
            default:
                printf("Scelta inserita non valida.\n");
        }
    }while(scelta != 0);
    free(canzoni);
    return 0;
}