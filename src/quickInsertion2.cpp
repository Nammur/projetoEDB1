#include "../include/quickInsertion2.h"

//Implementacao do QuickSort com InsertionSort

//inicio do insertionSort
void insertionSort2(int *Array,int inicio, int tamanhoVetor){
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
//final do insertioSort

//Quick normal
int quickPartition2 (int *Array, int inicio, int tamanhoVetor){  
    // Pivot para particionamento
    int pivot = Array[tamanhoVetor];  
    
    // Indice para o menor elemento
    int i = (inicio - 1);  
  
    // Percorrer todo o vetor
    for (int j = inicio; j <= tamanhoVetor - 1; j++){  
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

void quickSort2(int *Array, int inicio, int tamanhoVetor){  
    if (inicio < tamanhoVetor){  
        int pi = quickPartition2(Array, inicio, tamanhoVetor);  
  
        // Particionamento do vetor
        quickSort2(Array, inicio, pi - 1);  
        quickSort2(Array, pi + 1, tamanhoVetor);  
    }  
}
//Fim Quick normal

//Quick com Insertion
    //++++++++++++++++++++++++++++++++++++++++++++
    //ESSE É A FUNÇÃO QUE DEVE SER CHAMADA NO MAIN
    //++++++++++++++++++++++++++++++++++++++++++++
void quickInsertion2(int *Array, int inicio, int tamanhoVetor){
    while(inicio < tamanhoVetor){
        if(inicio - tamanhoVetor < 10){
            insertionSort2(Array, inicio, tamanhoVetor);
            break;
        }
        else{
            int pivot = quickPartition2(Array, inicio, tamanhoVetor);

            if(pivot - inicio < tamanhoVetor - pivot){
                quickInsertion2(Array, inicio, tamanhoVetor - 1);
                inicio = pivot - 1;
            }
            else{
                quickInsertion2(Array, pivot + 1, tamanhoVetor);
                tamanhoVetor = pivot - 1;
            }
        }
    }
}
//Fim QuickSort com InsertionSort