#include<stdio.h>
#include<stdbool.h>
#define MAX 20 

int graph[MAX][MAX];
int color[MAX];  // array to store the final colour assigned to each vertiex of the graph 
int V , m; // v = no of vertices , m = no of total colours
int solutionCount = 0; // initialise the solutionCount variable 

bool isSafe(int v, int c){
    for(int i=0;i<V;i++){ // checking for the all adjacent vertices of the given vertex v whether they are neighbour of v or not 
        if(graph[v][i] == 1 && color[i] == c){ // also checking whether the colour of vertex v and colour of that neighbouring vertex matches or not 
            return false;
        }
    }
    return true;
}

void printSolution(){
    solutionCount ++;
    printf("\n Solution %d:",solutionCount);
    for(int i=0;i<V;i++){
        printf(" V%d : C%d",i+1,color[i]);

    }
}

//main function for backtracking
void graphColoring(int v){
    if(v==V){ // if all vertices are assigned to specific colours then only print the solution
        printSolution();
        return;
    }
    // now iterative through each element of the color array 
    for(int c=1;c<=m;c++){
        if(isSafe(v,c)){  // if the condition for colouring passed 
            // assign colour c to the vertex v
            color[v] = c;
            graphColoring(v+1);
            color[v] = 0;
        }
    }
}

int main(){
    printf("\n Enter the no of vertices:");
    scanf("%d",&V);
    printf("\n Enter the no of colours:");
    scanf("%d",&m);
    printf("\n Enter the adjacency matrix for the graph:\n");
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    // initialize the colour matrix 
    for(int i=0;i<V;i++){
        color[i] = 0;
    }

    graphColoring(0);
    return 0;

}