#ifndef _ADMIN_
#define _ADMIN_


#include <string>
#include <fstream>

class Persona
{
    private:

        std::string dni_;
        std::string email_;
        std::string contrasenia_;
        std::string nombrecompleto_;
        std::string rol_;
        std::string facultad_;

    public:

        Persona(std::string dni, std::string email,std::string contrasenia, std::string nombre, std::string rol, std::string facultad)
        {
            dni_ = dni;
            email_ = email;
            contrasenia_ = contrasenia;
            nombrecompleto_ = nombre;
            rol_ = rol;
            facultad_ = facultad;
        }
        void MostrarPersona();
        void CambiaDni(std::string dni){dni_ = dni;}
        void CambiaEmail(std::string email){email_ = email;}
        void CambiaContrasenia(std::string contrasenia){contrasenia_ = contrasenia;}
        void CambiaNombre(std::string nombre){nombrecompleto_ = nombre;}
        void CambiaRol(std::string rol){rol_ = rol;}
        void CambiaFacultad(std::string facultad){facultad_ = facultad;}
        std::string ObtenerDni(){return dni_;}
        std::string ObtenerEmail(){return email_;}
        std::string ObtenerContrasenia(){return contrasenia_;}
        std::string ObtenerNombre(){return nombrecompleto_;}
        std::string ObtenerRol(){return rol_;}
        std::string ObtenerFacultad(){return facultad_;}

};

class Admin: public Persona
{
    public:
        Admin(std::string dni, std::string email,std::string contrasenia, std::string nombre, std::string rol,
        std::string facultad);
        void AniadirUsuario(Persona usuario);
        bool EliminarUsuario(std::string dni);
        bool ModificarUsuario(std::string dni);
        //void AniadirActividad(Actividad act);
        bool ModificarActividad(std::string id);
        bool EliminarActividad(std::string id);

};

#endif
