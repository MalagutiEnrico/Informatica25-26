/*scrivere una funzione che, preso in ingresso il nome del file contenente interi, lo modifichi in modo tale da contenere gli stessi numeri ordinati in decrescente*/
#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int vett[], int dim){
    int temp, flag=0, i=0;
    while(flag==0){
        flag=1;
        for(int j=0; j<dim-1-i; j++){
            if(vett[j]>vett[j+1]){
                flag=0;
                temp=vett[j];
                vett[j]=vett[j+1];
                vett[j+1]=temp;
            }
        }
        i++;
    }
}

void ordina_file(char* nome){
    int vett[100], i=0;
    FILE *f = fopen(nome, "r");
    if(f == NULL){
        printf("Errore nell'apertura del file\n");
        exit(1);
    }

    //leggi i numeri contenuti nel file, salvali nel vettore incrementando l'indice
    while(fscanf(f, "%d", &vett[i]) == 1){
        printf("Elemento %d: %d\n", i, vett[i++]);
    }
    fclose(f);

    //ordina il vettore
    bubbleSort(vett, i);

    //scrivi i dati ordinati
    f = fopen(nome, "w");
    for(int index = 0; index<i; i++){
        fprintf(f, "%d ", &vett[index]);
    }
}

int main(){
    char nome[50];
    printf("Inserisci il nome del file contenente i numeri: ");
    scanf("%s", nome);

    ordina_file(nome);
    return 0;
}