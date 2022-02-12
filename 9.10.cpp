#include <iostream>
using namespace std;
class base{

public:
virtual int fun(){
cout<<"base: :fun"<<endl;
return 10;
}
};
class divide:public base{
public:
int fun(){
cout<<"divide::fun"<<endl;
return 20;
}
};

int main(){
    divide d;
    base * b1=&d;
    base & b2=d;
b1->fun( );
b2.fun();
return 0;
}