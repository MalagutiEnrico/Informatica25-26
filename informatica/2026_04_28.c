/*CREARE UN PROGRAMMA CHE GESTISCA UNA LIBRERIA DOTATA DI DIVERSI LIBRI TALE DA POTER ESEGUIRE LE SEGUENTI OPERAZONI:
- AGGIUNTA/CREAZIONE DELLA LISTA DI LIBRI;
- RICERCA DI UN LIBRO;
- CANCELLAZIONE DI UN LIBRO;
- MODIFICA DELL'ISBN;
- SEPARARE LA LISTA DEI LIBRI IN DUE LISTE CONTENENTI RISPETTIVAMENTE I LIBRI CREATI PRIMA DEL 2000 E QUELLI DOPO;
TUTTO VIENE GESTITO DA FILE BINARI*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ANNO 2000

typedef struct{
    char autore[30];
    char titolo[30];
    char ISBN[20];
    int anno;
}Libro;

void clear_buffer(){                //funzione che pulisce il buffer di stdin
    char c;
    while((c = getchar()) != '\n'){}
}

void stampa_menu(int* scelta){      //stampa il menu e permetti all'utente di scegliere
    printf("===========GESTIONE BIBLIOTECA========\n");
    printf("1.Inserisci un libro\n2.Ricerca un libro per ISBN\n3.Modifica l'ISBN\n");
    printf("4.Separa i libri in due file in base alla data(2000)5.\nStampa i libri\n0.Esci\nEffettua la scelta: ");
    scanf("%d", &*scelta);
}

Libro set_libro(){                  //riempie i campi di un libro e li fa inserire all'utente
    Libro l;
    printf("Inserisci il titolo del libro: ");
    scanf(" %[^\n]", l.titolo);
    clear_buffer();
    printf("Inserisci l'autore del libro: ");
    scanf(" %[^\n]", l.autore);
    clear_buffer();
    printf("Inserisci l'ISBN del libro: ");
    scanf(" %[^\n]", l.ISBN);
    clear_buffer();
    printf("Inserisci l'anno di pubblicazione del libro: ");
    scanf("%d", &l.anno);
    clear_buffer();
    return l;
}

void aggiungi_libro(){              //inserisci il libro nel file
    Libro l = set_libro();
    FILE* f = fopen("2026_04_28_biblioteca.dat", "ab");
    if(f == NULL){
        printf("Errore nell'apertura del file\n");
        exit(1);
    }
    fwrite(&l, sizeof(Libro), 1, f);
    printf("Libro inserito nella biblioteca\n");
    fclose(f);
}

void stampa_libro(Libro l){         //stampa a video un singolo libro
    printf("%s\t\t%s\t\t%s\t\t%d\n", l.titolo, l.autore, l.ISBN, l.anno);
}

void stampa_biblioteca(){           //stampa a video tutti i libri
    Libro l;
    FILE* f = fopen("2026_04_28_biblioteca.dat", "rb");
    if(f == NULL){
        printf("Errore nell'apertura del file\n");
        exit(1);
    }
    printf("=========BIBLIOTECA=========\n");
    while(fread(&l, sizeof(Libro), 1, f)){
        stampa_libro(l);
        printf("=====================\n");
    }
    fclose(f);
}

void elimina_libro(char* ISBN){     //elimina un libro dal file
    Libro l;
    int trovato = 0;
    FILE* f_bin = fopen("2026_04_28_biblioteca.dat", "rb");
    if(f_bin == NULL){
        printf("Errore nell'apertura del file\n");
        exit(1);
    }
    FILE* f_tmp = fopen("tmp.dat", "wb");
    if(f_tmp == NULL){
        printf("Errore nell'apertura del file\n");
        exit(1);
    }
    while(fread(&l, sizeof(Libro), 1, f_bin)){
        if(strcmp(l.ISBN, ISBN) == 0){
            printf("Libro cancellato\n");
            trovato = 1;
        }
        else
            fwrite(&l, sizeof(Libro), 1, f_tmp);
    }
    if(!trovato)
            printf("Libro non presente nell'elenco\n");
    fclose(f_bin);
    fclose(f_tmp);
    remove("2026_04_28_biblioteca.dat");
    rename("tmp.dat", "2026_04_28_biblioteca.dat");
}

void ricerca_libro(char* ISBN){     //ricerca un libro per ISBN
    Libro l;
    FILE* f = fopen("2026_04_28_biblioteca.dat", "rb");
    if(f == NULL){
        printf("Errore nell'apertura del file\n");
        exit(1);
    }
    while(fread(&l, sizeof(Libro), 1, f)){
        if(strcmp(l.ISBN, ISBN) == 0){
            printf("=======Libro Trovato=======\n");
            stampa_libro(l);
            fclose(f);
            return;
        }
    }
    printf("Libro non presente nella biblioteca\n");
    fclose(f);
}

void modifica_ISBN(char* titolo){       //modifica l'isbn di un libro ricercato per titolo
    Libro l;
    FILE* f = fopen("2026_04_28_biblioteca.dat", "rb+");
    if(f == NULL){
        printf("Errore nell'apertura del file\n");
        exit(1);
    }
    while(fread(&l, sizeof(Libro), 1, f)){
        if(strcmp(l.titolo, titolo) == 0){
            printf("Inserisci il nuovo ISBN: ");
            scanf(" %[^\n]", l.ISBN);
            fseek(f, -sizeof(Libro), SEEK_CUR);
            fwrite(&l, sizeof(Libro), 1, f);
            printf("Libro modificato\n");
            fclose(f);
            return;
        }
    }
    printf("Libro non presente nella biblioteca\n");
    fclose(f);
}
void separa_libri(){                //separa i libri nei due file
    Libro l;
    FILE* f = fopen("2026_04_28_biblioteca.dat", "rb");
    if(f == NULL){
        printf("Errore nell'apertura del file\n");
        exit(1);
    }
    FILE* f_min = fopen("2026_04_28_biblioteca_min2000.dat", "wb");
    if(f_min == NULL){
        printf("Errore nell'apertura del file\n");
        exit(1);
    }
    FILE* f_magg = fopen("2026_04_28_biblioteca_magg2000.dat", "wb");
    if(f_magg == NULL){
        printf("Errore nell'apertura del file\n");
        exit(1);
    }
    while(fread(&l, sizeof(Libro), 1, f)){
        if(l.anno < ANNO)
           fwrite(&l, sizeof(Libro), 1, f_min);
        else
            fwrite(&l, sizeof(Libro), 1, f_magg);
    }
    fclose(f);
    fclose(f_min);
    fclose(f_magg);
    printf("Elenco libri separato\n");
}

int main(){
    char ISBN[20], autore[30];
    int scelta;
    do{
        stampa_menu(&scelta);
        switch(scelta){
            case 1:
                aggiungi_libro();
                break;
            case 2:
                printf("Inserisci l'ISBN del libro da cercare: ");
                scanf(" %[^\n]", ISBN);
                ricerca_libro(ISBN);
                break;
            case 3:
                printf("Inserisci il titolo del libro da modificare: ");
                scanf(" %[^\n]", autore);
                modifica_ISBN(autore);
                break;
            case 4:
                separa_libri();
                break;
            case 5:
                stampa_biblioteca();
                break;
            case 0:
                printf("Programma terminato\n");
                break;
            default:
                printf("Scelta effettuata non valida\n");
        }
    }while(scelta != 0);
    return 0;
}