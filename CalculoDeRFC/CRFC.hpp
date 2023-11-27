#include <iostream>
#include <string>
#include <clocale>

#pragma once
class CRFC
{
	public:
	CRFC();
	~CRFC();
	std::string CalculaRFC(std::string nombre, std::string apellidoPaterno, std::string apellidoMaterno, int dia = 0, int mes = 0, int anio = 0);
};

