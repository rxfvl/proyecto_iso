#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string linea, char delimitador)
{
    vector<string> campos;
    stringstream ss(linea);
    string campo;

    while (getline(ss, campo, delimitador)) {
        campos.push_back(campo);
    }

    return campos;
}


int main()
{
    ifstream archivoO("prueba.txt");
    ofstream archivoI;
    string linea, busqueda;

    if (archivoO.is_open())
    {
        archivoI.open("prueba-temp.txt");
        while(getline(archivoO, linea))
        {
            busqueda = linea.substr(0, linea.find('|'));
            if (busqueda != "3000")
            {
                archivoI << linea << '\n';
            }
        }
        
        archivoI.close();
        archivoO.close();

        remove("prueba.txt");
        rename("prueba-temp.txt", "prueba.txt");
    }
    else
    {
        cout << "Error abriendo <prueba.txt>\n"; 
    }
}