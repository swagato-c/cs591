#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define V 5

int min_key(int* key,int* mst){
	int min = INT_MAX, index;
	for(int v = 0; v < V; v++)
		if(!mst[v] && key[v] < min)
			min = key[v], index = v;
	return index;
}

void print_mst(int* p, int G[V][V]){
	int sum = 0;
	printf("Edge \tWeight\n"); 
	for (int i = 1; i < V; i++){
		sum += G[i][p[i]];
    	printf("%d - %d \t%d \n", p[i]+1, i+1, G[i][p[i]]);
    }
    printf("Minimum sum = %d\n", sum);
}

void prim(int G[V][V]){
	int key[V], p[V], mst[V];

	for(int v = 0; v < V; v++) 
		key[v] = INT_MAX, mst[v] = 0;

	key[0] = 0, p[0] = -1;

	for(int i = 0; i < V-1; i++){
		int u = min_key(key, mst);
		mst[u] = 1;

		for(int v = 0; v < V; v++)
			if(G[u][v] && !mst[v] && G[u][v] < key[v])
				key[v] = G[u][v], p[v] = u;
	}

	print_mst(p,G);
}

int main(int argc, char const *argv[]){
	/* Let us create the following graph 
        2 3 
    (0)--(1)--(2) 
    | / \ | 
    6| 8/ \5 |7 
    | /     \ | 
    (3)-------(4) 
            9         */
	int graph[V][V] =  {{0, 2, 0, 6, 0}, 
                    	{2, 0, 3, 8, 5}, 
                    	{0, 3, 0, 0, 7}, 
                    	{6, 8, 0, 0, 9}, 
                    	{0, 5, 7, 9, 0}}; 
  
    // Print the solution 
    prim(graph); 
	return 0;
}
