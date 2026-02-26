/*Data la struct prodotto (nome, codice, quantità, prezzo) eseguire:
1. inserire un prodotto
2. stampare elenco prodotti
3. cercare un prodotto per codice
4. calcolare valore totale del magazzino*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct prodotto{
    char nome[20];
    int codice;
    int quantita;
    float prezzo;
}prodotto;

void clear_buffer(){                                //pulisci il buffer di stdin
    char c;
    while((c = getchar()) && c != '\n') {}
}

void controlla_allocazione(void* ptr){              //controlla l'esito dell'allocazione di un puntatore
    if(ptr == NULL){
        printf("Errore nell'allocazione della memoria.\n");
        exit(1);
    }
}

void stampa_menu(int* scelta){                      //stampa a video il menu di scelta
    printf("===========Gestione Magazzino===========\n");
    printf("1.Inserisci un prodotto\n2.Stampa elenco prodotti\n3.Cerca un prodotto per codice\n4.Calcola il valore del magazzino\n0.Esci\nEffettua una scelta: ");
    scanf("%d", &*scelta);
    clear_buffer();
}

void set_prodotto(prodotto* p){                                //permette di inserire i campi di un prodotto
    printf("Inserisci il nome del prodotto: ");
    fgets(p->nome, 20, stdin);
    printf("Inserisci il codice del prodotto: ");
    scanf("%d", &p->codice);
    clear_buffer();
    printf("Inserisci la quantità' del prezzo: ");
    scanf("%d", &p->quantita);
    printf("Inserisci il prezzo del prodotto: ");
    scanf("%f", &p->prezzo);
}

prodotto* inserisci_prodotto(prodotto* magazzino, int* dim){        //inserisce un prodotto all'interno del magazzino
    (*dim)++;
    prodotto* nuovo = (prodotto*)realloc(magazzino, (*dim)*sizeof(prodotto));
    controlla_allocazione(nuovo);
    set_prodotto(&nuovo[(*dim)-1]);
    return nuovo;
}

void stampa_prodotto(prodotto p){                               //stampa a video un prodotto
    printf("Nome: %s\nCodice: %d\nQuantita': %d\nPrezzo: %.2f\n", p.nome, p.codice, p.quantita, p.prezzo);
}

int cerca_prodotto_codice(prodotto* magazzino, int dim, int codice){        //cerca un prodotto tramite codice. ritorna alla posizione dell'elemento se lo trova; altrimenti ritorna a -1
    for(int i=0; i<dim; i++){
        if(magazzino[i].codice == codice)
            return i;
    }
    return -1;
}

float calcola_valore(prodotto* magazzino, int dim){
    float somma = 0;
    for(int i=0; i<dim; i++){
        somma += magazzino[i].quantita * magazzino[i].prezzo;
    }
    return somma;
}

int main(){
    prodotto* magazzino = NULL;
    int dim=0,scelta, pos, codice;
    float somma;
    do{
        stampa_menu(&scelta);
        switch(scelta){
            case 1:
                magazzino = inserisci_prodotto(magazzino, &dim);
                break;
            case 2:
                if(dim == 0)
                    printf("Magazzino vuoto.\n");
                else{
                    printf("==========MAGAZZINO=========\n");
                    for(int i=0; i<dim; i++){
                        stampa_prodotto(magazzino[i]);
                        printf("======================");
                    }
                }
                break;
            case 3:
                printf("Inserisci il codice del prodotto da cercare: ");
                scanf("%d", &codice);
                pos = cerca_prodotto_codice(magazzino, dim, codice);
                if(pos == -1)
                    printf("Prodotto non presente all'interno del magazzino\n");
                else{
                    printf("========Prodotto trovato=======\n");
                    stampa_prodotto(magazzino[pos]);
                }
                break;
            case 4:
                somma = calcola_valore(magazzino, dim);
                printf("Il valore del magazzino è %.2f\n", somma);
                break;
            case 0:
                printf("Programma terminato\n");
                break;
            default:
                printf("Scelta inserita non valida\n");
        }
    }while(scelta != 0);
    free(magazzino);
    return 0;
}