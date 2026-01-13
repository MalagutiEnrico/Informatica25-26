#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char titolo[50];
    char autore[50];
    int anno;
    float prezzo;
}Libro;

void compatta(char* buffer, int lunghezza){
    if(lunghezza>0 && buffer[lunghezza-1]!='\n'){
        buffer[lunghezza-1] = '\0';
        lunghezza--;
    }
}

int main(){
    int n = 3, libro_max=0, max=0, len;
    Libro* libri = malloc(n*sizeof(Libro));
    char da_eliminare[50];
    if(libri == NULL)   exit(1);

    //inserimento dati libro 1
    strcpy(libri[0].titolo, "L'amore mio non muore");
    strcpy(libri[0].autore, "Roberto Saviano");
    libri[0].anno = 2025;
    libri[0].prezzo = 25;

    //inserimento dati libro 2
    strcpy(libri[1].titolo, "Divina Commedia");
    strcpy(libri[1].autore, "Dante Alighieri");
    libri[1].anno = 1300;
    libri[1].prezzo = 0.10;

    //inserimento dati libro 3
    strcpy(libri[2].titolo, "Giro del mondo in 80 giorni");
    strcpy(libri[2].autore, "Jules Verne");
    libri[2].anno = 1850;
    libri[2].prezzo = 30;

    //visualizzazione dei dati
    printf("===============Lista Libri==================\n");
    for(int i=0; i<n; i++){
        printf("Titolo: %s\nAutore: %s\nAnno: %d\nPrezzo: %.2f\n", libri[i].titolo, libri[i].autore, libri[i].anno, libri[i].prezzo);
        printf("===============\n");
    }

    //cerca il libro più costoso
    for(int i=0; i<n; i++){
        if(libri[i].prezzo > max){
            max = libri[i].prezzo;
            libro_max = i;
        }
    }
    printf("========Libro con prezzo più alto========\nTitolo: %s\nAutore: %s\nAnno: %d\nPrezzo: %.2f\n", libri[libro_max].titolo, libri[libro_max].autore, libri[libro_max].anno, libri[libro_max].prezzo);

    //elimina libro
    printf("Inserisci il titolo del libro da eliminare: ");
    fgets(da_eliminare, 50, stdin);
    len = strlen(da_eliminare);
    compatta(da_eliminare, len);
    for(int i=0; i<n; i++){
        if(strcmp(libri[i].titolo, da_eliminare) == 0){
            for(int j=i; j<(n-1); j++){
                strcpy(libri[j].titolo, libri[j+1].titolo);
                strcpy(libri[j].autore, libri[j+1].autore);
                libri[j].prezzo = libri[j+1].prezzo;
                libri[j].anno = libri[j+1].anno;
            }
            n--;
            libri = realloc(libri, n*sizeof(Libro));
            if(libri == NULL)   exit(1);
            break;
        }
    }

    //visualizzazione dei dati
    printf("===============Lista Libri==================\n");
    for(int i=0; i<n; i++){
        printf("Titolo: %s\nAutore: %s\nAnno: %d\nPrezzo: %.2f\n", libri[i].titolo, libri[i].autore, libri[i].anno, libri[i].prezzo);
        printf("===============\n");
    }
    
    //liberazione memoria
    free(libri);
    return 0;
}