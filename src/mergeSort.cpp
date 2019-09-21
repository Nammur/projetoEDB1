#include "../include/mergeSort.h"

/*void merge(int *Array, int l, int m, int r) 
{ 
	int i, j, k; 
	int n1 = m - l +1; 
	int n2 = r - m ; 

	// create temp arrays
	int L[n1], R[n2]; 

	// Copy data to temp arrays L[] and R[]
	for (i = 0; i < n1; i++) 
		L[i] = Array[l + i]; 
	for (j = 0; j < n2; j++) 
		R[j] = Array[m + 1+ j]; 

	// Merge the temp arrays back into arr[l..r]
	i = 0; // Initial index of first subarray 
	j = 0; // Initial index of second subarray 
	k = l; // Initial index of merged subarray 
	while (i < n1 && j < n2) 
	{ 
		if (L[i] <= R[j]) 
		{ 
			Array[k] = L[i]; 
			i++; 
		} 
		else
		{ 
			Array[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 

	//Copy the remaining elements of L[], if there 
	//are any
	while (i < n1) 
	{ 
		Array[k] = L[i]; 
		i++; 
		k++; 
	} 

	// Copy the remaining elements of R[], if there 
	a//re any 
	while (j < n2) 
	{ 
		Array[k] = R[j]; 
		j++; 
		k++; 
	} 
} 

// l is for left index and r is right index of the 
//sub-array of arr to be sorted 
void mergeSort(int *Array, int l, int r) 
{ 
	if (l < r) 
	{ 
		// Same as (l+r)/2, but avoids overflow for 
		// large l and h 
		int m = l+(r-l)/2; 

		// Sort first and second halves 
		mergeSort(Array, l, m); 
		mergeSort(Array, m+1, r);
		merge(Array, l, m, r); 
	} 
} 
*/
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