#include "../include/shellSort.h"

void shellSort(int *Array, int tamanhoVetor){
    int i, j, valor;
int gap = 1;
    while(gap < tamanhoVetor) {
        gap = 2*gap+1;
    }
    while (gap > 0) {
        for(i = gap; i <= tamanhoVetor; i++) {
            valor = Array[i];
            j = i;
            while (j > gap-1 && valor <= Array[j-gap]) {
                Array[j]= Array[j - gap];
                j = j - gap;
            }
            Array[j] = valor;
        }
        gap = gap/2;
    }
}
/*int gap = tamanhoVetor/2;
    do{
        int aux;
        for(i = 0; i < tamanhoVetor - gap; i++){
            if(Array[i]>Array[i+gap]){
               std::swap(Array[i],Array[i+gap]);
            }
        }
        gap = gap/2;
    } while( gap > 0);
}*/