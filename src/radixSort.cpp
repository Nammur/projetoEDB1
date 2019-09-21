#include "../include/radixSort.h"

// A utility function to get maximum value in arr[] 
int getMax(int *Array, int tamanhoVetor) 
{ 
	int mx = Array[0]; 
	for (int i = 1; i < tamanhoVetor; i++) 
		if (Array[i] > mx) 
			mx = Array[i]; 
	return mx; 
} 

// A function to do counting sort of arr[] according to 
// the digit represented by exp. 
void countSort(int *Array, int tamanhoVetor, int exp) 
{ 
	int output[tamanhoVetor]; // output array 
	int i, count[10] = {0}; 

	// Store count of occurrences in count[] 
	for (i = 0; i < tamanhoVetor; i++) 
		count[ (Array[i]/exp)%10 ]++; 

	// Change count[i] so that count[i] now contains actual 
	// position of this digit in output[] 
	for (i = 1; i < 10; i++) 
		count[i] += count[i - 1]; 

	// Build the output array 
	for (i = tamanhoVetor - 1; i >= 0; i--) 
	{ 
		output[count[ (Array[i]/exp)%10 ] - 1] = Array[i]; 
		count[ (Array[i]/exp)%10 ]--; 
	} 

	// Copy the output array to arr[], so that arr[] now 
	// contains sorted numbers according to current digit 
	for (i = 0; i < tamanhoVetor; i++) 
		Array[i] = output[i]; 
} 

// The main function to that sorts arr[] of size n using 
// Radix Sort 
void radixSort(int *Array, int tamanhoVetor) 
{ 
	// Find the maximum number to know number of digits 
	int m = getMax(Array, tamanhoVetor); 

	// Do counting sort for every digit. Note that instead 
	// of passing digit number, exp is passed. exp is 10^i 
	// where i is current digit number 
	for (int exp = 1; m/exp > 0; exp *= 10) 
		countSort(Array, tamanhoVetor, exp); 
} 
