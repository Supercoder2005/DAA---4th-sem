#include<stdio.h>
#include<stdbool.h>
#define MAX 20 

int graph[MAX][MAX];
int path[MAX];
int V;
int solutionCount = 0;

bool isSafe(int v,int pos){
    if(graph[v][path[pos-1]] == 0){
        return false;
    }
    for(int i=0;i<pos;i++){
        if(path[i]==v){
            return false;
        }
    }
    return true;
}

void printSolution(){
    solutionCount++;
    printf("\n Solution %d:",solutionCount);
    for(int i=0;i<V;i++){
        printf("V%d ->",path[i]);
    }
    printf("V%d",path[0]);
}

void hamiltonianCycle(int pos){
    if (pos == V && graph[path[pos-1]][path[0]] ){
        printSolution();
    }

    for(int v=1;v<V;v++){
        if(isSafe(v,pos)){
            path[pos] = v;
            hamiltonianCycle(pos+1);
            path[pos] = -1;
        }
    }

}

int main(){
    printf("\n Enter the no of vertices :");
    scanf("%d",&V);
    printf("\n Enter the adjacency matrix for the graph :\n");
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    // initialize the path array 
    for(int i=0;i<V;i++){
        path[i] = -1; 
    }

    path[0] = 0;
    hamiltonianCycle(1);
}