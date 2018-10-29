#include <stdio.h>
#include <stdlib.h>

int V, E;

typedef struct edge{
    int u, v, w;
} edge;

int find(int* parent, int i){
    if (parent[i] != i) 
        parent[i] = find(parent, parent[i]);
    return parent[i];
}

void Union(int* parent, int* rank, int x, int y){
    int xroot = find(parent, x);
    int yroot = find(parent, y);

    if (rank[xroot] < rank[yroot]) 
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot]) 
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

int comp(const void* a, const void* b){
    edge* u = (edge*) a;
    edge* v = (edge*) b;
    return u->w > v->w;
}

void kruskal(edge* G){
    int parent[V], rank[V];
    int sum = 0;
    
    for(int i = 0; i < V; i++)
        parent[i] = i, rank[i] = 0;

    qsort(G, E, sizeof(G[0]), comp);

    for (int i = 0, e = 0; e < V-1; ){
        edge next = G[i++];
        int u = find(parent, next.u);
        int v = find(parent, next.v);

        if (u != v){
            Union(parent, rank, u, v);
            e++;
            printf("%d - %d\t%d\n", next.u , next.v, next.w);
            sum += next.w;
        }

    }
    printf("Minimum weight = %d\n", sum);
}

int main(int argc, char const *argv[]){
    V = 4 , E = 5;
    int ed[5][3] ={{0,1,10},
                   {0,2,6},
                   {0,3,5},
                   {1,3,15},
                   {2,3,4}};
    
    edge G[E];
    for(int i = 0; i < E; i++)
        G[i].u = ed[i][0], G[i].v = ed[i][1], G[i].w = ed[i][2];

    kruskal(G);

    return 0;
}