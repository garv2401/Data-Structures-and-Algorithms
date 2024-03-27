#include<iostream>
#include<vector>

using namespace std;

void print_vector(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    vector<vector<int>> arr={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int> v;
    int row=arr.size();
    int col=arr[0].size();
    int count=0;
    int total=row*col;
    //indexes
    int rowstart=0;
    int rowend=row-1;
    int colstart=0;
    int colend=col-1;
    
    while(count<total){
        for(int i=colstart;i<=colend && count<total;i++){
            v.push_back(arr[rowstart][i]);
            count++;
        }
        rowstart++;
        for(int i=rowstart;i<=rowend && count<total;i++){
            v.push_back(arr[i][colend]);
            count++;
        }
        colend--;
        for(int i=colend;i>=colstart && count<total;i--){
            v.push_back(arr[rowend][i]);
            count++;
        }
        rowend--;
        for(int i=rowend;i>=rowstart && count<total;i--){
            v.push_back(arr[i][colstart]);
            count++;
        }
        colstart++;


    }
    print_vector(v);
    

}