#include <iostream>
#include <time.h>
#include <algorithm>
#include <chrono>

#include "../include/insertionSort.h"
#include "../include/bubbleSort.h"
#include "../include/quickSort.h"
#include "../include/shuf.h"
#include "../include/mergeSort.h"
#include "../include/selectionSort.h"

    //Aplicacao do vetor particionado e comparacoes
/* C program for Merge Sort */
#include<stdlib.h> 
#include<stdio.h> 

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
    
    //Definindo valores aleatórios em um vetor de >>>100<<< posições, os valores
    //vao de 1 até 666.    

    //Menu de selecao do algoritmo de ordenacao
    std::cout << "Selecione o algoritmo de ordenacao\n" 
                 "1) Insertion Sort\n" 
                 "2) Selection Sort\n"
                 "3) Bubble Sort\n"
                 "4) Shell Sort\n"
                 "5) Quick Sort\n"
                 "6) Merge Sort\n"
                 "7) Radix Sort" << std::endl;
    std::cin >> selecao;

    std::cout << "Selecione como deseja o vetor inicialmente\n" 
                 "1) Ordem Crescente\n"   
                 "2) 50% ordenado\n"
                 "3) 25% ordenado\n"
                 "4) 75% ordenado\n"
                 "5) Posições aleatórias\n"
                 "6) Ordem decrescente \n";
    std::cin >> selecaoVetor;

    if (selecaoVetor == 7){

    }
    else{    
        for(i = 0 ; i<= tamanhoVetor; i++){
            Array[i] = valor;
            ArrayIndex[i] = valor;
            valor ++;
        }

        if(selecaoVetor == 6){
            int first, last;
            first = 0;
            last = tamanhoVetor;
            while (first < last){
                std::swap(Array[first],Array[last]);
                first ++;
                last --;   
            }
        }

        if (selecaoVetor == 2 || selecaoVetor == 3 || selecaoVetor == 4 || selecaoVetor == 5 ){

            std::random_shuffle(&ArrayIndex[0], &ArrayIndex[tamanhoVetor +1]);
            int elemento1 = 0;
            int elemento2 = 1;

            //50% ordenado
            if (selecaoVetor == 2){
                range = meioVetor;
                shuf(Array, ArrayIndex, range, elemento1, elemento2);
            }
            //25% ordenado
            if (selecaoVetor == 3){
                range = umQuartoVetor + meioVetor +1;
                shuf(Array, ArrayIndex, range, elemento1, elemento2);
            }
            //75% ordenado
            if (selecaoVetor == 4){
                range = umQuartoVetor +1;
                shuf(Array, ArrayIndex, range, elemento1, elemento2);
            }
            //Todo aleatório
            if (selecaoVetor == 5){
                std::random_shuffle(&Array[0], &Array[tamanhoVetor + 1]);
            }
        }
    }
    //Selecao do Insertion Sort
    if (selecao == 1){
        //Ordena os valores através do Insertion Sort 
        auto inicio = std::chrono::high_resolution_clock::now();  
        insertionSort(Array, tamanhoVetor);
        std::cout << "O arranjo foi ordenado com sucesso atraves do Insertion Sort\n" << std::endl;
        auto resultado = std::chrono::high_resolution_clock::now() - inicio;
        long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(resultado).count();
        std::cout << "tempo de execução do insertion " << microseconds << " microsegundos \n";
    }

    //Selecao do Selection Sort
    if (selecao == 2){
        // ======================SELECTION SORT=================
        auto inicio = std::chrono::high_resolution_clock::now(); 
        SelectionSort(Array, tamanhoVetor);
        std::cout << "O arranjo foi ordenado com sucesso atraves do Selection Sort\n" << std::endl;
        auto resultado = std::chrono::high_resolution_clock::now() - inicio;
        long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(resultado).count();
        std::cout << "tempo de execução do Selection " << microseconds << " microsegundos \n";
    }

    //Selecao do Bubble Sort
    if (selecao == 3){
        //Ordena os valores através do Bubble Sort
        auto inicio = std::chrono::high_resolution_clock::now();
        bubbleSort(Array, tamanhoVetor);
        auto resultado = std::chrono::high_resolution_clock::now() - inicio;
        long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(resultado).count();
        std::cout << "tempo de execução do bubble " << microseconds << " microsegundos \n";
        std::cout << "O arranjo foi ordenado com sucesso atraves do Bubble Sort\n" << std::endl;
    }

    //Selecao do Shell Sort
    if(selecao == 4){
        // ======================Shell SORT=================
    }

    //Selecao do Quick Sort
    if(selecao == 5){
        auto inicio = std::chrono::high_resolution_clock::now();
        quickSort(Array,begin, tamanhoVetor);
        auto resultado = std::chrono::high_resolution_clock::now() - inicio;
        long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(resultado).count();
        std::cout << "tempo de execução do Quick " << microseconds << " microsegundos \n";
        std::cout << "O arranjo foi ordenado com sucesso atraves do Quick\n" << std::endl;
    }
    
    //Selecao do Merge Sort
    if(selecao == 6){
        // ======================MERGE SORT=================  
        auto inicio = std::chrono::high_resolution_clock::now();
        mergeSort(Array, begin, tamanhoVetor); 
        auto resultado = std::chrono::high_resolution_clock::now() - inicio;
        long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(resultado).count();
        std::cout << "tempo de execução do merge " << microseconds << " microsegundos \n";
        std::cout << "O arranjo foi ordenado com sucesso atraves do merge\n" << std::endl;
    }

    //Selecao do Radix Sort
    if(selecao == 7){
        // ======================RADIX SORT=================
    }

    
    //IMPRIMIR RESULTADO
    for (i = 0 ; i <= tamanhoVetor ; i++){
        std::cout << Array[i] << " ";
    }
    std::cout << "\n";
    /*std::cout << "Vetor de referencia para troca\n";
        //IMPRIMIR RESULTADO
    for (i = 0 ; i <= tamanhoVetor ; i++){
        std::cout << ArrayIndex[i] << " ";
    }
    std::cout << "\n";*/
    return 0;
}

/*separar o arquivo em funções.
1- funções de ordenação
2- função shuffle

começar o programa com o vetor de tamanho maximo e usar somente faixas do vetor conforme for pedido

fazer o menu por linha de comando

comentar com doxy

*/