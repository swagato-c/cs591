#include <stdio.h>
#include <stdlib.h>

typedef struct item{
	int p, w;
}item;

int comp(const void* a, const void* b){
	item* a1 = (item*) a;
	item* b1 = (item*) b;
	return (a1->p/(double)a1->w) < (b1->p/(double)b1->w);
}

double knap(int W, item* list, int n){
	qsort(list, n, sizeof(list[0]), comp);

	int weight = 0;
	double profit = 0.0;

	for(int i=0; i < n; i++){
		if(weight + list[i].w <= W){
			profit += list[i].p;
			weight += list[i].w;
		}
		else{
			profit += ((W - weight)/(double)list[i].w) * list[i].p;
			weight = W;
			break;
		}
	}
	return profit;
}

int main(int argc, char const *argv[])
{
	int W = 50;   //    Weight of knapsack 
    item arr[] = {{60, 10}, {100, 20}, {120, 30}}; 
  
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%.2f\n",knap(W, arr, n));
	return 0;
}
