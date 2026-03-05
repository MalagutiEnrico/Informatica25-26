#include <stdio.h>

typedef struct{
    char nome[20];
    char cognome[20];
    int eta;
}Persona;

void clear_buffer(){
    char c;
    while((c = getchar()) && c!= '\n'){}
}

int main(){
    int numero;
    Persona p;
    FILE *file = fopen("2026_03_05_03.txt","w");
    if(file == NULL){
        printf("Errore nell'apertura del file\n");
        return -1;
    }
    printf("Inserisci il numero di persone da memorizzare: ");
    scanf("%d", &numero);
    clear_buffer();
    for(int i=0; i<numero; i++){
        printf("Inserisci il nome della %d persona: ", i);
        fgets(p.nome, 20, stdin);
        printf("Inserisci il cognome della %d persona: ", i);
        fgets(p.cognome, 20, stdin);
        printf("Inserisci l'eta' della %d persona: ", i);
        scanf("%d", &p.eta);
        clear_buffer();
        fprintf(file, "%s %s %d", p.nome, p.cognome, p.eta);        //scrivi di volta in volta i dati su file
    }
    printf("Scrittura terminata\n");
    fclose(file);
    return 0;
}