#include <bits/stdc++.h>
using namespace std;

#define MITAD(x) (x/2)

int suma(int a,int b){
    return a+b;
}

int potencia(int base,int exp){

    int resultado=1;

    for(int i=0;i<exp;i++)
        resultado*=base;

    return resultado;
}

int factorial(int n){

    int f=1;

    for(int i=1;i<=n;i++)
        f*=i;

    return f;
}

int main(){

    int x,y;

    cout<<"Ingrese x: ";
    cin>>x;

    cout<<"Ingrese y: ";
    cin>>y;

    int s=suma(x,y);

    int d=MITAD(s);

    int p=potencia(d,2);

    int f=factorial(p);

    cout<<"Resultado final: "<<f;

}