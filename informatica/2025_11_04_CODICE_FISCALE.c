#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stringlib.h"
#include "Stringlib.c"

typedef char* String;

#define DIM 16
#define DATA 11

void compatta(String str, int len){
    if(len>0 && str[len-1]=='\n'){
        str[len-1] = '\0';
        len--;
    }
}

Bool isVocale(char c){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')        return true;        //controllo se vocale minuscola
    else if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')   return true;        //controllo se vocale maiuscola
    else                                                                return false;       //non è vocale, ritorna false
}

void shiftDx(int *vett, char c){
    int i=0;
    while(vett[i]!='\0'){
        vett[i] = vett[i+1];
        i++;
    }
}

String calcoloNomi(String str){
    int pos=0, cnt=0;
    String tmp = malloc(4*sizeof(char));
    if(tmp==NULL)   exit(1);
    while(str[pos]!='\0'){
        if(!isVocale(str[pos]) && cnt<3)         tmp[cnt++] = str[pos];
        pos++;
    }
    if(cnt<3){
        pos=0;
        while(cnt<3){
            if(isVocale(str[pos]))             tmp[cnt++] = str[pos];
        }
        pos++;
    }
    return tmp;
}

void calcolaAnagrafica(String* matrix){
    for(int i=0; i<2; i++){
        if(i==0)    printf("Inserisci il nome: ");
        else        printf("Inserisci il cognome: ");
        matrix[i] = creaStringa('\n');
        compatta(matrix[i], lenString(matrix[i]));
        matrix[i] = calcoloNomi(matrix[i]);
    }
}

void calcolaData(String *matrix){
    String dataNascita;
    int pos=2;
    printf("Inserisci la data di nascita (formato gg/mm/aa): ");
    dataNascita = creaStringa('\n');
    for(int i=0; i<3; i++){
        matrix[i] = malloc(3*sizeof(char));
        matrix[i] = strtok(dataNascita, "/");
        shiftDx(matrix[i], '/');
        pos+=2;
        printf("%s\n", matrix[i]);
    }
    
}

int main(){
    char codiceFiscale[DIM+1], genere;
    String *anagrafica = malloc(2*sizeof(String));
    String *dataNascitaSep = (String)malloc(3*sizeof(char));
    printf("*****Calcolo Codice Fiscale*****\n");
    calcolaAnagrafica(anagrafica);
    calcolaData(dataNascitaSep);
    printf("Inserisci il genere: ");
    scanf(" %c", &genere);
    return 0;
}