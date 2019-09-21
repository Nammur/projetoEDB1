#include "../include/insertionSort.h"

//Implementacao do InsertionSort
void insertionSort(int *Array,int tamanhoVetor){
    int k, auxiliar, n;
    
    //Percorre todo o vetor criado (Array)
    for(k = 1 ; k<= tamanhoVetor ; k++){
        auxiliar = Array[k];
        n = k - 1;

        //Empurra o elemento para o inicio do vetor    
        while(n >= 0 && auxiliar < Array[n]){
            Array[n + 1] = Array[n];
            n--;
        }

        //Próximo elemento do velor;
        Array[n+1] =  auxiliar;
    }
}
//final do InsertioSort