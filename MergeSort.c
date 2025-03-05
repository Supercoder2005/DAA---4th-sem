#include<stdio.h>

// this function will merge two sub arrays into a sorted array
void merge(int arr[],int lb,int mid , int ub){
    int i,j,k;
    int b[ub+1];
    i=lb;
    j=mid+1;
    k=lb;
    while(i<=mid && j<=ub){
        if(arr[i] >= arr[j]){
            b[k] = arr[j];
            j++;
        }
        else if(arr[i] <= arr[j]){
            b[k] = arr[i];
            i++;
        }
        k++;
    }
    if(i>mid){
        while(j <= ub){
            b[k] = arr[j];
            j++;
            k++;
        }
    }
    else{
        while(i <= mid){
            b[k] = arr[i];
            i++;
            k++;
        }
    }
    for(k=0;k<=ub;k++){
        arr[k] = b[k];
    }
}

void merge_sort(int arr[],int lb,int ub){
    if(lb<ub){
        int mid = lb+(ub-lb)/2;
        merge_sort(arr,lb,mid);
        merge_sort(arr,mid+1,ub);
        merge(arr,lb,mid,ub);
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
    merge_sort(arr,0,n-1);
    display(arr,n);
    return 0;
}
