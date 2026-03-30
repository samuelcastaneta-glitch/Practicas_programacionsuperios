#include <iostream>
using namespace std;

class Vehiculo{

public:

    string tipo;
    string color;

    void mostrar(){
        cout<<"Vehiculo: "<<tipo<<endl;
        cout<<"Color: "<<color<<endl;
    }
};

int main(){

    Vehiculo v;

    cout<<"Seleccione vehiculo"<<endl;
    cout<<"1 Mini"<<endl;
    cout<<"2 Camioneta"<<endl;
    cout<<"3 Vagoneta"<<endl;
    cout<<"4 Peta"<<endl;

    int op;
    cin>>op;

    switch(op){
        case 1: v.tipo="Mini"; break;
        case 2: v.tipo="Camioneta"; break;
        case 3: v.tipo="Vagoneta"; break;
        case 4: v.tipo="Peta"; break;
    }

    cout<<"Color: ";
    cin>>v.color;

    v.mostrar();

}