#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b){
	int t = *a; *a = *b; *b = t; 
}

int partition(int* arr, int p, int r){
	int x = arr[r];
	int i = p - 1;
	for(int j = i + 1; j < r; j++)
		if(arr[j] < x)
			swap(&arr[j], &arr[++i]);
	swap(&arr[r], &arr[i+1]);
	return i + 1;
}

void quick(int* arr, int p, int r){
	if(p < r){
		int q = partition(arr, p, r);
		quick(arr, p, q - 1);
		quick(arr, q + 1, r);
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

	quick(arr, 0, arr_size - 1); 

	printf("\nSorted array is \n"); 
	printArray(arr, arr_size); 
	return 0; 
	return 0;
}