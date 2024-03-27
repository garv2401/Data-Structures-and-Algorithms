#include<iostream>
using namespace std;


class heap{
    private:
    int arr[100];
    int size;
    public:

    heap(){
        size=0;
        arr[1]=-1;

    }

    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
    }
    
    void insertion(int val){
        size++;
        int index=size;
        arr[index]=val;
        while(index>1){
            int parent=index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else{
                return;
            }
        }

    }

    void deletion(){
        arr[1]=arr[size];
        size--;
        int i=1;
        while(i<size){
            int left_i=2*i;
            int right_i=2*i+1;

            if(arr[left_i]>arr[i] && left_i<size){
                swap(arr[left_i],arr[i]);
                i=left_i;
            }

            else if(arr[right_i]>arr[i] && right_i<size){
                swap(arr[right_i],arr[i]);
                i=right_i;
            }

            else{
                return;
            }

        }

    }

};

void heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i;
    int right=2*i+1;
    if(left<n && arr[left]>arr[largest]){
        largest=left;
    }

    if(right<n && arr[right]>arr[largest]){
        largest=right;
    }

    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);

    }
}

void build_heap(int arr[],int n){
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
}

void heap_sort(int arr[],int n){
    build_heap(arr,n);
    int i=n-1;
    while(i>1){
        swap(arr[i],arr[1]);
        i--;
        heapify(arr,i,1);

    }
}



int main(){
    heap h;
    // h.insertion(3);
    // h.insertion(83);
    // h.insertion(56);
    // h.insertion(99);
    // h.insertion(97);
    // h.insertion(43);

    // h.print();
    // cout<<endl;
    // h.deletion();
    // h.print();
    // cout<<endl;
    // h.deletion();
    // h.print();
    // cout<<endl;
    // h.deletion();
    // h.print();
    int arr[7]={-1,23,11,45,1,2,77};
    int n=7;
    build_heap(arr,n);
    cout<<"Initial arrray:"<<endl;
    for(int i=1;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    heap_sort(arr,n);
    cout<<"Sorted arrray:"<<endl;
    for(int i=1;i<n;i++){
        cout<<arr[i]<<" ";
    }



}