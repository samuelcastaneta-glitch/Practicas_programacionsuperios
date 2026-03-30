#include <bits/stdc++.h>
using namespace std;

class Persona{

private:
    string nombre;
    int edad;
    string correo;
    string password;

public:

    Persona(string n, int e, string c, string p){
        nombre = n;
        edad = e;
        correo = c;
        password = p;
    }

    string getNombre(){
        return nombre;
    }

    // Este codigo fue echo no I.A MAS DETALLES EN LA LINEA 70
    bool verificarPassword(){

        if(password.length() < 6)
            return false;

        int tieneNumero = 0;

        for(int i=0; i<password.length(); i++){

          
            if(password[i] >= '0' && password[i] <= '9'){
                tieneNumero = tieneNumero | 1;
            }
        }

        return tieneNumero;
    }
};

class RegistroPersonas{

private:
    vector<Persona> lista;

public:

    RegistroPersonas(){}

    void agregar(Persona p){

        if(lista.size() < 5){
            lista.push_back(p);
        }else{
            cout<<"Limite alcanzado (5 personas)"<<endl;
        }
    }

    void mostrar(){

        for(int i=0;i<lista.size();i++){
            cout<<lista[i].getNombre()<<endl;
        }
    }
    //SI viste directamente aqui pues si use I.A .Insonio y Anciedad hasta creen que perdere la oportunidad de desbelarme sufiendo
    void buscar(string nombre){

        for(int i=0;i<lista.size();i++){

            if(lista[i].getNombre() == nombre){
                cout<<"Encontrado: "<<nombre<<endl;
                return;
            }
        }

        cout<<"No encontrado"<<endl;
    }
};

int main(){

    RegistroPersonas reg;
    int opcion;

    do{

        cout<<"\n1 Crear persona";
        cout<<"\n2 Agregar persona";
        cout<<"\n3 Verificar password";
        cout<<"\n4 Mostrar personas";
        cout<<"\n5 Buscar persona";
        cout<<"\n0 Salir\n";

        cin>>opcion;

        if(opcion==1 || opcion==2){

            string n,c,p;
            int e;

            cout<<"Nombre: ";
            cin>>n;

            cout<<"Edad: ";
            cin>>e;

            cout<<"Correo: ";
            cin>>c;

            cout<<"Password: ";
            cin>>p;

            Persona per(n,e,c,p);

            if(opcion==1){
                cout<<"Persona creada"<<endl;
            }

            if(opcion==2){
                reg.agregar(per);
            }

            if(opcion==3){
                if(per.verificarPassword())
                    cout<<"Password valido"<<endl;
                else
                    cout<<"Password invalido"<<endl;
            }
        }

        if(opcion==4){
            reg.mostrar();
        }

        if(opcion==5){
            string nombre;
            cout<<"Buscar nombre: ";
            cin>>nombre;
            reg.buscar(nombre);
        }

    }while(opcion!=0);

}