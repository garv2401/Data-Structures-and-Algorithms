#include<iostream>
using namespace std;

//creation of class
class hero{
    private:
    int health;
    char level;

    
    

    public:

    //static keyword
    static int timetocompl;
    //static function

    static int fun(){
        return timetocompl;
    }




    //constructor
    hero(){
        cout<<"Constructor called"<<endl;
    };

    int gethealth(){
        return health;

    }

    char getlevel(){
        return level;
    }

    void sethealth(int h){
        health=h;

    }

    void setlevel(char c){
        level=c;
    }

    int doublehealth();

    //destructor
    ~hero(){
        cout<<"Destructor called"<<endl;

    };


};

//scope resolution

int hero::doublehealth(){
    return health*2;
}

//static keyword initialisation

int hero::timetocompl=5;


int main(){
    //static
    hero paul;
    //dynamic
    hero *jin=new hero;

    //static allocation
    paul.sethealth(80);
    paul.setlevel('A');

    //dynamic allocation
    jin->sethealth(90); //or (*jin).sethealth(90)
    jin->setlevel('B'); //or (*jin).setlevel('B')


    cout<<"Health:"<<paul.gethealth()<<endl;
    cout<<"Level:"<<paul.getlevel()<<endl;
    cout<<"Time to complete:"<<hero::timetocompl<<endl;
    cout<<"Double health:"<<paul.doublehealth()<<endl<<endl;
    

    cout<<"Health:"<<jin->gethealth()<<endl; 
    cout<<"Level:"<<jin->getlevel()<<endl;
    cout<<"Time to complete:"<<hero::timetocompl<<endl;
    cout<<"Double health:"<<jin->doublehealth()<<endl;

    cout<<"Static function call:"<<hero::fun()<<endl;

    delete jin;//destructor call for dynamic allocation
}