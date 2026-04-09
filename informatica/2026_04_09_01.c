/*file binario*/
#include <stdio.h>

int main(){
    FILE *f = fopen("2026_04_09_01.bin", "wb");
    int numeri_scritti[3] = {10, 20, 30};
    if(f == NULL){
        printf("Errore nell'apertura del file\n");
        return 1;
    }
    fwrite(numeri_scritti, sizeof(int), 3, f);
    fclose(f);
    
    FILE *fp = fopen("2026_04_09_01.bin", "rb");
    int numeri_letti[3];
    if(f == NULL){
        printf("Errore nell'apertura del file\n");
        return 1;
    }
    fread(numeri_letti, sizeof(int), 3, fp);
    for(int i=0; i<3; i++){
        printf("%d ", numeri_letti[i]);
    }
    fclose(fp);
    return 0;
}