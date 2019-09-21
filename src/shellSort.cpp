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
