//scrittura di dati formattati
#include <stdio.h>

int main(){
    /*FILE *file = fopen("2026_03_05_02.txt", "w");      //apri il file in lettura

    if(file == NULL){
        printf("Errore nell'apertura del file\n");
        return -1;
    }
    fprintf(file, "%s %d %.2f", "Luca", 12, 6.5);       //scrivi i dati ordinati
    
    fclose(file);
    */
    FILE *file2 = fopen("2026_03_05_02.txt", "r");
    char nome[100];                                     //variabili necessarie per savlare i dati formattati
    int eta;
    float media;

    if(file2 == NULL){
        printf("Errore nell'apertura del file\n");
        return -1;
    }

    fscanf(file2, "%s %d %f", nome, &eta, &media);
    printf("%s %d %.2f", nome, eta, media);
    return 0;
}