#include <iostream>
#include <time.h>
#include <algorithm>
#include <chrono>
#include <stdlib.h> 
#include <stdio.h> 

// Arquivos de cabecalho das funcoes
#include "../include/insertionSort.h"
#include "../include/bubbleSort.h"
#include "../include/quickSort.h"
#include "../include/shuf.h"
#include "../include/mergeSort.h"
#include "../include/selectionSort.h"
#include "../include/menu.h"
#include "../include/shellSort.h"
#include "../include/radixSort.h"

int main(){
    
    srand (time(NULL));
    
    //Variavel para armazenar o valor máximo de valores a ser armazenado
    //de forma aleatória.
    //Variaveis aleatórias até limiteAleatorio
    int valor = 0; 
    int begin = 0;
    int range = 0;
    int  selecao, selecaoVetor;;
    int  tamanhoVetor, i;
    std::cout << "Qual o tamanho do vetor?\n";
    std::cin >> tamanhoVetor;
    int meioVetor = tamanhoVetor/2;
    int umQuartoVetor = tamanhoVetor/4;

    
    //Auxiliares na ordenacao do insertion sort
    //i =  indice
    //int  i;    
    //Alocacao dinamica de um ponteiro que aponta para um array de x posições
    int  *Array = new int  [tamanhoVetor];
    int  *ArrayIndex  = new int [tamanhoVetor];
    std::cout << "Selecione como deseja o vetor inicialmente\n" 
                 "1) Ordem Crescente\n"   
                 "2) 50% ordenado\n"
                 "3) 25% ordenado\n"
                 "4) 75% ordenado\n"
                 "5) Posições aleatórias\n"
                 "6) Ordem decrescente \n";
    std::cin >> selecaoVetor;
 
        for(i = 0 ; i<= tamanhoVetor; i++){
            Array[i] = valor;
            ArrayIndex[i] = valor;
            valor ++;
        }
/*
    //Selecao do Shell Sort
    if(selecao == 4){
        // ======================Shell SORT=================
    }
    //Selecao do Radix Sort
    if(selecao == 7){
        // ======================RADIX SORT=================
    }
    quick com insertion ? ------
    
*/  
    std::cout << "\n===============================\n"
                 "===== COMECANDO ORDENACAO =====\n" 
                 "===============================\n" << std::endl;

    // InsertionSort
    std::cout << "Ordenando com o InsertionSort" << std::endl;
    menu(Array, ArrayIndex, tamanhoVetor,selecaoVetor);
    auto inicio = std::chrono::high_resolution_clock::now();  
    insertionSort(Array, tamanhoVetor);
    auto resultado = std::chrono::high_resolution_clock::now() - inicio;
    long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(resultado).count();
    std::cout << "Ordenacao concluida. Tempo de execução do insertionSort: " << microseconds << " microsegundos \n\n";

    // SelectionSort
    std::cout << "Ordenando com o SelectionSort" << std::endl;
    menu(Array, ArrayIndex, tamanhoVetor,selecaoVetor);
    auto inicio3 = std::chrono::high_resolution_clock::now(); 
    SelectionSort(Array, tamanhoVetor);
    auto resultado3 = std::chrono::high_resolution_clock::now() - inicio3;
    long long microseconds3 = std::chrono::duration_cast<std::chrono::microseconds>(resultado3).count();
    std::cout << "Ordenacao concluida. Tempo de execução do SelectionSort: " << microseconds3 << " microsegundos \n\n";

    // BubbleSort
    std::cout << "Ordenando com o BubbleSort" << std::endl;
    menu(Array, ArrayIndex, tamanhoVetor,selecaoVetor);
    auto inicio4 = std::chrono::high_resolution_clock::now();
    bubbleSort(Array, tamanhoVetor);
    auto resultado4 = std::chrono::high_resolution_clock::now() - inicio4;
    long long microseconds4 = std::chrono::duration_cast<std::chrono::microseconds>(resultado4).count();
    std::cout << "Ordenacao concluida. Tempo de execução do BubbleSort: " << microseconds4 << " microsegundos \n\n";

    // QuickSort
    std::cout << "Ordenando com QuickSort" << std::endl;
    menu(Array, ArrayIndex, tamanhoVetor,selecaoVetor);
    auto inicio5 = std::chrono::high_resolution_clock::now();
    quickSort(Array,begin, tamanhoVetor);
    auto resultado5 = std::chrono::high_resolution_clock::now() - inicio5;
    long long microseconds5 = std::chrono::duration_cast<std::chrono::microseconds>(resultado5).count();
    std::cout << "Ordenacao concluida. Tempo de execução do QuickSort: " << microseconds5 << " microsegundos \n\n";

    // MergeSort
    std::cout << "Ordenando com MergeSort" << std::endl;
    menu(Array, ArrayIndex, tamanhoVetor,selecaoVetor);
    auto inicio2= std::chrono::high_resolution_clock::now();
    mergeSort(Array, begin, tamanhoVetor); 
    auto resultado2 = std::chrono::high_resolution_clock::now() - inicio2;
    long long microseconds2 = std::chrono::duration_cast<std::chrono::microseconds>(resultado2).count();
    std::cout << "Ordenacao concluida. Tempo de execução do MergeSort: " << microseconds2 << " microsegundos \n\n";

    // ShellSort
    std::cout << "Ordenando com ShellSort" << std::endl;
    menu(Array, ArrayIndex, tamanhoVetor,selecaoVetor);
    auto inicio6= std::chrono::high_resolution_clock::now();
    shellSort(Array, tamanhoVetor); 
    auto resultado6 = std::chrono::high_resolution_clock::now() - inicio6;
    long long microseconds6 = std::chrono::duration_cast<std::chrono::microseconds>(resultado6).count();
    std::cout << "Ordenacao concluida. Tempo de execução do ShellSort: " << microseconds6 << " microsegundos \n\n";

    // RadixSort
    std::cout << "Ordenando com RadixSort" << std::endl;
    menu(Array, ArrayIndex, tamanhoVetor,selecaoVetor);
    auto inicio7= std::chrono::high_resolution_clock::now();
    radixSort(Array, tamanhoVetor); 
    auto resultado7 = std::chrono::high_resolution_clock::now() - inicio7;
    long long microseconds7 = std::chrono::duration_cast<std::chrono::microseconds>(resultado7).count();
    std::cout << "Ordenacao concluida. Tempo de execução do RadixSort: " << microseconds7 << " microsegundos \n\n";
    

    return 0;
}

/*
-> refazer o merge e o quick sort
   	for (i = 0; i < tamanhoVetor; i++){
            std::cout << Array[i];
            std::cout << " ";
        }
*/