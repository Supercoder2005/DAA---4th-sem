#include<stdio.h>
#include<limits.h>
#define MAX 100
#define INF 99999 

int n;
int graph[MAX][MAX]; // adjacency matrix to store the cost to go from one city to another city 
int dp[MAX][MAX]; // dp table to store the values of small sub problems 
int visited[MAX]; // array to store whether a city is visited or not 

int tspDP(int currentCity, int count){
    // currentCity = the current city where the salesman is present now 
    // count = number of cities allready visited till now 
    
    //base case --- if all the cities are visited and there is also a path from last visited node to the source node
    if(count == n && graph[currentCity][0]!=0){
        return graph[currentCity][0];
    }

    // memoization table 
    if(dp[currentCity][count]!= -1){ // if a subproblem is solved previously , don't recalculate it , return the result from the table
        return dp[currentCity][count];
    }

    int minCost = INF;
    for(int city=0;city<n;city++){
        // if there is a unvisited city present, which is reachable from vertex city
        if(!visited[city] && graph[currentCity][city]!=0){
            visited[city] = 1;
            int temp = graph[currentCity][city] + tspDP(city,count+1);
            if(temp<minCost){
            minCost = temp;
            }
            //backtracking 
            visited[city] = 0;
        }
    }
    dp[currentCity][count] = minCost;
    return minCost;
}


int main(){
    printf("\n Enter the number of cities:");
    scanf("%d",&n);
    printf("\n Enter the adjacency matrix to store the cost required to go to a city from another city:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }

    // initialisation of dp table 
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j] = -1; // initially all the sub problems are unsolved 
        }
    }

    //initialisation of visited array 
    for(int i=0;i<n;i++){
        visited[i] = 0; // initially all cities are unvisited
    }
    visited[0] = 1; // source vertex is assigned to as visited 

    printf("\n The minimum cost for the travelling salesman problem : %d",tspDP(0,1)); // calling of tspDP(currentCity,count) function 
    // here current city = starting city/0th city & count = 1 as only the starting city is visited till now 
    return 0;
}