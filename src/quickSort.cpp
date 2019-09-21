#include "../include/quickSort.h"
#include <chrono>

int partition(int *Array, int inicio, int tamanhoVetor)  
{  
    int pivot = Array[tamanhoVetor]; // pivot  
    int i = (inicio - 1); // Index of smaller element  
  
    for (int j = inicio; j <= tamanhoVetor - 1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (Array[j] < pivot)  
        {  
            i++; // increment index of smaller element  
            std::swap(Array[i], Array[j]);  
        }  
    }  
    std::swap(Array[i + 1], Array[tamanhoVetor]);  
    return (i + 1);  
}  
  
/* The main function that implements QuickSort  
Array[] --> Arrayay to be sorted,  
inicio --> Starting index,  
tamanhoVetor --> Ending index */
void quickSort(int *Array, int begin, int tamanhoVetor)  
{  
    if (begin < tamanhoVetor)  
    {  
        int pi = partition(Array, begin, tamanhoVetor);  
  
        // Separately sort elements before  
        // partition and after partition  
        quickSort(Array, begin, pi - 1);  
        quickSort(Array, pi + 1, tamanhoVetor);  
    }  
}