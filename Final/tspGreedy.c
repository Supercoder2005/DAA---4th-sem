#include<stdio.h>
#define MAX 100 
#define INF 99999

int graph[MAX][MAX];
int n,src;
int visited[MAX];
int path[MAX];

void tspGreedy(){
    int totalCost = 0;
    int currentCity = src;

    for(int count = 1;count<n;count++){
        int nextCity = -1;
        int min = INF;
        //loop to find out the unvisited city having minimum cost to reach from the currentCity 
        for(int city=0;city<n;city++){
            if(!visited[city] && graph[currentCity][city]!=0 && graph[currentCity][city]<min){
                min = graph[currentCity][city];
                nextCity = city;
            }
        }
        if(nextCity == -1){
            printf("\n No unvisited city found. TSP can't be completed.\n");
            break;
        }

        visited[nextCity] = 1;
        path[count] = nextCity;

        totalCost += graph[currentCity][nextCity];
        currentCity = nextCity;
    }
    // return to the starting city 
    totalCost += graph[currentCity][src];
    path[n] = src;

    // print the path 
    printf("\n TSP path (greedy approach):\n");
    for(int i=0;i<=n;i++){
        printf("%d ->",path[i]);
    }
    printf("\n Total cost : %d",totalCost);
}

int main(){
    printf("\n Enter the number of cities:");
    scanf("%d",&n);
    printf("\n Enter the adjacency matrix that stores the cost to go from one city to another:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    printf("\n Enter the starting city:");
    scanf("%d",&src);
    //initialization of visited array 
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    visited[src] = 1; // make the source city or starting city as visited
    path[0] = src;    // the path of traversing the tsp problem will start from the src city , so the first element of path[] is src 

    tspGreedy();
    return 0;
}