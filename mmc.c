#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void print_paren(int i, int j, int n, int* brackets, char* name){
	
	if(i == j){
		printf("%c", (*name)++);
		return;
	}
	printf("(");
	print_paren(i, *((brackets + i * n) + j), n, brackets, name);
	print_paren(*((brackets + i * n) + j) + 1, j, n, brackets, name);
	printf(")");
}

int mcm(int* p, int n){

	int m[n][n], paren[n][n];

	for(int i = 1; i < n; i++)
		m[i][i] = 0;

	for(int L = 2; L < n; L++){
		for(int i = 1; i < n - L + 1; i++){
			int j = i + L - 1;
			m[i][j] = INT_MAX;

			for(int k = i ; k < j; k++){
				int q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];

				if(q < m[i][j])
					m[i][j] = q, paren[i][j] = k;
			}
		}
	}
	char name = 'A';
	print_paren(1, n-1, n, (int*)paren, &name);
	printf("\n");
	return m[1][n-1];
}

int main(int argc, char const *argv[]){
	int arr[] = {1, 2, 3, 4}; 
    int size = sizeof(arr)/sizeof(arr[0]); 
  
    printf("Minimum number of multiplications is %d \n", mcm(arr, size)); 
	return 0;
}
