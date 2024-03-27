#include<iostream>
using namespace std;
int binarysearch(int arr[],int n,int key){
    int i=0;
    int j=n-1;
    int mid=(i+j)/2;
    while(i<=j){
        if(arr[mid]==key){
            int h=mid;
        }
        else if(arr[mid]>key){
            j=mid-1;
        }else{
            i=mid+1;

        }
        mid=(i+j)/2;
    }
    return -1;
}
int main(){
    int arr[6]={0,1,2,2,5,6};
    int k=binarysearch(arr,6,2);
    cout<<"index of 2:"<<k;

}