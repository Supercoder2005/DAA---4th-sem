// find out the min no of scalar multiplication required in a matrix chain multiplication
#include<stdio.h>
#include<limits.h>
int min_count = INT_MAX;

int matrix_chain_order(int d[],int i,int j){
    int k;
    if(i==j){
        return 0;
    }
    for(k=i;k<j;k++){
        int count = matrix_chain_order(d,i,k)+
                    matrix_chain_order(d,k+1,j)+
                    d[i-1]*d[k]*d[j];
        if(count<min_count){
            min_count = count;
        }
        return min_count;
    }
}
int main(){
    return 0;
}