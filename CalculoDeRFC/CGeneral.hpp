#include <string> // para std::string
#include <sstream> // para std::istringstream
#include <chrono> 
#include <ctime>
#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <map>

#pragma once
class CGeneral
{
public:
	CGeneral();
	~CGeneral();
	bool validarLetras(char* cCadena);
	bool validarNumeros(char* cCadena);
	bool validarFecha(char* cCadena);
	bool esFechaValida(const std::string& fecha);
	std::string convertirMayusculas(std::string sTexto);
	void convertirCadenaMayusculas(char* cCadena);
	void convertirCadenaMinusculas(char* cCadena);
	std::string quitarArticulos(std::string sPalabra);
	bool esVocal(char letra);
	char validarNombres(std::string sNombres);
	void calcularHomoclave(std::string sNombreCompleto, std::string sFechaNacimiento, std::string& sRfc);
};

