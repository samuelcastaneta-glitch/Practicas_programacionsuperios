#include <bits/stdc++.h>
using namespace std;

float suma(float a,float b){ return a+b; }
float resta(float a,float b){ return a-b; }
float multiplicacion(float a,float b){ return a*b; }
float division(float a,float b){ return a/b; }
float potencia(float a,float b){ return pow(a,b); }
float raiz(float a){ return sqrt(a); }

int main(){

    float x,y;
    int op;

    cout<<"Ingrese dos numeros: ";
    cin>>x>>y;

    cout<<"1 Suma"<<endl;
    cout<<"2 Resta"<<endl;
    cout<<"3 Multiplicacion"<<endl;
    cout<<"4 Division"<<endl;
    cout<<"5 Potencia"<<endl;
    cout<<"6 Raiz"<<endl;

    cin>>op;

    switch(op){

        case 1: cout<<suma(x,y); break;
        case 2: cout<<resta(x,y); break;
        case 3: cout<<multiplicacion(x,y); break;
        case 4: cout<<division(x,y); break;
        case 5: cout<<potencia(x,y); break;
        case 6: cout<<raiz(x); break;
    }

}