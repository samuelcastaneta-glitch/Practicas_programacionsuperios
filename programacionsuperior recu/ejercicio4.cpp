#include <bits/stdc++.h>
using namespace std;

class Equipos {
protected:
    string nombre, color, marca;
private:
    double precio;

public:
    Equipos(string n, string c, string m, double p){
        nombre = n;
        color = c;
        marca = m;
        precio = p;
    }

    virtual void mostrar(){
        cout << "Producto: " << nombre << endl;
        cout << "Color: " << color << endl;
        cout << "Marca: " << marca << endl;
        cout << "Precio: " << precio << " Sus\n";
    }
};

class Parlante : public Equipos {
public:
    Parlante(string c, string m, double p)
    : Equipos("Parlante", c, m, p) {}
};

class Audifonos : public Equipos {
public:
    Audifonos(string c, string m, double p)
    : Equipos("Audifonos", c, m, p) {}
};

class Microfono : public Equipos {
public:
    Microfono(string c, string m, double p)
    : Equipos("Microfono", c, m, p) {}
};

class Tocadiscos : public Equipos {
public:
    Tocadiscos(string c, string m, double p)
    : Equipos("Tocadiscos", c, m, p) {}
};

int main(){
    vector<Equipos*> lista;

    lista.push_back(new Parlante("Azul","Amazon",100));
    lista.push_back(new Audifonos("Negro","Sony",50));
    lista.push_back(new Audifonos("Blanco","Samsung",25));
    lista.push_back(new Parlante("Azul","Bose",40));
    lista.push_back(new Tocadiscos("Cafe","Pioneer",200));
    lista.push_back(new Microfono("Gris","Blue Snowball",70));

    int op;

    do{
        cout << "\n1.Ver productos\n0.Salir\n";
        cin >> op;

        if(op == 1){
            for(auto e : lista){
                e->mostrar();
                cout << "----------------\n";
            }
        }

    } while(op != 0);
}