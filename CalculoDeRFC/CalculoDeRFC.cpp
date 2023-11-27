// CalculoDeRFC.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "CEmpleado.hpp"

int main()
{
    std::locale::global(std::locale("es_MX.UTF8"));
    setlocale(LC_ALL, "spanish");

    std::string sNombre;
    std::string sApellidoPaterno;
    std::string sApellidoMaterno;
    std::string sFechaNacimiento;
    bool bRet = false;

    while (sNombre.empty())
    {
        std::cout << "Favor de capturar el nombre: ";
        std::getline(std::cin, sNombre); 
    }

    while(sApellidoPaterno.empty())
	{
		std::cout << "Favor de capturar el apellido paterno: ";
		std::getline(std::cin, sApellidoPaterno);
	}

    while (sApellidoMaterno.empty())
    {
        std::cout << "Favor de capturar el apellido materno: ";
        std::getline(std::cin, sApellidoMaterno);
    }

    CEmpleado objEmpleado;
    
    while (sFechaNacimiento.empty())
    {
        std::cout << "Favor de capturar la fecha de nacimiento con el siguiente formato (DD-MM-YYYY): ";
        std::getline(std::cin, sFechaNacimiento);
    }
    
    bRet = objEmpleado.validarFecha(sFechaNacimiento);
    if (!bRet)
    {
        std::cout << "La fecha de nacimiento no es valida" << std::endl;
        return 0;
    }

    sFechaNacimiento.erase(std::remove(sFechaNacimiento.begin(), sFechaNacimiento.end(), '-'), sFechaNacimiento.end());

    std::cout << sFechaNacimiento << std::endl;
    
    std::cout << sNombre << std::endl;
    std::cout << sApellidoPaterno << std::endl;
    std::cout << sApellidoMaterno << std::endl;
    std::cout << sFechaNacimiento << std::endl;

    std::string sRfc = objEmpleado.generaRfc(sNombre, sApellidoPaterno, sApellidoMaterno, sFechaNacimiento);

    std::cout << "El RFC es: " << sRfc << std::endl;
    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
