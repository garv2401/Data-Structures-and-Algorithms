#include<iostream>
using namespace std;

float binary_search(int arr[],int s,int e,int key){
    int mid=s+(e-s)/2;float ans=0;
    while(s<=e){
        if((arr[mid] * arr[mid])==key){
            ans=arr[mid];
            return ans;

        }

        else if((arr[mid] * arr[mid])<key){
            ans=arr[mid];
            s=mid+1;

        }
        else if((arr[mid] * arr[mid])>key){
            e=mid-1;
        }

        mid=s+(e-s)/2;
    }
    return ans;
}

float precision(int arr[],int s,int e,float ans,int key,float c){
    int mid=s+(e-s)/2;float ans1=0;
    int k=(ans+c*arr[mid]) * (ans+c*arr[mid]);
    while(s<=e){
        if((ans+c*arr[mid]) * (ans+c*arr[mid]) == key){
            ans1=ans+c*arr[mid];
            return ans;

        }

        else if((ans+c*arr[mid]) * (ans+c*arr[mid]) < key){
            ans1=ans+c*arr[mid];
            s=mid+1;

        }
        else if((ans+c*arr[mid]) * (ans+c*arr[mid]) > key){
            e=mid-1;
        }

        mid=s+(e-s)/2;
    }
    return ans1;
}

int main(){
    int k=80;float c=0.1;
    int arr2[9]={1,2,3,4,5,6,7,8,9};
    int arr1[k]={0};
    for(int i=1;i<k;i++){
        arr1[i]=i;
    }

    float i=binary_search(arr1,0,k-1,k);
    cout<<"Floor value:"<<i<<endl;

    float j=precision(arr2,0,8,i,k,c);
    cout<<"precise value:"<<j<<endl;

    c=c/10;
    float m=precision(arr2,0,8,j,k,c);
    cout<<"more precise value:"<<m<<endl;


}
