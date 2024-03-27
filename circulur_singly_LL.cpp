#include<iostream>
#include<map>

using namespace std;

class node{

    public:
    int data;
    node* next;


    //constructor
    node(int d){
        this->data=d;
        this->next=NULL;
        
    }

    //destructor
    ~node(){
        if(this->next!=NULL){
            delete next;
            next=NULL;
        }
    }

};

void print(node* &tail){
    node* temp=tail;
    do{
        cout<<tail->data<<" ";
        tail=tail->next;

    }while(tail!=temp);
}

bool is_circ(node* &tail){
    // if(tail==NULL){
    //     return false;
    // }
    // else{
    //     node* temp=tail->next;
    //     while(temp!=NULL && temp!=tail){
    //         temp=temp->next;
    //     }

    //     if(temp==NULL){
    //         return false;

    //     }
    //     if(temp==tail){
    //         return 1;
    //     }
    // }
    map<node*,bool> vis;
    node* temp=tail;

    while(temp!=NULL){
        if(vis[temp]==1){
            return 1;
        }
        else{
            vis[temp]=1;
            temp=temp->next;
        }
    }
    return 0;


}

void insert(node* &tail,int d,int ele){

    node* newnode=new node(d);
    //list is empty

    if(tail==NULL){
        tail=newnode;
        tail->next=tail;

    }

    else{
        node* temp=tail;
        while((temp->data)!=ele){
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
        
    }

}

void del(node * &tail,int d){
    if(tail==NULL){
        cout<<"List is empty"<<endl;
    }
    else{
        node* prev=tail;
        node* curr=prev->next;

        while(curr->data != d){
            prev=curr;
            curr=curr->next;
        }

        prev->next=curr->next;

        //one node present
        if(prev==curr){
            tail=NULL;
        }

        else if(tail==curr){
            tail=prev;
        }

        curr->next=NULL;
        delete curr;
    }

}


int main(){
    node* tail=NULL;
    insert(tail,3,3);
    insert(tail,4,3);
    insert(tail,5,4);
    insert(tail,6,5);
    insert(tail,7,6);
    insert(tail,8,7);

    cout<<endl<<"Linked list:"<<endl;
    print(tail);

    if(is_circ(tail)){
        cout<<endl<<"List is circular"<<endl;
    }
    else{
        cout<<endl<<"List is not circular"<<endl;

    }


    // cout<<endl<<"Linked list after deletion 3:"<<endl;
    // del(tail,3);
    // print(tail);


    // cout<<endl<<"Linked list after deletion 7:"<<endl;
    // del(tail,7);
    // print(tail);
    
}