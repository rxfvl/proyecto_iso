#include "admin.h"
#include <iostream>
#include <string>

Admin::Admin(std::string dni, std::string email,std::string contrasenia, std::string nombre, std::string rol,
        std::string facultad) : Persona (dni, email, contrasenia, nombre, rol, facultad){}

void Admin::AniadirUsuario(Persona usuario)
{
    std::ofstream fichero("usuarios.txt", std::ios::app);
    if(fichero.is_open())
    {
        fichero << usuario.ObtenerDni()<<'|'<<usuario.ObtenerEmail()<<'|'
        <<usuario.ObtenerContrasenia()<<'|'<<usuario.ObtenerNombre()<<'|'<<usuario.ObtenerRol()
        <<'|'<<usuario.ObtenerFacultad()<<'\n';

        fichero.close();
    }

    else
    {
        std::cout << "No se ha podido abrir el archivo 'usuarios.txt'" << '\n';
    }
}

bool Admin::EliminarUsuario(std::string dni)
{
    std::ifstream archivoO("usuarios.txt");
    std::ofstream archivoI;
    std::string linea, busqueda;
    bool var = false;

    if (archivoO.is_open())
    {
        archivoI.open("usuarios-temp.txt");
        while(getline(archivoO, linea))
        {
            busqueda = linea.substr(0, linea.find('|'));
            if (busqueda != dni)
            {
                archivoI << linea << '\n';
            }
            else
            {
                var = true;
            }
        }
        archivoI.close();
        archivoO.close();

        remove("usuarios.txt");
        rename("usuarios-temp.txt", "usuarios.txt");
    }
    else
    {
        std::cout << "Error abriendo <usuarios.txt>\n"; 
    }
    return var;
}