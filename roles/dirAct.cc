#include <fstream>

int main()
{
    std::ofstream fichero("prueba.txt");

    fichero << "Hola me llamo juan" << '|' << '\n';
    fichero.close();
}