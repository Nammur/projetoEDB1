#include "../include/bubbleSort.h"
#include <chrono>

void bubbleSort(int  *Array, int  tamanhoVetor){
    int  n;
    int  k;
    //Percorre todo o vetor criado (Array)
    std::cout << "Ordenando com Bubble sort" << std::endl;
    for(k = 0 ; k < tamanhoVetor ; k++){
        //Percorrer o vetor procurando os pares para fazermos a troca
        for(n = 0; n < tamanhoVetor - k ; n++){
            //Se o valor comparado for menor que o próximo valor
            //será realizada a troca 
            if(Array[n] > Array[n+1]){
                std::swap(Array[n],Array[n+1]);
            }
        }
    }
}