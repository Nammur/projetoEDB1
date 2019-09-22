#include "../include/quickSort.h"
#include <chrono>

//Implementacao do QuickSort
int quickPartition (int *Array, int begin, int tamanhoVetor){  
    // Pivot para particionamento
    int pivot = Array[tamanhoVetor];  
    
    // Indice para o menor elemento
    int i = (begin - 1);  
  
    // Percorrer todo o vetor
    for (int j = begin; j <= tamanhoVetor - 1; j++){  
        // Condional para testar se o elemento é menor
        // que o pivot  
        if (Array[j] < pivot){  
            i++;  
            std::swap(Array[i], Array[j]);  
        }  
    }
    // Troca dos elementos  
    std::swap(Array[i + 1], Array[tamanhoVetor]);  
    
    return (i + 1);  
}

void quickSort(int *Array, int begin, int tamanhoVetor){  
    if (begin < tamanhoVetor){  
        int pi = quickPartition(Array, begin, tamanhoVetor);  
  
        // Particionamento do vetor
        quickSort(Array, begin, pi - 1);  
        quickSort(Array, pi + 1, tamanhoVetor);  
    }  
}
// Fim QuickSort