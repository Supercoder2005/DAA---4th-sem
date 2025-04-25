#include<stdio.h>

int max(int a, int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}

int knapsackDP(int W,int weight[],int profit[],int n){
    int i,w;
    int DP[n+1][W+1]; // initialize the grid for the tabulation of dynamic programming 
    for(i=0;i<n+1;i++){
        for(w=0;w<W+1;w++){
            if(i==0 || w==0){
                DP[i][w] = 0;
            }
            else if(w<weight[i-1]){
                DP[i][w] = DP[i-1][w];
            }
            else{
                DP[i][w] = max(DP[i-1][w] , DP[i-1][w-weight[i-1]] + profit[i-1]);
            }
        }
    }
    return DP[n][W];

}

int main(){
    int W,n;
    printf("\n Enter the no of items in the knapsack:");
    scanf("%d",&n);
    printf("\n Enter the maximum weight capacity of the knapsack :");
    scanf("%d",&W);
    int weight[n], profit[n];
    for(int i=0;i<n;i++){
        printf("\n Enter weight & profit of item(%d):",i);
        scanf("%d%d",&weight[i],&profit[i]);
    }
    printf("\n The maximum profit will be :%d",knapsackDP(W,weight,profit,n));
    return 0;

}