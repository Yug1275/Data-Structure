#include<iostream>
using namespace std;

int linearsearch(int arr[],int size,int search){
    for(int i=0;i<size;i++){
        if(arr[i]==search){
            return i;
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
    if(linearsearch(arr,size,search)==-1){
        cout<<"The element is not present";
    }
    else{
    cout<<"Your search element is at index number: "<<linearsearch(arr,size,search);
    }
    return 0;
}