#include <stdio.h>
#include <stdlib.h>

typedef char* String;
typedef enum {false, true} Bool;

void clearBuffer(){
    int c;
    while(c=getchar()!='\n'){}
}

String creaStringaDimensionata(int dim){
    String str = (String)malloc(dim*sizeof(char));
    if(str==NULL)   exit(1);
    fgets(str, dim, stdin);
    clearBuffer();
    return str;
}

String creaStringa(char terminator){
    int size=0, capacity=10;
    char c;
    String str = (String)malloc(capacity*sizeof(char));
    while((c = getchar())!=terminator && c!= EOF){
        if(size+1>capacity){
            capacity+=10;
            String tmp = (String)realloc(str, capacity*sizeof(char));
            if(tmp == NULL)    exit(1);
            str = tmp;
        }
        str[size++] = c;
    }
    str[size] = '\0';
    return str;
}

int lenString(String str){
    int i=0;
    while(str[i]!='\0')  i++;
    return i-1;
}

String concatString(String str1, String str2, char sep){
    int lenstr1 = lenString(str1);
    int lenstr2 = lenString(str2);
    int totalLen = lenstr1 + lenstr2 + 2;
    int i=0;
    String str3 = (String)malloc(totalLen*sizeof(char));
    if(str3 == NULL)    exit(1);
    for(i=0; i<lenstr1; i++)
        str3[i] = str1[i];
    str3[i] = sep;
    for(int j=0; j<lenstr2; j++){
        i++;
        str3[i] = str2[j];
    }
    str3[totalLen] = '\0';
    return str3;
}

int charFrequency(String str, char character){
    int i=0, freq=0;
    while(str[i]!='\0'){
        if(str[i]==character)   freq++;
    }
    return freq;
}

int stringInString(String str1, String str2){
    int lenstr1 = lenString(str1);
    int lenstr2 = lenString(str2);
    int freq=0, flag=0;
    for(int i=0; i<lenstr1-lenstr2+1; i++){
        if(str1[i] = str2[0]){
            flag = 1;
            for(int j=0; j<lenstr2; j++){
                if(str1[i+j]!=str2[j]){
                    flag = 0;
                    break;
                }
            }
            freq += flag;
        }
    }
    return freq;
}

String* sepString(String str, char sep){
    String* result=NULL;
    int len = lenString(str);
    int lenstr1=0, lenstr2, cnt=0, i=0;
    result = (String*)malloc(2*sizeof(String));
    while(str[i]!=sep)  i++;
    lenstr1 = i+1;
    lenstr2 = len - lenstr1;
    result[0] = malloc(lenstr1*sizeof(char));
    result[1] = malloc(lenstr2*sizeof(char));
    for(int j=0; j<lenstr1; j++)    result[0][j] = str[j];
    result[0][lenstr1] = '\0';
    for(int j=lenstr1; j<len; j++)  result[1][cnt++] = str[j]; 
    result[1][lenstr2] = '\0';
    return result;
}

String copyString(String str){
    int len = lenString(str);
    String copy = malloc(len*sizeof(char));
    if(copy==NULL)  exit(1);
    for(int i=0; i<len; i++){
        copy[i] = str[i];
    }
    return copy;
}

Bool equal(String str1, String str2){
    int lenstr1 = lenString(str1);
    int lenstr2 = lenString(str2);
    if(lenstr1==lenstr2){
        for(int i=0; i<lenstr1; i++){
            if(str1[i]!=str2[i]) return false;
        } return true;
    } else return false;
}

void maiuscMinusc(String str, Bool condition){
    int i=0;
    if(condition){      //se vero converti da maiuscolo a minuscolo
        while(str[i]!='\0'){
            if(str[i]>=65 && str[i]<=90){
                str[i] += 32;
            }
            i++;
        }
    }
    else{               //se falso il contrario
        while(str[i]!='\0'){
            if(str[i]>=97 && str[i]<=122){
                str[i] -= 32;
            }
            i++;
        }
    }
}