/*Data una stringa, contare il numero delle vocali*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef char* string;

void compatta(string str, int len){
    if(len>0 && str[len-1]=='\n'){
        str[len-1] = '\0';
        len--;
    }
}

int contaVocali(string str){
    int i=0, cnt=0;
    char c;
    while(str[i]!='\0'){
        c = tolower(str[i]);
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')   cnt++;
        i++;
    }
    return cnt;
}

int main(){
    char buffer[200];
    int len, vocali=0;
    string frase=NULL;
    printf("Inserisci una stringa: ");
    fgets(buffer, sizeof(buffer), stdin);
    len = strlen(buffer);
    compatta(buffer, len);
    frase = (string)malloc((len+1)*sizeof(char));
    if(frase==NULL) return 1;
    strcpy(frase, buffer);
    vocali = contaVocali(frase);
    printf("Il numero delle vocali è: %d\n", vocali);
    return 0;
}