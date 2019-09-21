#include "../include/selectionSort.h"

// Implementacao do SelectionSort
void SelectionSort(int *Array, int tam){
    //Percorrer todo o vetor
    for (int indice = 0; indice < tam; ++indice){
        int indiceMenor = indice;
        for (int indiceSeguinte = indice + 1; indiceSeguinte <= tam; ++indiceSeguinte){
            if (Array[indiceSeguinte] < Array[indiceMenor]){
                indiceMenor = indiceSeguinte;
            }
        }
        // troca dos valroes do vetor
        std::swap(Array[indice],Array[indiceMenor]);
    }
}
// Fim SelectionSort