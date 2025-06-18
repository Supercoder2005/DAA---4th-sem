#include<stdio.h>
#include<limits.h>
#define MAX 100
#define INF 99999 

int graph[MAX][MAX];
int n,src;
int dist[MAX];
int visited[MAX];

void printSolution(){
    for(int i=0;i<n;i++){
        if(dist[i]==INF){
            printf("\n Unreachable");
        }
        else{
            printf("\n %d -> %d : %d",src,i,dist[i]);
        }
    }
}

void dijkstra(){
    for(int i=0;i<n-1;i++){
        int u = -1;
        int min = INF; 
        // loop to find out the unvisited vertex 'u' having minimum distance 
        for(int v=0;v<n;v++){
            if(!visited[v] && dist[v]<min){
                min = dist[v];
                u = v;
            }
        }
        visited[u] = 1;
        // loop to find out whether the minimum distance vertex u is connected to vertex v or not 
        for(int v=0;v<n;v++){
            if(!visited[v] && graph[u][v]!=0 && dist[u]!= INF && dist[u]+graph[u][v]<dist[v]){
                dist[v] = dist[u]+graph[u][v];
            }
        }
    }
    printSolution();
}

int main(){
    printf("\n Enter the number of vertices:");
    scanf("%d",&n);
    printf("\n Enter the adjacency matrix of the graph:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    printf("\n Enter the source vertex:");
    scanf("%d",&src);

    //initialization of distance[] & visited[]
    for(int i=0;i<n;i++){
        visited[i]=0; // initially all vertices are unvisited
        dist[i]=INF; // initially all vertices have distance from source = infinity 
    }
    dist[0] = 0 ;// as distance of src from itself is = 0 

    dijkstra();
    return 0;

}
