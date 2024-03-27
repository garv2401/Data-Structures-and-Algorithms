#include<iostream>
using namespace std;
void print_array(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void intersection(int arr1[],int arr2[],int n,int m){
    int i=0;int j=0;int arr[4];
    while(i<n && j<m){
        if(arr1[i]==arr2[j]){
            arr[i]=arr1[i];i++;j++;
        }
        else if(arr1[i]<arr2[j]){
            i++;
        }
        else{
            j++;
        }

    }
    //int l=sizeof(arr)/sizeof(int);
    cout<<"intersection:"<<endl;
    print_array(arr,4);

}

int main(){
    int arr1[6]={1,2,2,2,3,4};
    int arr2[4]={2,2,3,3};
    intersection(arr1,arr2,6,4);

}