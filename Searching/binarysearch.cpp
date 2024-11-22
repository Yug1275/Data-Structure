#include<iostream>
using namespace std;

int binarysearch(int arr[],int size,int search){
    int s=0;
    int e=size;

    while(s<=e){
        int mid=(s+e)/2;
        if(arr[mid]==search){
            return mid;
        }
        else if(arr[mid]>search){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return -1;
}

int main(){
    int size;
    cout<<"Enter the size of the array:"<<endl;
    cin>>size;
    int arr[size];
    int search;

    cout<<"Enter the elements of the array:"<<endl;
    for(int i=0;i<size;i++){
    cin>>arr[i];
    }
    cout<<"The elements of the array are: "<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"Enter the element you want to search:"<<endl;
    cin>>search;
    if(binarysearch(arr,size,search)==-1){
        cout<<"The element is not present";
    }
    else{
    cout<<"Your search element is at index number: "<<binarysearch(arr,size,search);
    }
    return 0;
}