#include<iostream>
#include<map>
using namespace std;

class node{

    public:
    int data;
    node* next ;

    //constructor
    node(int n){
        this->data=n;
        this->next=NULL;
    }
    
    //destructor                                                       d
    ~node(){
        if(this->next != NULL){
            delete next;
            this->next=NULL;
        }
    }

};

void print(node * &head){
    node * temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

void insert_head(node * &head,int d){
    node* n1=new node(d);
    if(head==NULL){
        head=n1;
    }
    else{
        n1->next=head;
        head=n1;

    }
}

void insert_end(node * &head,int d){
    node * n1=new node(d);
    node * temp=head;
    while(temp->next !=NULL){
        temp=temp->next;
    }
    temp->next=n1;
}

void insert(node * &head,int d,int pos){
    node * n1=new node(d);
    int i=1;
    node * temp=head;
    while(i<(pos-1)){
        temp=temp->next;
        i++;
    }
    n1->next=temp->next;
    temp->next=n1;
    
}

void del(node * &head,int pos){
    node * temp=head;
    if(pos==1){
        
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        node * prev;
        int i=1;
        while(i<pos){
            prev=temp;
            temp=temp->next;
            i++;
        }
        prev->next=temp->next;
        temp->next=NULL;
        delete temp;

    }

}

node* is_circ(node* &head){
    node* slow=head;
    node* fast=head;

    while(fast!=NULL){
        slow=slow->next;
        if(fast->next!=NULL){
            fast=fast->next->next;
        }

        if(fast==slow){
            return slow;
        }
    }

    if(fast==NULL){
        return head;
    }

}

node* find_beg(node* &head){
    node* temp1=is_circ(head);
    node* temp2=head;

    while(temp1!=temp2){
        temp1=temp1->next;
        temp2=temp2->next;
    }

    return temp1;
}
void remove_loop(node* &head){

    node* beg=find_beg(head);
    node* temp=beg;
    while(temp->next!=beg){
        temp=temp->next;
    }

    temp->next=NULL;
}

void reverse(node* & head){
    node* curr=head;
    node* prev=NULL;
    node* forward;
    while(curr->next!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }

    if(curr->next==NULL){
        curr->next=prev;
        head=curr;
    }
}



node* reverse_k(node* &head,int k){
    node* prev=NULL;
    node* curr=head;
    node* forward;

    if(curr==NULL){
        return NULL;
    }

    int i=0;
    while(i<k && curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
        i++;
    }

    head->next=reverse_k(forward,k);
    return prev;


}

void remove_dup(node* &head){
    node* curr=head;

    while(curr->next!=NULL){
        if(curr->data!=curr->next->data){
            curr=curr->next;
        }

        else if(curr->data==curr->next->data){
            node* n=curr->next->next;
            // node* del=curr->next;
            // delete del;
            curr->next=n;

        }
    }
    
}

void remove_duplicates(node* &head){
    map<int,bool> vis;
    node* temp=head;
    node* prev=NULL;

    while(temp!=NULL){
        if(vis[temp->data]==1){
            node* n=temp->next;
            prev->next=n;
            temp=prev->next;
        }
        else{
            vis[temp->data]=1;
            prev=temp;
            temp=temp->next;
        }
    }

}


int main(){

    node * head =NULL;
    insert_head(head,30);
    insert_head(head,37);
    insert_head(head,67);
    insert_head(head,37);
    
    insert_end(head,45);
    insert_end(head,30);
    insert_end(head,67);

    insert(head,45,5);

    

    // cout<<endl<<"Reversed:"<<endl;
    // reverse(head);
    // print(head);
    
    // cout<<endl<<"Reversed k:"<<endl;
    // node* temp=reverse_k(head,3);
    // print(temp);

    // cout<<endl<<"Deletion of 4th value:"<<endl;
    // del(head,4);
    // print(head);

    // cout<<endl<<"Deletion of 1th value:"<<endl;
    // del(head,1);
    // print(head);

    // cout<<endl<<"Deletion of last value:"<<endl;
    // del(head,6);
    // print(head);

    // if(is_circ(head)){
    //     cout<<endl<<"List is circular"<<endl;
    // }
    // else{
    //     cout<<endl<<"List is not circular"<<endl;

    // }
    cout<<endl<<"original:"<<endl;
    print(head);
    cout<<endl<<"removed duplicates:"<<endl;
    remove_duplicates(head);
    print(head);

    // node* temp=head;
    // while(temp->next!=NULL){
    //     temp=temp->next;

    // }
    // // 
    // temp->next=head->next->next->next;

    
    // //print(head);

    // node* temp2=find_beg(head);
    // cout<<endl<<"beginnig of loop:"<<temp2->data<<endl;
    

    // cout<<endl<<"after removing loop:"<<endl;
    // remove_loop(head);
    // //cout<<endl<<"head:"<<head->data<<endl;
    
    // print(head);


}
