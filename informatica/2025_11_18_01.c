/*data una stringa, stamparla ribaltata*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* string;

string invertiStringa(string str){
    int len = strlen(str), i=0;
    string tmp = malloc((len+1)*sizeof(char*));
    if(tmp==NULL)   exit(1);
    tmp[len] = '\0';
    while(str[i]!='\0'){
        tmp[i] = str[len-i-1];
        i++;
    }
    return tmp;
}

int main(){
    string stringa;
    printf("Inserisci la stringa da invertire: ");
    fgets(stringa, 200, stdin);
    printf("Stringa prima: %s\n", stringa);
    stringa = invertiStringa(stringa);
    printf("Stringa invertita: %s\n", stringa);
    free(stringa);
    return 0;
}