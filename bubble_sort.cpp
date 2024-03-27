#include<iostream>
using namespace std;

void print_array(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void bubble_sort(int arr[],int n){
    //no. of rounds(1 to n-1)
    for(int i=1;i<n;i++){
        //comparing elements
        for(int j=0;j<n-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                
            }
        }
        
    }
}

int main(){
    int arr[5]={45,67,2,34,55};
    bubble_sort(arr,5);
    print_array(arr,5);
}