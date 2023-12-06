#include "admin.h"
#include <iostream>

int main()
{
    Admin admin("XX1", "juan@gmail.com", "4321", "Juan", "Admin", "Medicina");
    Persona pepe("XX2", "pepe@gmail.com", "1234", "Pepe", "Usuario", "Medicina");
    Persona miguelin("XX3", "miguelin@gmail.com", "5432", "Miguel", "Usuario", "Informatica");


    if(admin.ModificarUsuario("XX6"))
    {
        std::cout << "Usuario modificado con exito"<< '\n';
    }

    else{
        std::cout <<"No ta\n";
    }


}
