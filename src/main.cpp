#include <iostream>
#include <time.h>
#include <algorithm>
#include <chrono>
#include <stdlib.h> 
#include <stdio.h> 
#include <fstream>
#include <string>
#include <iostream>
#include <string>

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
    int vetorPos = 0;
    int selecaoVetor;
        std::cout << "Selecione como deseja o vetor inicialmente\n" 
                    "1) Ordem Crescente\n"   
                    "2) 50% ordenado\n"
                    "3) 25% ordenado\n"
                    "4) 75% ordenado\n"
                    "5) Posições aleatórias\n"
                    "6) Ordem decrescente \n";
        std::cin >> selecaoVetor;

        std::string nomeArq;
        
        if (selecaoVetor == 1){
            nomeArq = "100ordenado";
        }
        if (selecaoVetor ==  2){
            nomeArq = "50ordenado";
        }
        if (selecaoVetor ==  3){
            nomeArq = "25ordenado";
        }
        if (selecaoVetor ==  4){
            nomeArq = "75ordenado";
        }
        if (selecaoVetor ==  5){
            nomeArq = "0ordenado";
        }
        if (selecaoVetor ==  6){
            nomeArq = "inverso";
        }
    while(vetorPos<= 3){
        int arrayTamanhos[4] = {2,4,8,100};
        srand (time(NULL));

        std::ofstream myfile;
        
        //Variavel para armazenar o valor máximo de valores a ser armazenado
        //de forma aleatória.
        //Variaveis aleatórias até limiteAleatorio
        int valor = 0; 
        int begin = 0;
        int  tamanhoVetor, i;
        tamanhoVetor = arrayTamanhos[vetorPos];

        
        //Auxiliares na ordenacao do insertion sort
        //i =  indice
        //int  i;    
        //Alocacao dinamica de um ponteiro que aponta para um array de x posições
        int  *Array = new int  [tamanhoVetor];
        int  *ArrayIndex  = new int [tamanhoVetor];
        int  *copia = new int [tamanhoVetor];

        for(i = 0 ; i<= tamanhoVetor; i++){
            Array[i] = valor;
            ArrayIndex[i] = valor;
            valor ++;
        } 
        menu(Array, ArrayIndex, tamanhoVetor,selecaoVetor);
        copiar(Array, copia, tamanhoVetor);
        std::cout << "Ordenando com Insertion sort" << std::endl;
        auto inicio = std::chrono::high_resolution_clock::now();  
        insertionSort(Array, tamanhoVetor);
        std::cout << "O arranjo foi ordenado com sucesso atraves do Insertion Sort" << std::endl;
        auto resultado = std::chrono::high_resolution_clock::now() - inicio;
        long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(resultado).count();
        std::cout << "tempo de execução do insertion " << microseconds << " microsegundos \n\n";
        if(vetorPos == 0){
            myfile.open (std::string("../output/" + nomeArq + "/insertion" + nomeArq + ".txt"), std::ios::trunc);
        }
        else{
            myfile.open (std::string("../output/" + nomeArq + "/insertion" + nomeArq + ".txt"), std::ios::app);
        }
        myfile << microseconds << std::endl; 
        myfile.close();

        copiarReverso(Array, copia, tamanhoVetor);
        auto inicio3 = std::chrono::high_resolution_clock::now(); 
        SelectionSort(Array, tamanhoVetor);
        std::cout << "O arranjo foi ordenado com sucesso atraves do Selection Sort" << std::endl;
        auto resultado3 = std::chrono::high_resolution_clock::now() - inicio3;
        long long microseconds3 = std::chrono::duration_cast<std::chrono::microseconds>(resultado3).count();
        std::cout << "tempo de execução do Selection " << microseconds3 << " microsegundos \n\n5";
        if(vetorPos == 0){
            myfile.open (std::string("../output/" + nomeArq + "/selection" + nomeArq + ".txt"), std::ios::trunc);
        }
        else{
            myfile.open (std::string("../output/" + nomeArq + "/selection" + nomeArq + ".txt"), std::ios::app);
        } 
        myfile << microseconds3 << std::endl; 
        myfile.close();

        copiarReverso(Array, copia, tamanhoVetor);
        auto inicio4 = std::chrono::high_resolution_clock::now();
        bubbleSort(Array, tamanhoVetor);
        auto resultado4 = std::chrono::high_resolution_clock::now() - inicio4;
        long long microseconds4 = std::chrono::duration_cast<std::chrono::microseconds>(resultado4).count();
        std::cout << "tempo de execução do bubble " << microseconds4 << " microsegundos \n";
        std::cout << "O arranjo foi ordenado com sucesso atraves do Bubble Sort\n" << std::endl;
        if(vetorPos == 0){
            myfile.open (std::string("../output/" + nomeArq + "/bubble" + nomeArq + ".txt"), std::ios::trunc);
        }
        else{
            myfile.open (std::string("../output/" + nomeArq + "/bubble" + nomeArq + ".txt"), std::ios::app);
        }
        myfile << microseconds4 << std::endl; 
        myfile.close();

        copiarReverso(Array, copia, tamanhoVetor);
        std::cout << "Ordenando com Quick sort" << std::endl;
        auto inicio5 = std::chrono::high_resolution_clock::now();
        quickSort(Array,begin, tamanhoVetor);
        auto resultado5 = std::chrono::high_resolution_clock::now() - inicio5;
        long long microseconds5 = std::chrono::duration_cast<std::chrono::microseconds>(resultado5).count();
        std::cout << "tempo de execução do Quick " << microseconds5 << " microsegundos \n";
        std::cout << "O arranjo foi ordenado com sucesso atraves do Quick\n" << std::endl;
        if(vetorPos == 0){
            myfile.open (std::string("../output/" + nomeArq + "/quick" + nomeArq + ".txt"), std::ios::trunc);
        }
        else{
            myfile.open (std::string("../output/" + nomeArq + "/quick" + nomeArq + ".txt"), std::ios::app);
        }
        myfile << microseconds5 << std::endl; 
        myfile.close();

        copiarReverso(Array, copia, tamanhoVetor);
        std::cout << "Ordenando com Merge sort" << std::endl;
        auto inicio2= std::chrono::high_resolution_clock::now();
        mergeSort(Array, begin, tamanhoVetor); 
        auto resultado2 = std::chrono::high_resolution_clock::now() - inicio2;
        long long microseconds2 = std::chrono::duration_cast<std::chrono::microseconds>(resultado2).count();
        std::cout << "tempo de execução do merge " << microseconds2 << " microsegundos \n";
        std::cout << "O arranjo foi ordenado com sucesso atraves do merge\n" << std::endl;
        if(vetorPos == 0){
            myfile.open (std::string("../output/" + nomeArq + "/merge" + nomeArq + ".txt"), std::ios::trunc);
        }
        else{
            myfile.open (std::string("../output/" + nomeArq + "/merge" + nomeArq + ".txt"), std::ios::app);
        }
        myfile << microseconds2 << std::endl; 
        myfile.close();

        copiarReverso(Array, copia, tamanhoVetor);
        std::cout << "Ordenando com Shell sort" << std::endl;
        auto inicio6= std::chrono::high_resolution_clock::now();
        shellSort(Array, tamanhoVetor); 
        auto resultado6 = std::chrono::high_resolution_clock::now() - inicio6;
        long long microseconds6 = std::chrono::duration_cast<std::chrono::microseconds>(resultado6).count();
        std::cout << "tempo de execução do Shell " << microseconds6 << " microsegundos \n";
        std::cout << "O arranjo foi ordenado com sucesso atraves do Shell\n" << std::endl;
        if(vetorPos == 0){
            myfile.open (std::string("../output/" + nomeArq + "/shell" + nomeArq + ".txt"), std::ios::trunc);
        }
        else{
            myfile.open (std::string("../output/" + nomeArq + "/shell" + nomeArq + ".txt"), std::ios::app);
        }
        myfile << microseconds6 << std::endl; 
        myfile.close();

        copiarReverso(Array, copia, tamanhoVetor);
        std::cout << "Ordenando com Radix sort" << std::endl;
        auto inicio7= std::chrono::high_resolution_clock::now();
        radixSort(Array, tamanhoVetor); 
        auto resultado7 = std::chrono::high_resolution_clock::now() - inicio7;
        long long microseconds7 = std::chrono::duration_cast<std::chrono::microseconds>(resultado7).count();
        std::cout << "tempo de execução do Radix " << microseconds7 << " microsegundos \n";
        std::cout << "O arranjo foi ordenado com sucesso atraves do Radix\n" << std::endl;
        if(vetorPos == 0){
            myfile.open (std::string("../output/" + nomeArq + "/radix" + nomeArq + ".txt"), std::ios::trunc);
        }
        else{
            myfile.open (std::string("../output/" + nomeArq + "/radix" + nomeArq + ".txt"), std::ios::app);
        } 
        myfile << microseconds7 << std::endl; 
        myfile.close();
        vetorPos++;
    }
return 0;
}