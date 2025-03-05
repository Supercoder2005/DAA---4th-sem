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
    int n,i;
    printf("\n Enter the number of matrices that we have to multiply:");
    scanf("%d",&n);
    int dim[n+1];
    printf("\n Enter the dimensions of the matrices(space separated Values):");
    for(i=0;i<=n;i++){
        scanf("%d",&dim[i]);
    }
    int min_multiplications = matrix_chain_order(dim,1,n);
    printf("Minimum number of scalar multiplications: %d\n", min_multiplications);

    return 0;
}