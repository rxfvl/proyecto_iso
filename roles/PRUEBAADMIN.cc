#include "admin.h"
#include <iostream>

int main()
{
    Admin admin("XX1", "juan@gmail.com", "4321", "Juan", "Admin", "Medicina");
    Persona pepe("XX2", "pepe@gmail.com", "1234", "Pepe", "Usuario", "Medicina");
    Persona miguelin("XX3", "miguelin@gmail.com", "5432", "Miguel", "Usuario", "Informatica");


    admin.AniadirUsuario(miguelin);
    if(admin.EliminarUsuario("XX7"))
    {
        std::cout << "Usuario eliminado con exito\n";
        return 0;
    }

    return -1;

}
