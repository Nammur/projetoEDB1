#include "../include/radixSort.h"

// ==================================================================================
// COMENTARIO:
//*		O RadixSort junto com o ShellSort foram complicados para entender/implementar
//*		já que não foi nos dada uma explicação sobre esses algoritmos e tivemos que 
//*		fazer a pesquisa "as cegas", ainda sim, cremos que o resultado esteja
//*		correto e satisfatório (otimizado), já que nos baseamos em outro algoritmo já
//*		disponibilizado na internet
// ==================================================================================
// Implementacao do RadixSort
int valorMaximo(int *Array, int tamanhoVetor){
	int maximo = Array[0]; 
	
	// Percorre o vetor procumando o maio valor
	// dentre os elementos
	for (int i = 1; i < tamanhoVetor; i++){ 
		if (Array[i] > maximo){ 
			maximo = Array[i];
		}
	}

	return maximo; 
} 

// Ordenação dos elemtos
void Sort(int *Array, int tamanhoVetor, int exponencial){ 
	int i, contador[10] = {0};

	// Vetor temporario
	int radixTemp[tamanhoVetor];

	for (i = 0; i < tamanhoVetor; i++){
		contador[ (Array[i]/exponencial) % 10 ]++; 
	}

	for (i = 1; i < 10; i++){
		contador[i] += contador[i - 1]; 
	}

	// Construcao do vetor temporario 
	for (i = tamanhoVetor - 1; i >= 0; i--){ 
		radixTemp[contador[ (Array[i]/exponencial) % 10 ] - 1] = Array[i]; 
		contador[ (Array[i]/exponencial) % 10 ]--; 
	} 

	// Copia dos valores do vetor tmeporario
	// para o vetor final 
	for (i = 0; i < tamanhoVetor; i++){
		Array[i] = radixTemp[i];
	}
} 

void radixSort(int *Array, int tamanhoVetor){
	// Funcao para encontrar o maior valor entre os elemntos
	// dos vetores 
	int maximo = valorMaximo(Array, tamanhoVetor);
	int exponencial;

	// Passar o maior valor exponencial, da forma 10^i 
	for (exponencial = 1; maximo / exponencial > 0; exponencial *= 10){ 
		Sort(Array, tamanhoVetor, exponencial);
	}
}
// Fim RadixSort