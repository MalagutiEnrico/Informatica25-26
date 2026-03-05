//scrivi dati su un file
#include <stdio.h>

int main(){
    //scrivi i dati su un file
    FILE *file = fopen("2026_03_05_01.txt", "w");      //apri il file in lettura

    if(file == NULL){
        printf("Errore nell'apertura del file\n");
        return -1;
    }
    fprintf(file, "Ciao mondo!\n");
    fprintf(file, "prova di scrittura con numero %d\n", 5);

    fclose(file);                                   //chiudi il file aperto
    
    //leggi i dati dal medesimo file
    FILE *file2 = fopen("2026_03_05_01.txt", "r");
    char stringa[100];
    if(file2 == NULL){
        printf("Errore nell'apertura del file\n");
        return -1;
    }

    while(fgets(stringa, 100, file2) != NULL){      //finchè continua a trovare righer le stampa a video
        printf("%s", stringa);
    }

    fclose(file2);
    return 0;
}