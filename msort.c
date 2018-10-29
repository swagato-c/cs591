#include <stdio.h>
#include <stdlib.h>

void merge(int* arr, int p, int q, int r){
	int n1 = q - p + 1;
	int n2 = r - q;
	int L[n1], R[n2];
	
	for (int i = 0; i < n1; ++i) L[i] = arr[p + i];
	for (int i = 0; i < n2; ++i) R[i] = arr[q + 1 + i];
	
	int i = 0, j = 0, k = p;
	
	while ((i < n1) && (j < n2)) arr[k++] = (L[i] < R[j]) ? L[i++] : R[j++];
	while (i < n1) arr[k++] = L[i++];
	while (j < n2) arr[k++] = R[j++];
}

void mergesort(int* arr, int p, int r){
	if(p < r){
		int q = p + (r - p >> 1);
		mergesort(arr, p, q);
		mergesort(arr, q + 1, r);
		merge(arr, p, q, r);
	}
}

void printArray(int* arr, int size){  
	for (int i=0; i < size; i++) 
		printf("%d ", arr[i]); 
	printf("\n"); 
} 

int main(){
	int arr[] = {12, 11, 13, 5, 6, 7}; 
	int arr_size = sizeof(arr)/sizeof(arr[0]); 

	printf("Given array is \n"); 
	printArray(arr, arr_size); 

	mergesort(arr, 0, arr_size - 1); 

	printf("\nSorted array is \n"); 
	printArray(arr, arr_size); 
	return 0; 
}