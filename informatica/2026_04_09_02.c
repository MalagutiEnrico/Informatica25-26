/*Creare una rubrica che gestisca la memorizzazione dei contatti e ne visualizzi 
l'elenco*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[20];
    char telefono[15];
    char sesso;
}Contatto;

void clear_buffer(){                        //pulisce il buffer di stdin
    char c;
    while((c = getchar()) != '\n'){}
}

void stampa_menu(int* scelta){              //stampa il menu di scelta e salva la scelta dell'utente
    printf("\n==========MENU RUBRICA=========\n");
    printf("1.Aggiungi un contatto\n2.Visualizza i Contatti\n3.Elimina un contatto in base al nome\n4.Separa il file in due file in base al sesso\n0.Esci\nEffettua la scelta: ");
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
    do{
        printf("Inserisci il sesso: ");
        scanf("%c", &c->sesso);
        clear_buffer();
        if(c->sesso != 'f' && c->sesso != 'm')
            printf("Sesso inserito non valido\n");
    }while(c->sesso != 'f' && c->sesso != 'm');
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
    printf("\n===========Contatti Salvati=========\nNome\tNumero\tSesso\n");
    while(fread(&c, sizeof(Contatto), 1, f) != 0){
        printf("%s\t%s\t%c\n", c.nome, c.telefono, c.sesso);
        printf("---------------------\n");
        cnt++;
    }
    printf("Contatti Salvati: %d\n", cnt);
    fclose(f);
}

void elimina_contatto(){
    char stringa[20];
    FILE *f = fopen("2026_04_09_02_rubrica.bin", "rb");
    FILE *temp = fopen("temp.bin", "wb");
    if(f == NULL || temp == NULL){
        printf("Errore nell'apertura del file\n");
        return;
    }
    printf("Inserisci il nome del contatto da eliminare: ");
    scanf("%[^\n]", stringa);
    Contatto c;
    while(fread(&c, sizeof(Contatto), 1, f)){
        if(!strcmp(c.nome, stringa)){
            printf("Elemento trovato ed eliminato\n");
        }
        else{
            fwrite(&c, sizeof(Contatto), 1, temp);
        }
    }
    remove("2026_04_09_02_rubrica.bin");
    rename("temp.bin", "2026_04_09_02_rubrica.bin");
    fclose(temp);
}

void separa_contatti(){
    FILE *f = fopen("2026_04_09_02_rubrica.bin", "rb");
    FILE* f_maschi = fopen("2026_04_09_02_rubricaM.bin", "wb");
    FILE* f_femmine = fopen("2026_04_09_02_rubricaF.bin", "wb");
    Contatto c;
    while(fread(&c, sizeof(Contatto), 1, f)){
        if(c.sesso == 'm'){
            fwrite(&c, sizeof(Contatto), 1, f_maschi);
        }
        else{
            fwrite(&c, sizeof(Contatto), 1, f_femmine);
        }
    }
    fclose(f);
    fclose(f_maschi);
    fclose(f_femmine);
    printf("Contatti separati correttamente nei due file");
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
            case 3:
                elimina_contatto();
                break;
            case 4:
                separa_contatti();
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