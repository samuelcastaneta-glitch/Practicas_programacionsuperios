#include <bits/stdc++.h>
using namespace std;

string trim(string s) {
    size_t a = s.find_first_not_of(" \t\n\r\f\v");
    if (a == string::npos) return "";
    size_t b = s.find_last_not_of(" \t\n\r\f\v");
    return s.substr(a, b - a + 1);
}

string lowerStr(string s) {
    transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return tolower(c); });
    return s;
}

string leerLinea(const string& mensaje) {
    string s;
    cout << mensaje;
    getline(cin, s);
    return trim(s);
}

int leerEnteroPositivo(const string& mensaje) {
    while (true) {
        string s = leerLinea(mensaje);
        try {
            size_t pos = 0;
            int x = stoi(s, &pos);
            if (pos == s.size() && x > 0) return x;
        } catch (...) {}
        cout << "Valor invalido. Intente de nuevo.\n";
    }
}

string pedirNombreValido() {
    static const unordered_map<string, string> validos = {
        {"pepe", "Pepe"},
        {"pedro", "Pedro"},
        {"juana", "Juana"},
        {"maria", "Maria"},
        {"virginia", "Virginia"},
        {"lucia", "Lucia"},
        {"jose", "Jose"}
    };

    while (true) {
        string n = leerLinea("Ingrese el nombre (Pepe, Pedro, Juana, Maria, Virginia, Lucia, Jose): ");
        auto it = validos.find(lowerStr(n));
        if (it != validos.end()) return it->second;
        cout << "Nombre rechazado. Debe ser uno de los permitidos.\n";
    }
}

string pedirCiudadValida() {
    static const unordered_map<string, string> validas = {
        {"la paz", "La Paz"},
        {"el alto", "El Alto"},
        {"cochabamba", "Cochabamba"},
        {"santa cruz", "Santa Cruz"},
        {"oruro", "Oruro"},
        {"potosi", "Potosi"},
        {"sucre", "Sucre"},
        {"tarija", "Tarija"},
        {"beni", "Beni"},
        {"pando", "Pando"},
        {"trinidad", "Trinidad"},
        {"montero", "Montero"},
        {"warnes", "Warnes"},
        {"yacuiba", "Yacuiba"},
        {"quillacollo", "Quillacollo"},
        {"viacha", "Viacha"}
    };

    while (true) {
        string c = leerLinea("Ingrese la ciudad de nacimiento (Bolivia): ");
        auto it = validas.find(lowerStr(c));
        if (it != validas.end()) return it->second;
        cout << "Ciudad rechazada. Debe pertenecer a Bolivia.\n";
    }
}

class Persona {
private:
    string nombre;
    string ciudad;
    int edad;

public:
    Persona(const string& n, const string& c, int e) : nombre(n), ciudad(c), edad(e) {}

    string getNombre() const { return nombre; }
    string getCiudad() const { return ciudad; }
    int getEdad() const { return edad; }

    void info(bool permitirEdicion = false) {
        cout << "\n--- DATOS DE LA PERSONA ---\n";
        cout << "Nombre : " << nombre << '\n';
        cout << "Ciudad : " << ciudad << '\n';
        cout << "Edad   : " << edad << '\n';

        if (permitirEdicion) {
            bool cambio = false;

            string op = lowerStr(leerLinea("¿Desea modificar la ciudad? (si/no): "));
            if (op == "si" || op == "s") {
                ciudad = pedirCiudadValida();
                cambio = true;
            }

            op = lowerStr(leerLinea("¿Desea modificar la edad? (si/no): "));
            if (op == "si" || op == "s") {
                edad = leerEnteroPositivo("Ingrese la nueva edad: ");
                cambio = true;
            }

            if (cambio) {
                cout << "Datos actualizados correctamente.\n";
                cout << "\n--- DATOS ACTUALIZADOS ---\n";
                cout << "Nombre : " << nombre << '\n';
                cout << "Ciudad : " << ciudad << '\n';
                cout << "Edad   : " << edad << '\n';
            } else {
                cout << "No se realizaron cambios.\n";
            }
        }
    }
};

void mostrarPersonas(const vector<Persona>& personas) {
    if (personas.empty()) {
        cout << "No hay personas registradas.\n";
        return;
    }

    for (size_t i = 0; i < personas.size(); ++i) {
        cout << i + 1 << ") " << personas[i].getNombre()
             << " | " << personas[i].getCiudad()
             << " | " << personas[i].getEdad() << " anios\n";
    }
}

int elegirPersona(const vector<Persona>& personas) {
    if (personas.empty()) {
        cout << "No hay personas registradas.\n";
        return -1;
    }

    mostrarPersonas(personas);

    while (true) {
        string s = leerLinea("Seleccione el numero de la persona: ");
        try {
            size_t pos = 0;
            int idx = stoi(s, &pos);
            if (pos == s.size() && idx >= 1 && idx <= (int)personas.size()) return idx - 1;
        } catch (...) {}
        cout << "Seleccion invalida.\n";
    }
}

void ordenarUsuarios(vector<Persona>& personas, int criterio) {
    if (criterio == 1) {
        sort(personas.begin(), personas.end(), [](const Persona& a, const Persona& b) {
            return lowerStr(a.getNombre()) < lowerStr(b.getNombre());
        });
    } else if (criterio == 2) {
        sort(personas.begin(), personas.end(), [](const Persona& a, const Persona& b) {
            if (a.getEdad() != b.getEdad()) return a.getEdad() < b.getEdad();
            return lowerStr(a.getNombre()) < lowerStr(b.getNombre());
        });
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<Persona> personas;

    while (true) {
        cout << "\n===== MENU PRINCIPAL =====\n";
        cout << "1. Registrar persona\n";
        cout << "2. Verificar datos de una persona\n";
        cout << "3. Modificar datos de una persona\n";
        cout << "4. Ordenar usuarios\n";
        cout << "5. Mostrar todas las personas\n";
        cout << "Escriba 'salir' para terminar\n";

        string opcion = lowerStr(leerLinea("Opcion: "));
        if (opcion == "salir") break;

        if (opcion == "1") {
            string nombre = pedirNombreValido();
            string ciudad = pedirCiudadValida();
            int edad = leerEnteroPositivo("Ingrese la edad: ");
            personas.emplace_back(nombre, ciudad, edad);
            cout << "Persona registrada correctamente.\n";
        } else if (opcion == "2") {
            int idx = elegirPersona(personas);
            if (idx != -1) personas[idx].info(false);
        } else if (opcion == "3") {
            int idx = elegirPersona(personas);
            if (idx != -1) personas[idx].info(true);
        } else if (opcion == "4") {
            if (personas.empty()) {
                cout << "No hay personas para ordenar.\n";
                continue;
            }

            cout << "1. Ordenar por nombre\n";
            cout << "2. Ordenar por edad\n";
            int criterio = leerEnteroPositivo("Elija el criterio: ");
            if (criterio == 1 || criterio == 2) {
                ordenarUsuarios(personas, criterio);
                cout << "Usuarios ordenados correctamente.\n";
                mostrarPersonas(personas);
            } else {
                cout << "Criterio invalido.\n";
            }
        } else if (opcion == "5") {
            mostrarPersonas(personas);
        } else {
            cout << "Opcion invalida.\n";
        }
    }

    return 0;
}