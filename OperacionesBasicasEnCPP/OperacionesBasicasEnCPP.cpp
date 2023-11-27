// OperacionesBasicasEnCPP.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include <string>
#include <locale>
#include <iomanip> // Para std::setprecision

int main() 
{
    std::locale::global(std::locale("es_MX.UTF8"));
    setlocale(LC_ALL, "spanish");

    double dNum1 = 0.0;
    double dNum2 = 0.0;

    std::cout << "Escribe el primer número: ";
    while (!(std::cin >> dNum1)) 
    {
        std::cout << "Por favor, ingresa un número válido: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Escribe el segundo número: ";
    while (!(std::cin >> dNum2)) 
    {
        std::cout << "Por favor, ingresa un número válido: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << std::fixed << std::setprecision(6);
    std::cout << "La suma es: " << dNum1 + dNum2 << std::endl;
    std::cout << "La resta es: " << dNum1 - dNum2 << std::endl;
    std::cout << "La multiplicación es: " << dNum1 * dNum2 << std::endl;

    if (dNum2 != 0)
    {
        std::cout << "La división es: " << dNum1 / dNum2 << std::endl;
    }
    else 
    {
        std::cout << "La división no se puede llevar a cabo ya que el segundo número es 0." << std::endl;
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
