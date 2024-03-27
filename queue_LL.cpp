#include<iostream>
using namespace std;
struct node{
    int data;
    struct node* next;

};

class deque{
    struct node* front;
    struct node* rear;
    public:
    deque(){
        front=NULL;
        rear=NULL;
    }
    void push(int d){

        struct node* newnode=new node;
        newnode->data=d;
        newnode->next=NULL;
        if(front==NULL){
            front=newnode;
            rear=newnode;
            front->next=front;
        }
        else{
            newnode->next=front;
            rear->next=newnode;
            rear=newnode;
        }
        cout<<"data added"<<endl;
        
    }

    void pop(){
        struct node* temp=new node;
        if(front==rear && front==NULL){
            cout<<"Queue is empty"<<endl;
        }
        if(front==rear && front!=NULL){
            cout<<"Popped:"<<rear->data<<endl;
            front=NULL;
            rear=NULL;
        }
        else{
            temp=front->next;
            int ans=front->data;
            front=temp;
            rear->next=temp;
            cout<<"Popped:"<<ans<<endl;

        }
    }

    void print(){
        struct node* temp=front;
        cout<<"Queue is:"<<endl;
        do{
            cout<<temp->data<<" ";
            temp=temp->next;


        }while(temp!=front);
        cout<<endl;

    }

    void qfront(){
        if(front==NULL){
            cout<<-1;

        }
        else{
            cout<<"Front:"<<front->data<<endl;
        }
    }
    void qrear(){
        if(rear==NULL){
            cout<<-1;

        }
        else{
            cout<<"Rear:"<<rear->data<<endl;
        }
    }
    

};

int main(){
    deque d;
    d.push(4);
    d.push(5);
    d.push(6);
    d.push(7);
    d.push(8);
    d.print();
    d.qfront();
    d.qrear();
    d.pop();
    d.pop();
    d.print();
    d.qfront();
    d.qrear();
    d.pop();
    d.pop();
    d.pop();
    d.pop();

    //d.print();
}