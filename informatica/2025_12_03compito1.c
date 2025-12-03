/* creare una struct Squadra contenente le seguenti 
informazioni: nome, colore, punteggio e le informazioni del proprio  
alenatore(nome, cognome, titoli)
caricato un massimo di 10 squadre stampare quelle 
con punteggio superiore a 100 e numero di titoli per allenatore superiore a 10
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[20];
    char cognome[20];
    int titoli;
}allenatore;

typedef struct{
    char nome[20];
    char colore[20];
    int punteggio;
    allenatore coach;
}squadra;

void clearBuffer(){
    char c;
    while((c=getchar()) != '\n'){}
}

void riempiAllenatore(squadra* team){
    printf("Inserisci il nome dell'allenatore: ");
    fgets(team->coach.nome, 20, stdin);
    printf("Inserisci il cognome dell'allenatore: ");
    fgets(team->coach.cognome, 20, stdin);
    printf("Inserisci i titoli vinti dall'allenatore: ");
    scanf("%d", &team->coach.titoli);
    clearBuffer();
}

void riempiSquadra(squadra* team){
    printf("Inserisci il nome della squadra: ");
    fgets(team->nome, 20, stdin);
    printf("Inserisci il colore della squadra: ");
    fgets(team->colore, 20, stdin);
    printf("Inserisci il punteggio della squadra: ");
    scanf("%d", &team->punteggio);
    clearBuffer();
    riempiAllenatore(team);
}

void stampaSquadra(squadra team){
    printf("Nome: %sColore: %sPunteggio: %d\n", team.nome, team.colore, team.punteggio);
    printf("Dati allenatore:\n Nome: %sCognome: %sTitoli ottenuti: %d\n", team.coach.nome, team.coach.cognome, team.coach.titoli);
    
}

int main(){
    squadra* teams;
    int num;
    do{
        printf("Inserisci il numero di squadre: ");
        scanf("%d", &num);
        clearBuffer();
    }while(num<=0 || num>10);
    teams = (squadra*)malloc(num*sizeof(squadra));
    for(int i=0; i<num; i++){
        printf("INSERISCI SQUADRA %d\n", i+1);
        riempiSquadra(&teams[i]);
    }
    for(int i=0; i<num; i++){
        if(teams[i].punteggio<100 && teams[i].coach.titoli > 10){
            printf("***********************\n");
            printf("SQUADRA %d\n", i+1);
            stampaSquadra(teams[i]);
        }
    }
    free(teams);
    return 0;
}