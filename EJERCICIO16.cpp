#include <bits/stdc++.h>
using namespace std;

#define KG 0.001
#define MG 1000
#define LIBRA 0.00220462
#define ONZA 0.035274

int main(){

    float gramos;

    cout<<"Ingrese gramos: ";
    cin>>gramos;

    cout<<"Kilogramos: "<<gramos*KG<<endl;
    cout<<"Miligramos: "<<gramos*MG<<endl;
    cout<<"Libras: "<<gramos*LIBRA<<endl;
    cout<<"Onzas: "<<gramos*ONZA<<endl;

}