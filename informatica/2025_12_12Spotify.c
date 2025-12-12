#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Canzone{
    char titolo[20];
    char artista[20];
    int durata;
    int id;
}Canzone;

typedef struct{
    Canzone* testa;
    int len;
}Playlist;

void clear_buffer(){
    char c;
    while((c = getchar()) != '\n'){}
}

int stampa_menu(){
    int scelta;
    printf("============SPOTIFY===========\n");
    printf("1.Inserisci una canzone\n2.Stampa una canzone\n");
    printf("Effettua una scelta: ");
    scanf("%d", &scelta);
    return scelta;
}

void stampa_canzone(Canzone* song){
    printf("Titolo: %s\nArtista: %s\nDurata: %d\nID: %d\n", song->titolo, song->artista, song->durata, song->id);
}

void inserisci_canzone(Canzone* c){
    printf("======Inserisci canzone======\n");
    printf("Inserisci il titolo della canzone: ");
    fgets(c->titolo, 20, stdin);
    printf("Inserisci l'artista della canzone: ");
    fgets(c->artista, 20, stdin);
    printf("Inserisci la durata della canzone: ");
    scanf("%d", &c->durata);
    clear_buffer();
}

Playlist* crea_playlist(){
    Playlist* tmp;
    tmp->len = 0;
    tmp->testa = NULL;
    return tmp;
}

void stampa_playlist(Playlist* p){
    for(int i=0; i<p->len; i++){
        stampa_canzone(&p[i]);
    }
}