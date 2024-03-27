#include<iostream>
using namespace std;

void print_array(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}

int insertion_sort(int arr[],int n){
    //round 1 to n-1
    for(int i=0;i<n;i++){
        int temp=arr[i];
        int j=i-1;
        //comparison
        while(j>=0){
            if(arr[j]>temp){
                arr[j+1]=arr[j];
                j--;
            }
            else{
                break;
            }
        }
        arr[j+1]=temp;

    }
}


int main(){
    int arr[6]={67,2,13,88,3,45};
    insertion_sort(arr,6);
    print_array(arr,6);


}