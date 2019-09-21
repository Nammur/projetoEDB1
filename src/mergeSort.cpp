#include "../include/mergeSort.h"

//Implementação do MergeSort
void merge(int *Array, int left, int middle, int right) { 
	// Auxiliares para determinar o tamanho do vetor
	int auxiliarLeft = middle - left + 1; 
	int auxiliarRight = right - middle; 

	// Variaveis também auxiliares
	int i, j, k; 

	// Arrays temporarios para ajudar no particionamento
	int MergeTempLeft[auxiliarLeft], MergeTempRight[auxiliarRight]; 

	// Copia dos valores para os arrays temporarios
	for (i = 0; i < auxiliarLeft; i++) 
		MergeTempLeft[i] = Array[left + i]; 
	for (j = 0; j < auxiliarRight; j++) 
		MergeTempRight[j] = Array[middle + 1 + j]; 

	// Os valores são resertados para os valores serem
	// Reposicionados no vetor original
	i = 0; 
	j = 0; 
	k = left;  

	while (i < auxiliarLeft && j < auxiliarRight){ 
		// Comparacao dos valores dos vetores, se o vetor
		// Se o valor da direita for menor que o da esquerda
		// Ele entra no array definitivo e o i é incrementado
		if (MergeTempLeft[i] <= MergeTempRight[j]){ 
			Array[k] = MergeTempLeft[i]; 
			i++; 
		}
		// A outra situação possivel, agora o j é incrementado
		else{ 
			Array[k] = MergeTempRight[j]; 
			j++; 
		} 
		k++; 
	} 

	// Cópia dos valores restantes da esquerda
	while (i < auxiliarLeft) { 
		Array[k] = MergeTempLeft[i]; 
		i++; 
		k++; 
	} 

	// Cópia dos valores restantes da direita
	while (j < auxiliarRight){ 
		Array[k] = MergeTempRight[j]; 
		j++; 
		k++; 
	} 
} 

//Particionamento do vetor
void mergeSort(int *Array, int left, int right){ 
	if (left < right){
		// Encontrando o valor do meio
		int middle = left + (right - left)/2; 

		//Usando recursividade para separar os valores 
		mergeSort(Array, left, middle); 
		mergeSort(Array, middle + 1, right);

		//Processo de reconstrução
		merge(Array, left, middle, right); 
	} 
}
// Fim QuickSort 
