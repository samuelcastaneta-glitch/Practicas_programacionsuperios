#include <bits/stdc++.h>
using namespace std;

void intercambiar(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main(){
    int x,y;

    cout<<"Ingrese valor de x: ";
    cin>>x;

    cout<<"Ingrese valor de y: ";
    cin>>y;

    intercambiar(&x,&y);

    cout<<"Valores invertidos:"<<endl;
    cout<<"x = "<<x<<endl;
    cout<<"y = "<<y<<endl;

    return 0;
}