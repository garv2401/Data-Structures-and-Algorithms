#include<iostream>
using namespace std;


//function overloading
class A{
    public:

    int data;
    void sayhello(){
        cout<<"Hello me"<<endl;
    }

    void sayhello(int n){
        cout<<"number:"<<n<<endl;
        

    }

    void sayhello(int n,int m){
        cout<<"m+n:"<<m+n<<endl;

    }

    void operator +(A& obj){
        int val1=obj.data;
        int val2=this->data;
        cout<<"WE are doin minus:"<<(val1-val2)<<endl;
    }

};

class human{
    public:
    int age;
    int height;

    void say1(){
        cout<<"HUman"<<endl;
    }

};

class animal{

    public:
    void bark(){
        cout<<"Barking"<<endl;

    }

};
//child class
class male: public human{
    public:
    void showhair(){
        cout<<"small hair"<<endl;
    }

};

class female:public human{
    public:
    void showhair(){
        cout<<"long hair"<<endl;
    }


};
//mutlilevel inheritance
class strmale:public male{
    public:
    void iam(){
        cout<<"strong male"<<endl; 
    }

};


//multiple inheritance 
class babymale:public human,public animal{
    public:
    void baby(){
        cout<<"I am baby"<<endl;
    }

};

int main(){
    // male ab;
    // ab.say();
    // ab.showhair();
    // female ab2;
    // ab.say();
    // ab2.showhair();


    //multilevel inheritance
    // strmale me;
    // me.say();
    // me.showhair();
    // me.iam();
    

    //multiple inheritance
    babymale b1;
    b1.baby();
    b1.say1();
    b1.bark();

    //function overloading
    // A obj;
    // obj.sayhello();
    // obj.sayhello(6);
    // obj.sayhello(5,6);
    
    A obj1,obj2;
    obj1.data=5;
    obj2.data=7;
    obj1 + obj2;
    


}