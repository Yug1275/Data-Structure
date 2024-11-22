#include<stdio.h>

void selectionsort(int arr[],int size){
   for(int i=0;i<size-1;i++){
    int minIndex=i;
    for(int j=i+1;j<size;j++){
        if(arr[j]<arr[minIndex]){
            minIndex=j;
        }
    }
    int temp=arr[minIndex];
    arr[minIndex]=arr[i];
    arr[i]=temp;
   }
}

void printarr(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    int size;
    printf("Enter the size of the array:");
    scanf("%d",&size);
    int arr[size];
    printf("Enter the elements of the array:");

    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("The sorted order is: ");
    selectionsort(arr,size);
    printarr(arr,size);
}