#include<stdio.h>
#define MAX 100

int n,e ; // n = no of vertices , e = no of edges 
int edge[MAX][3]; // edge is such an array contains rows = total e edges , col = u,v,weight 
int parent[MAX]; // which are used to store parent vertex of each vertices 

int findParent(int v){
    while(parent[v] != v){
        v = parent[v];
    }
    return v;
}
void sortEdges(){
    for(int i=0;i<e-1;i++){
        for(int j=i+1;j<e;j++){
            if(edge[i][2]>edge[j][2]){
                int temp1 = edge[i][0];
                int temp2 = edge[i][1];
                int temp3 = edge[i][2];

                edge[i][0] = edge[j][0];
                edge[i][1] = edge[j][0];
                edge[i][2] = edge[j][0];

                edge[j][0] = temp1;
                edge[j][1] = temp2;
                edge[i][2] = temp3;
            }
        }
    }
}

int kruskal(){
    int totalCost = 0;
    int count = 0;

    sortEdges();

    for(int i=0;i<e;i++){
        int u = edge[i][0];
        int v = edge[i][1];
        int weight = edge[i][2];

        int rootU = findParent(u);
        int rootV = findParent(v);

        if(rootU != rootV){
            parent[rootV] = rootU;
        }

        printf("%d -> %d: Weight %d\n",u,v,weight);
        totalCost += weight;
        count ++;

        if(count==n-1){
            break;
        }
    }
    return totalCost;

}

int main(){
    printf("\n Enter the no of vertices:");
    scanf("%d",&n);
    printf("\n Enter the total no of edges:");
    scanf("%d",&e);
    printf("\n Enter the edges (u -> v weight):\n");
    for(int i=0;i<e;i++){
        scanf("%d %d %d",&edge[i][0],&edge[i][1],&edge[i][2]);
    }
    // initialize the parent array , initially each vertex is their own parent 
    for(int v=0;v<n;v++){
        parent[v] = v;
    }
    int v;
    printf("\n The total cost of the MST : %d",kruskal());
    return 0;
}
