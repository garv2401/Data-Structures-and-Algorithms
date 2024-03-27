#include<iostream>
using namespace std;

struct lnode{
    int data;
    struct lnode* next;
};

class stack{
    public:
    struct lnode* top=NULL;

    void push(int d){
        struct lnode* newnode=new struct lnode;
        if(top==NULL){
            top=newnode;
            top->next=NULL;
            top->data=d;
        }
        else{
            newnode->next=top;
            newnode->data=d;
            top=newnode;
        }
    }

    void pop(){
        if(top==NULL){
            cout<<"Stack is empty!"<<endl;;
        }
        else{
            cout<<"Popped data:"<<top->data<<endl;
            top=top->next;
        }
    }

    void peek(){
        if(top==NULL){
             cout<<"Stack is empty!"<<endl;

        }
        else{
            cout<<"Top:"<<top->data<<endl;
        }
  
    }

    void isempty(){
        if(top==NULL){
            cout<<"Stack is empty!"<<endl;

        }
        else{
            cout<<"Stack is not empty!"<<endl;
            
        }
        
    }

};

int main(){
    stack s;
    s.push(11);
    s.push(12);
    s.push(13);
    s.peek();
    s.pop();
    s.peek();
    s.isempty();
    s.pop();
    s.peek();
    s.pop();
    s.isempty();
    s.pop();
}