#include<stdio.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void sort(int jobNo[],int profit[],int deadline[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(profit[j]<profit[j+1]){
                swap(&profit[j],&profit[j+1]);
                swap(&deadline[j],&deadline[j+1]);
                swap(&jobNo[j],&jobNo[j+1]);
            }
        }
    }
}

int maxDeadline(int deadline[],int n){
    int maximum=deadline[0];
    for(int i=0;i<n;i++){
        if(deadline[i]>maximum){
            maximum=deadline[i];
        }
    }
    return maximum;
}

void displaySlot(int slot[],int maximumDeadline){
    printf("\n The job sequencing for the maximum profit will be ---- \n");
    for(int i=0;i<maximumDeadline;i++){
        printf("\t%d",slot[i]);
    }
}

int jobSequencing(int jobNo[],int profit[],int deadline[],int n){
    sort(jobNo,profit,deadline,n);
    int maximumDeadline = maxDeadline(deadline,n);

    int slot[maximumDeadline];
    for(int i=0;i<maximumDeadline;i++){
        slot[i] = -1;
    }

    // slot = [-1,-1,-1] where maxdeadline is the length of the array so indexing is from 0 to 2 (as deadline 1,2,3)
    // jobNo = [2,3,1]
    // deadline = [3,1,2]
    //profit = [11,45,23]

    int maxProfit = 0;
    for(int i=0;i<n;i++){ // i is for profit array
        for(int j=deadline[i]-1;j>=0;j--){ // j is for slot array
            if(slot[j]==-1){
                slot[j] = jobNo[i];
                maxProfit += profit[i];
                break;
            }
        }
    }
    displaySlot(slot,maximumDeadline);
    return maxProfit;
}


int main(){
    int n;
    printf("\n Enter the number of total jobs:");
    scanf("%d",&n);
    int profit[n],deadline[n],jobNo[n];
    for(int i=0;i<n;i++){
        printf("\n Enter the jobNo and it's respective profit and deadline:");
        scanf("%d%d%d",&jobNo[i],&profit[i],&deadline[i]);
    }
    int ans = jobSequencing(jobNo,profit,deadline,n) ;
    printf("\n The maximum profit = %d",ans);
}