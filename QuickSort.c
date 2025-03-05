#include<stdio.h>
void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
int partition(int arr[],int lb,int ub){
    int pivot,start,end;
    pivot = arr[lb];
    start = lb;
    end = ub;
    while(start<end){
        while(arr[start]<=pivot){
            start ++;
        }
        while(arr[end]>pivot){
            end --;
        }
        if(start<end){
            swap(&arr[start],&arr[end]);
        }
    }
    swap(&arr[lb],&arr[end]);
    return end;
}

void quick_sort(int arr[],int lb,int ub){
    if(lb<ub){
        int loc;
        loc = partition(arr,lb,ub);
        quick_sort(arr,lb,loc-1);
        quick_sort(arr,loc+1,ub);
    }
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
    quick_sort(arr,0,n-1);
    display(arr,n);
    return 0;
}