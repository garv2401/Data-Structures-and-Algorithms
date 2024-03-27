#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int bsearch(int arr[],int s,int e,int k){
    int mid=s+(e-s)/2;
    while(s<=e){
        if(arr[mid]==k){
            return mid;
        }
        else if(arr[mid]>k){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return -1;

}

int fpo(int arr[],int s,int e,int k){
    
    if(e>=s){
        int mid=s+(e-s)/2;
        if((mid==0 || k>arr[mid-1]) && arr[mid]==k){
            return mid;
        }
        else if(k>arr[mid]){
            return fpo(arr,mid+1,e,k);
        }
        else{
            return fpo(arr,s,mid-1,k);

        }
    }
    return -1;


    /*
    while(s<=e){
        if(arr[mid]==k){
            ans=mid;
            e=mid-1;
        }
        else if(arr[mid]>k){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
    */

}

int lpos(int arr[],int s,int e,int k,int n){
    if(s>e){
        return -1;
    }
    if(e>=s){
        int mid=s+(e-s)/2;
        if((mid==n-1 || k<arr[mid+1]) && arr[mid]==k){
            return mid;
        }
        else if(arr[mid]>k){
            return lpos(arr,s,mid-1,k,n);
        }
        else{
            return lpos(arr,mid+1,e,k,n);
        }
    }

}

void sayword(int n, string arr[]){
    //base case
    if(n==0){
        return;
    }
    int digit=n%10;
    n=n/10;
    sayword(n,arr);
    cout<<arr[digit]<<" ";
    
}

int main(){
    /*
    int n;
    cin>>n;
    string arr[10]={"zero","one","two","three","four",
                    "five","six","seven","eight","nine"};
    sayword(n,arr);
    */
    int arr[6]={1,2,2,2,2,5};
    int f=fpo(arr,0,5,2);
    int l=lpos(arr,0,5,2,6);
    cout<<f<<" "<<l<<endl;

}