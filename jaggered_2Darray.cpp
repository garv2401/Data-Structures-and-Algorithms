#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter no. of rows:";
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cout<<"Enter no. of cols:";
        cin>>arr[i];
    }
    //creation 
    int **arr1=new int*[n];

    for(int i=0;i<n;i++){
        arr1[i]=new int[arr[i]];
    }

    //taking input
    for(int i=0;i<n;i++){
        for(int j=0;j<arr[i];j++){
            cout<<"Enter element:";
            cin>>arr1[i][j];
        }
    }

    //displaying
    for(int i=0;i<n;i++){
        for(int j=0;j<arr[i];j++){
            cout<<arr1[i][j]<<" ";
        }
        cout<<endl;
    }

    //deleting
    for(int i=0;i<n;i++){
        delete [] arr1[i];
    }

    delete []arr1;
    cout<<"array deleted"<<endl;

}

