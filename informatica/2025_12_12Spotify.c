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

void clear_buffer(){                                            //pulisci il buffer stdin
    char c;
    while((c = getchar()) != '\n'){}
}

void controlla_allocazione(void* ptr){                          //controlla se l'allocazione della memoria è avvenuta correttamente
    if(ptr == NULL){
        printf("Errore nell'allocazione della memoria.\n");
        exit(1);
    }
}

int stampa_menu(){                                              //stampa il menu di scelta
    int scelta;
    printf("============SPOTIFY===========\n");
    printf("1.Inserisci una canzone\n2.Stampa canzoni lista\n3.Cerca canzoni per artista\n");
    printf("4.Aggiungi canzone alla playlist\n5.Stampa Playlist\n6.Cancella canzone dalla playlist.\n0.Esci\n");
    printf("Effettua una scelta: ");
    scanf("%d", &scelta);
    clear_buffer();
    return scelta;
}

void stampa_canzone(Canzone* c){                                //stampa a video una singola canzone
    printf("Titolo: %sArtista: %sDurata: %d\nID: %d\n", c->titolo, c->artista, c->durata, c->id);
}

void set_canzone(Canzone* c){                                   //riempi i campi di una singola canzone
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

Lista* crea_lista(){                                            //crea una lista di canzoni
    Lista* tmp = malloc(sizeof(Lista));
    controlla_allocazione(tmp);
    tmp->len = 0;
    tmp->testa = NULL;
    return tmp;
}

void stampa_lista(Lista* l){                                    //stampa a video tutti gli elementi di una lista
    Canzone *tmp = l->testa;
    int i=0;
    if(tmp == NULL)
        printf("Lista vuota.\n");
    while(tmp != NULL){
        printf("===============\n");
        printf("Canzone: %d\nTitolo: %sArtista: %sDurata: %d\nID: %d\n", i+1, tmp->titolo, tmp->artista, tmp->durata, tmp->id);
        tmp = tmp->next;
        i++;
    }
}

void inserisci_canzone_lista(Lista *l){                         //inserisci una canzone in testa alla lista
    Canzone *tmp = malloc(sizeof(Canzone));
    controlla_allocazione(tmp);
    set_canzone(tmp);
    tmp->next = l->testa;
    l->testa = tmp;
    l->len++;
}

void ricerca_canzone_artista(Lista* l, char* artista){          //cerca e stampa a video le canzoni in base all'artista
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
    if(flag == 0)
        printf("Non ci sono canzoni dell'artista selezionato all'interno della Lista.\n");
}

void libera_memoria(Lista* l){                                  //libera la memoria allocata
    Canzone* current = l->testa;
    while(current->next != NULL && current->next != l->testa){
        Canzone* tmp = current;
        current = current->next;
        free(tmp);
    }
    free(l);
}

int cerca_canzone_id(Lista* l, int id){                        //cerca la canzone all'interno della lista e ne restituisce la posizione. ritorna a -1 se non la trova
    Canzone* tmp = l->testa;
    int i=0;
    if(tmp == NULL){
        printf("Lista vuota.\n");
        return -1;
    }
    while(tmp != NULL){
        if(tmp->id == id)
            return i;
        if(tmp->next == l->testa)
            break;
        i++;
        tmp = tmp->next;
    }
    return -1;
}

Canzone* copia_canzone(Lista* l, int pos){                      //copia la canzone con id
    Canzone* tmp = l->testa;
    Canzone *copia = malloc(sizeof(Canzone));
    controlla_allocazione(copia);
    for(int i=0; i<pos; i++)
        tmp = tmp->next;
    strcpy(copia->titolo, tmp->titolo);
    strcpy(copia->artista, tmp->artista);
    copia->durata = tmp->durata;
    copia->id = tmp->id;
    return copia;
}

void inserisci_canzone_playlist(Lista* l, Lista* playlist){     //inserisce una canzone all'interno della playlist
    int id, pos;
    printf("Inserisci l'ID della canzone da inserire nella playlist: ");
    scanf("%d", &id);
    pos = cerca_canzone_id(l, id);
    if(pos == -1)
        printf("La canzone non è stata trovata all'interno dell'elenco\n");
    else{
        Canzone* tmp = copia_canzone(l, pos);
        if(playlist->testa == NULL){                            //controlla se la playlist è vuota
            playlist->testa = tmp;
            tmp->next = tmp;   
        }
        else{
            Canzone* tmp_prec = playlist->testa;
            while(tmp_prec->next != playlist->testa)
                tmp_prec = tmp_prec->next;
            tmp_prec->next = tmp;
            tmp->next = playlist->testa;
        }
        playlist->len++;
        printf("Canzone inserita all'interno della playlist.\n");
    }
}

void stampa_playlist(Lista* playlist){                          //funzione che stampa la playlist circolare
    Canzone *tmp = playlist->testa;
    if(tmp == NULL)
        printf("Playlist vuota.\n");
    else{
        printf("==========PLAYLIST=========\n");
        for(int i=0; i<playlist->len; i++){
            stampa_canzone(tmp);
            tmp = tmp->next;
            printf("================\n");
        }
    }
}

void cancella_canzone_playlist(Lista* playlist){                //funzione che cancella una canzone dalla playlist
    int id, pos;
    Canzone* tmp = playlist->testa;
    printf("Inserisci l'ID della canzone da eliminare: ");
    scanf("%d", &id);
    pos = cerca_canzone_id(playlist, id);
    if(pos == -1)
        printf("Canzone non presente all'interno della playlist.\n");
    else{
        if(pos == 0){                                           //se la posizione è 0, allora l'elemento è in testa alla lista
            if(playlist->len == 1){                             //caso in cui la playlist sia di un solo elemento
                playlist->testa = NULL;
                free(tmp);
            }
            else{                                               //caso in cui la playlist sia di più elementi
                while(tmp->next != playlist->testa) 
                    tmp = tmp->next;
                Canzone* da_cancellare = playlist->testa;
                tmp->next = playlist->testa->next;
                playlist->testa = playlist->testa->next;
                free(da_cancellare);
            }
       }
       else{                                                    //l'elemento si trova all'interno della lista
            for(int i=0; i<pos-1; i++)
                tmp = tmp->next;
            Canzone *da_cancellare = tmp->next;
            tmp->next = da_cancellare->next;
            free(da_cancellare);
       }
        playlist->len--;
        printf("Canzone eliminata dalla playlist.\n");
    }
}

int main(){
    Lista* canzoni = crea_lista();
    Lista* playlist = crea_lista();
    int scelta;
    char artista[50];
    do{
        system("CLS");
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
            case 4:
                inserisci_canzone_playlist(canzoni, playlist);
                break;
            case 5:
                stampa_playlist(playlist);
                break;
            case 6:
                cancella_canzone_playlist(playlist);
                break;
            case 0:
                printf("Programma terminato.\n");
                break;
            default:
                printf("Scelta inserita non valida.\n");
        }
        system("PAUSE");
    }while(scelta != 0);
    libera_memoria(canzoni);
    libera_memoria(playlist);
    return 0;
}