#include<stdio.h>
#include<limits.h>

#define MAX 100 

int graph[MAX][MAX];
int n;
int visited[MAX];
int minCost[MAX]; // This should store the actual edge weights of the MST
int parent[MAX];

void printMST(){
    int totalCost = 0;
    printf("\nThe MST of the given graph:\n");
    for(int i=1; i<n; i++){
        if(parent[i] != -1){
            printf("V%d -> V%d : %d\n", parent[i], i, graph[parent[i]][i]);
            totalCost += graph[parent[i]][i];
        }
    }
    printf("\nTotal Cost: %d\n", totalCost);
}

void prim(){
    for(int count=0; count<n-1; count++){
        int u = -1;
        int min = INT_MAX;

        for(int v=0; v<n; v++){
            if(!visited[v] && minCost[v] < min){
                min = minCost[v];
                u = v;
            }
        }
        
        if(u == -1) break; // No vertex found (graph might be disconnected)
        
        visited[u] = 1;

        for(int v=0; v<n; v++){
            if(!visited[v] && graph[u][v] && graph[u][v] < minCost[v]){
                minCost[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }
    printMST();
}

int main(){
    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix for the graph:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &graph[i][j]);
            if(graph[i][j] == 0 && i != j){
                graph[i][j] = INT_MAX; // Represent no edge with INT_MAX
            }
        }
    }

    for(int i=0; i<n; i++){
        visited[i] = 0;
        minCost[i] = INT_MAX;
        parent[i] = -1;
    }

    // Start with vertex 0
    minCost[0] = 0; // To get picked first
    parent[0] = -1; // Root of MST

    prim();

    return 0;
}