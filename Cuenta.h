#pragma once
#include "Lambda.h"
#include "Vector.h"
class Cuenta {
    string Banco;
    string Moneda;
    float Monto;

public:
    Cuenta(string a, string c = " ", float o=0.0) :Banco(a), Moneda(c), Monto(o) {
        ofstream arch("Archivos/Archivos de Usuarios/" + a + ".txt"); //Cuando se crea un objeto Cuenta, se crea el txt correspondiente
    }
    ~Cuenta() {}
    string getnarch() { return Banco; }
    string getCom() { return Moneda; }
    float getMon() { return Monto; }


    // ----Abrir archivo de cuenta ----
    void abrirArch() {
        system(CLEAR);
        cout << "Imprimiendo datos de la Cuenta " << Banco << ".txt" << endl;
        cout << "Tipo de Moneda: " << Moneda << endl;//cout << "Comentario: " << Moneda << endl;
        cout << "Monto disponible en la cuenta: " << Monto << endl;
        string linea, texto;
        ifstream archivo("Archivos/Archivos de Usuarios/" + Banco + ".txt");
        while (getline(archivo, linea))
        {
            texto = texto + linea;
        }
        cout << texto;
        cin.get();
    }
    //----------------  O   P   E   R   A  C  I   O   N   E   S-----------------
    
    //EXCHANGE VENTA
    void operacionVenta(float valor) {
        float cantidad_venta = 0.0;
        float cambio = 0.0;
        float resultado = 0.0;
        cout << "Ingrese la cantidad a cambiar:" << endl;
        cin >> cantidad_venta;
        cambio = cantidad_venta / valor;
        resultado = Monto - cantidad_venta;
        cout << "Has cambiado " << cantidad_venta << " soles a " << fixed << setprecision(2) << cambio << " dolares" << endl;
        cout << "El saldo en tu cuenta actual es de " << resultado << " soles";
    }
    //EXCHANGE COMPRA
    void operacionCompra(float valor) {
        float resultado = 0.0;
        float cambio = 0.0;
        float cantidad_compra = 0.0;

        cout << "Ingrese la cantidad a cambiar:" << endl;
        cin >> cantidad_compra;
        cambio = cantidad_compra * valor;
        resultado = Monto - cantidad_compra;
        cout << "Has cambiado " << cantidad_compra << " dolares a " << fixed << setprecision(2) << cambio  << " soles" << endl;
        cout << "El saldo en tu cuenta actual es de " << resultado << " dolares";
    }
     
    //------------M   E   N   U       D  E           O   P   E   R   A  C  I   O   N   E   S-----------------

    void menu() {
        int opcion;
        bool run = true;
        while (run)
        {
            system(CLEAR);

            Vector<float> dolarvalores;
            dolarvalores.pushback(3.7180);
            dolarvalores.pushback(3.7480);

            cout << "Nombre del archivo: " << Banco << endl;
            cout << "Tipo de Moneda: " << Moneda << endl << endl;
            cout << "Monto disponible: " << Monto << endl << endl;
            cout << "                         "<<endl;

            cout << "  $$   Realizar Operacion  $$" << endl;
            cout << "-------------------------------------                         " << endl;
            cout << "Dolar compra: " << dolarvalores.pos(0) << "  Dolar venta: " << dolarvalores.pos(1) << endl;
            cout<<  "1. - Visualizar Cuenta" << endl;
            cout << "2. - EXCHANGE--->  Cambio de soles a dolares (VENTA)" << endl;
            cout << "3. - EXCHANGE--->  Cambio de dolares a soles (COMPRA)" << endl;

            cout << "4. - Regresar" << endl;
           
            cin >> opcion;
            switch (opcion)
            {
            case 1:
                abrirArch();
                cin.get();
                break;
            case 2:
                operacionVenta(dolarvalores.pos(0));
                getch();
                break;
            case 3:
                operacionCompra(dolarvalores.pos(1));
                getch();
                break;
            case 4:
                run = false;
                break;
            }
        }
    }
};