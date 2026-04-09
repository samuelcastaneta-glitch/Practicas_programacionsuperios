#include <bits/stdc++.h>
using namespace std;

string leerLinea(const string& mensaje) {
    string s;
    cout << mensaje;
    getline(cin, s);
    return s;
}

int leerEnteroRango(const string& mensaje, int minimo, int maximo) {
    while (true) {
        string s = leerLinea(mensaje);
        try {
            size_t pos = 0;
            int x = stoi(s, &pos);
            if (pos == s.size() && x >= minimo && x <= maximo) return x;
        } catch (...) {}
        cout << "Opcion invalida.\n";
    }
}

class Pieza {
protected:
    string tipo;
    int costo = 0;

public:
    virtual ~Pieza() = default;
    virtual string parte() const = 0;

    int getCosto() const { return costo; }

    virtual void mostrar() const {
        cout << parte() << ": " << tipo << " - " << costo << " Bs\n";
    }
};

class Brazo : public Pieza {
public:
    Brazo(const string& t, int c) { tipo = t; costo = c; }
    string parte() const override { return "Brazo"; }
};

class Cuerpo : public Pieza {
public:
    Cuerpo(const string& t, int c) { tipo = t; costo = c; }
    string parte() const override { return "Cuerpo"; }
};

class Control : public Pieza {
public:
    Control(const string& t, int c) { tipo = t; costo = c; }
    string parte() const override { return "Control"; }
};

struct Robot {
    unique_ptr<Brazo> brazo;
    unique_ptr<Cuerpo> cuerpo;
    unique_ptr<Control> control;

    int total() const {
        return (brazo ? brazo->getCosto() : 0) +
               (cuerpo ? cuerpo->getCosto() : 0) +
               (control ? control->getCosto() : 0);
    }

    void mostrar() const {
        cout << "\n--- ROBOT CREADO ---\n";
        if (brazo) brazo->mostrar();
        if (cuerpo) cuerpo->mostrar();
        if (control) control->mostrar();
        cout << "TOTAL: " << total() << " Bs\n";
    }
};

unique_ptr<Brazo> elegirBrazo() {
    cout << "\nSeleccione el BRAZO:\n";
    cout << "1. Cierra - 20 Bs\n";
    cout << "2. Fuego  - 40 Bs\n";
    cout << "3. Laser  - 100 Bs\n";

    int op = leerEnteroRango("Opcion: ", 1, 3);
    if (op == 1) return make_unique<Brazo>("Cierra", 20);
    if (op == 2) return make_unique<Brazo>("Fuego", 40);
    return make_unique<Brazo>("Laser", 100);
}

unique_ptr<Cuerpo> elegirCuerpo() {
    cout << "\nSeleccione el CUERPO:\n";
    cout << "1. Metal    - 30 Bs\n";
    cout << "2. Hierro   - 50 Bs\n";
    cout << "3. Blindado - 200 Bs\n";

    int op = leerEnteroRango("Opcion: ", 1, 3);
    if (op == 1) return make_unique<Cuerpo>("Metal", 30);
    if (op == 2) return make_unique<Cuerpo>("Hierro", 50);
    return make_unique<Cuerpo>("Blindado", 200);
}

unique_ptr<Control> elegirControl() {
    cout << "\nSeleccione el CONTROL:\n";
    cout << "1. Cable            - 10 Bs\n";
    cout << "2. Bluetooth        - 60 Bs\n";
    cout << "3. Radio Frecuencia - 30 Bs\n";

    int op = leerEnteroRango("Opcion: ", 1, 3);
    if (op == 1) return make_unique<Control>("Cable", 10);
    if (op == 2) return make_unique<Control>("Bluetooth", 60);
    return make_unique<Control>("Radio Frecuencia", 30);
}

Robot crearRobotConLimite(int limite) {
    while (true) {
        Robot r;
        r.brazo = elegirBrazo();
        r.cuerpo = elegirCuerpo();
        r.control = elegirControl();

        if (limite == INT_MAX || r.total() <= limite) {
            r.mostrar();
            return r;
        }

        cout << "\nEl robot cuesta " << r.total() << " Bs y supera el limite de " << limite << " Bs.\n";
        cout << "Vuelva a crear el robot.\n";
    }
}

Robot creacionRobot() {
    return crearRobotConLimite(INT_MAX);
}

Robot robotCompetencia() {
    cout << "\nSeleccione el tier:\n";
    cout << "1. Tier A - maximo 100 Bs\n";
    cout << "2. Tier B - maximo 150 Bs\n";
    cout << "3. Tier C - Sin limite\n";

    int tier = leerEnteroRango("Opcion: ", 1, 3);
    int limite = (tier == 1) ? 100 : (tier == 2) ? 150 : INT_MAX;

    return crearRobotConLimite(limite);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Robot ultimoRobot;
    bool hayRobot = false;

    while (true) {
        cout << "\n===== MENU ROBOT =====\n";
        cout << "1. Crear robot normal\n";
        cout << "2. Robot de competencia\n";
        cout << "3. Mostrar ultimo robot\n";
        cout << "4. Salir\n";

        int op = leerEnteroRango("Seleccione una opcion: ", 1, 4);

        if (op == 4) break;

        if (op == 1) {
            ultimoRobot = creacionRobot();
            hayRobot = true;
        } else if (op == 2) {
            ultimoRobot = robotCompetencia();
            hayRobot = true;
        } else if (op == 3) {
            if (hayRobot) {
                ultimoRobot.mostrar();
            } else {
                cout << "Todavia no se ha creado ningun robot.\n";
            }
        }
    }

    return 0;
}