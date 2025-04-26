#include<stdio.h>
#include<limits.h>

#define MAX 100
#define INF 99999 

int minDistanceVertex(int dist[],int visited[],int V){
    int min = INF , minIndex = -1;
    for(int v=0;v<V;v++){
        if(!visited[v] && dist[v]<min){
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void printSolution(int dist[],int V,int src){
    for (int i=0;i<V;i++){
        if(dist[i] == INF){
            printf("\n Unreachable");
        }
        else{
            printf("Vertex %d -> %d : %d\n",src,i,dist[i]);
        } 
    }
}

void dijkstra(int graph[MAX][MAX],int src,int V){
    int dist[V];
    int visited[V];

    // initialize each vertex as unvisited and also dist from src to that v vertex as infinity 
    for(int v=0;v<V;v++){
        dist[v] = INF;
        visited[v] = 0;
    }
    // initialize dist from src vertex to src as 0
    dist[src] = 0;


    for(int i=0;i<V-1;i++){
        int u = minDistanceVertex(dist,visited,V);
        if(u==-1){ // when there is no unvisited node with min distance left 
            break;
        }

        visited[u] = 1;

        for(int v=0;v<V;v++){
            if(!visited[v] && graph[u][v] && dist[u]!= INF && dist[u]+graph[u][v]<dist[v]){
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printSolution(dist,V,src);
}

int main(){
    int V,src;
    printf("\n Enter the no of vertices:");
    scanf("%d",&V);
    int graph[MAX][MAX];
    printf("\n Enter the adjacency matrix of graph:");
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    printf("\n Enter the source vertex:");
    scanf("%d",&src);
    printf("\n The minimum distance from source vertex %d to every vertex ---\n",src);
    dijkstra(graph,src,V);
    return 0;
    
}