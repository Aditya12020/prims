#include <stdio.h>

#define V 7
#define E 10
#define INF 999

struct Edge {
    int src, dest, weight;
};

void printPath(int parent[], int j) {
    if (parent[j] == -1)
        return;

    printPath(parent, parent[j]);
    printf("->%d", j + 1);
}

int main() {

    struct Edge edges[E] = {
        {0,1,6},
        {0,2,5},
        {0,3,5},
        {1,4,-1},
        {2,1,-2},
        {2,4,1},
        {3,2,-2},
        {3,5,-1},
        {4,6,3},
        {5,6,3}
    };

    int dist[V], parent[V];
    int table[V][V];
    int i, j, k;
    int source = 0;

    for(i = 0; i < V; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }

    dist[source] = 0;
    for(k = 0; k < V-1; k++) {

        for(i = 0; i < E; i++) {

            int u = edges[i].src;
            int v = edges[i].dest;
            int w = edges[i].weight;

            if(dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }

        for(j = 0; j < V; j++) {
            table[k][j] = dist[j];
        }
    }
    printf("\nOutput:\n\n");

    printf("k\t");
    for(i = 0; i < V; i++) {
        printf("1->%d\t", i + 1);
    }

    printf("\n\n");

    for(i = 0; i < V-1; i++) {

        printf("%d\t", i + 1);

        for(j = 0; j < V; j++) {

            if(table[i][j] == INF)
                printf("∞\t");
            else
                printf("%d\t", table[i][j]);
        }

        printf("\n\n");
    }
    printf("\nPath:\n\n");

    for(i = 1; i < V; i++) {

        printf("1");
        printPath(parent, i);

        printf(" : %d\n", dist[i]);
    }

    return 0;
}