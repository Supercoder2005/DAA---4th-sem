#include<stdio.h>
#include<limits.h>
#define MAX 100 

int graph[MAX][MAX];
int n;
int visited[MAX];
int parent[MAX];
int minCost[MAX];

void printMST(){
    int totalCost = 0;
    printf("\n The MST of the given graph is ---\n");
    for(int i=0;i<n;i++){
        printf("\n%d -> %d : weight %d",parent[i],i,graph[parent[i]][i]);
        totalCost += graph[parent[i]][i];
    }
    printf("\n Total cost of the MST:%d",totalCost);
}

void prims(){
    for(int i=0;i<n-1;i++){
        int u = -1;
        int min = INT_MAX;
        for(int v=0;v<n;v++){
            if(!visited[v] && minCost[v]<min){
                min = minCost[v];
                u = v;
            }
        }
        visited[u] = 1;

        for(int v=0;v<n;v++){
            if(!visited[v] && graph[u][v]!=0 && graph[u][v]<minCost[v]){
                minCost[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }
    printMST();
}

int main(){
    printf("\n Enter the number of vertices:");
    scanf("%d",&n);
    printf("\n Enter the adjacency matrix of the graph:");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        visited[i] = 0;
        minCost[i] = INT_MAX;
    }
    parent[0] = 0;
    minCost[0] = 0;

    prims();
    return 0;
}