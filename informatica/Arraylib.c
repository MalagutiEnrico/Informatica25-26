#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void stampaVettore(int vett[], int dim, char sep){
    for(int i=0; i<dim; i++){
        printf("%d%c", vett[i], sep);
    }
}

void riempiVettore(int vett[], int dim){
    for(int i=0; i<dim; i++){
        printf("Inserisci il %d numero del vettore: ", i+1);
        scanf("%d", &vett[i]);
    }
}

void riempiVettoreCasuale(int vett[], int dim, int min, int max){
    srand(time(NULL));
    for(int i=0; i<dim; i++){
        vett[i] = rand()%(max-min+1)+min;
    }
}

void riempiCasualiDiversi(int vett[], int dim, int min, int max){
    srand(time(NULL));
    for(int i=0; i<dim; i++){
        int flag = 0;
        do{
            flag = 0;
            vett[i] = rand()%(max-min+1)+min;
            for(int j=0; j<i; j++){
                if(vett[i] == vett[j]){
                    flag = 1;
                }
            }
        }while(flag=1);
    }
}

int contaValore(int vett[], int dim, int num){
    int cnt=0;
    for(int i=0; i<dim; i++){
        if(vett[i] == num)
            cnt++;
    }
    return cnt;
}

int massimo(int vett[], int dim){
    int max=vett[0];
    for(int i=1; i<dim; i++){
        if(vett[i]>max)
            max = vett[i];
    }
    return max;
}

int minimo(int vett[], int dim){
    int min = vett[0];
    for(int i=0; i<dim; i++){
        if(vett[i]<min)
            min = vett[i];
    }
    return min;
}

int somma(int vett[], int dim){
    int somma=0;
    for(int i=0; i<dim; i++){
        somma += vett[i];
    }
    return somma;
}

float mediaVettore(int vett[], int dim){
    return (float)somma(vett, dim)/dim;
}

void scambia(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int ricercaSequenziale(int vett[], int dim, int val){
    for(int i=0; i<dim; i++){
        if(vett[i] == val)
            return i;
    }
    return -1;
}

int ricercaBinaria(int vett[], int dim, int estInf, int estSup, int val){
    int media=(estInf+estSup)/2;
    if(estInf>estSup)
        return -1;
    if(vett[media] == val)
        return media;
    if(vett[media]>val)
        return ricercaBinaria(vett, dim, media+1, estSup, val);
    else
        return ricercaBinaria(vett, dim, estInf, media-1, val);
}

void shiftDx(int vett[], int dim, int pos){
    for(int i=dim; i>pos; i--){
        vett[i] = vett[i-1];
    }
}

int trovaPosizione(int vett[], int dim, int num){
    int i=0;
    while(vett[i]<num && i<dim){
        i++;
    }
    return i;
}

void riempiVettoreOrdinatoCasuale(int vett[], int dim, int minimo, int massimo) {
    srand(time(NULL));
    int num, pos;
    vett[0] = rand()%(massimo-minimo+1)+minimo;
    for(int i=1; i<dim; i++){
        num = rand()%(massimo-minimo+1)+minimo;
        pos = trovaPosizione(vett, i, num); 
        shiftDx(vett, i, pos);
        vett[pos] = num;
    }
}

void scambiaVettori(int v1[], int v2[], int dim){
    int temp;
    for(int i=0; i<dim; i++){
        temp = v1[i];
        v1[i] = v2[i];
        v2[i] = temp;
    }
}

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

void bubbleSortDec(int vett[], int dim){
    int temp, i=0, flag=0;
    while(flag==0){
        flag=1;
        for(int j=0; j<dim-1-i; j++){
            if(vett[j+1]>vett[j]){
                flag=0;
                temp=vett[j];
                vett[j]=vett[j+1];
                vett[j+1]=temp;
            }
        }
        i++;
    }
}

void quickSort(int v[], int dim, int inizio, int fine){
    int i, j, pivot;
    if(inizio < fine){
        pivot = inizio;
        i = inizio;
        j = fine;
        while(i < j){
            while(v[i] <= v[pivot] && i < fine)
                i++;
            while(v[j] > v[pivot])
                j--;
            if(i < j){
                scambia(&v[i], &v[j]);
            }
        }
        scambia(&v[pivot], &v[j]);
        quickSort(v, dim, inizio, j - 1);
        quickSort(v, dim, j + 1, fine);
    } 
}