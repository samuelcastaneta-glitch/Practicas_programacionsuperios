#include <iostream>
using namespace std;

class equipos{

protected:

    string marca;
    string color;
    float precio;

public:

    void mostrar(){
        cout<<"Marca: "<<marca<<endl;
        cout<<"Color: "<<color<<endl;
        cout<<"Precio: "<<precio<<endl;
    }
};

class parlante: public equipos{

public:

    parlante(){
        marca="Amazon";
        color="Azul";
        precio=100;
    }
};

class audifono: public equipos{

public:

    audifono(){
        marca="Sony";
        color="Negro";
        precio=50;
    }
};

int main(){

    parlante p;
    audifono a;

    p.mostrar();
    a.mostrar();

}