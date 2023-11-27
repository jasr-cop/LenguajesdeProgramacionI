// CalculoDeEdadEnLenguajeCpp.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include <locale>
#include <conio.h>

int main() 
{    // 1. Pide el ingreso de un valor entero positivo que represente la edad de una persona.
    int iEdad           = 0;
    bool bEsMayorDeEdad = false;
    std::string sEdad;

    std::locale::global(std::locale("es_MX.UTF8"));
    setlocale(LC_ALL, "spanish");
    // 1.1. Valida que el valor ingresado sea un número entero positivo.
    do 
    {
        std::cout << "Por favor, ingresa tu edad: ";
        std::getline(std::cin, sEdad);
        // Verifica si la línea está vacía
        if (sEdad.empty()) 
        {
            std::cout << "Por favor, ingresa un número." << std::endl;
            continue;
        }
        // Intenta convertir la entrada a un número entero
        try 
        {
            iEdad = std::stoi(sEdad);
        }
        catch (std::invalid_argument&) 
        {
            std::cout << "Por favor, ingresa un número válido" << std::endl;
            continue;
        }
        if (iEdad <= 0 || iEdad > 150)
        {
            std::cout << "Por favor, ingresa un número válido (mayor a 0 y menor o igual a 150)." << std::endl;
        }
    } while (iEdad <= 0 || iEdad > 150);
    // 2. Muestra en pantalla con su respectivo enunciado, si es mayor de edad o no
    if (iEdad >= 18) 
    {
        std::cout << "Eres mayor de edad. Tu edad es " << iEdad << ".\n";
    }
    else 
    {
        std::cout << "Eres menor de edad. Tu edad es " << iEdad << ".\n";
    }

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
