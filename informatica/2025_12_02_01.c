/*esempio di utilizzo di una struct facendo accesso ai campi sia in modalità puntatore, sia in modalità variabile*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[20];
    char cognome[20];
    int eta;
}persona;

int main(){
    persona p1;     //tipo variabile
    persona *p2;    //tipo persona
    
    //inserisci gli elementi all'interno di p1
    printf("Inserisci il nome della persona 1: ");
    scanf("%s", p1.nome);
    fflush(stdin);      //pulisci il buffer stdin
    printf("Inserisci il cognome: ");
    scanf("%s", p1.cognome);
    fflush(stdin);
    printf("Inserisci l'eta della persona: ");
    scanf("%d", &p1.eta);

    //inserisci i dati in p2 e alloca lo spazio
    p2 = malloc(sizeof(persona));
    printf("Inserisci il nome della persona 1: ");
    scanf("%s", p2->nome);
    fflush(stdin);      //pulisci il buffer stdin
    printf("Inserisci il cognome: ");
    scanf("%s", p2->cognome);
    fflush(stdin);
    printf("Inserisci l'eta della persona: ");
    scanf("%d", &p2->eta);

    //stampa i dati della persona 1
    printf("%s %s eta:%d\n", p1.nome, p1.cognome, p1.eta);
    printf("%s %s eta:%d\n", p2->nome, p2->cognome, p2->eta);
    return 0;
}
