#include<iostream>
using namespace std;

class kqueue{
    public:
    int n;
    int k;
    int *arr;
    int *front;
    int *rear;
    int *next;
    int free;

    kqueue(int n,int k){
        this->n=n;
        this->k=k;
        arr=new int[n];
        front=new int[k];
        rear=new int[k];
        next=new int[n];

        for(int i=0;i<k;i++){
            front[i]=-1;
            rear[i]=-1;
        }

        for(int i=0;i<n;i++){
            next[i]=i+1;
        }
        next[n-1]=-1;
        free=0;
    }

    void enque(int d,int qn){
        if(free==-1){
            cout<<"No empty space left"<<endl;
        }

        int index=free;
        free=next[index];

        if(front[qn-1]==-1){
            front[qn-1]=index;
        }
        else{
            next[rear[qn-1]]=index;
        }
        next[index]=-1;
        rear[qn-1]=index;
        arr[index]=d;

    }

    int deque(int qn){
        if(front[qn-1]==-1){
            cout<<"Queue is empty"<<endl;
            return -1;
        }

        int index=front[qn-1];
        front[qn-1]=next[index];
        next[index]=free;
        free=index;

        return arr[index];

    }

    void print(){
        cout<<"Queue is:"<<endl;
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
    }



};


int main(){

    kqueue Q(10,3);
    Q.enque(12,1);
    Q.enque(13,2);
    Q.enque(14,2);
    Q.enque(15,1);
    //Q.print();
    cout<<Q.deque(1)<<endl;
    cout<<Q.deque(1)<<endl;
    cout<<Q.deque(2)<<endl;
    
}