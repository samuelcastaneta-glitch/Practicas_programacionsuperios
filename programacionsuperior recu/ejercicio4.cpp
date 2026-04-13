#include <bits/stdc++.h>
using namespace std;

string trim(const string &s) {
    size_t start = s.find_first_not_of(" \t\n\r");
    if (start == string::npos) return "";
    size_t end = s.find_last_not_of(" \t\n\r");
    return s.substr(start, end - start + 1);
}

string leerLinea(const string &mensaje) {
    cout << mensaje;
    string s;
    getline(cin, s);
    return trim(s);
}

int leerEntero(const string &mensaje, int minVal = INT_MIN, int maxVal = INT_MAX) {
    while (true) {
        string entrada = leerLinea(mensaje);
        try {
            size_t idx = 0;
            int valor = stoi(entrada, &idx);
            if (idx != entrada.size()) throw invalid_argument("sobrante");
            if (valor < minVal || valor > maxVal) {
                cout << "Valor fuera de rango. Intente de nuevo.\n";
                continue;
            }
            return valor;
        } catch (...) {
            cout << "Ingrese un numero valido.\n";
        }
    }
}

class Equipos {
private:
    double precio;

protected:
    string tipo;
    string marca;
    string color;
    string energia;
    string conexion;
    string descripcion;

public:
    Equipos(const string &t, const string &m, const string &c, const string &e,
            const string &con, const string &d, double p)
        : precio(p), tipo(t), marca(m), color(c), energia(e), conexion(con), descripcion(d) {}

    virtual ~Equipos() = default;

    double getPrecio() const { return precio; }
    virtual void mostrar() const = 0;
};

class ParlanteInteligente : public Equipos {
public:
    ParlanteInteligente()
        : Equipos("Parlante inteligente", "Amazon", "Azul", "Bateria autonoma", "", "Inteligente", 100) {}

    void mostrar() const override {
        cout << "\nProducto: " << tipo << '\n';
        cout << "Marca: " << marca << '\n';
        cout << "Color: " << color << '\n';
        cout << "Energia: " << energia << '\n';
        cout << "Caracteristica: " << descripcion << '\n';
        cout << "Precio: " << getPrecio() << " Sus\n";
    }
};

class AudifonosInteligentes : public Equipos {
public:
    AudifonosInteligentes()
        : Equipos("Audifonos inteligentes", "Sony", "Negro", "Bateria autonoma", "", "Inteligentes", 50) {}

    void mostrar() const override {
        cout << "\nProducto: " << tipo << '\n';
        cout << "Marca: " << marca << '\n';
        cout << "Color: " << color << '\n';
        cout << "Energia: " << energia << '\n';
        cout << "Caracteristica: " << descripcion << '\n';
        cout << "Precio: " << getPrecio() << " Sus\n";
    }
};

class AudifonosNoInteligentes : public Equipos {
public:
    AudifonosNoInteligentes()
        : Equipos("Audifonos no inteligentes", "Samsung", "Blanco", "", "Tipo C", "No inteligentes", 25) {}

    void mostrar() const override {
        cout << "\nProducto: " << tipo << '\n';
        cout << "Marca: " << marca << '\n';
        cout << "Color: " << color << '\n';
        cout << "Conexion: " << conexion << '\n';
        cout << "Caracteristica: " << descripcion << '\n';
        cout << "Precio: " << getPrecio() << " Sus\n";
    }
};

class Parlante : public Equipos {
public:
    Parlante()
        : Equipos("Parlante", "Bose", "Azul", "", "Jack", "", 40) {}

    void mostrar() const override {
        cout << "\nProducto: " << tipo << '\n';
        cout << "Marca: " << marca << '\n';
        cout << "Color: " << color << '\n';
        cout << "Conexion: " << conexion << '\n';
        cout << "Precio: " << getPrecio() << " Sus\n";
    }
};

class TocadiscosInalambrico : public Equipos {
public:
    TocadiscosInalambrico()
        : Equipos("Tocadiscos inalambrico", "Pioneer", "Cafe mate", "Bateria autonoma", "Inalambrico", "", 200) {}

    void mostrar() const override {
        cout << "\nProducto: " << tipo << '\n';
        cout << "Marca: " << marca << '\n';
        cout << "Color: " << color << '\n';
        cout << "Energia: " << energia << '\n';
        cout << "Conexion: " << conexion << '\n';
        cout << "Precio: " << getPrecio() << " Sus\n";
    }
};

class MicrofonoInteligente : public Equipos {
public:
    MicrofonoInteligente()
        : Equipos("Microfono inteligente", "Blue Snowball", "Gris", "", "USB", "Inteligente", 70) {}

    void mostrar() const override {
        cout << "\nProducto: " << tipo << '\n';
        cout << "Marca: " << marca << '\n';
        cout << "Color: " << color << '\n';
        cout << "Conexion: " << conexion << '\n';
        cout << "Caracteristica: " << descripcion << '\n';
        cout << "Precio: " << getPrecio() << " Sus\n";
    }
};

void mostrarTodos(const vector<unique_ptr<Equipos>> &equipos) {
    for (size_t i = 0; i < equipos.size(); ++i) {
        cout << "\n===== Equipo " << i + 1 << " =====\n";
        equipos[i]->mostrar();
    }
}

int main() {
    vector<unique_ptr<Equipos>> equipos;
    equipos.push_back(make_unique<ParlanteInteligente>());
    equipos.push_back(make_unique<AudifonosInteligentes>());
    equipos.push_back(make_unique<AudifonosNoInteligentes>());
    equipos.push_back(make_unique<Parlante>());
    equipos.push_back(make_unique<TocadiscosInalambrico>());
    equipos.push_back(make_unique<MicrofonoInteligente>());

    while (true) {
        cout << "\n===== MENU DE EQUIPOS =====\n";
        cout << "1) Mostrar todos los productos\n";
        cout << "2) Mostrar un producto por numero\n";
        cout << "3) Mostrar solo precios\n";
        cout << "0) Salir\n";

        int opcion = leerEntero("Opcion: ", 0, 3);

        if (opcion == 0) break;

        if (opcion == 1) {
            mostrarTodos(equipos);
        } else if (opcion == 2) {
            for (size_t i = 0; i < equipos.size(); ++i) {
                cout << i + 1 << ") Producto " << i + 1 << '\n';
            }
            int idx = leerEntero("Seleccione el numero del producto: ", 1, (int)equipos.size());
            equipos[idx - 1]->mostrar();
        } else if (opcion == 3) {
            cout << "\nPrecios disponibles:\n";
            for (size_t i = 0; i < equipos.size(); ++i) {
                cout << i + 1 << ") " << equipos[i]->getPrecio() << " Sus\n";
            }
        }
    }

    cout << "\nPrograma finalizado.\n";
    return 0;
}
