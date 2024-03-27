#include<iostream>
using namespace std;
int binary_search(int arr[],int s,int e,int n,int key){
    int mid=s+(e-s)/2;
    while(s<=e){
        if(arr[mid]==key){
            return mid;
        }

        else if(key>arr[mid]){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;

    }
    return -1;

}

int find_pivot(int arr[],int n){
    int s=0;int e=n-1;
    int mid=s+(e-s)/2;
    while(s<e){
        if(arr[mid]>=arr[0]){
            s=mid+1;
        }
        else{
            e=mid;
        }

        mid=s+(e-s)/2;

    }

    return e;

}


int main(){
    int arr[5]={12,15,1,2,4};int k=1;
    int p=find_pivot(arr,5);
    cout<<"Pivot index:"<<p<<endl;
    if(k>=arr[0]){
        //int start=0;int end=p;
        int i=binary_search(arr,0,p,5,k);
        cout<<"index:"<<i<<endl;
    }
    else{
        int i=binary_search(arr,p,4,5,k);
        cout<<"index:"<<i<<endl;       
    }

}


