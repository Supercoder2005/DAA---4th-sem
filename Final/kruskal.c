#include<stdio.h>
#define MAX 100 

int n,e;
int edge[MAX][3];
int parent[MAX];

int findParent(int v){
    while(parent[v] != v){
        v = parent[v];
    }
    return v;
}

void sortEdge(){
    for(int i=0;i<e-1;i++){
        for(int j=i+1;j<e;j++){
            if(edge[i][2]>edge[j][2]){
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

int kruskal(){
    int totalCost = 0;
    int count = 0;
    sortEdge();
    for(int i=0;i<e;i++){
        int u = edge[i][0];
        int v = edge[i][1];
        int weight = edge[i][2];
        int rootU = findParent(u);
        int rootV = findParent(v);
        if(rootU != rootV){
            parent[rootV] = rootU;
            
            printf("\n %d -> %d: weight %d",edge[i][0],edge[i][1],edge[i][2]);
            totalCost += weight ;
            count ++;

            if(count == n-1){
                break;
            }
            
        } 
    }
    return totalCost;
}

int main(){
    printf("\n Enter the no of vertices:");
    scanf("%d",&n);
    printf("\n Enter the no of edges:");
    scanf("%d",&e);
    printf("\n Enter the edges as (source -> destination weight):");
    for(int i=0;i<e;i++){
        scanf("%d %d %d",&edge[i][0],&edge[i][1],&edge[i][2]);
    }
    for(int i=0;i<n;i++){
        parent[i] = i;
    }
    printf("\n The cost of the minimum spanning tree using kruskal's algorithm = %d",kruskal());
    return 0;
}