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

char calcoloMese(String str){
    char vettore[] = {'A', 'B', 'C', 'D', 'E', 'H', 'L', 'M', 'P', 'R', 'S', 'T'};
    int num = atoi(str);
    return vettore[num-1];
}

String calcoloGiorno(String str, char c){
    if(c == 'f'){
        int num = atoi(str);
        num += 40;
        sprintf(str, "%d", num);
    }
    return str;
}

String* calcolaData(String dataNascita, char c){
    String* tmp = (String*)malloc(DIMDATA*sizeof(String));
    if(tmp == NULL)     exit(1);
    int cnt=0;
    for(int i=0; i<DIMDATA; i++){
        int j=0;
        tmp[i] = malloc(DIMDATA*sizeof(char));
        while(dataNascita[cnt] != '/' && dataNascita[cnt] != '\0'){
            tmp[i][j++] = dataNascita[cnt++];
        }
        tmp[i][j] = '\0';
        cnt++;
    }
    tmp[0] = calcoloGiorno(tmp[0], c);
    tmp[1][0] = calcoloMese(tmp[1]);
    return tmp;
}

void unisciCodice(char *codiceFiscale, String nome, String cognome, String* dataNascita){
    int i=0, index=3;
    for(i; i<index; i++){
        codiceFiscale[i] = cognome[i];
    }
    i++;
    index+=3;
    for(i; i<index; i++){
        codiceFiscale[i] = nome[i];
    }
    codiceFiscale[DIM] ='\0';
}

int main(){
    char codiceFiscale[DIM+1], genere;
    String nome, cognome, dataNascita;
    String* matDataNascita;
    printf("*****Calcolo Codice Fiscale*****\n");
    printf("Inserisci il nome: ");
    nome = creaStringa('\n');
    printf("Inserisci il cognome: ");
    cognome = creaStringa('\n');
    printf("Inserisci la data di nascita (formato gg/mm/aa): ");
    dataNascita = creaStringa('\n');
    printf("Inserisci il genere (m-maschio, f-femmina): ");
    scanf(" %c", &genere);
    nome = calcoloNomi(nome);
    cognome = calcoloNomi(cognome);
    matDataNascita = calcolaData(dataNascita, genere);
    unisciCodice(codiceFiscale, nome, cognome, matDataNascita);
    printf("Il codice fiscale stampato: %s\n", codiceFiscale);
    return 0;
}
