/*Creare una rubrica che gestisca la memorizzazione dei contatti e ne visualizzi 
l'elenco*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[20];
    char telefono[15];
}Contatto;

void clear_buffer(){                        //pulisce il buffer di stdin
    char c;
    while((c = getchar()) != '\n'){}
}

void stampa_menu(int* scelta){              //stampa il menu di scelta e salva la scelta dell'utente
    printf("\n==========MENU RUBRICA=========\n");
    printf("1.Aggiungi un contatto\n2.Visualizza i Contatti\n0.Esci\nEffettua la scelta: ");
    scanf("%d", &*scelta);
    clear_buffer();
}

void set_contatto(Contatto *c){             //riempie i campi di un contatto
    printf("Insersci il nome: ");
    scanf("%[^\n]", c->nome);
    clear_buffer();
    printf("Inserisci il numero di telefono: ");
    scanf("%[^\n]", c->telefono);
    clear_buffer();
}

void aggiungi_contatto(){                   //aggiunge un contatto all'interno del file
    FILE *f = fopen("2026_04_09_02_rubrica.bin", "ab");
    if(f == NULL){
        printf("Errore nell'apertura del file\n");
        return;
    }
    Contatto c;
    set_contatto(&c);
    fwrite(&c, sizeof(Contatto), 1, f);
    printf("Contatto salvato correttamente\n");
    fclose(f);
}

void stampa_contatti(){                     //stampa i contatti contenuti nel file
    FILE *f = fopen("2026_04_09_02_rubrica.bin", "rb");
    if(f == NULL){
        printf("Errore nell'apertura del file\n");
        return;
    }
    Contatto c;
    int cnt=0;
    printf("\n===========Contatti Salvati=========\nNome\tNumero\n");
    while(fread(&c, sizeof(Contatto), 1, f) != 0){
        printf("%s\t%s\n", c.nome, c.telefono);
        cnt++;
    }
    printf("Contatti Salvati: %d\n", cnt);
    fclose(f);
}

int main(){
    int scelta;
    do{
        stampa_menu(&scelta);
        switch(scelta){
            case 1:
                aggiungi_contatto();
                break;
            case 2:
                stampa_contatti();
                break;
            case 0:
                printf("Programma terminato\n");
                break;
            default:
                printf("Scelta inserita non valida\n");
        }
    }while(scelta != 0);
    return 0;
}