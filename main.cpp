#include<iostream>
#include<set>
#include<vector>
#include<string>
#include<map>

using namespace std;

void Add_map(map<string , vector<string>>& BD , string fecha , string evento);
void Del_map(map<string , vector<string>>& BD , string fecha , string evento);
void Find_map(map<string , vector<string>>& BD , string fecha);
void Print_map(map<string , vector<string>>& BD);
void Ordenar_map(map<string , vector<string>>& BD);

int main() {
    map<string , vector<string>> BD;
    BD[""] = {""};
    int cantidad = 0;
    int controlador = 0;
    int controlador2 = 0;
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
            if(caracter == " " && cantidad == 0 || i + 1 == entrada.size() && cantidad == 0) {
                if(i + 1 == entrada.size()) {
                    dato = dato + caracter;
                    comando = dato;
                }
                comando = dato;
                ++cantidad;
                dato = "";
                continue;
            }
            else if(caracter == " " && cantidad == 1 || i + 1 == entrada.size() && cantidad ==1) {
                if(i + 1 == entrada.size()) {
                    dato = dato + caracter;
                    fecha = dato;
                }
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
        if(calendario == "" && comando != "Print" || mes == "" && comando != "Print" || dia == "" && comando != "Print") {
            cout << "Wrong date format: " << fecha << endl;
        }
        else if(comando != "Print") {
            int month;
            int day;
            int year;
            year = stoi(calendario);
            month = stoi(mes);
            day = stoi(dia);
            if(month < 1 || month > 12) {
                cout << "Month value is invalid: " << month << endl;
            }
            else if(day < 1 || day > 31) {
                cout << "Day value is invalid: " << day << endl;
            }
            else if(year < 1000) {
                for(int i = 0 ; calendario.size() != 4 ; ++i) {
                    calendario = "0" + calendario;
                }
                if(month < 10) {
                    mes = "0" + mes;
                    if(day < 10) {
                        dia = "0" + dia;
                    }
                }
                else if(day < 10) {
                    dia = "0" + dia;
                }
            }
            else if(month < 10) {
                mes = "0" + mes;
                if(day < 10) {
                    dia = "0" + dia;
                }
            }
            else if(day < 10) {
                dia = "0" + dia;
            }
            fecha = calendario + "-" + mes + "-" + dia;
            if(comando == "Add") {
                Add_map(BD , fecha , evento);
            }
        }
        cout << fecha << endl;
        Print_map(BD);
        dato = "";
        fecha = "";
        evento = "";
        cantidad = 0;
        controlador = 0;
    }

    return 0;
}
void Add_map(map<string , vector<string>>& BD , string fecha , string evento) {
    vector<string> v;
    for(const auto& item : BD) {
        if(item.first == fecha) {
            for(const auto& elementos : item.second) {
                if(elementos == evento) {
                    break;
                }
                v = item.second;
                v.push_back(evento);
                BD[fecha] = v;
                break;
            }
        }
        v.push_back(evento);
        BD[fecha] = v;
        break;
    }
}

void Print_map(map<string , vector<string>>& BD) {
    for(const auto& item : BD) {
        for(const auto& elementos : item.second) {
            if(item.first == "" ) {
                continue;
            }
            else {
            cout << item.first << ": " << elementos << endl;
            }
        }
    }
}

void Ordenar_map(map<string , vector<string>>& BD) {

}