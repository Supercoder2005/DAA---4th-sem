#include<stdio.h>
#define MAX 100

int n,e ; // n = no of vertices , e = no of edges 
int edge[MAX][3]; // edge is such an array contains rows = total e edges , col = u,v,weight 
int parent[MAX]; // which are used to store parent vertex of each vertices 

int findParent(int v){
    if(parent[v] != v){
        parent[v] = v;
    }
    return v;
}
void sortEdges(){
    for(int i=0;i<e-1;i++){
        for(int j=i+1;j<e;j++){
            if(edge[i][2]>edge[j][2]){
                int temp1 = edge[i][0];
                int temp2 = edge[i][1];
                int temp3 = edge[i][3];

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

int main(){
    printf("\n Enter the no of vertices:");
    scanf("%d",&n);
    printf("\n Enter the total no of edges:");
    scanf("%d",&e);
    printf("\n Enter the edges (u -> v weight):\n");
    for(int i=0;i<e;i++){
        for(int j=0;j<3;j++){
            scanf("%d %d %d",&edge[i][0],&edge[i][1],&edge[i][2]);
        }
    }
    // initialize the parent array , initially each vertex is their own parent 
    for(int v=0;v<n;v++){
        parent[v] = v;
    }
}
