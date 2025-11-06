#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stringlib.h"
#include "Stringlib.c"

typedef char* String;

#define DIM 16
#define DATA 11
#define DIMANAGRAFICA 2
#define DIMDATA 3

void compatta(String str, int len){     //compatta la stringa per eliminare gli spazi vuoti
    if(len>0 && str[len-1]=='\n'){
        str[len-1] = '\0';
        len--;
    }
}

Bool isVocale(char c){                  //controlla se la lettera è una vocale
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')        return true;        //controllo se vocale minuscola
    else if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')   return true;        //controllo se vocale maiuscola
    else                                                                return false;       //non è vocale, ritorna false
}

void shiftDX(String str, int pos){
    int i=pos;
    while(str[i]!='\0')     str[i++] = str[i+1];
}

String calcoloNomi(String str){         //calcola i tre caratteri del nome e del cognome da inserire nel codce fiscale
    int pos=0, cnt=0;
    String tmp = malloc(4*sizeof(char));                                        //crea la stringa per contenere i caratteri
    if(tmp==NULL)   exit(1);
    while(str[pos]!='\0'){
        if(!isVocale(str[pos]) && cnt<3)         tmp[cnt++] = str[pos];         //se incontra una vocale e ha isnerito meno di 3 caratteri, allora inserisci il carattere
        pos++;
    }
    if(cnt<3){                                                                  //se il contatore è minore di tre allora inserisci le vocali mancanti
        pos=0;
        while(cnt<3){
            if(isVocale(str[pos]))             tmp[cnt++] = str[pos++];
        }
    }
    return tmp;
}

void calcolaAnagrafica(String* matrix){
    for(int i=0; i<DIMANAGRAFICA; i++){
        if(i==0)    printf("Inserisci il nome: ");
        else        printf("Inserisci il cognome: ");
        matrix[i] = creaStringa('\n');
        compatta(matrix[i], lenString(matrix[i]));
        matrix[i] = calcoloNomi(matrix[i]);
    }
}

char calcoloMese(String str){
    char vettore[] = {'A', 'B', 'C', 'D', 'E', 'H', 'L', 'M', 'P', 'R', 'S', 'T'};
    int num = atoi(str);
    return vettore[num];
}

char calcoloGiorno(String str, char c){
    if(c == 'f'){
        int num = atoi(str);
        num += 40;
        sprintf(str, "%d", num);
    }
    return str;
}

void calcolaData(String *matrix, char c){
    char dataNascita[15];
    printf("Inserisci la data di nascita (formato gg/mm/aa): ");
    fgets(dataNascita, 15, stdin);
    for(int i=0; i<DIMDATA; i++){
        matrix[i] = malloc(DIMDATA*sizeof(char));
        matrix[i] = strtok(dataNascita, "/\0");
        printf("%s\n", matrix[i]);
    }
    //matrix[1] = calcoloMese(matrix[1]);
    //matrix[2] = calcoloGiorno(matrix[2], c);
}

String compattaCodice(char dest, String* strNomi, String* strData){

}

int main(){
    char codiceFiscale[DIM+1], genere;
    String *anagrafica = malloc(2*sizeof(String));
    String *dataNascitaSep = (String)malloc(DIMDATA*sizeof(char));
    printf("*****Calcolo Codice Fiscale*****\n");
    calcolaAnagrafica(anagrafica);
    printf("Inserisci il genere(m-maschio, f-femmina): ");
    scanf(" %c", &genere);
    calcolaData(dataNascitaSep, genere);
    compattaCodice(codiceFiscale, anagrafica, dataNascitaSep);
    printf("Il codice fiscale stampato: %s\n", codiceFiscale);
    return 0;
}