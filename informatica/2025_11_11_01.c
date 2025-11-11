/*Scrivere un programma che simuli il cifrario di Cesare*/
#include <stdio.h>
#include <stdlib.h>
#include "Stringlib.h"
#include "Stringlib.c"

typedef char* string;

string cifra(string str, int key){
    int i=0, controllo=0;
    string tmp = malloc(lenString(str)*sizeof(char));
    if(tmp==NULL)   exit(1);
    while(str[i]!='\0'){
        controllo = 0;
        if(str[i]+key>122){
            controllo = 26;
        }
        tmp[i] = str[i] + key - controllo;
        i++;
    }
    return tmp;
}

string decifra(string str, int key){
    int i=0, controllo=0;
    string tmp = malloc(lenString(str)*sizeof(char));
    if(tmp==NULL)   exit(1);
    while(str[i]!='\0'){
        controllo = 0;
        if(str[i]-key<97){
            controllo = 26;
        }
        tmp[i] = str[i] - key + controllo;
        i++;
    }
    return tmp;
}

int main(){
    string stringa, stringamodificata;
    int chiave, scelta;
    printf("Inserisci la stringa: ");
    stringa = creaStringa('\n');
    do{
        printf("Inserisci il fattore di cifratura: ");
        scanf("%d", &chiave);
        if(chiave<0 || chiave>25)
            printf("Chiave inserita non valida.\n");
    }while(chiave<0 || chiave>25);
    printf("Inserisci uno per cifrare la frase; inserisci due per decifrarla: ");
    scanf("%d", &scelta);
    stringamodificata = malloc(lenString(stringa)*sizeof(char));
    if(scelta==1){
        stringamodificata = cifra(stringa, chiave);
        printf("La stringa cifrata: %s\n", stringamodificata);
    }
    else{
        stringamodificata = decifra(stringa, chiave);
        printf("La stringa decifrata: %s\n", stringamodificata);
    }
    free(stringa);
    free(stringamodificata);
    return 0;
}