//Date due stringhe, concatenarle alternandone i caratteri
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* string;
#define DIM 200

string unisciStringhe(string str1, string str2){
    int len1 = strlen(str1), len2 = strlen(str2);
    int len = len1 + len2 + 1;
    str1[len1] = '\0';
    str2[len2] = '\0';
    int i=0, j1=0, j2;
    string tmp = (string)malloc(len*sizeof(char));
    if(tmp==NULL)   exit(1);
    tmp[len] = '\0';
    while(j1<len1 || j2<len2){
        if(j1<len1)    tmp[i++] = str1[j1++];
        if(j2<len2)     tmp[i++] = str2[j2++];
    }
    return tmp;
}

int main(){
    string str1 = malloc(DIM*sizeof(char)), str2 = malloc(DIM*sizeof(char));
    string result;
    printf("Inserisci la prima stringa: ");
    fgets(str1, DIM, stdin);
    printf("Inserisci la seconda stringa: ");
    fgets(str2, DIM, stdin);
    result = unisciStringhe(str1, str2);
    printf("Stringhe unite: %s\n", result);
    free(str1);
    free(str2);
    free(result);
    return 0;
}