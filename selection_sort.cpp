#include<iostream>
using namespace std;

void print_array(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}


void selection_sort(int arr[],int n){
    
    for(int i=0;i<n-1;i++){
        int ans=i;
        
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[ans]){  
                ans=j;
            }
        }
        swap(arr[ans],arr[i]);

    }
}


int main(){
    int arr[5]={67,23,45,2,33};
    selection_sort(arr,5);
    print_array(arr,5);
}