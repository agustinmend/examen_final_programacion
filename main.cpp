#include<iostream>
#include<set>
#include<vector>
#include<string>
#include<map>

using namespace std;

int main() {
    map<int , vector<string>> BD;
    int cantidad = 0;
    string dato = "";
    string entrada;
    string comando;
    string fecha;
    string evento;
    string caracter;
    while(true) {
        getline(cin , entrada);
        for(int i = 0 ; i < entrada.size(); ++i){
            caracter = entrada[i];
            if(caracter == " " && cantidad == 0) {
                comando = dato;
                ++cantidad;
                dato = "";
                continue;
            }
            else if(caracter == " " && cantidad == 1) {
                fecha = dato;
                ++cantidad;
                dato = "";
                continue;
            }
            else if(cantidad == 2 && i + 1== entrada.size() ) {
                dato = dato + caracter;
                evento = dato;
            }
            dato = dato + caracter;
        }
    cout << comando << endl;
    cout << fecha << endl;
    cout << evento << endl;

    }

    return 0;
}