#include<stdio.h>

// this function will merge two sub arrays into a sorted array
void merge(int arr[],int lb,int mid,int ub){
    int i,j,k;

    int b[ub+1];   //a new array is introduced of the same size of the user given array arr to store the sorted elements after merging
    i=lb;         // i pointer will indicate the elements of left subarray
    j=mid+1;     // j pointer will indicate the elements of right subarray
    k=lb;       // k pointer will indicate the elements of new sorted and merged array

    // the left subarray is started from lb and ends at mid 
    // the right subarray is started from (mid+1) and ends at ub
    while(i<=mid && j<=ub){
        // checks if i th element of left subarray is greater than j th element of right subarray, then place the smaller element of the right subarray at the kth index of new array b
        if(arr[i] >= arr[j]){ 
            b[k] = arr[j];
            j++;
        }
        // checks if i th element of left subarray is smaller than j th element of right subarray, then place the smaller element of the left subarray at the kth index of new array b
        else if(arr[i] <= arr[j]){
            b[k] = arr[i];
            i++;
        }
        k++;
    }
    // if all the elements of left subarray is visited but still some elements are left in right subarray then , simply copy them from right subarray to the new array b
    if(i>mid){
        while(j <= ub){
            b[k] = arr[j];
            j++;
            k++;
        }
    }
    // if all the elements of right subarray is visited but still some elements are left in left subarray then , simply copy them from left subarray to the new array b
    else{
        while(i <= mid){
            b[k] = arr[i];
            i++;
            k++;
        }
    }
    // at last again copy all the elements of new array b to the old array arr where after merging all the elements are sorted 
    for(k=0;k<=ub;k++){
        arr[k] = b[k];
    }
}

// this function will divide the main array into two subarrays and do this process recursively untill lb is greater than ub
void merge_sort(int arr[],int lb,int ub){
    if(lb<ub){
        // at first calculate mid
        int mid = lb+(ub-lb)/2;
        merge_sort(arr,lb,mid);   // left subarray
        merge_sort(arr,mid+1,ub); // right subarray
        merge(arr,lb,mid,ub);     // merge the subarrays imto a new array where elements are sorted
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
