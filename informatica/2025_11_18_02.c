/*Data una sottostringa, trovare una sottostringa*/
#include <stdio.h>
#include <stdlib.h>

typedef char* string;
typedef enum{false, true} bool;

int lenstringa(string str){
    int len=0;
    while(str[len]!='\0')   len++;
    return len-1;
}

bool cercaStringa(string str, string substr, int lenstr, int lensubstr){
    int i=0, j=0;
    while(str[i] != '\0'){
        if(str[i] == substr[0]){
            j=0;
            while(str[j] == substr[j]){
                if(str[j] != substr[j]){
                    break;
                }
                j++;
            }
            return true;
        }
        i++;
    }
    return false;
}

int main(){
    string stringa, sottoStringa;
    int lenStringa, lenSottostringa;
    printf("Inserisci la stringa: ");
    fgets(stringa, 200, stdin);
    printf("Inserisci la sottostringa da cercare: ");
    fgets(sottoStringa, 200, stdin);
    lenStringa = lenstringa(stringa);
    lenSottostringa = lenstringa(sottoStringa);
    if(lenSottostringa>lenStringa){
        printf("Impossibile cercare. La sottostringa è pià lunga della stringa in cui cercare.\n");
    }
    else{
        if(cercaStringa(stringa, sottoStringa, lenStringa, lenSottostringa)){
            printf("La sottostringa è presente nella stringa principale.\n");
        }
        else{
            printf("La sottostringa non è presente nella stringa principale.\n");
        }
    }
    free(stringa);
    free(sottoStringa);
    return 0;
}