#include "../include/selectionSort.h"


void SelectionSort(int *Array, int tam) {
    std::cout << "Ordenando com Selection sort" << std::endl;
    for (int indice = 0; indice < tam; ++indice) {
        int indiceMenor = indice;
        for (int indiceSeguinte = indice + 1; indiceSeguinte <= tam; ++indiceSeguinte) {
            if (Array[indiceSeguinte] < Array[indiceMenor]) {
                indiceMenor = indiceSeguinte;
            }
        }
        std::swap(Array[indice],Array[indiceMenor]);
    }
}