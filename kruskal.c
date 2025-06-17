#include<stdio.h>
#define MAX 100 

int n,e; // n : no of vertices , e : no of edges in the graph
int edge[MAX][3]; // edge is a 2D array that stores in its rows : the edges present in a graph , in its coloumns : source(u) , destination(v), weight
int parent[MAX]; // parent array is used to store the parent of each vertex

// use bubble sort to sort the edges according to their ascending order of weights 
void edgeSort(){
    for(int i=0;i<e-1;i++){
        for(int j=i+1;j<e;j++){
            if(edge[i][2] > edge[j][2]){
                int temp1 = edge[i][0];
                int temp2 = edge[i][1];
                int temp3 = edge[i][2];

                edge[i][0] = edge[j][0];
                edge[i][1] = edge[j][1];
                edge[i][2] = edge[j][2];

                edge[j][0] = temp1;
                edge[j][1] = temp2;
                edge[j][2] = temp3;
            }
        }
    }
}

// findParent function is used to find the parent of a particular vertex 
int findParent(int v){
    while(parent[v] != v){
        v = parent[v];
    }
    return parent[v];
}

// kruskal's algorithm
int kruskal(){
    int totalCost = 0;
    int count = 0;

    edgeSort();

    for(int i=0;i<e;i++){
        int u = edge[i][0];
        int v = edge[i][1];
        int weight = edge[i][2];

        int rootU = findParent(u);
        int rootV = findParent(v);

        if(rootU != rootV){
            parent[rootV] = rootU;

            printf("%d -> %d: weight %d\n",u,v,weight);
            totalCost += weight;
            count ++;

            if(count == n-1){
                break;
            }
        }
    }
    return totalCost;
}

int main(){
    printf("\n Enter the total number of vertices:");
    scanf("%d",&n);
    printf("\n Enter the total number of edges:");
    scanf("%d",&e);
    printf("\n Enter the edges of the graph as(source ---> destination : weight):\n");
    for(int i=0;i<e;i++){
        scanf("%d %d %d",&edge[i][0],&edge[i][1],&edge[i][2]);
    }
    // initialize the parrent array : parent[] , as parent of each vertex is that vertex itself
    for(int i=0;i<n;i++){
        parent[i]=i; 
    }
    // call the kruskal's algorithm function
    printf("\nThe weight of the MST using kruskal's algorithm = %d",kruskal());
    return 0;
}