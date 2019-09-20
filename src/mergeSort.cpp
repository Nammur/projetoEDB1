#include "../include/mergeSort.h"
#include <chrono>

/*
void mergeSort(int *Array, int first, int middle, int auxiliar, int last, int tamanhoVetor){
    int *MergeTemp = new int [tamanhoVetor];
	int i, j, k;
    i = first;
    j = last;
    k = 0;
    //First = First. Last = middle. Auxiiliar1 = middle+1. Auxiliar2 = last. tamanhoVetor = last+1
    //Comparacoes e ordenacao
    while(i <= last && j <= auxiliar){
        if(Array[i] < Array[j]){
            MergeTemp[k++] = Array[i++];
        }
        else{
            MergeTemp[k++] = Array[j++];
        }
    }

    while(i <= last){
        MergeTemp[k++] = Array[i++];
    }

    while(j <= last){
        MergeTemp[k++] = Array[j++];
    }
    
    //Realocacao do vetor temporario para o principal
    for(i = first, j = 0; i <= last; i++, j++){
        Array[i] = MergeTemp[j];
    }
}

void mergeSort(int *Array, int first, int last){
    int middle;

	std::cout << "\n";

	for (int i = 0 ; i <= last ; i++){
        std::cout << Array[i] << " ";
    }

    if(first < last){
        middle = (first + last) / 2;
        //Chamada recursiva para particionar o Array
        mergeSort(Array, first, middle);
        mergeSort(Array, middle+1, last);
        mergeSort(Array, first, middle, middle + 1, last, last + 1);
    }
}
*/

void construcaoMerge(int Array, int first, int middle, int last){
	int auxiliar01 = middle - first + 1;
	int auxiliar02 = last - middle;

	int k, i, j;

	int *MergeTemp01 = new int [auxiliar01];
	int *MergeTemp02 = new int [auxiliar02];

	for (i = 0 ; i < auxiliar01 ; i++){
		MergeTemp01[i] = Array[&first + i];
	}

	for(j = 0 ; j < auxiliar02 ; j++){
		MergeTemp02[j] = Array[&middle + 1 + j];
	}

	i = 0;
	j = 0;
	k = first;

	while(i < auxiliar01 && j < auxiliar02){
		if(MergeTemp01[i] <= MergeTemp02[j]){
			Array[&k] = MergeTemp01[i];
			i++;
		}
		else{
			Array[&k] = MergeTemp02[j];
			j++;
		}
		first++;
	}

	while(i < auxiliar01){
		Array[&k] = MergeTemp01[i];
		i++;
		k++;
	}
	while(j < auxiliar02){
		Array[&k] = MergeTemp02[j];
		j++;
		k++;
	}
}

void mergeSort(int *Array, int first, int last){
	int middle;

	if(first < last){
		middle = (first + last) / 2;
		mergeSort(Array, first, middle);
		mergeSort(Array, middle + 1, last);
		
		construcaoMerge(*Array, first, middle, last);
	}
}
