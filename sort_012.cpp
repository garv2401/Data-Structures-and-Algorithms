#include<iostream>
using namespace std;

int print_array(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void sort(int arr[],int n){
    int i=0;
    int j=n-1;
    while(i<=j){
        while(arr[i]==0){
            i++;
        }
        while(arr[j]==2){
            j--;
        }
        while(i<j){
            if(arr[j]==0 && arr[i]==2){
                swap(arr[i],arr[j]);i++;j--;
            }
            else if(arr[j]==0 && arr[i]==1){
                swap(arr[i],arr[j]);i++;
            }
            else if(arr[j]==1 && arr[i]==2){
                swap(arr[i],arr[j]);j--;
            }
            else{
                swap(arr[i],arr[j]);i++;j--;
            }

        }
    }
    print_array(arr,7);
}
int main(){
    int arr[7]={0,1,2,1,1,0,2};
    sort(arr,7);

}
