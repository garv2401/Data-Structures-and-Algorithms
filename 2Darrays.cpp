#include<iostream>
#include<limits>
using namespace std;

void row_wise_sum(int arr[][4],int row,int col){
    int max=0;
    for(int i=0;i<row;i++){
        int sum=0;
        for(int j=0;j<col;j++){
            sum+=arr[i][j];

        }
        cout<<"Row "<<i+1<<" sum: "<<sum<<endl;
    }
    
}

int row_max(int arr[][4],int row,int col){
    int max=0;int ans;
    for(int i=0;i<row;i++){
        int sum=0;
        for(int j=0;j<col;j++){
            sum+=arr[i][j];

        }
        if(sum>max){
            max=sum;ans=i+1;
        }
        
    }
    return ans;
    
}


int col_max(int arr[][4],int row,int col){
    int max=0;int ans;
    for(int i=0;i<col;i++){
        int sum=0;
        for(int j=0;j<row;j++){
            sum+=arr[j][i];

        }
        if(sum>max){
            max=sum;ans=i+1;
        }
        
    }
    return ans;
}



void col_wise_sum(int arr[][4],int row,int col){
    for(int i=0;i<col;i++){
        int sum=0;
        for(int j=0;j<row;j++){
            sum+=arr[j][i];

        }
        cout<<"col "<<i+1<<" sum: "<<sum<<endl;
    }
}

bool ispresent(int arr[][4],int row,int col,int key){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j]==key){
                return true;
            }
        }
    }
    return false;

}

int main(){
    int arr[3][4]={{1,2,3,4},{2,3445,4,5},{10,12,133,12}};

    //row wise input
    /*
    for(int row=0;row<3;row++){
        for(int col=0;col<4;col++){
            cin>>arr[row][col];
        }
    }
    */
    

    //col wise input
    /*
    for(int col=0;col<4;col++){
        for(int row=0;row<3;row++){
            cin>>arr[row][col];
        }
    }
    */


    //printing 2D array
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    row_wise_sum(arr,3,4);
    int i=row_max(arr,3,4);
    int j=col_max(arr,3,4);
    cout<<"Max row:"<<i<<endl;
    col_wise_sum(arr,3,4);
    cout<<"Max col:"<<j<<endl;

}