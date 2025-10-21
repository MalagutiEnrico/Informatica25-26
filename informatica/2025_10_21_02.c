/*Data una stringa, rimuovere tutti gli spazi*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* string;

void compatta(string str, int len){
    if(len>0 && str[len-1]=='\n'){
        str[len-1] = '\0';
        len--;
    }
}

void shiftDX(string str, int pos, int len){
    for(int i=pos; i<len; i++){
        str[i] = str[i+1];
    }
}

void togliSpazi(string str, int *len){
    int i=0;
    while(str[i]!='\0'){
        if(str[i]==' '){
            shiftDX(str, i, *len);
            (*len)--;
            i--;                    //decrementa la i per evitare di saltare un carattere durante il confronto
        }
        i++;
    }
}

int main(){
    char buffer[200];
    int len;
    string frase=NULL;
    printf("Inserisci una stringa: ");
    fgets(buffer, sizeof(buffer), stdin);
    len = strlen(buffer);
    compatta(buffer, len);
    frase = (string)malloc((len+1)*sizeof(char));
    if(frase==NULL) return 1;
    strcpy(frase, buffer);
    togliSpazi(frase, &len);
    printf("Frase senza spazi: %s\n", frase);
    return 0;
}