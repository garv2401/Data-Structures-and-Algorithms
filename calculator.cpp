#include<iostream>
using namespace std;
int main(){
    int a,b;
    cout<<"enter value of a:";
    cin>>a;
    cout<<"enter value of b:";
    cin>>b;
    char X;
    cout<<"enter operator:";
    cin>>X;
    switch(X){
        case '*':
        cout<<a<<X<<b<<"="<<a*b<<"\n";
        break;
        case '/':
        cout<<a<<X<<b<<"="<<a/b<<"\n";
        break;
        case '%':
        cout<<a<<X<<b<<"="<<a%b<<"\n";
        break;
        case '+':
        cout<<a<<X<<b<<"="<<a+b<<"\n";
        break;
        case '-':
        cout<<a<<X<<b<<"="<<a-b<<"\n";
        break;
        default:
        cout<<"Enter valid operator ";
        break;



    }

}
