#include <iostream>
#include <time.h>
#include <algorithm>
#include <chrono>
#include <fstream>
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
#include "../include/quickInsertion2.h"

int main(){
    srand (time(NULL));

    std::ofstream myfile;

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
        if (selecaoVetor <= 0 || selecaoVetor > 6){
            while(selecaoVetor <= 0 || selecaoVetor > 6){
                std::cout << "Opcao invalida.\n"
                    "Selecione como deseja o vetor inicialmente\n" 
                    "1) Ordem Crescente\n"   
                    "2) 50% ordenado\n"
                    "3) 25% ordenado\n"
                    "4) 75% ordenado\n"
                    "5) Posições aleatórias\n"
                    "6) Ordem decrescente \n";
                std::cin >> selecaoVetor;
            }
        }
        int selecao;
        std::cout << "Selecione qual algoritmo deseja testar\n" 
                    "0) todos\n"
                    "1) insertion\n"   
                    "2) selection\n"
                    "3) bubble\n"
                    "4) quick\n"
                    "5) merge\n"
                    "6) shell\n"
                    "7) radix\n"
                    "8) quick com insertion\n";
        std::cin >> selecao;
        if (selecao < 0 || selecao > 8){
            while(selecao < 0 || selecao > 8){
                std::cout << "Opcao invalida.\nSelecione qual algoritmo deseja testar\n" 
                        "0) todos\n"
                        "1) insertion\n"   
                        "2) selection\n"
                        "3) bubble\n"
                        "4) quick\n"
                        "5) merge\n"
                        "6) shell\n"
                        "7) radix\n"
                        "8) quick com insertion\n";
                std::cin >> selecao;
            }
        }
        int quantidadeTamanhos;
        int valoresVetor;
        int indice;
        std::cout << "Escreva a quantidade de tamanhos para o vetor que deseja testar:";
        std::cin >> quantidadeTamanhos;
        int arrayTamanhos[quantidadeTamanhos];
        std::cout << "Escreva a quais os valores de tamanhos para o vetor que deseja testar:";
        for (indice = 0 ; indice <= quantidadeTamanhos -1 ; indice++){
            std::cin >> valoresVetor;
            arrayTamanhos[indice] = valoresVetor;
            std::cout << " ";
        }
        std::cout << "\n";

        std::string nomeArq;
        
        int vezes = 0;
        int vezesTotal;
        std::cout << "Escreva a quantidade de vezes que quer testar o tamanho para cada algoritmo selecionado:";
        std::cin >> vezesTotal;
                
        
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

    while(vetorPos <= quantidadeTamanhos - 1){

        
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

        if(selecao == 1 || selecao == 0){
            while (vezes<vezesTotal){
                std::cout << "Ordenando com Insertion sort" << std::endl;
                auto inicio = std::chrono::high_resolution_clock::now();  
                insertionSort(Array, tamanhoVetor);
                std::cout << "O arranjo foi ordenado com sucesso atraves do Insertion Sort" << std::endl;
                auto resultado = std::chrono::high_resolution_clock::now() - inicio;
                long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(resultado).count();
                std::cout << "tempo de execução do insertion " << microseconds << " microsegundos \n\n";
                if(vezes == 0){
                    myfile.open (std::string("../output/" + nomeArq + "/insertion/" + std::to_string(tamanhoVetor) + ".txt"), std::ios::trunc);
                }
                else{
                    myfile.open (std::string("../output/" + nomeArq + "/insertion/" + std::to_string(tamanhoVetor) + ".txt"), std::ios::app);
                }
                myfile << microseconds << std::endl; 
                myfile.close();
                vezes++;
            }
        }
        vezes = 0;

        if(selecao == 2 || selecao == 0){
            while (vezes<vezesTotal){
                copiarReverso(Array, copia, tamanhoVetor);
                auto inicio3 = std::chrono::high_resolution_clock::now(); 
                SelectionSort(Array, tamanhoVetor);
                std::cout << "O arranjo foi ordenado com sucesso atraves do Selection Sort" << std::endl;
                auto resultado3 = std::chrono::high_resolution_clock::now() - inicio3;
                long long microseconds3 = std::chrono::duration_cast<std::chrono::microseconds>(resultado3).count();
                std::cout << "tempo de execução do Selection " << microseconds3 << " microsegundos \n\n";
                if(vezes == 0){
                    myfile.open (std::string("../output/" + nomeArq + "/selection/" + std::to_string(tamanhoVetor) + ".txt"), std::ios::trunc);
                }
                else{
                    myfile.open (std::string("../output/" + nomeArq + "/selection/" + std::to_string(tamanhoVetor) + ".txt"), std::ios::app);
                } 
                myfile << microseconds3 << std::endl; 
                myfile.close();
                vezes++;
            }
            vezes = 0;
        }
        if(selecao == 3 || selecao == 0){
            while (vezes<vezesTotal){
                copiarReverso(Array, copia, tamanhoVetor);
                auto inicio4 = std::chrono::high_resolution_clock::now();
                bubbleSort(Array, tamanhoVetor);
                auto resultado4 = std::chrono::high_resolution_clock::now() - inicio4;
                long long microseconds4 = std::chrono::duration_cast<std::chrono::microseconds>(resultado4).count();
                std::cout << "tempo de execução do bubble " << microseconds4 << " microsegundos \n";
                std::cout << "O arranjo foi ordenado com sucesso atraves do Bubble Sort\n" << std::endl;
                if(vezes == 0){
                    myfile.open (std::string("../output/" + nomeArq + "/bubble/" + std::to_string(tamanhoVetor) + ".txt"), std::ios::trunc);
                }
                else{
                    myfile.open (std::string("../output/" + nomeArq + "/bubble/" + std::to_string(tamanhoVetor) + ".txt"), std::ios::app);
                }
                myfile << microseconds4 << std::endl; 
                myfile.close();
                vezes++;
            }
            vezes = 0;
        }

        if(selecao == 4 || selecao == 0){
            while (vezes<vezesTotal){
                copiarReverso(Array, copia, tamanhoVetor);
                std::cout << "Ordenando com Quick sort" << std::endl;
                auto inicio5 = std::chrono::high_resolution_clock::now();
                quickSort(Array,begin, tamanhoVetor);
                auto resultado5 = std::chrono::high_resolution_clock::now() - inicio5;
                long long microseconds5 = std::chrono::duration_cast<std::chrono::microseconds>(resultado5).count();
                std::cout << "tempo de execução do Quick " << microseconds5 << " microsegundos \n";
                std::cout << "O arranjo foi ordenado com sucesso atraves do Quick\n" << std::endl;
                if(vezes == 0){
                    myfile.open (std::string("../output/" + nomeArq + "/quick/" + std::to_string(tamanhoVetor) + ".txt"), std::ios::trunc);
                }
                else{
                    myfile.open (std::string("../output/" + nomeArq + "/quick/" + std::to_string(tamanhoVetor) + ".txt"), std::ios::app);
                }
                myfile << microseconds5 << std::endl; 
                myfile.close();
                vezes++;
            }
            vezes = 0;
        }
        if(selecao == 5 || selecao == 0){
            while (vezes<vezesTotal){
                copiarReverso(Array, copia, tamanhoVetor);
                std::cout << "Ordenando com Merge sort" << std::endl;
                auto inicio2= std::chrono::high_resolution_clock::now();
                mergeSort(Array, begin, tamanhoVetor);
                auto resultado2 = std::chrono::high_resolution_clock::now() - inicio2;
                long long microseconds2 = std::chrono::duration_cast<std::chrono::microseconds>(resultado2).count();
                std::cout << "tempo de execução do merge " << microseconds2 << " microsegundos \n";
                std::cout << "O arranjo foi ordenado com sucesso atraves do merge\n" << std::endl;
                if(vezes == 0){
                    myfile.open (std::string("../output/" + nomeArq + "/merge/" + std::to_string(tamanhoVetor) + ".txt"), std::ios::trunc);
                }
                else{
                    myfile.open (std::string("../output/" + nomeArq + "/merge/" + std::to_string(tamanhoVetor) + ".txt"), std::ios::app);
                }
                myfile << microseconds2 << std::endl; 
                myfile.close();
                vezes++;
            }
            vezes = 0;
        }
        if(selecao == 6 || selecao == 0){
            while (vezes<vezesTotal){
                copiarReverso(Array, copia, tamanhoVetor);
                std::cout << "Ordenando com Shell sort" << std::endl;
                auto inicio6= std::chrono::high_resolution_clock::now();
                shellSort(Array, tamanhoVetor);
                auto resultado6 = std::chrono::high_resolution_clock::now() - inicio6;
                long long microseconds6 = std::chrono::duration_cast<std::chrono::microseconds>(resultado6).count();
                std::cout << "tempo de execução do Shell " << microseconds6 << " microsegundos \n";
                std::cout << "O arranjo foi ordenado com sucesso atraves do Shell\n" << std::endl;
                if(vezes == 0){
                    myfile.open (std::string("../output/" + nomeArq + "/shell/" + std::to_string(tamanhoVetor) + ".txt"), std::ios::trunc);
                }
                else{
                    myfile.open (std::string("../output/" + nomeArq + "/shell/" + std::to_string(tamanhoVetor) + ".txt"), std::ios::app);
                }
                myfile << microseconds6 << std::endl; 
                myfile.close();
                vezes++;
            }
            vezes = 0;
        }
        if(selecao == 7 || selecao == 0){
            while (vezes<vezesTotal){
                copiarReverso(Array, copia, tamanhoVetor);
                std::cout << "Ordenando com Radix sort" << std::endl;
                auto inicio7= std::chrono::high_resolution_clock::now();
                radixSort(Array, tamanhoVetor);
                auto resultado7 = std::chrono::high_resolution_clock::now() - inicio7;
                long long microseconds7 = std::chrono::duration_cast<std::chrono::microseconds>(resultado7).count();
                std::cout << "tempo de execução do Radix " << microseconds7 << " microsegundos \n";
                std::cout << "O arranjo foi ordenado com sucesso atraves do Radix\n" << std::endl;
                if(vezes == 0){
                    myfile.open (std::string("../output/" + nomeArq + "/radix/" + std::to_string(tamanhoVetor) + ".txt"), std::ios::trunc);
                }
                else{
                    myfile.open (std::string("../output/" + nomeArq + "/radix/" + std::to_string(tamanhoVetor) + ".txt"), std::ios::app);
                } 
                myfile << microseconds7 << std::endl; 
                myfile.close();
                vezes++;
            }
            vezes = 0;
        }
        if(selecao == 8 || selecao == 0){
            while (vezes<vezesTotal){
                copiarReverso(Array, copia, tamanhoVetor);
                std::cout << "Ordenando com quickInsertion sort" << std::endl;
                auto inicio8= std::chrono::high_resolution_clock::now();
                quickInsertion2(Array,begin, tamanhoVetor); 
                auto resultado8 = std::chrono::high_resolution_clock::now() - inicio8;
                long long microseconds8 = std::chrono::duration_cast<std::chrono::microseconds>(resultado8).count();
                std::cout << "tempo de execução do quick com insertion " << microseconds8 << " microsegundos \n";
                std::cout << "O arranjo foi ordenado com sucesso atraves do quick com insertion\n" << std::endl;
                if(vezes == 0){
                    myfile.open (std::string("../output/" + nomeArq + "/quickInsertion/" + std::to_string(tamanhoVetor) + ".txt"), std::ios::trunc);
                }
                else{
                    myfile.open (std::string("../output/" + nomeArq + "/quickInsertion/" + std::to_string(tamanhoVetor) + ".txt"), std::ios::app);
                } 
                myfile << microseconds8 << std::endl; 
                myfile.close();
                vezes++;
            }
            vezes = 0;
        }
        vetorPos++;
    }
    return 0;
}

//fazer uma variavel com a quantidade de vezes que quer rodar para cada tamanho de vetor.
//para limpar o arquivo, o vetorPos e a quantidade de vezes tem q estar no valor inicial.
//mudar o destino dos arquivos para a pasta com o tamanho do vetor
// ou fazer a media dos valores ja no programa e gravar no arquivo apenas a media