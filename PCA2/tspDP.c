#include<stdio.h>
#include<stdbool.h>
#include<limits.h>

#define MAX  100
#define INF 10000000

int n;
int graph[MAX][MAX];
int dp[MAX][MAX];
int visited[MAX];

int tsp(int currentCity,int count){ //  count = no of cities visited already
    // base condition 
    if(count == n && graph[currentCity][0] != 0){ // when all cities are visited and there is a way to goback to starting city to the current city
        return graph[currentCity][0];
    }

    // memoization 
    if(dp[currentCity][count]!= -1){ // if previously we have already calculated graph[city][count] return that for further calculation
        return dp[currentCity][count];
    }

    int minCost = INF;

    for(int city=0;city<n;city++){
        if(!visited[city] && graph[currentCity][city]!=0){ // if the city is not visited yet and there is a path from the current city to the city
            visited[city] = 1;
            int temp = graph[currentCity][city] + tsp(city,count+1); // calculate the min cost for sub problem
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
    printf("\n Enter the total no of cities:");
    scanf("%d",&n);
    printf("\n Enter the adjacency matrix holding the cost to go from one city to another:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    // initialize the dp table 
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j] = -1;
        }
    }

    // initialize the visited array (atfirst mark all the cities as unvisited)
    for(int i=0;i<n;i++){
        visited[i] = 0;
    }

    // now make the starting city / source city as visited 
    visited[0] = 1;

    int ans = tsp(0,1);  // as tsp(currentcity = 0th / starting city , count = 1 / already 1 city or the starting city is visited)
    printf("\n The minimum cost for this travelling salesman problem is : %d",ans);

    return 0;
}