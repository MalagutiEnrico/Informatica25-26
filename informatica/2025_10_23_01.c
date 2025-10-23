/*Data una stringa, determinare se è palindroma*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* string;
typedef enum {false, true} bool;

int lunghezza(string str){
    int len = 0;
    while(str[len]!='\0') len++;
    return len-1;
}

bool palindroma(string str, int len){
    int i=0;
    while(i < (len/2)){
        if(str[i]!=str[len-i-1])  return false;
        else                    i++;
    }
    return true;
}

int main(){
    int len;
    string frase = (string)malloc(100*sizeof(char));
    if(frase == NULL)   return 1;
    printf("Inserisci una stringa: ");
    fgets(frase, 100, stdin);
    len = lunghezza(frase);
    if(palindroma(frase, len))  printf("La frase è palindroma.\n");
    else                        printf("La frase non è palindroma.\n");
    free(frase);
    return 0;
}
    