/*Crea una strutturea di tipo squadra che contenga nome, colore, punteggio,
caricate un massimo di 10 squadre stampare quelle con un punteggio inferiore a 100*/
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[20];
    char colore[20];
    int punteggio;
}Squadra;

void inserisciValori(Squadra *teams, int num){
    for(int i=0; i<num; i++){
        printf("Inserisci il nome della squadra: ");
        fgets(teams[i].nome, 20, stdin);
        printf("Inserisci il colore della squadra: ");
        fgets(teams[i].colore, 20, stdin);
        printf("Inserisci il punteggio: ");
        scanf("%d", &teams[i].punteggio);
    }
}

void stampaSquadra(Squadra *teams){
    printf("Squadra: %s Colore: %s Punteggio: %d\n", teams->nome, teams->colore, teams->punteggio);
}

int main(){
    Squadra *teams;
    int num;
    do{
        printf("Inserisci il numero di squadre: ");
        scanf("%d", &num);
        if(num<0 || num>10)
            printf("Il numero di squadre non è valido");
    }while(num<0 || num>10);
    teams = (Squadra*)malloc(num*sizeof(Squadra));
    inserisciValori(teams, num);
    printf("Squadre con punteggio minore di 100: ");
    for(int i=0; i<num; i++){
        if(teams[i].punteggio < 100)
            stampaSquadra(&teams[i]);
    }
    return 0;
}