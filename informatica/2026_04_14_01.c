/*Creata una struct Prodotto con nome, id e prezzo. Scrivere su file binario una serie di prodotti. Modificare il prezzo di un prodotto dato il suo ID*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int ID;
    char nome[20];
    float prezzo;
}Prodotto;

void clear_buffer(){                        //pulisce il buffer di stdin
    char c;
    while((c = getchar()) != '\n'){}
}

void stampa_menu(int* scelta){              //stampa il menu di scelta e salva la scelta dell'utente
    printf("\n==========MENU PRODOTTI=========\n");
    printf("1.Aggiungi un prodotto\n2.Visualizza elenco prodotti\n3.Modifica il prezzo di un prodotto\n0.Esci\nEffettua la scelta: ");
    scanf("%d", &*scelta);
    clear_buffer();
}

void set_prodotto(Prodotto *p){                    //riempi i campi di un prodotto
    printf("Inserisci l'ID del prodotto: ");
    scanf("%d", &p->ID);
    clear_buffer();
    printf("Inserisci il nome del prodotto: ");
    scanf("%[^\n]", &p->nome);
    printf("Inserisci il prezzo del prodotto: ");
    scanf("%f", &p->prezzo);
    clear_buffer();
}

void stampa_prodotto(Prodotto p){                   //stampa a video un prodotto
    printf("ID: %d\tNome: %s\tPrezzo: %.2f\n", p.ID, p.nome, p.prezzo);
}

void aggiungi_prodotto(const char* nome_file){            //aggiungi un numero di prodotti scelti dall'utente al file
    int num;
    printf("Inserisci il numero di prodotti da inserire: ");
    scanf("%d", &num);
    clear_buffer();
    FILE *f = fopen(nome_file, "ab");
    if(f == NULL){
        printf("Errore nell'apertura del file\n");
        return;
    }
    Prodotto p;
    for(int i=0; i<num; i++){
        printf("Prodotto numero %d\n", i+1);
        set_prodotto(&p);
        fwrite(&p, sizeof(Prodotto), 1, f);
    }
    fclose(f);
}

void stampa_prodotti(const char* nome_file){           //stampa a video tutto l'elenco di prodotti
    FILE *f = fopen(nome_file, "rb");
    if(f == NULL){
        printf("Errore nell'apertura del file\n");
        return;
    }
    Prodotto p;
    printf("============ELENCO PRODOTTI============\nID\tNome\tPrezzo\n");
    while(fread(&p, sizeof(Prodotto), 1, f)){
        stampa_prodotto(p);
        printf("========================\n");
    }
    fclose(f);
}

void modifica_prodotto(const char* nome_file, int id){         //ricerca e modifica di un prodotto in base al suo ID
    float nuovo_prezzo;
    FILE *f = fopen(nome_file, "rb");
    if(f == NULL){
        printf("Errore nell'apertura del file\n");
        return;
    }
    Prodotto p;
    while(fread(&p, sizeof(Prodotto), 1, f)){
        if(p.ID == id){
            printf("Prodotto trovato\n");
            stampa_prodotto(p);
            printf("Inserisci il nuovo prezzo del prodotto: ");
            scanf("%f", &p.prezzo);
            fseek(f, -sizeof(Prodotto), SEEK_CUR);          //se si mette il meno davanti si torna indietro
            fwrite(&p, sizeof(Prodotto), 1, f);
            fclose(f);
            return;
        }
    }
    printf("Prodotto non presente all'interno del'elenco\n");
    fclose(f);
}

int main(){
    const char *nome_file = "2026_04_14_01_prodotti.dat";
    int id, pos;
    int scelta;
    do{
        stampa_menu(&scelta);
        switch(scelta){
            case 1:
                aggiungi_prodotto(nome_file);
                break;
            case 2:
                stampa_prodotti(nome_file);
                break;
            case 3:
                printf("Inserisci l'ID del prodotto da cercare: ");
                scanf("%d", &id);
                modifica_prodotto(nome_file, id);
                break;
            case 0:
                printf("Programma terminato\n");
                break;
            default:
                printf("Scelta inserita non valida\n");
        }
    }while(scelta != 0);
}