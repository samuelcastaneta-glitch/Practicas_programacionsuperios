#include <iostream>
using namespace std;

class Conversor{

public:
    virtual void convertir(string valor)=0;

};

class Romano: public Conversor{

public:

    void convertir(string valor){

        cout<<"Convirtiendo romano "<<valor<<endl;
    }

};

int main(){

    Conversor *c;

    Romano r;

    c=&r;

    c->convertir("X");

}