#include<iostream>
using namespace std;

class hero{
    int health;
    char level;
    char name[50];

    public:

    //parameterised constructor
    hero(int health,char level){
        (*this).health=health; //this stores address of the current obj
        this->level=level;
    };

    //copy constructor(creates shalllow copy)
    // hero(hero& temp){
    //     this->health=temp.health;
    //     this->level=temp.level;
    // };

    //copy constructor(deep copy)
    hero(hero& temp){
        int *h=new int;
        (*h)=(temp.health);
        this->health=(*h);
        this->level=temp.level;
        delete h;
        
    };

    void sethealth(int h){
        health=h;

    }

    int gethealth(){
        return health;

    }

    char getlevel(){
        return level;
    }


};

int main(){
    hero adam(60,'D');
    
    //hero ogre(67,'A');
    //adam.sethealth(89);

    cout<<"Health adam:"<<adam.gethealth()<<endl;
    cout<<"Level adam:"<<adam.getlevel()<<endl<<endl;
    

    //cout<<"Health:"<<ogre.gethealth()<<endl;
    //cout<<"Level:"<<ogre.getlevel()<<endl;

    hero kaz(adam);//hero kaz=adam;
    cout<<"Health kaz:"<<kaz.gethealth()<<endl;
    cout<<"Level kaz:"<<kaz.getlevel()<<endl;

    cout<<endl<<endl<<"AFTER:"<<endl<<endl;
    adam.sethealth(90);
    cout<<"Health adam:"<<adam.gethealth()<<endl; 
    cout<<"Level adam:"<<adam.getlevel()<<endl<<endl;
    cout<<"Health kaz:"<<kaz.gethealth()<<endl;
    cout<<"Level kaz:"<<kaz.getlevel()<<endl;
    


    
}