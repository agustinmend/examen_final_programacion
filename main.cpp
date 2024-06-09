#include<iostream>
#include<set>
#include<vector>
#include<string>
#include<map>

using namespace std;

int main() {
    map<string , vector<string>> BD;
    int cantidad = 0;
    string dato = "";
    string entrada;
    string comando;
    string fecha = "";
    string evento = "";
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
        dato = "";
        cantidad = 0;
        int controlador = 0;
        string calendario = "";
        string mes = "";
        string dia = "";
        if(comando != "Add" && comando != "Del" && comando != "Find" && comando != "Print") {
            cout << "Unknow command: " << comando << endl;
        }
        for(int i = 0 ; i < fecha.size() ; ++i) {
            caracter = fecha[i];
            if(caracter == "-" && i == 0) {
                continue;
            }
            else if (caracter == "-" && controlador == 0) {
                ++controlador;
                calendario = dato;
                dato = "";
                for(int j = i ; caracter != "1" && caracter != "2" && caracter != "3" && caracter != "4" && caracter != "5" && caracter != "6" && caracter != "7" && caracter != "8" && caracter != "9" && caracter != "0"; ++j) {
                    caracter = fecha[j];
                    if(caracter == "-" ) {
                        ++cantidad;
                    }
                }
                if(cantidad > 2) {
                    cout << "Wrong date format: " << fecha << endl;
                    break;
                }
                else {
                    for(int j = i + 1 ; j < fecha.size() ; ++j) {
                        caracter = fecha[j];
                        if(caracter == "-" && j == i + 1) {
                            dato = dato + caracter;
                            continue;
                        }
                        else if(caracter == "-") {
                            mes = dato;
                            dato = "";
                            cantidad = 0;
                            for(int k = j ; caracter != "1" && caracter != "2" && caracter != "3" && caracter != "4" && caracter != "5" && caracter != "6" && caracter != "7" && caracter != "8" && caracter != "9" && caracter != "0"; ++k) {
                                caracter = fecha[k];
                                if(caracter == "-") {
                                    ++cantidad;
                                }
                            }
                            if(cantidad > 2) {
                                cout << "Wrong date format: " << fecha << endl;
                                break;
                            }
                            else {
                                for(int k = j + 1 ; k < fecha.size() ; ++k) {
                                    caracter = fecha[k];
                                    if(caracter == "-" && k == j + 1) {
                                        dato = dato + caracter;
                                        continue;
                                    }
                                    else if(caracter == "-" || k + 1 == fecha.size()) {
                                        dato = dato + caracter;
                                        dia = dato;
                                        break;
                                    }
                                    dato = dato + caracter;
                                }
                            }
                            break;
                        }
                        else{
                        dato = dato + caracter;
                        }
                    }
                }
            }
            dato = dato + caracter;
        }
        cout << calendario << endl;
        cout << mes << endl;
        cout << dia << endl;
        if(calendario == "" || mes == "" || dia == "") {
            cout << "Wrong date format: " << fecha << endl;
        }
        else {
            int month;
            int day;
            month = stoi(mes);
            day = stoi(dia);
            if(month < 1 || month > 12) {
                cout << "Month value is invalid: " << month << endl;
            }
            else if(day < 1 || day > 31) {
                cout << "Day value is invalid: " << day << endl;
            }
        }
    }

    return 0;
}