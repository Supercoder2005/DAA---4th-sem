#include<stdio.h>
int binary_search(int arr[],int low,int high,int key){
    int mid = low+(high-low)/2;
    if(low>high){
        return -1;
    }
    else if(arr[mid]==key){
        return mid;
    }
    else if(arr[mid]>key){
        return binary_search(arr,low,mid-1,key);
    }
    else if(arr[mid]<key){
        return binary_search(arr,mid+1,high,key);
    }
}
void bubble_sort(int arr[],int n){
    int temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
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
    for(i=0;i<n;i++){
        printf("\n Enter element[%d]:",i);
        scanf("%d",&arr[i]);
    }
    printf("\n The unsorted array -----\n");
    display(arr,n);
    bubble_sort(arr,n);
    printf("\n The sorted array -----\n");
    display(arr,n);
    printf("\n Enter the element you want to search:");
    scanf("%d",&key);
    bs = binary_search(arr,0,n-1,key);
    printf("\n Element found at index : %d",bs);
    return 0;
}
