#include<stdio.h>
void MaxMin(int arr[],int low,int high,int *max,int *min){
    // when there is only 1 element in the array both min and max will be that element
    if(low == high){
        *min = *max = arr[low];
    }
    // if there are 2 elements in the array , compare them and according to this decide the max and min
    else if(low == high-1){
        if(arr[low]<arr[high]){
            *min = arr[low];
            *max = arr[high];
        }
        else{
            *min = arr[high];
            *max = arr[low];
        }
    }
    // when there are more than 2 elements in the array , divide the array in to two parts , one is from low to mid , another one is from mid+1 to high
    else{
        int min1,max1;
        int mid = (low+high)/2;
        MaxMin(arr,low,mid,max,min);
        MaxMin(arr,mid+1,high,&max1,&min1);
        if(min1<*min){
            *min = min1;
        }
        if(max1>*max){
            *max = max1;
        }
    }
}
int main(){
    int n,i,max,min;
    printf("\n enter the size of the array:");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++){
        printf("\n Element[%d]:",i);
        scanf("%d",&arr[i]);
    }
    printf("\n The array is -----\n");
    for(i=0;i<n;i++){
        printf("\t%d",arr[i]);
    }
    MaxMin(arr,0,n-1,&max,&min);
    printf("\n\nMaximum element: %d", max);
    printf("\nMinimum element: %d\n", min);
    return 0;
}