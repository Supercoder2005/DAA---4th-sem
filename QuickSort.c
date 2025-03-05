#include<stdio.h>

int partition(int arr[],int lb,int ub){
    
}

void display(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("\t%d",arr[i]);
    }
}

int main(){
    int i,n,key,bs;
    printf("\n Enter the size of the array:");
    scanf("%d",&n);
    int arr[n];
    int b[n];
    for(i=0;i<n;i++){
        printf("\n Enter element[%d]:",i);
        scanf("%d",&arr[i]);
    }
    printf("\n The unsorted array----\n");
    display(arr,n);
    printf("\n The sorted array----\n");
    
    display(arr,n);
    return 0;
}