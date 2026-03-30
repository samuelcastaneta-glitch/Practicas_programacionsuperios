#include <iostream>
using namespace std;

int valor(char r){

    switch(r){
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
    }

    return 0;
}

int romanoEntero(string s){

    int total=0;

    for(int i=0;i<s.length();i++){

        int v1=valor(s[i]);

        if(i+1<s.length()){

            int v2=valor(s[i+1]);

            if(v1>=v2)
                total+=v1;
            else{
                total+=v2-v1;
                i++;
            }

        }else
            total+=v1;
    }

    return total;
}

int main(){

    string romano;

    cout<<"Numero romano: ";
    cin>>romano;

    cout<<"Entero: "<<romanoEntero(romano);

}