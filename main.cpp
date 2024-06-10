#include<iostream>
#include<set>
#include<vector>
#include<string>
#include<map>

using namespace std;

void Add_map(map<string , vector<string>>& BD , const string fecha , const string evento);
void Del_map(map<string , vector<string>>& BD , const string fecha , const string evento);
void Find_map(map<string , vector<string>>& BD , const string fecha);
void Print_map(map<string , vector<string>>& BD);
void Ordenar_map(map<string , vector<string>>& BD);

int main() {
    map<string , vector<string>> BD;
    BD[""] = {""};
    int cantidad = 0;
    int controlador = 0;
    int controlador2 = 0;
    int controlador4 = 0;
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
        int controlador3 = 0;
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
                if(cantidad > 2 && controlador3 == 0) {
                    cout << "Wrong date format: " << fecha << endl;
                    ++controlador3;
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
                            if(cantidad > 2 && controlador3 == 0) {
                                cout << "Wrong date format: " << fecha << endl;
                                ++controlador3;
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
        if(calendario == "" && comando != "Print" && controlador3 == 0 || mes == "" && comando != "Print" && controlador3 == 0 || dia == "" && comando != "Print" && controlador3 == 0) {
            cout << "Wrong date format: " << fecha << endl;
            ++controlador3;
            continue;
        }
        else if(comando != "Print" && controlador3 == 0) {
            int month;
            int day;
            int year;
            year = stoi(calendario);
            month = stoi(mes);
            day = stoi(dia);
            if(month < 1 || month > 12) {
                cout << "Month value is invalid: " << month << endl;
                ++controlador4;
            }
            else if(day < 1 || day > 31) {
                cout << "Day value is invalid: " << day << endl;
                ++controlador4;
            }
            else if(calendario.size() < 4 && year < 1000) {
                for(int i = 0 ; calendario.size() != 4 ; ++i) {
                    calendario = "0" + calendario;
                }
                if(mes.size() < 2 && month < 10) {
                    mes = "0" + mes;
                    if(dia.size() < 2) {
                        dia = "0" + dia;
                    }
                }
                else if(dia.size() < 2 && day < 10) {
                    dia = "0" + dia;
                }
            }
            else if(mes.size() < 2 && month < 10) {
                mes = "0" + mes;
                if(dia.size() < 2 && day < 10) {
                    dia = "0" + dia;
                }
            }
            else if(dia.size() < 2 && day < 10) {
                dia = "0" + dia;
            }
            fecha = calendario + "-" + mes + "-" + dia;
            if(comando == "Add" && controlador3 == 0 && controlador4 == 0) {
                Add_map(BD , fecha , evento);
            }
            else if(comando == "Del") {
                Del_map(BD, fecha , evento);
            }
            else if(comando == "Find") {
                Ordenar_map(BD);
                Find_map(BD , fecha);
            }
        }
        else if(comando == "Print") {
            Ordenar_map(BD);
            Print_map(BD);
        }
        dato = "";
        fecha = "";
        evento = "";
        cantidad = 0;
        controlador = 0;
        controlador2 = 0;
        controlador3 = 0;
        controlador4 = 0;
    }

    return 0;
}
void Add_map(map<string , vector<string>>& BD , const string fecha , const string evento) {
    int cuenta = 0;
    for(auto& item : BD) {
        if(item.first == fecha) {
            for(int i = 0 ; i < item.second.size() ; ++i) {
                if(item.second[i] == evento) {
                    ++cuenta;
                }
            }
        }
    }
    if(cuenta == 0) {
        BD[fecha].push_back(evento);
    }
}

void Print_map(map<string , vector<string>>& BD) {
    for(const auto& item : BD) {
        for(const auto& elementos : item.second) {
            if(item.first == ""  || elementos == "") {
                continue;
            }
            else {
            cout << item.first << ": " << elementos << endl;
            }
        }
    }
}

void Ordenar_map(map<string , vector<string>>& BD) {
    string almacen;
    for(auto& item : BD) {
        for(int i = 0 ; i < item.second.size() ; ++i) {
            for(int j = 0 ; j < item.second.size() - 1; ++j) {
                if(item.second[j] > item.second[j + 1] && item.second[j] != "") {
                    almacen = item.second[j];
                    item.second[j] = item.second[j+1];
                    item.second[j+1] = almacen;
                }
            }
        }
    }
}

void Del_map(map<string , vector<string>>& BD , const string fecha , const string evento) {
    int n = 0;
    if( evento == "") {
        for(auto& item : BD) {
            if(item.first == fecha) {
                for(int i = 0; i < item.second.size() ; ++i ) {
                    if(item.second[i] != "") {
                        item.second[i] = "";
                        ++n;
                    }
                }
            }
        }
        cout << "Deleted " << n << " events" << endl;
    }
    else {
        for(auto& item : BD) {
            if(item.first == fecha) {
                for( int i = 0 ; i < item.second.size() ; ++i ) {
                    if(item.second[i] == evento) {
                        item.second[i] = "";
                        cout << "Deleted successfully" << endl;
                        break;
                    }
                    else if(i + 1 == item.second.size()){
                        cout << "Event not found" << endl;
                        break;
                    }
                }
            }
        }
    }
}

void Find_map(map<string , vector<string>>& BD , const string fecha) {
    for(auto& item : BD) {
        if (item.first == fecha) {
            for(int i = 0 ; i < item.second.size() ; ++i) {
                if(item.second[i] != "") {
                    cout << item.second[i] << endl;;
                }
            }
        }
    }
}