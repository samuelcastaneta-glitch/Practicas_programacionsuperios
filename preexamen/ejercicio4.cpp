#include <bits/stdc++.h>
using namespace std;
//que el omnisalla nos proteja en el parcial
class VentaAccion{

private:
    float valorVenta;
    string empresa;
    float ganancia;

public:

    VentaAccion(float v, string e, float g){
        valorVenta = v;
        empresa = e;
        ganancia = g;
    }

    void mostrar(){
        cout<<"Venta: "<<valorVenta<<endl;
        cout<<"Empresa: "<<empresa<<endl;
        cout<<"Ganancia: "<<ganancia<<endl;
    }
};


class PagoPersonal{

private:
    float mensual;
    int meses;
    float total;
    string id;

public:

    PagoPersonal(float m, int me, float t, string i){
        mensual = m;
        meses = me;
        total = t;
        id = i;
    }

    void mostrar(){
        cout<<"ID: "<<id<<endl;
        cout<<"Pago mensual: "<<mensual<<endl;
        cout<<"Meses: "<<meses<<endl;
        cout<<"Total: "<<total<<endl;
    }
};


class GananciaCliente{

private:
    string id;
    float inversion;
    string empresa;

public:

    GananciaCliente(string i, float inv, string e){
        id = i;
        inversion = inv;
        empresa = e;
    }

    void mostrar(){
        cout<<"Cliente: "<<id<<endl;
        cout<<"Inversion: "<<inversion<<endl;
        cout<<"Empresa: "<<empresa<<endl;
    }
};

int main(){

    
    VentaAccion v1(350000,"Amazon",500000);
    VentaAccion v2(200000,"Ebay",150000);

    PagoPersonal p1(3000,3,9000,"1443");
    PagoPersonal p2(2700,5,13500,"8437");

    GananciaCliente g1("0085",5000,"Sony");
    GananciaCliente g2("0241",2500,"Amazon");

    int op;

    do{

        cout<<"\n1 Ventas";
        cout<<"\n2 Pagos";
        cout<<"\n3 Ganancias";
        cout<<"\n0 Salir\n";

        cin>>op;

        switch(op){

            case 1:
                v1.mostrar();
                v2.mostrar();
                break;

            case 2:
                p1.mostrar();
                p2.mostrar();
                break;

            case 3:
                g1.mostrar();
                g2.mostrar();
                break;
        }

    }while(op!=0);

}