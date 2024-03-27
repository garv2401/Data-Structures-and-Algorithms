#include<iostream>
using namespace std;

void print_array(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void merge(int *arr,int s,int e){

    //cout<<"fine"<<endl;
    //int mid=s+(e-s)/2;
    // int len1=mid-s+1;
    // int len2=e-mid;
    // int *first=new int[len1];
    // int *second=new int[len2];
    // //copying left part elements
    // int mainindex=s;
    // for(int i=0;i<len1;i++){
    //     first[i]=arr[mainindex++];
    // }

    // //copying right part elements
    // mainindex=mid+1;
    // for(int i=0;i<len2;i++){
    //     second[i]=arr[mainindex++];
    // }

    // //merging two arrays
    int temp[100];int k=0;
    int mid=s+(e-s)/2;
    int index1=s;
    int index2=mid+1;
    while(index1<=mid && index2<=e){
        if(arr[index1]<=arr[index2]){
            temp[k++]=arr[index1++];
        }
        else{
            temp[k++]=arr[index2++];

        }
    }
    
    while(index1<=mid){
        temp[k++]=arr[index1++];
    
    }
    
    while(index2<=e){
        temp[k++]=arr[index2++];
    
    }
        
    for(int i=s;i<=e;i++){
        arr[i]=temp[i-s];
    }
    
    
}

void merge_sort(int arr[],int s,int e){

    if(s>=e){
        return;
    }
    int mid=s+(e-s)/2;
    //left part
    merge_sort(arr,s,mid);
    //right part
    merge_sort(arr,mid+1,e);

    merge(arr,s,e);

}


int main(){
    int arr[5]={1,56,34,2,77};
    int n=5;
    merge_sort(arr,0,n-1);
    print_array(arr,5);

}