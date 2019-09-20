#include <iostream>
#include <time.h>
#include <algorithm>
#include <chrono>
#include<stdlib.h> 
#include<stdio.h> 

#include "../include/insertionSort.h"
#include "../include/bubbleSort.h"
#include "../include/quickSort.h"
#include "../include/shuf.h"
#include "../include/mergeSort.h"
#include "../include/selectionSort.h"
#include "../include/menu.h"

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
    
*/  
    menu(Array, ArrayIndex, tamanhoVetor,selecaoVetor);
    auto inicio = std::chrono::high_resolution_clock::now();  
    insertionSort(Array, tamanhoVetor);
    std::cout << "O arranjo foi ordenado com sucesso atraves do Insertion Sort\n" << std::endl;
    auto resultado = std::chrono::high_resolution_clock::now() - inicio;
    long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(resultado).count();
    std::cout << "tempo de execução do insertion " << microseconds << " microsegundos \n";
        for (i = 0 ; i <= tamanhoVetor ; i++){
        std::cout << Array[i] << " ";
    }
    std::cout << "\n";

    menu(Array, ArrayIndex, tamanhoVetor,selecaoVetor);
    auto inicio3 = std::chrono::high_resolution_clock::now(); 
    SelectionSort(Array, tamanhoVetor);
    std::cout << "O arranjo foi ordenado com sucesso atraves do Selection Sort\n" << std::endl;
    auto resultado3 = std::chrono::high_resolution_clock::now() - inicio3;
    long long microseconds3 = std::chrono::duration_cast<std::chrono::microseconds>(resultado3).count();
    std::cout << "tempo de execução do Selection " << microseconds3 << " microsegundos \n";
        for (i = 0 ; i <= tamanhoVetor ; i++){
        std::cout << Array[i] << " ";
    }
    std::cout << "\n";
    menu(Array, ArrayIndex, tamanhoVetor,selecaoVetor);
    auto inicio4 = std::chrono::high_resolution_clock::now();
    bubbleSort(Array, tamanhoVetor);
    auto resultado4 = std::chrono::high_resolution_clock::now() - inicio4;
    long long microseconds4 = std::chrono::duration_cast<std::chrono::microseconds>(resultado4).count();
    std::cout << "tempo de execução do bubble " << microseconds4 << " microsegundos \n";
    std::cout << "O arranjo foi ordenado com sucesso atraves do Bubble Sort\n" << std::endl;
        for (i = 0 ; i <= tamanhoVetor ; i++){
        std::cout << Array[i] << " ";
    }
    std::cout << "\n";

    menu(Array, ArrayIndex, tamanhoVetor,selecaoVetor);
    std::cout << "Ordenando com Quick sort" << std::endl;
    auto inicio5 = std::chrono::high_resolution_clock::now();
    quickSort(Array,begin, tamanhoVetor);
    auto resultado5 = std::chrono::high_resolution_clock::now() - inicio5;
    long long microseconds5 = std::chrono::duration_cast<std::chrono::microseconds>(resultado5).count();
    std::cout << "tempo de execução do Quick " << microseconds5 << " microsegundos \n";
    std::cout << "O arranjo foi ordenado com sucesso atraves do Quick\n" << std::endl;
        for (i = 0 ; i <= tamanhoVetor ; i++){
        std::cout << Array[i] << " ";
    }
    std::cout << "\n";


    menu(Array, ArrayIndex, tamanhoVetor,selecaoVetor);
    std::cout << "Ordenando com Merge sort" << std::endl;
    auto inicio2= std::chrono::high_resolution_clock::now();
    mergeSort(Array, begin, tamanhoVetor); 
    auto resultado2 = std::chrono::high_resolution_clock::now() - inicio2;
    long long microseconds2 = std::chrono::duration_cast<std::chrono::microseconds>(resultado2).count();
    std::cout << "tempo de execução do merge " << microseconds2 << " microsegundos \n";
    std::cout << "O arranjo foi ordenado com sucesso atraves do merge\n" << std::endl;
        for (i = 0 ; i <= tamanhoVetor ; i++){
        std::cout << Array[i] << " ";
    }
    std::cout << "\n";
    return 0;
}

/*
-> refazer o merge e o quick sort
*/

