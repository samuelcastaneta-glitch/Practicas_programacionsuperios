#include <bits/stdc++.h>
using namespace std;

vector<string> nombresValidos = {"Pepe","Pedro","Juana","Maria","Virginia","Lucia","Jose"};
vector<string> ciudadesBolivia = {"La Paz","Cochabamba","Santa Cruz","Oruro","Potosi","Tarija","Beni","Pando","Sucre"};

class Persona {
private:
    string nombre;
    string ciudad;
    int edad;

public:
    Persona(string n, string c, int e) {
        nombre = n;
        ciudad = c;
        edad = e;
    }

    string getNombre() { return nombre; }
    int getEdad() { return edad; }

    void info() {
        cout << "Nombre: " << nombre << endl;
        cout << "Ciudad: " << ciudad << endl;
        cout << "Edad: " << edad << endl;

        cout << "¿Desea modificar datos? (1=Si, 0=No): ";
        int op;
        cin >> op;

        if(op == 1){
            cout << "Nueva ciudad: ";
            cin >> ciudad;
            cout << "Nueva edad: ";
            cin >> edad;
        }
    }
};

bool validar(vector<string> lista, string valor){
    return find(lista.begin(), lista.end(), valor) != lista.end();
}

void ordenarUsuarios(vector<Persona> &personas, int tipo){
    if(tipo == 1){
        sort(personas.begin(), personas.end(), [](Persona a, Persona b){
            return a.getNombre() < b.getNombre();
        });
    } else {
        sort(personas.begin(), personas.end(), [](Persona a, Persona b){
            return a.getEdad() < b.getEdad();
        });
    }
}

int main(){
    vector<Persona> personas;
    string opcion;

    while(true){
        cout << "\nMENU: registrar / ver / ordenar / salir\n";
        cin >> opcion;

        if(opcion == "salir") break;

        if(opcion == "registrar"){
            string nombre, ciudad;
            int edad;

            do{
                cout << "Nombre: ";
                cin >> nombre;
            } while(!validar(nombresValidos, nombre));

            do{
                cout << "Ciudad: ";
                cin >> ciudad;
            } while(!validar(ciudadesBolivia, ciudad));

            cout << "Edad: ";
            cin >> edad;

            personas.push_back(Persona(nombre, ciudad, edad));
        }

        else if(opcion == "ver"){
            for(auto &p : personas){
                p.info();
                cout << "-------------\n";
            }
        }

        else if(opcion == "ordenar"){
            int tipo;
            cout << "1.Nombre  2.Edad: ";
            cin >> tipo;
            ordenarUsuarios(personas, tipo);
        }
    }
}