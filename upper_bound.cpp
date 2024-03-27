#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
using namespace std;


int main(){
    vector<int> v={1,2,3,4,5};
    vector<int>::iterator upper,lower;

    upper=upper_bound(v.begin(),v.end(),4);
    cout<<"Upper bound:"<<(upper-v.begin())<<endl;

    lower=lower_bound(v.begin(),v.end(),3);
    cout<<"Lower bound:"<<(lower-v.begin())<<endl;


}