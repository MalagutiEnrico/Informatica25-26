/*Registrare le informazioni di alcuni libri: titolo, autore, anno pubblicazione
1. carica l'array di libri
2. stampa l'array di libri
3. elimina un libro (in base al titolo)
4. cerca un libro (in base al titolo)*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char titolo[40];
    char autore[30];
    int anno_pubblicazione;
}Libro;

void clearbuffer(){
    char c;
    while((c = getchar()) != '\n'){}
}

void setLibro(Libro* book){                                         //riempie i campi di un libro
    printf("=====Inserimento libro=====\n");       
    printf("Inserisci il titolo del libro: ");
    fgets(book->titolo, 40, stdin);
    printf("Inserisci l'autore del libro: ");
    fgets(book->autore, 30, stdin);
    printf("Inserisci l'anno di pubblicazione del libro: ");
    scanf("%d", &book->anno_pubblicazione);
    clearbuffer();
}

Libro* aggiungiLibro(Libro* libri, int* dim){                       //aggiunge un libro al vettore
    (*dim)++;
    Libro* tmp = realloc(libri, (*dim)*sizeof(Libro));
    if(tmp == NULL)
        exit(1);
    setLibro(&tmp[(*dim)-1]);
    return tmp;
}

void stampaLibro(Libro book){                                       //stampa a video il libro scelto     
    printf("============================\n");
    printf("Titolo: %sAutore: %sAnno Pubblicazione: %d\n", book.titolo, book.autore, book.anno_pubblicazione);
}

int trovaLibro(Libro* libri, int dim, char* titolo){                //funzione che cerca un libro in base al titolo. ritorna alla posizione del libro; se non lo trova ritona a -1
    for(int i=0; i<dim; i++){
        if(strcmp(libri[i].titolo, titolo)==0)
            return i;
    }
    return -1;
}

void shiftSX(Libro* libri, int inizio, int fine){                   //funzione che sposta gli elementi di un vettore di una posizione verso sinistra
    for(int i=inizio; i<fine; i++){
        libri[i] = libri[i+1];
    }
}

Libro* eliminaLibro(Libro* libri, int* dim, char* titolo){          //funzione che elimina un libro in base al titolo
    int posizione = trovaLibro(libri, *dim, titolo);
    if(posizione == -1){
        printf("Libro non presente nella memoria.\n");
        return libri;
    }
    else{
        shiftSX(libri, posizione, *dim);
        (*dim)--;
        Libro* tmp = realloc(libri, (*dim)*sizeof(Libro));
        if(tmp == NULL){
            exit(1);
        }
        return tmp;
    }
}

int main(){
    Libro* libri;
    int scelta, dim, posizione;
    char titolo_da_trovare[40];
    do{
        printf("==========GESTIONE DI LIBRI==========\n");
        printf("1.Inserisci un nuovo libro\n2.Stampa i libri\n3.Elimina un libro\n4.Cerca un libro\n0.Esci\nEffettua la scelta: ");
        scanf("%d", &scelta);
        clearbuffer();
        switch(scelta){
            case 1:
                libri = aggiungiLibro(libri, &dim);
                break;
            case 2:
                for(int i=0; i<dim; i++){
                    stampaLibro(libri[i]);
                }
                break;
            case 3:
                printf("Inserisci il titolo del libro da eliminare: ");
                fgets(titolo_da_trovare, 40, stdin);
                libri = eliminaLibro(libri, &dim, titolo_da_trovare);
                break;
            case 4:
                printf("Inserisci il titolo del libro da eliminare: ");
                fgets(titolo_da_trovare, 40, stdin);
                posizione = trovaLibro(libri, dim, titolo_da_trovare);
                if(posizione == -1)
                    printf("Libro non trovato.\n");
                else{
                    printf("Libro trovato in posizione %d\n", posizione+1);
                    stampaLibro(libri[posizione]);
                }
                break;
            case 0:
                printf("Programma terminato.\n");
                break;
            default:
                printf("Scelta inserita non valida.\n");
        }
    }while(scelta!=0);
    free(libri);
    return 0;
}