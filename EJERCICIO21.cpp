#include <iostream>
using namespace std;

class Robot{

public:

    string brazo;
    string cuerpo;
    string control;

    int costo;

    void calcular(){

        costo=0;

        if(brazo=="cierra") costo+=20;
        if(brazo=="fuego") costo+=40;
        if(brazo=="laser") costo+=100;

        if(cuerpo=="metal") costo+=30;
        if(cuerpo=="hierro") costo+=50;
        if(cuerpo=="blindado") costo+=200;

        if(control=="cable") costo+=10;
        if(control=="bluetooth") costo+=60;
        if(control=="radio") costo+=30;
    }

    void mostrar(){

        cout<<"Costo total: "<<costo<<" Bs"<<endl;
    }

};

int main(){

    Robot r;

    cout<<"Brazo: ";
    cin>>r.brazo;

    cout<<"Cuerpo: ";
    cin>>r.cuerpo;

    cout<<"Control: ";
    cin>>r.control;

    r.calcular();
    r.mostrar();

}