#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;

    cout<<"Tamano del arreglo: ";
    cin>>n;

    char *letras = new char[n];

    for(int i=0;i<n;i++)
        letras[i]='A'+i;

    cout<<"De 2 en 2"<<endl;

    for(int i=0;i<n;i+=2)
        cout<<*(letras+i)<<" ";

    cout<<endl;

    cout<<"De 5 en 5"<<endl;

    for(int i=0;i<n;i+=5)
        cout<<*(letras+i)<<" ";

    delete[] letras;

}