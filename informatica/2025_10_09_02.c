/*Stringhe con malloc*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char* buffer=NULL;
    int len;
    printf("Inserisci la lunghezza della stringa:");
    scanf("%d", &len);
    buffer = (char *)malloc((len+1)*sizeof(char));       //il +1 è per il carattere terminatore
    if(buffer == NULL)  return -1;
    printf("Inserisci la stringa: ");
    fgets(buffer, (len+1), stdin);
    printf("Hai inserito: %s\n", buffer);
    free(buffer);
    return 0;
}