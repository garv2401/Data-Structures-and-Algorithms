#include<iostream>
using namespace std;

class stack{
    public:
    int top;
    int size;
    int *arr;

   //constructor
    stack(int s){
        this->size=s;
        top=-1;
        arr=new int(s);
    }

    void push(int d){
        if(size-top > 1){
            top++;
            arr[top]=d;
        }
        else{
            cout<<"Stack overflow!";
        }

    }

    void pop(){
        if(top==-1){
            cout<<"Stack underflow!";
        }
        else{
            top--;
        }
    }

    int peek(){
        if(top==-1){
            cout<<"Stack underflow!";
        }
        else{
            return arr[top];
        }

    }
    
    bool isempty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }


};

int main(){
    stack s(5);
    s.push(12);
    s.push(13);
    s.push(14);
    s.push(15);
    if(s.isempty()){
        cout<<"Stack empty";
    }
    else{
        cout<<"Stack not empty";
    }
    int k=s.peek();
    cout<<endl<<"Top is:"<<k;
    s.push(16);
    k=s.peek();
    cout<<endl<<"Top is:"<<k;
    s.push(17);
    s.pop();
    s.pop();
    k=s.peek();
    cout<<endl<<"Top is:"<<k;

}