#include "../include/includeGeral.h"

int main(){

    /*
    Esse algoritmo tem como objetivo recolher os dados em txt e fazer a media para cada um gerado anteriormente. 
    */

    std::string nomeArq;

    int selecaoVetor;
    std::cout << "Selecione como era o vetor inicialmente\n" 
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
                "Selecione como era o vetor inicialmente\n" 
                "1) Ordem Crescente\n"   
                "2) 50% ordenado\n"
                "3) 25% ordenado\n"
                "4) 75% ordenado\n"
                "5) Posições aleatórias\n"
                "6) Ordem decrescente \n";
            std::cin >> selecaoVetor;
        }
    }

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

    int quantidadeTamanhos;
    int valoresVetor;
    int indice, tamanhoVetor;
    int vetorPos = 0;
    std::cout << "Escreva a quantidade de tamanhos para o vetor que deseja testar:";
    std::cin >> quantidadeTamanhos;
    int arrayTamanhos[quantidadeTamanhos];
    std::cout << "Escreva quais os valores de tamanhos para o vetor que deseja testar:";
    for (indice = 0 ; indice <= quantidadeTamanhos -1 ; indice++){
        std::cin >> valoresVetor;
        arrayTamanhos[indice] = valoresVetor;
        std::cout << " ";
    }

    while(vetorPos <= quantidadeTamanhos - 1){

        std::ifstream myfile;
        std::ofstream myfileOut;

        tamanhoVetor = arrayTamanhos[vetorPos];

        std::string dado;
        int media = 0;
        int vezes = 0;

        myfile.open (std::string("../output/" + nomeArq + "/insertion/" + std::to_string(tamanhoVetor) + ".txt"), std::ios::in);
        if (myfile.is_open() && myfile.good())
        {   
            myfile >> media;

            while(!myfile.fail())
            { myfile >> dado;
                media = (media + std::stoi(dado));
                vezes++;
            }
            media = media - std::stoi(dado);
            media = media / vezes;
            myfile.close();
            //myfile.open (std::string("../output/" + nomeArq + "/selection/" + std::to_string(tamanhoVetor) + ".txt"), std::ios::trunc);
            myfileOut.open (std::string("../output/medias/" + nomeArq + "/" + std::to_string(tamanhoVetor)  + ".txt"), std::ios::trunc);
            myfileOut << media << std::endl;

            myfileOut.close();
            media = 0;
            vezes = 0;
        }
        myfile.open (std::string("../output/" + nomeArq + "/selection/" + std::to_string(tamanhoVetor) + ".txt"), std::ios::in);
        if (myfile.is_open() && myfile.good())
        {   
            myfile >> media;

            while(!myfile.fail())
            { myfile >> dado;
                media = (media + std::stoi(dado));
                vezes++;
            }
            media = media - std::stoi(dado);
            media = media / vezes;
            myfile.close();
            //myfile.open (std::string("../output/" + nomeArq + "/selection/" + std::to_string(tamanhoVetor) + ".txt"), std::ios::trunc);
            myfileOut.open (std::string("../output/medias/" + nomeArq + "/" + std::to_string(tamanhoVetor)  + ".txt"), std::ios::app);
            myfileOut << media << std::endl;

            myfileOut.close();
            media = 0;
            vezes = 0;
        }
        myfile.open (std::string("../output/" + nomeArq + "/bubble/" + std::to_string(tamanhoVetor) + ".txt"), std::ios::in);
        if (myfile.is_open() && myfile.good())
        {   
            myfile >> media;

            while(!myfile.fail())
            { myfile >> dado;
                media = (media + std::stoi(dado));
                vezes++;
            }
            media = media - std::stoi(dado);
            media = media / vezes;
            myfile.close();
            //myfile.open (std::string("../output/" + nomeArq + "/selection/" + std::to_string(tamanhoVetor) + ".txt"), std::ios::trunc);
            myfileOut.open (std::string("../output/medias/" + nomeArq + "/" + std::to_string(tamanhoVetor)  + ".txt"), std::ios::app);
            myfileOut << media << std::endl;

            myfileOut.close();
            media = 0;
            vezes = 0;
        }
        myfile.open (std::string("../output/" + nomeArq + "/quick/" + std::to_string(tamanhoVetor) + ".txt"), std::ios::in);
        if (myfile.is_open() && myfile.good())
        {   
            myfile >> media;

            while(!myfile.fail())
            { myfile >> dado;
                media = (media + std::stoi(dado));
                vezes++;
            }
            media = media - std::stoi(dado);
            media = media / vezes;
            myfile.close();
            //myfile.open (std::string("../output/" + nomeArq + "/selection/" + std::to_string(tamanhoVetor) + ".txt"), std::ios::trunc);
            myfileOut.open (std::string("../output/medias/" + nomeArq + "/" + std::to_string(tamanhoVetor)  + ".txt"), std::ios::app);
            myfileOut << media << std::endl;

            myfileOut.close();
            media = 0;
            vezes = 0;
        }
        myfile.open (std::string("../output/" + nomeArq + "/merge/" + std::to_string(tamanhoVetor) + ".txt"), std::ios::in);
        if (myfile.is_open() && myfile.good())
        {   
            myfile >> media;

            while(!myfile.fail())
            { myfile >> dado;
                media = (media + std::stoi(dado));
                vezes++;
            }
            media = media - std::stoi(dado);
            media = media / vezes;
            myfile.close();
            //myfile.open (std::string("../output/" + nomeArq + "/selection/" + std::to_string(tamanhoVetor) + ".txt"), std::ios::trunc);
            myfileOut.open (std::string("../output/medias/" + nomeArq + "/" + std::to_string(tamanhoVetor)  + ".txt"), std::ios::app);
            myfileOut << media << std::endl;

            myfileOut.close();
            media = 0;
            vezes = 0;
        }
        myfile.open (std::string("../output/" + nomeArq + "/shell/" + std::to_string(tamanhoVetor) + ".txt"), std::ios::in);
        if (myfile.is_open() && myfile.good())
        {   
            myfile >> media;

            while(!myfile.fail())
            { myfile >> dado;
                media = (media + std::stoi(dado));
                vezes++;
            }
            media = media - std::stoi(dado);
            media = media / vezes;
            myfile.close();
            //myfile.open (std::string("../output/" + nomeArq + "/selection/" + std::to_string(tamanhoVetor) + ".txt"), std::ios::trunc);
            myfileOut.open (std::string("../output/medias/" + nomeArq + "/" + std::to_string(tamanhoVetor)  + ".txt"), std::ios::app);
            myfileOut << media << std::endl;

            myfileOut.close();
            media = 0;
            vezes = 0;
        }
        myfile.open (std::string("../output/" + nomeArq + "/radix/" + std::to_string(tamanhoVetor) + ".txt"), std::ios::in);
        if (myfile.is_open() && myfile.good())
        {   
            myfile >> media;

            while(!myfile.fail())
            { myfile >> dado;
                media = (media + std::stoi(dado));
                vezes++;
            }
            media = media - std::stoi(dado);
            media = media / vezes;
            myfile.close();
            //myfile.open (std::string("../output/" + nomeArq + "/selection/" + std::to_string(tamanhoVetor) + ".txt"), std::ios::trunc);
            myfileOut.open (std::string("../output/medias/" + nomeArq + "/" + std::to_string(tamanhoVetor)  + ".txt"), std::ios::app);
            myfileOut << media << std::endl;

            myfileOut.close();
            media = 0;
            vezes = 0;
        }
        myfile.open (std::string("../output/" + nomeArq + "/quickInsertion/" + std::to_string(tamanhoVetor) + ".txt"), std::ios::in);
        if (myfile.is_open() && myfile.good())
        {   
            myfile >> media;

            while(!myfile.fail())
            { myfile >> dado;
                media = (media + std::stoi(dado));
                vezes++;
            }
            media = media - std::stoi(dado);
            media = media / vezes;
            myfile.close();
            //myfile.open (std::string("../output/" + nomeArq + "/selection/" + std::to_string(tamanhoVetor) + ".txt"), std::ios::trunc);
            myfileOut.open (std::string("../output/medias/" + nomeArq + "/" + std::to_string(tamanhoVetor)  + ".txt"), std::ios::app);
            myfileOut << media << std::endl;

            myfileOut.close();
            media = 0;
            vezes = 0;
        }
        vetorPos++;
    }
    return 0;
}