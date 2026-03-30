#include <iostream>
using namespace std;

class VentaAccion{

private:

    float valorVenta;
    string empresa;
    float ganancia;

public:

    void setDatos(float v,string e,float g){

        valorVenta=v;
        empresa=e;
        ganancia=g;
    }

    void mostrar(){

        cout<<"Venta: "<<valorVenta<<endl;
        cout<<"Empresa: "<<empresa<<endl;
        cout<<"Ganancia: "<<ganancia<<endl;
    }
};

int main(){

    VentaAccion v1;

    v1.setDatos(350000,"Amazon",500000);

    v1.mostrar();

}