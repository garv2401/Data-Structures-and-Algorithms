#include<iostream>
using namespace std;

void print_array(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}

int partition(int arr[],int s,int e){
    int pivot=arr[s];
    int cnt=0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<=pivot){
            cnt++;
        }
    }
    int pindex=s+cnt;
    swap(arr[pindex],arr[s]);
    int i=s;
    int j=e;
    while((i<pindex && j>pindex) && i<j){
        while(arr[i]<=pivot && i<pindex){
            i++;
        }
        while(arr[j]>pivot && j>pindex){
            j--;
        }
        if(i<pindex && j>pindex){
            swap(arr[i++],arr[j--]);
        }
    }
    return pindex;


}

void quick_sort(int arr[],int s,int e){
    if(s>=e){
        return;
    }
    int p=partition(arr,s,e);
    quick_sort(arr,s,p-1);
    quick_sort(arr,p+1,e);
}

int main(){
    int arr[6]={4,10,1,7,6,2};
    int n=6;
    quick_sort(arr,0,n-1);
    print_array(arr,n);
}
