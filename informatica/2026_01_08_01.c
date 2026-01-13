/*Classe di studenti:
Cognome, Nome, classe, Matricola
Per ogni studente dotato di matricola abbiamo le informazioni riguardanti gli esami e il livello raggiunto
1)Calcola lo studente che ha più certificazioni*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char cognome[20];
    char nome[20];
    char classe[3];
    int matricola;  //da 1000 a 9999
}Studente;

typedef struct{
    char corso[20];
    int livello;
}Esame;

typedef struct{
    int matricola;
    Esame esame;
}Certificazioni;

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

void stampa_menu(int *scelta){                                  //stampa a video il menu di scelta
    printf("=====Gestioni studenti e esami=====\n");
    printf("1)Inserisci uno studente.\n2)Inserisci una certificazione\n3)Calcola lo studente con più certificazioni\n0)Esci dal programma\n");
    printf("Effettua la scelta: ");
    scanf("%d", &*scelta);
    clear_buffer();
}

Studente* aggiungi_alunno(Studente* s, int *dim){               //aggiunge uno studente al vettore studente
    (*dim)++;
    Studente* tmp = realloc(s, (*dim)*sizeof(Studente));
    controlla_allocazione(s);
    return tmp;
}

void set_alunno(Studente* s){                                   //riempie i campi dello studente
    printf("Inserisci il nome dell'alunno: ");
    fgets(s->nome, 20, stdin);
    printf("Inserisci il cognome dell'alunno: ");
    fgets(s->cognome, 20, stdin);
    printf("Insersci la classe dello studente: ");
    fgets(s->classe, 3, stdin);
    do{
        printf("Inserisci la matricola dello studente[1000-9999]: ");
        scanf("%d", &s->matricola);
        if(s->matricola < 1000 || s->matricola > 9999)
            printf("Matricola inserita non valida.\n");
    }while(s->matricola < 1000 || s->matricola > 9999);
    clear_buffer();
}

Certificazioni* aggiungi_certificazione(Certificazioni* c, int* dim){
    (*dim)++;
    Studente* tmp = realloc(c, (*dim)*sizeof(Studente));
    controlla_allocazione(c);
    return tmp;
}

void set_certificazione(Certificazioni* c){                     //riempie i campi della certificazione
    do{
        printf("Inserisci la matricola dello studente[1000-9999]: ");
        scanf("%d", &c->matricola);
        if(c->matricola < 1000 || c->matricola > 9999)
            printf("Matricola inserita non valida.\n");
    }while(c->matricola < 1000 || c->matricola > 9999);
    clear_buffer();
    printf("Inserisci il corso completato dallo studente: ");
    fgets(c->esame.corso, 20, stdin);
    printf("Inserisci il livello raggiunto dallo studente: ");
    scanf("%d", &c->esame.livello);
    clear_buffer();
}

int main(){
    Studente* alunni=malloc(3*sizeof(Studente));
    Certificazioni* certificazioni=malloc(sizeof(Certificazioni));
    int scelta, dim_alunni=0, dim_certificazioni=0;
    do{
        stampa_menu(&scelta);
        switch(scelta){
            case 1:
                alunni = aggiungi_alunno(alunni, &dim_alunni);
                set_alunno(&alunni[dim_alunni-1]);
                break;
            case 2:
                certificazioni = aggiungi_certificazione(certificazioni, &dim_certificazioni);
                set_certificazione(&certificazioni[dim_certificazioni-1]);
                break;
            case 3:
                //da completare
                break;
            default:
                printf("Scelta inserita non valida.\n");
        }
    }while(scelta!=0);
    free(alunni);
    free(certificazioni);
    return 0;
}