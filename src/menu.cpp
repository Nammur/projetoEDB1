#include "../include/shuf.h"
#include "../include/menu.h"

void menu(int *Array, int *ArrayIndex,int tamanhoVetor, int selecaoVetor){
    int meioVetor = tamanhoVetor/2;
    int umQuartoVetor = tamanhoVetor/4;
    int range = 0;
    
    if(selecaoVetor == 6){
        int first, last;
        first = 0;
        last = tamanhoVetor;
        while (first < last){
            std::swap(Array[first],Array[last - 1]);
            first ++;
            last --;   
        }
    }

    if (selecaoVetor == 2 || selecaoVetor == 3 || selecaoVetor == 4 || selecaoVetor == 5 ){

        std::random_shuffle(&ArrayIndex[0], &ArrayIndex[tamanhoVetor]);
        int elemento1 = 0;
        int elemento2 = 1;

            //50% ordenado
        if (selecaoVetor == 2){
            range = meioVetor -1;
            shuf(Array, ArrayIndex, range, elemento1, elemento2);
        }
            //25% ordenado
        if (selecaoVetor == 3){
            range = umQuartoVetor + meioVetor -1;
            shuf(Array, ArrayIndex, range, elemento1, elemento2);
        }
            //75% ordenado
        if (selecaoVetor == 4){
            range = umQuartoVetor ;
            shuf(Array, ArrayIndex, range, elemento1, elemento2);
        }
            //Todo aleatório
        if (selecaoVetor == 5){
            std::random_shuffle(&Array[0], &Array[tamanhoVetor]);          
          }
    }
}
   /* for (i = 0 ; i <= tamanhoVetor -1 ; i++){
        std::cout << Array[i] << " ";
    }
    std::cout << Array[i] << "\n";
*/
void copiar(int *Array, int *copia, int tamanhoVetor){
    for (int i = 0; i < tamanhoVetor; i++){
       copia[i] = Array[i];
    }
     return;
}
void copiarReverso(int *Array, int *copia, int tamanhoVetor){
    for (int i = 0; i < tamanhoVetor; i++){
       Array[i] = copia[i];
    }
    return;
}
void printArray(int *Array, int tamanhoVetor){
    int i;
    for (i = 0; i < tamanhoVetor; i++){
        std::cout << Array[i];
        std::cout << " ";
    }
}