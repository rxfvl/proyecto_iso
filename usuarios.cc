#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

struct Usuario {
    string nombre;
    string apellidos;
    string dni;
    string email;
};

// Función para mostrar un usuario
void mostrarUsuario(const Usuario& usuario) {
    cout << "Nombre: " << usuario.nombre << endl;
    cout << "Apellidos: " << usuario.apellidos << endl;
    cout << "DNI: " << usuario.dni << endl;
    cout << "Email: " << usuario.email << endl;
    cout << "---------------------" << endl;
}

// Función para dividir una línea en campos separados por un delimitador
vector<string> split(const string& linea, char delimitador) {
    vector<string> campos;
    stringstream ss(linea);
    string campo;

    while (getline(ss, campo, delimitador)) {
        campos.push_back(campo);
    }

    return campos;
}

// Función para cargar usuarios desde el archivo
vector<Usuario> cargarUsuarios(const string& nombreArchivo) {
    vector<Usuario> usuarios;
    ifstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        string linea;

        while (getline(archivo, linea)) {
            vector<string> campos = split(linea, '|');

            Usuario usuario;
            usuario.nombre = campos[0];
            usuario.apellidos = campos[1];
            usuario.dni = campos[2];
            usuario.email = campos[3];

            usuarios.push_back(usuario);
        }

        archivo.close();
    }

    return usuarios;
}

// Función para guardar usuarios en el archivo
void guardarUsuarios(const string& nombreArchivo, const vector<Usuario>& usuarios) {
    ofstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        for (const auto& usuario : usuarios) {
            archivo << usuario.nombre << '|' << usuario.apellidos << '|' << usuario.dni << '|' << usuario.email << '\n';
        }

        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo para guardar." << endl;
    }
}

// Función para añadir un nuevo usuario
void agregarUsuario(vector<Usuario>& usuarios) {
    Usuario nuevoUsuario;
    cout << "Ingrese el nombre: ";
    getline(cin >> ws, nuevoUsuario.nombre);
    cout << "Ingrese los apellidos: ";
    getline(cin >> ws, nuevoUsuario.apellidos);
    cout << "Ingrese el DNI: ";
    getline(cin >> ws, nuevoUsuario.dni);
    cout << "Ingrese el email: ";
    getline(cin >> ws, nuevoUsuario.email);

    usuarios.push_back(nuevoUsuario);
}

// Función para modificar un usuario existente
void modificarUsuario(vector<Usuario>& usuarios) {
    string dni;
    cout << "Ingrese el DNI del usuario a modificar: ";
    getline(cin >> ws, dni);

    for (auto& usuario : usuarios) {
        if (usuario.dni == dni) {
            cout << "Ingrese el nuevo nombre: ";
            getline(cin >> ws, usuario.nombre);
            cout << "Ingrese los nuevos apellidos: ";
            getline(cin >> ws, usuario.apellidos);
            cout << "Ingrese el nuevo email: ";
            getline(cin >> ws, usuario.email);
            cout << "Usuario modificado correctamente." << endl;
            return;
        }
    }

    cout << "Usuario no encontrado." << endl;
}

// Función para eliminar un usuario existente
void eliminarUsuario(vector<Usuario>& usuarios) {
    string dni;
    cout << "Ingrese el DNI del usuario a eliminar: ";
    getline(cin >> ws, dni);

    for (auto iter = usuarios.begin(); iter != usuarios.end(); ++iter) {
        if (iter->dni == dni) {
            iter = usuarios.erase(iter);
            cout << "Usuario eliminado correctamente." << endl;
            return;
        }
    }

    cout << "Usuario no encontrado." << endl;
}

int main() {
    vector<Usuario> usuarios = cargarUsuarios("usuarios.txt");
    int opcion;

    do {
        cout << "===== GESTIÓN DE USUARIOS =====" << endl;
        cout << "1. Mostrar usuarios" << endl;
        cout << "2. Añadir usuario" << endl;
        cout << "3. Modificar usuario" << endl;
        cout << "4. Eliminar usuario" << endl;
        cout << "5. Guardar y salir" << endl;
        cout << "Elija una opción: ";
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer del salto de línea

        switch (opcion) {
            case 1:
                cout << "===== LISTA DE USUARIOS =====" << endl;
                for (const auto& usuario : usuarios) {
                    mostrarUsuario(usuario);
                }
                break;
            case 2:
                agregarUsuario(usuarios);
                break;
            case 3:
                modificarUsuario(usuarios);
                break;
            case 4:
                eliminarUsuario(usuarios);
                break;
            case 5:
                guardarUsuarios("usuarios.txt", usuarios);
                cout << "Usuarios guardados. Saliendo..." << endl;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
                break;
        }
    } while (opcion != 5);

    return 0;
}
