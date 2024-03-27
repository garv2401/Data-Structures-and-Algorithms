#include<iostream>

using namespace std;

class node{

    public:
    int data;
    node* prev;
    node* next;


    //constructor
    node(int d){
        this->data=d;
        this->next=NULL;
        this->prev=NULL;
        
    }

    //destructor
    ~node(){
        if(this->next!=NULL){
            delete next;
            next=NULL;
        }
    }

};

void print(node * &head){
    node * temp=head;
    cout<<"Linked list is:";
    node * temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}


void insert_start(node* &head,node* &tail){
    int choice;
    while(choice){
        int d;
        cout << "Enter data to be added:";
        cin >> d;
        node *newnode = new node(d);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            head->prev = newnode;
            newnode->next = head;
            head = newnode;
        }
        cout << "After Insert at head," << endl;
        print(head);
        cout << "to insert more enter 1 else enter 0:";
        cin >> choice;
    }
    
}

void insert_end(node* &head,node* &tail,int d){
    node* newnode=new node(d);
    if(tail==NULL){
        tail=newnode;
        head=newnode;
    }
    else{
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }

}

void insert(node* &head,int d,int pos){

    node* newnode=new node(d);
    node* temp=head;
    int i=1;
    while(i<pos-1){
        temp=temp->next;
        i++;
    }
    newnode->next=temp->next;
    temp->next->prev=newnode;
    temp->next=newnode;
    newnode->prev=temp;

}

void del(node* &head,int pos){

    if(pos==1){
        node* temp=head;
        head=temp->next;
        head->prev=NULL;
        temp->next=NULL;
        
        delete temp;

    }

    else{
        int i=1;
        node* curr=head;
        node* pre;
        while(i<pos){
            pre=curr;
            curr=curr->next;
            i++;
        }
        if(curr->next==NULL){
            pre->next=NULL;
            curr->prev=NULL;
            delete curr;
        }
        else{
            curr->prev=NULL;
            pre->next=curr->next;
            pre->next->prev=pre;
            curr->next=NULL;

            delete curr;

        }
    }

}

void reverse(node* &head,node* &tail){

    node* temp=head;node* tem;tail=head;
    

    while(temp->next != NULL){
        tem=temp->next;
        temp->next=temp->prev;
        temp->prev=tem;

        temp=temp->prev;
    }

    if(temp->next == NULL){
        tem=temp->next;
        temp->next=temp->prev;
        temp->prev=tem;
        head=temp;
    }
    
}

node* detect_loop(node* &head){

    if(head==NULL){
        return NULL;
    }
    node* s=head;
    node* f=head;
    while(f!=NULL && s!=NULL){
        s=s->next;
        f=f->next;
        if(f!=NULL){
            f=f->next;
        }

        if(f==s){
            return f;
        }
    }
    return NULL;

}

node* beg_loop(node* &head){
    if(head==NULL){
        return NULL;
    }
    node* p1=detect_loop(head);

    if(p1==NULL){
        return NULL;
    }
    node* p2=head;

    while(p1 != p2){
        p1=p1->next;
        p2=p2->next;

    }

    return p1;

}

node* delete_loop(node* &head){

    if(head==NULL){
        return NULL;
    }

    node* t1=beg_loop(head);
    if(t1==NULL){
        return NULL;
    }
    node* t2=t1;

    while(t2->next != t1){
        t2=t2->next;
    }

    
    t2->next=NULL;
    return head;
    
}



int main(){

    node* head=NULL;
    node* tail=NULL;

    // insert_start(head,tail,10);
    // insert_start(head,tail,20);
    // insert_start(head,tail,30);
    // cout<<endl;
    // print(head);
    // cout<<endl;

    //print(head);

    insert_end(head,tail,40);
    insert_end(head,tail,50);

    // cout<<endl;
    // print(head);
    // cout<<endl;

    insert(head,45,4);

    // cout<<endl;
    // print(head);
    // cout<<endl;

    insert(head,56,5);

    // cout<<endl;
    // print(head);
    // cout<<endl;

    cout<<"Original list:"<<endl;
    print(head);
    cout<<endl;

    // cout<<"after deletion:"<<endl;
    // del(head,7);
    // print(head);
    // cout<<endl;

    cout<<endl<<"Head:"<<head->data<<endl;
    cout<<"Tail:"<<tail->data<<endl;

    reverse(head,tail);
    cout<<endl<<"reversed list:"<<endl;
    print(head);
    cout<<endl;
    cout<<endl<<"Head:"<<head->data<<endl;
    cout<<"Tail:"<<tail->data<<endl;
    tail->next=head->next->next->next;

    //cout<<"Loop begining:"<<beg_loop(head)<<endl;
    //loop deleted
    delete_loop(head);
    cout<<endl<<"Loop removed:"<<endl;

    print(head);

    node* temp=beg_loop(head);
    if(temp==NULL){
        cout<<endl<<"No loop"<<endl;
    }
    

      
    

}
