#include<iostream>
using namespace std;

int main(){
    /*
    int arr[5]={1,2,3,4,5};

    //both output same
    cout<<"address of 1st loaction:"<<arr<<endl;
    cout<<"address of 1st loaction:"<<&arr[0]<<endl;

    cout<<*arr<<endl;   //output=1
    cout<<arr[0]<<endl; //output=1

    cout<<*(arr+1)<<endl; //output=2
    cout<<arr[1]<<endl;   //output=2
    cout<<(*arr)+1<<endl; //output=1+1=2

    //traversing array
    cout<<"given array:";
    for(int i=0;i<5;i++){
        cout<<*(arr+i)<<" ";
    }
    cout<<endl;
    //another way
    cout<<"given array:";
    for(int i=0;i<5;i++){
        cout<<i[arr]<<" ";
    }
    cout<<endl;
    //size using arr
    cout<<sizeof(arr)<<endl;
    //size using pointer
    int *p=&arr[0];
    cout<<sizeof(p)<<endl;
    */

    /*
    int arr[5]={1,2,3,4,5};
    //error
    //arr=arr+1; (cannot be changed)

    int *p=&arr[0];
    p=p+1;  //no error
    cout<<*p<<endl; //output=2
    */
    
    int arr[4]={1,2,3,4};
    char ch[8]="abcdefg";
    cout<<arr<<endl;
    cout<<ch<<endl;

    char *c=&ch[1];
    cout<<c<<endl; //op=bcde

    char temp=' ';
    char *p=&temp;
    cout<<p<<endl;


   


}