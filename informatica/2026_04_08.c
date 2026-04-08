/*Scrivere un programma che inverta ogni riga contenuta nel file righe.txt e riporti il risultato 
sullo schermo. Per esempio la riga "PROVA DI STAMPA"  diventa "APMATS ID AVORP"*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inverti_riga(char* riga){
    int n = strlen(riga);

    if (n > 0 && riga[n - 1] == '\n') {
        riga[n - 1] = '\0';
        n--;
    }

    for (int i = 0; i < n / 2; i++) {
        char tmp = riga[i];
        riga[i] = riga[n - 1 - i];
        riga[n - 1 - i] = tmp;
    }
}

int main(){
    int dim = 256;
    char riga[dim];
    FILE* f = fopen("2026_04_08.txt", "r");
    if(f == NULL){
        perror("fopen");
        return 1;
    }
    while(fgets(riga, sizeof(riga), f)){
        inverti_riga(riga);
        printf("%s\n", riga);
    }
    fclose(f);
    return 0;
}