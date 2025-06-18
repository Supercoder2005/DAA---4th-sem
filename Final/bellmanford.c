#include<stdio.h>
#include<limits.h>
#define MAX 100 
#define INF 99999 

int graph[MAX][MAX];
int n,src;
int dist[MAX]; 

void printSolution(){
    for(int i=0;i<n;i++){
        if(dist[i]==INF){
            printf("\n Unreachable");
        }
        else{
            printf("%d -> %d:%d\n",src,i,dist[i]);
        }
    }
}

void bellmanford(){
    //relaxation of edges
    for(int i=0;i<n-1;i++){
        for(int u=0;u<n;u++){
            for(int v=0;v<n;v++){
                if(dist[u]!=INF && graph[u][v]!=0 && dist[u]+graph[u][v]<dist[v]){
                    dist[v] = dist[u]+graph[u][v];
                }
            }
        }
    }
    //negative edge cycle detection 
    for(int u=0;u<n;u++){
        for(int v=0;v<n;v++){
            if(dist[u]!=INF && graph[u][v]!=0 && dist[u]+graph[u][v]<dist[v]){
                printf("\n Negative edge cycle is present in the graph.");
            }
        }
    }
    printSolution();
}

int main(){
    printf("\n Enter the total no of vertices:");
    scanf("%d",&n);
    printf("\n Enter the adjacency matrix of the graph:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    printf("\n Enter the source vertex:");
    scanf("%d",&src);

    //initialization of dist[] array 
    for(int i=0;i<n;i++){
        dist[i]= INF;
    }
    //distance of src vertex from itself is 0
    dist[0] = 0;
    bellmanford();
    return 0;
}