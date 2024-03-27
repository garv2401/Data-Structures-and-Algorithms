#include<iostream>
using namespace std;

int main(){
    //nxn array
    /*
    int n;
    cout<<"Enter size:";
    cin>>n;
    int **arr=new int*[n]; //array of pointers created
    //2D nxn matrix
    for(int i=0;i<n;i++){
        arr[i]=new int[n];
    }
    cout<<endl;

    //taking input
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"Enter element:";
            cin>>arr[i][j];
        }
    }


    //displaying array
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    //deleting the heap space

    for(int i=0;i<n;i++){
        delete [] arr[i]; //n arrays deleted
    }

    delete []arr; //array of pointers deleted
    cout<<"Array deleted"<<endl;
    */

    //nxm array
    int n,m;
    cout<<"Enter rows:";
    cin>>n;
    cout<<"Enter cols:";
    cin>>m;

    int **arr=new int*[n]; //array of pointers created
    for(int i=0;i<n;i++){
        arr[i]=new int[m];
    }
    cout<<endl;

    //taking input
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<"Enter element:";
            cin>>arr[i][j];
        }
    }

    //displaying array
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    //deleting the heap space

    for(int i=0;i<n;i++){
        delete [] arr[i]; //n arrays deleted
    }

    delete []arr; //array of pointers deleted
    cout<<"Array deleted"<<endl;

}
