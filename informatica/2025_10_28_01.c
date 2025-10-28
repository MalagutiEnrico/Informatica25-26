/*Provare la libreria string.h
1. Calcolo lunghezza stringa
2. Controllo stringhe uguali
3. Copiare una stringa
4. Cercare un carattere e comunicare la frequenza
5. Concatenare due stringhe
6. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* string;

int charFreq(string str, char c){
    int freq=0, i=0;
    while(str[i]!='\0'){
        if(str[i]==c)   freq++;
        i++;
    }
    return freq;
}

int main(){
    char str1[100], str2[100], c;
    string copia;
    int len, freq=0;
    printf("Inserisci la prima stringa:\n");
    fgets(str1, 100, stdin);
    printf("Inserisci la seconda stringa:\n");
    fgets(str2, 100, stdin);
    //calcolo lunghezza stringa
    len = strlen(str1);
    printf("La lunghezza della prima stringa è di %d\n", len);
    //compara stringhe
    if(strcmp(str1, str2) == 0)  printf("Le due stringhe sono uguali.\n");
    else                    printf("Le due stringhe sono diverse.\n");
    //copia stringhe
    copia = (string)malloc(len*sizeof(char));
    strcpy(copia, str1);
    printf("La stringa copiata: %s\n", copia);
    //cerca carattere
    printf("Inserisci il carattere da cercare: ");
    scanf(" %c", &c);
    freq = charFreq(str1, c);
    printf("Il carattere %c è presente %d volte.\n", c, freq);
    //concatena due stringhe
    strcat(str1, str2);
    printf("La stringa concatenata: %s\n", str1);
    free(copia);
    return 0;
}