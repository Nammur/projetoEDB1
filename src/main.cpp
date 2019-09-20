#include <iostream>
#include <time.h>
#include <algorithm>
#include "../include/insertionSort.h"
#include "../include/bubbleSort.h"
#include "../include/quickSort.h"
#include "../include/shuf.h"

int main(){
    
    srand (time(NULL));
    
    //Variavel para armazenar o valor máximo de valores a ser armazenado
    //de forma aleatória.
    //Variaveis aleatórias até limiteAleatorio
    int valor = 0; 
    int inicio = 0;
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
        insertionSort(Array, tamanhoVetor);
        std::cout << "O arranjo foi ordenado com sucesso atraves do Insertion Sort\n" << std::endl;
    }

    //Selecao do Selection Sort
    if (selecao == 2){
        // ======================SELECTION SORT=================
    }

    //Selecao do Bubble Sort
    if (selecao == 3){
        //Ordena os valores através do Bubble Sort
        bubbleSort(Array, tamanhoVetor);
        std::cout << "O arranjo foi ordenado com sucesso atraves do Bubble Sort\n" << std::endl;
    }

    //Selecao do Shell Sort
    if(selecao == 4){
        // ======================Shell SORT=================
    }

    //Selecao do Quick Sort
    if(selecao == 5){
        quickSort(Array,inicio, tamanhoVetor);
        std::cout << "O arranjo foi ordenado com sucesso atraves do Quick Sort\n" << std::endl;
    }
    
    //Selecao do Merge Sort
    if(selecao == 6){
        // ======================MERGE SORT=================  
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

ajeitar a desordenação do vetor criando um segundo vetor com os indices, dando um shuffle 
nele e fazendo swap de dois elementos em dois

*/