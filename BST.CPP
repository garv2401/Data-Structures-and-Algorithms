#include<iostream>
#include<queue>
using namespace std;


class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int x){
        this->data=x;
        this->left=NULL;
        this->right=NULL;
    }
};


void insertion(Node* root,int val){
    Node* curr=root;
    Node* prev=NULL;
    Node* temp=new Node(val);

    if(root==NULL){
        root=temp;
    }

    while(curr!=NULL){
        prev=curr;
        if(val>curr->data){
            curr=curr->right;
        }
        if(val<curr->data){
            curr=curr->left;
        }
        else{
            break;
        }

    }

    if(prev!=NULL){
        if(prev->data>val){
            prev->left=temp;
        }
        else if(prev->data < val){
            prev->right=temp;
        }
    }

}

Node* findpred(Node* root){
    while(root->left==NULL){
        root=root->right;
    }
    if(root->left!=NULL){
        root=root->left;
        while(root->right!=NULL){
            root=root->right;
        }
    }

    return root;
}

Node* findsucc(Node* root){
    while(root->right==NULL){
        root=root->left;
    }

    if(root->right!=NULL){
        root=root->right;
        while(root->left!=NULL){
            root=root->left;
        }
    }

    return root;

}

Node* deletion(Node* root,int val){
    if(root==NULL){
        return NULL;
    }

    if(root->left==NULL && root->right==NULL){
        return NULL;
    }

    if(val>root->data){
        root->right=deletion(root->right,val);
    }

    else if(val<root->data){
        root->left=deletion(root->left,val);
    }

    else{
        Node* pred=findpred(root);
        root->data=pred->data;
        root->left=deletion(root->left,pred->data);//taking findpred
    }

    return root;
}


void levelorder(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* front=q.front();
        q.pop();
        if(front==NULL){
            cout<<"\n";
            if(!q.empty()){
                q.push(NULL);
            }
        }

        if(front!=NULL){
            cout<<front->data<<" ";
        }
        if(front->left){
            q.push(front->left);
        }

        if(front->right){
            q.push(front->right);
        }

    }
    
}

int main(){

    Node* root= NULL;

}