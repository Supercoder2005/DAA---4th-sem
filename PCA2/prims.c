#include<stdio.h>
#include<limits.h>

#define MAX 100 

int graph[MAX][MAX];
int n;
int visited[MAX]; // array to store each vertex are visited otr not in the process of making the MST 
int minCost[MAX]; // array to store minimium cost to connect each vertex to the MST 
int parent[MAX]; // array to store the parent of each vertex in the MST 


void printMST(){
    int totalCost = 0;
    printf("\n The MST of the given graph :\n");
    for(int i=1;i<n;i++){
        printf("V%d -> V%d : %d\n",parent[i],i,graph[parent[i]][i]);
        totalCost += graph[parent[i]][i];
    }
    printf("\n Total Cost : %d",totalCost);

}

void prim(){

    // loop to find out the MST , it will run for (n-1) times as there are n nodes and n-1 edges in a MST 
    for(int count = 0;count < n-1;count++){
        int u = -1;
        int min = INT_MAX;

        // loop to find out the vertex with the minimum cost which is not visited yet
        for(int v=0;v<n;v++){
            if(!visited[v] && minCost[v]<min){
                min = minCost[v];
                u = v;
            }
        }
        visited[u] = 1; 

        //update the minimum cost for adjacency vertices 
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
    printf("\n Enter the no of vertices:");
    scanf("%d",&n);
    printf("\n Enter the adjacency matrix for the graph :\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    // initialize the visited and minCost array 
    for(int i=0;i<n;i++){
        visited[i] = 0; // initally all the vertices are unvisited so set 0 
        minCost[i] = INT_MAX; // initially the MST is empty so assign a large value for minCost to connect each vertex to the MST
    }

    // initialize for the 0th vertex or the source vertex
    //visited[0] = 1; // mark the 0th vertex as visited
    parent[0] = -1; // as there will be no parent of the 0th node so to mark it as root node set it to -1
    minCost[0] = 0;

    prim();

    return 0;

}